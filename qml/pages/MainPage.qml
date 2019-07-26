import QtQuick 2.0
import Sailfish.Silica 1.0
import user 1.0


Page {
    id: page
    property int avg_walk_speed: user.averWalkSpeed;

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.Portrait
   User{
        id: user
    }

   Column {
       id: column
       spacing: Theme.paddingMedium
       width: parent.width
       y: 40
       Label {
           anchors.horizontalCenter: parent.horizontalCenter
           text: "Username"
           font.pixelSize: 40
           color: Theme.primaryColor
       }
       Image {
           id: pic
           source: "user.png"
           anchors.horizontalCenter: column.horizontalCenter
           sourceSize.height: 172
           sourceSize.width: 172
       }
//       Row {
//           id: row
//           anchors {
//               left: parent.left
//               right: parent.right
//               margins: Theme.paddingLarge
//           }
//           spacing: 20
//           width: parent.width
//           Rectangle {
//               id: rectLab
//               height: 60
//               color: "transparent"
//               border.color: Theme.primaryColor
//               width: 400
//               Label {
//                   height: 60
//                   text: "Current level"
//                   color: Theme.primaryColor
//                   font.pixelSize: 40
//                   anchors.centerIn: rectLab
//               }
//           }
//           Rectangle {
//               id: rectPB
//               height: 60
//               color: "transparent"
//               border.color: Theme.primaryColor
//               width: 200
//               Label {
//                   property int value: 38
//                   text: value + " / 100"
//                   anchors.centerIn: rectPB
//               }
//           }
//       }
      Rectangle {
          id: rateRect
          width: parent.width
          height: 60
          color: "transparent"
          border.color: Theme.primaryColor
          anchors {
              left: parent.left
              right: parent.right
              margins: Theme.paddingMedium

          }
          Label {
              property int rating: 10000
              text: "Rating: " + rating
              anchors.centerIn: rateRect
              font.pixelSize: 40
              color: Theme.primaryColor
          }
      }
      Label {
          anchors {
              left: parent.left
              right: parent.right
              margins: Theme.paddingMedium

          }
          property int avg_run_speed: user.averRunSpeed;
          text: "Средняя скорость бега: %1 км/ч".arg(avg_run_speed)
          font.pixelSize: 40
          color: Theme.primaryColor
      }
      Label {
          anchors {
              left: parent.left
              right: parent.right
              margins: Theme.paddingMedium

          }
          text: "Средняя скорость хотьбы: %1 км/ч".arg(avg_walk_speed)
          font.pixelSize: 40
          color: Theme.primaryColor
      }
      Label {
          id: lastDateOfTest
          anchors {
              left: parent.left
              right: parent.right
              margins: Theme.paddingMedium

          }
          text: "Дата последнего теста: %1/%2/%3"
          .arg(25)
          .arg(07)
          .arg(2019)
          font.pixelSize: 40
          color: Theme.primaryColor
      }
   }
    Rectangle {
        width: parent.width
        height: 160
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        z: -1
        color: Theme.darkSecondaryColor

        Row {
            anchors {
                left: parent.left
                right: parent.right
                bottom: parent.bottom
                margins: Theme.paddingSmall
            }
            spacing: 30

            Button {
                 height: 160
                 width: 210
                 text: "Журнал"
                 onClicked: {
                     pageStack.push(Qt.resolvedUrl("Journal.qml"))
                 }
            }
            Button {
                height: 160
                width: 210
                text: "Пробежка"
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("RunPage.qml"))
                }
            }
            Button {
                height: 160
                width: 210
                text: "Тест"
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("TestRunPage.qml"))
                }
            }
        }
    }
}
