import QtQuick 2.0
import Sailfish.Silica 1.0
import "pages"
import "model"

ApplicationWindow
{
    readonly property JournalModel jmodel: JournalModel {}
    function openNewNoteDialog(operationType) {
            var dialog = pageStack.push(Qt.resolvedUrl("dialogs/NoteDialog.qml"),
                                 { isNewNote: true },
                                 operationType);
            dialog.accepted.connect(function () {
                jmodel.appendNote(dialog.collectProperties());
            });
        }

    initialPage: Component { MainPage { } }
    cover: Qt.resolvedUrl("cover/CoverPage.qml")
    allowedOrientations: defaultAllowedOrientations
}
