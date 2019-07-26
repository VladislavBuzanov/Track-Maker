import QtQuick 2.0
import QtLocation 5.0
import QtPositioning 5.0
import Sailfish.Silica 1.0

Page {
    id: page
    property string date;
    property string coords;
    property string time;
    property bool isNewNote: false

    function collectProperties() {
        return {
            date: this.date,
            coords: this.coords,
            time: this.time
        };
    }


    SilicaFlickable {
        anchors.fill: parent
        contentHeight: column.height


        Column {
            id: column
            width: parent.width
            spacing: 25
            anchors {
                left: parent.left
                right: parent.right
            }

            //ToDo: Добавить парсер координат и отображение маршрута на карте
            Plugin {
                id: mapPlugin
                name: "osm"
                PluginParameter {
                    name: "osm.mapping.host";
                    value: "http://osm.tile.server.address/"
                }
            }
            Map {
                id: map
                width: page.width
                height: page.height / 2
                plugin: mapPlugin
                zoomLevel: 8
                gesture.enabled: true
                gesture.activeGestures: MapGestureArea.PinchGesture | MapGestureArea.PanGesture
        }

            Label {
                anchors {
                    margins: Theme.paddingLarge
                    horizontalCenter: parent.horizontalCenter

                }

                text: "Дата пробежки: %1".arg(date)
                font.pixelSize: 40
                color: Theme.primaryColor
            }
            Label {
                anchors {
                    horizontalCenter: parent.horizontalCenter

                    margins: Theme.paddingLarge
                }
                text: "Длительность: %1".arg(time)
                font.pixelSize: 40
                color: Theme.primaryColor
            }
        }
    }
}
