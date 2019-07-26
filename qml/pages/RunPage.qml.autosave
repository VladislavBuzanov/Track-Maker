import QtQuick 2.0
import Sailfish.Silica 1.0
import QtPositioning 5.3

Page {
    id: page
    //ToDO: Make dependences
    property real avg_speed: 0;
    property int distPasses: 0;
    property int minute: 0;
    property int hours: 0;
    property int seconds: 0;

    Image {
        id: image
        anchors {
            horizontalCenter: parent.horizontalCenter
            margins: Theme.paddingLarge
        }
        source: "StartRun.png"
        MouseArea {
            id: mouseArea
            anchors.fill : image
            onClicked:  {
                if (image.state == 'Runing') {
                    image.state = 'NotRuning'
                    minute = 0;
                    hours = 0;
                    timePassed.text = "Времени осталось - 00:00"
                }
                else {
                    var dialog = pageStack.push("Sailfish.Silica.TimePickerDialog", {
                                                hourMode: DateTime.TwentyFourHours});
                    dialog.accepted.connect(function() {
                        minute = dialog.minute
                        hours = dialog.hour
                        var second = (minute + hours * 60) * 60;
                        seconds = second;
                        timePassed.text = "Времени осталось - " + dialog.timeText;
                    })
                    image.state = 'Runing'
                }
            }
        }
        states: [
            State {
                name: "Runing"
                PropertyChanges {
                    target: image
                    source: "StopRun.png"
                }
            },
            State {
                name: "NotRuning"
                PropertyChanges {
                    target: image
                    source: "StartRun.png"
                }
            }
        ]
        Label {
            text: image.state == 'Runing'? "Завершить" : "Начать"
            anchors {
                top: image.bottom
                margins: Theme.paddingLarge
                horizontalCenter: image.horizontalCenter
            }
            font.pixelSize: 40
            color: Theme.primaryColor
        }
    }

   Column {
       spacing: 30
       anchors {
           left: parent.left
           right: parent.right
           verticalCenter: parent.verticalCenter
           margins: Theme.paddingLarge
       }


       Label {
           text: "Средняя скорость - %1 км/ч".arg(avg_speed)
           font.pixelSize: 40
           color: Theme.primaryColor
       }
       Label {
           text: "Пройденное растояние - %1 метров".arg(distPasses)
           font.pixelSize: 40
           color: Theme.primaryColor
       }
       Label {
           id: timePassed
           text: "Времени прошло - %1 ч %2 м".arg(hours).arg(minute)
           font.pixelSize: 40
           color: Theme.primaryColor
       }
   }
}

