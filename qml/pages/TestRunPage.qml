import QtQuick 2.0
import qualRun 1.0
import Sailfish.Silica 1.0
import qualRun 1.0

Page  {
    Image {
        id: image
        anchors {
            horizontalCenter: parent.horizontalCenter
            margins: Theme.paddingLarge
        }
        source: "start.png"
        MouseArea {
            id: mouseArea
            anchors.fill : image
            onClicked:  {
                console.log("run");
                qRun.run();
                image.state = 'Walk'
                }
            }

        states: [
            State {
                name: "Walk"
                PropertyChanges {
                    target: image
                    source: "Walk.png"
                }
                PropertyChanges {
                    target: label
                    text:"Идите 100 метров
                           обычным шагом"

                }
            },
            State {
                name: "Walk_Fast"
                PropertyChanges {
                    target: image
                    source: "fast_walk.png"
                }
                PropertyChanges {
                    target: label
                    text: "Идите 200 метров
                            быстрым шагом"

                }
            },
            State {
                name: "Run"
                PropertyChanges {
                    target: image
                    source: "RunT.png"
                }
                PropertyChanges {
                    target: label
                    text: "Пробегите 1 км"

                }
            }
        ]
    }

        Label {
            id: label
            text: "Начать"
            anchors {
                top: image.bottom
                margins: Theme.paddingLarge
                horizontalCenter: image.horizontalCenter
            }
            font.pixelSize: 40
            color: Theme.primaryColor
        }

   Column {
       spacing: 30
       anchors {
           left: parent.left
           right: parent.right
           verticalCenter: parent.verticalCenter
           margins: Theme.paddingLarge
       }
   }
}
