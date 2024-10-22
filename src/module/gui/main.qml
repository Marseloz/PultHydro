import "front/moduls/Compass"
import "front/moduls/Attitude"
import "front/moduls/Depth"
import "front/moduls/Force"
import "front/moduls/Direction"
import "front/moduls/Rpd"
import QtQuick 6.7
import QtQuick.Controls 6.7
import QtQuick.Dialogs 6.7

import QtMultimedia 6.7
import QtQuick.Window 6.7
import QtQuick.Layouts 6.7

import org.freedesktop.gstreamer.Qt6GLVideoItem 1.0

Window {
    property var context
    property real joyxr: 0.2
    id: mainWindow
    width: 1200
    height: 800
    minimumHeight: 484
    minimumWidth: 479

    visible: true
    color: "#212121"

    property int marginsHorizontal: 40
    property int marginsVertical: 40
    property real fontSize: 0.5

    property real _win_size: 1080/1920 //соотношение сторон видео

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent
        spacing: 0
        MenuBar {
            id: menuBar
            height: 800
            palette.window: "#3D3D3D"
            palette.text: "#DADADA"
            //palette.highlight: "#76767E"

            Menu {
                palette.base: "#2D2D2F" // up rect
                title: qsTr("&File")
                // Action {
                //     text: qsTr("&New...")

                // }
                // Action {
                //     text: qsTr("&Open...")

                // }
                // Action { text: qsTr("&Save")

                // }
                // Action { text: qsTr("Save &As...")

                // }
                //MenuSeparator { }
                Action { text: qsTr("&Exit")
                    onTriggered: {
                        Qt.quit()
                    }
                }
            }

            Menu {
                palette.base: "#2D2D2F"
                title: qsTr("&Edit")
                // Action { text: qsTr("Cu&t")

                // }
                // Action { text: "&Copy"

                // }
                // Action { text: qsTr("&Paste")

                // }
                MenuSeparator { }
                Action {
                    text: qsTr("&Settings")
                    onTriggered: {
                        var component = Qt.createComponent("front/SettingsWindow.qml")
                        var window = component.createObject()
                        window.show()
                    }
                }
            }

            Menu {
                palette.base: "#2D2D2F"
                title: qsTr("&Windows")
                Action { text: qsTr("&Full Screen")
                    property real xt1:0;
                    onTriggered: {
                        if(xt1 == 0){
                            text = "OFF &Full Screen"
                            mainWindow.visibility = "FullScreen"
                            xt1 = 1

                        }else{
                            mainWindow.visibility = "Windowed"
                            xt1 = 0
                            text = "&Full Screen"
                        }
                    }
                }
                Action { text: "Split"
                    property real xt:0;
                    onTriggered: {
                        if(xt == 0){
                            text = "OFF Split"
                            xt = 1
                            columnLayout1.visible = false
                            rectangle1.visible = false
                        }else{
                            text = "Split"
                            xt = 0
                            columnLayout1.visible = true
                            rectangle1.visible = true
                        }
                    }

                }
            }

            Menu {
                palette.base: "#2D2D2F"
                title: qsTr("&Help")
                Action {
                    text: qsTr("&About")

                    onTriggered: {
                        var component = Qt.createComponent("front/AboutWindow.qml")
                        var window = component.createObject()
                        window.show()
                    }
                }
            }

            delegate: MenuBarItem {
                id: menuBarItem

                function replaceText(txt)
                {
                    var index = txt.indexOf("&");
                    if(index >= 0)
                        txt = txt.replace(txt.substr(index, 2), ("<u>" + txt.substr(index + 1, 1) +"</u>"));
                    return txt;
                }

                contentItem: Text {
                    text: replaceText(menuBarItem.text)
                    font: menuBarItem.font
                    opacity: enabled ? 1.0 : 0.3
                    color: menuBarItem.highlighted ? "#ffffff" : "#ffffff"
                    horizontalAlignment: Text.Right
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle { // это элемент панели
                    implicitWidth: 40
                    implicitHeight: 20
                    opacity: enabled ? 1 : 0.3
                    color: menuBarItem.highlighted ? "#a9a9a9" : "transparent"
                }
            }



            background: Rectangle { // это вехняя панель, на которой расположены кнопки меню
                implicitWidth: mainWindow.width
                implicitHeight: 20
                color: "#3D3D3D"
            }

        }
        ColumnLayout {
            id: columnLayout2
            width: 100
            height: 100
            spacing: 10
            Layout.margins: 5
            //Layout.margins: 5

            RowLayout {
                id: rowLayout
                width: 100
                height: 100
                spacing: 0

                Rectangle {
                    id: rectangle4
                    width: 200
                    height: 200
                    color: "#37363a"
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    RowLayout {
                        id: rowLayout1
                        anchors.fill: parent
                        spacing: 0


                        Rectangle {
                            id: rectangle
                            width: 3
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            color: "#232325"
                            radius: 0
                            border.color: "#3a3a3a"
                            border.width: 0
                            Layout.preferredHeight: 0
                            Layout.preferredWidth: 2
                            Layout.rightMargin: 1
                            Layout.bottomMargin: 1
                            Layout.leftMargin: 1
                            Layout.topMargin: 1
                            Layout.margins: 0

                            // GQ {// болванка экрана стриминга видео
                            //     id: video
                            //     //visible: true
                            //     objectName: "videoItem"
                            //     //anchors.fill: parent
                            //     //anchors.leftMargin: 1
                            //     //anchors.rightMargin: 1
                            //     //anchors.topMargin: 1
                            //     //anchors.bottomMargin: 1
                            //     //width: (rectangle.width*mainWindow._win_size)>rectangle.height?rectangle.height/mainWindow._win_size:rectangle.width
                            //     //height:(rectangle.width*mainWindow._win_size)>rectangle.height?rectangle.height:rectangle.width*mainWindow._win_size
                            // }
                            GstGLQt6VideoItem {// болванка экрана стриминга видео
                                id: video
                                visible: true
                                objectName: "videoItem"
                                anchors.fill: parent
                                anchors.leftMargin: 1
                                anchors.rightMargin: 1
                                anchors.topMargin: 1
                                anchors.bottomMargin: 1
                                //width: (rectangle.width*mainWindow._win_size)>rectangle.height?rectangle.height/mainWindow._win_size:rectangle.width
                                //height:(rectangle.width*mainWindow._win_size)>rectangle.height?rectangle.height:rectangle.width*mainWindow._win_size
                            }


                            Text {
                                id: text3
                                color: "#54ffffff"
                                text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Camera 1</p></body></html>"
                                anchors.left: parent.left
                                anchors.top: parent.top
                                anchors.leftMargin: 7
                                anchors.topMargin: 6
                                font.pixelSize: 14
                                horizontalAlignment: Text.AlignRight
                                textFormat: Text.RichText
                                font.family: "Arial"
                            }
                        }
                        ColumnLayout {
                            id: columnLayout1
                            width: 1
                            height: 100
                            visible: true
                            spacing: 0

                            Rectangle {
                                id: rectangle2
                                visible: true
                                color: "#232325"
                                radius: 0
                                border.color: "#3a3a3a"
                                border.width: 0
                                Layout.preferredHeight: 0
                                Layout.preferredWidth: 0
                                Layout.bottomMargin: 1
                                Layout.rightMargin: 1
                                Layout.topMargin: 1
                                Layout.leftMargin: 0
                                Layout.margins: 0
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                Rectangle {// болванка экрана стриминга видео
                                    id: video1
                                    visible: true
                                    color: "#1b1b1b"
                                    border.width: 0
                                    objectName: "videoItem"
                                    anchors.fill: parent
                                    anchors.leftMargin: 0
                                    anchors.rightMargin: 1
                                    anchors.topMargin: 1
                                    anchors.bottomMargin: 1
                                    //width: (rectangle.width*mainWindow._win_size)>rectangle.height?rectangle.height/mainWindow._win_size:rectangle.width
                                    //height:(rectangle.width*mainWindow._win_size)>rectangle.height?rectangle.height:rectangle.width*mainWindow._win_size
                                }

                                Text {
                                    id: text2
                                    visible: true
                                    color: "#54ffffff"
                                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Camera 2</p></body></html>"
                                    anchors.left: parent.left
                                    anchors.top: parent.top
                                    anchors.leftMargin: 7
                                    anchors.topMargin: 6
                                    font.pixelSize: 14
                                    horizontalAlignment: Text.AlignRight
                                    textFormat: Text.RichText
                                    font.family: "Arial"
                                }
                            }

                            Rectangle {
                                id: rectangle3
                                visible: true
                                color: "#232325"
                                radius: 0
                                border.color: "#3a3a3a"
                                border.width: 0
                                Layout.preferredHeight: 1
                                Layout.preferredWidth: 0
                                Layout.bottomMargin: 1
                                Layout.rightMargin: 1
                                Layout.topMargin: 0
                                Layout.leftMargin: 0
                                Layout.margins: 0
                                Layout.fillWidth: true
                                Layout.fillHeight: true

                                Rectangle {// болванка экрана стриминга видео
                                    id: video2
                                    visible: true
                                    color: "#1b1b1b"
                                    border.width: 0
                                    objectName: "videoItem"
                                    anchors.fill: parent
                                    anchors.leftMargin: 0
                                    anchors.rightMargin: 1
                                    anchors.topMargin: 0
                                    anchors.bottomMargin: 1
                                    //width: (rectangle.width*mainWindow._win_size)>rectangle.height?rectangle.height/mainWindow._win_size:rectangle.width
                                    //height:(rectangle.width*mainWindow._win_size)>rectangle.height?rectangle.height:rectangle.width*mainWindow._win_size
                                }

                                Text {
                                    id: text1
                                    visible: true
                                    color: "#54ffffff"
                                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Camera 3</p></body></html>"
                                    anchors.left: parent.left
                                    anchors.top: parent.top
                                    anchors.leftMargin: 7
                                    anchors.topMargin: 6
                                    font.pixelSize: 14
                                    horizontalAlignment: Text.AlignRight
                                    textFormat: Text.RichText
                                    font.family: "Arial"
                                }
                            }
                        }
                    }
                }
            }

            Rectangle {
                id: rectangle1
                Layout.fillWidth: true
                height: 150
                color: "#19ffffff"
                border.width: 0

                Row {
                    id: row1
                    anchors.fill: parent
                    Layout.fillWidth: false
                    layoutDirection: Qt.LeftToRight



                    Row {
                        id: row
                        anchors.left: parent.left
                        anchors.right: row2.left
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.rightMargin: 0
                        spacing: 10




                        // Rectangle {
                        //     id: rectangle7
                        //     width: rectangle1.height
                        //     height: rectangle1.height
                        //     color: "#947e7e7e"
                        //     border.width: 0
                        //     Layout.fillWidth: false
                        //     Layout.fillHeight: true
                        // }

                        // DirectionModule {
                        //     id: directionModule
                        //     width: rectangle1.height
                        //     height: rectangle1.height
                        // }
                        CompassModule {
                            id: compassModule
                            width: rectangle1.height
                            height: rectangle1.height
                        }
                        // RpdModule {
                        //     id: rpdModule
                        //     width: rectangle1.height
                        //     height: rectangle1.height
                        // }
                        Rectangle {
                            id: rectangle8
                            width: rectangle1.height
                            height: rectangle1.height
                            color: "#317e7e7e"
                            border.width: 0
                            Layout.fillWidth: false
                            Layout.fillHeight: true
                        }
                        Rectangle {
                            id: rectangle9
                            width: rectangle1.height*1.5
                            height: rectangle1.height
                            color: "#317e7e7e"
                            border.width: 0
                            Layout.fillWidth: false
                            Layout.fillHeight: true
                        }
                        Rectangle {
                            id: rectangle10
                            width: rectangle1.height
                            height: rectangle1.height
                            visible: true
                            color: "#317e7e7e"
                            border.width: 0
                            Layout.fillWidth: false
                            Layout.fillHeight: true
                            // MouseArea {
                            //     anchors.fill: parent
                            //     onClicked: {
                            //         rectangle10.color = "#ffffff"
                            //         GUI.updateSetting()
                            //     }
                            // }
                        }

                        Rectangle {
                            id: rectangle11
                            width: rectangle1.height
                            height: rectangle1.height
                            visible: true
                            color: "#317e7e7e"
                            border.width: 0
                            Layout.fillWidth: false
                            Layout.fillHeight: true
                        }
                    }

                    Row {
                        id: row2
                        width: 400
                        anchors.right: parent.right
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.rightMargin: 0
                        anchors.topMargin: 0
                        anchors.bottomMargin: 0
                        layoutDirection: Qt.RightToLeft

                        Rectangle {
                            id: rectangle12
                            width: rectangle1.height*2
                            height: rectangle1.height
                            color: "#317e7e7e"
                            border.width: 0
                            Layout.fillWidth: false
                            Layout.fillHeight: true
                        }
                    }
                }
            }
        }
    }
}
