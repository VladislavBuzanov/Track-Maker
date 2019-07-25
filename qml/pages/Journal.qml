import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.Portrait

    SilicaListView {
           anchors.fill: parent
           header: PageHeader { title: qsTr("Журнал пробежек") }
           model: jmodel
           delegate: journalD

           VerticalScrollDecorator { }
           PullDownMenu {
               MenuItem {
                   text: qsTr("Create a note")
                   onClicked: openNewNoteDialog()
               }
           }


       }
       Component {
           id: journalD

           ListItem {
               id: journalItem
               contentHeight: Theme.itemSizeMedium

               function remove() {
                   notesModel.removeNote(model.index);
               }

               menu: ContextMenu {
                   MenuItem {
                       text: qsTr("Delete")
                       onClicked: journalItem.remove()
                   }
               }

//               onClicked: {
//                   var dialog = pageStack.push(Qt.resolvedUrl("../dialogs/NoteDialog.qml"));
//                   dialog.update(notesModel.getNote(model.index));
//                   dialog.accepted.connect(function () {
//                       journalItem.setNote(model.index, dialog.collectProperties());
//                   });
//               }
               ListView.onRemove: journalItem.animateRemoval()

               Column {
                   anchors {
                       left: parent.left
                       right: parent.right
                       margins: Theme.horizontalPageMargin
                       verticalCenter: parent.verticalCenter
                   }

                   Label {
                       text: model.date
                       color: journalItem.highlighted ? Theme.highlightColor : Theme.primaryColor
                       width: parent.width
                   }

                   Label {
                       text: model.time
                       color: journalItem.highlighted ? Theme.secondaryHighlightColor : Theme.secondaryColor
                       font.pixelSize: Theme.fontSizeSmall
                       width: parent.width
                   }
               }
           }
       }
}
