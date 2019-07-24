import QtQuick 2.0
import Sailfish.Silica 1.0

Dialog {
    property alias notedate: noteTitleField.text
    property alias notecoords: noteTitleField1.text
    property alias notetime: noteTitleField2.text
    property bool isNewNote: false

    function collectProperties() {
        return {
            date: notedate,
            coords: notecoords,
            time: notetime
        };
    }

    canAccept: !noteTitleField.errorHighlight

    SilicaFlickable {
        anchors.fill: parent
        contentHeight: column.height

        Column {
            id: column
            width: parent.width

            DialogHeader { acceptText: isNewNote ? qsTr("Create") : qsTr("Save") }
            TextField {
                id: noteTitleField
                label: qsTr("Title")
                placeholderText: qsTr("Enter the title")
                width: parent.width
            }
            TextField {
                id: noteTitleField1
                label: qsTr("Title")
                placeholderText: qsTr("Enter the title")
                width: parent.width
            }
            TextField {
                id: noteTitleField2
                label: qsTr("Title")
                placeholderText: qsTr("Enter the title")
                width: parent.width
        }
        VerticalScrollDecorator { }
    }
}
}
