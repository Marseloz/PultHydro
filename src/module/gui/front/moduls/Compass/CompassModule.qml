import QtQuick 2.0
import QtQuick.Controls 6.2

Item {
    id: baseItem
    width: 198
    height: 198
    property string mode
    property int _margins: 5

    Rectangle {
        id: compassBackground
        color: "#0F878AA0"
        anchors.fill: baseItem
        Image {
            id: compassScaleImage
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
            anchors.margins: _margins
            //anchors.verticalCenter: compassBackground.verticalCenter
            //anchors.horizontalCenter: compassBackground.horizontalCenter
            source: "svg/point.svg"
        }
        Image {
            id: compassPointerImage
            anchors.fill: parent
            anchors.margins: _margins
            //anchors.verticalCenter: compassBackground.verticalCenter
            //anchors.horizontalCenter: compassBackground.horizontalCenter
            source: "svg/compass.svg"
            fillMode: Image.PreserveAspectFit
            RotationAnimation on rotation {
                loops: Animation.Infinite
                from: 0
                to: 360
                duration: 10000
            }
        }
    }
}
