import QtQuick 2.0
import QtQuick.Layouts 6.0
import QtQuick.Controls 6.2


Window {
    id: aboutWindow
    title: "About"
    visible: true
    width: 500; height: 300
    color: "#212121"
    // flags: Qt.FramelessWindowHint // убирает верхнюю часть окна с изначальными кнопками
    // flags: Qt.SubWindow



    Text {
        text: "Программа разработана для УНМЦ \"Гидронавтика\""
        anchors.fill: parent
        anchors.leftMargin: 40
        anchors.rightMargin: 40
        anchors.topMargin: 40
        anchors.bottomMargin: 90
        color: "white"
        font.pixelSize: 20
        horizontalAlignment: Text.AlignLeft
        wrapMode: Text.WordWrap
        anchors.horizontalCenterOffset: 40
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
