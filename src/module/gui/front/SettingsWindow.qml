import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Layouts


Window {
    id: settWind
    width: 1000
    height: 700
    visible: true
    maximumHeight: 800
    maximumWidth: 1000
    minimumHeight: 700
    minimumWidth: 1000
    title: joyxr
Rectangle {
    id: rectangle
    width: 1000
    height: 700
    color: "#2c2c2c"

    ColumnLayout {
        id: columnLayout
        anchors.fill: rectangle
        anchors.leftMargin: 16
        anchors.rightMargin: 16
        anchors.topMargin: 16
        anchors.bottomMargin: 16
        spacing: 15

        RowLayout {
            id: rowLayout
            anchors.fill: columnLayout.alignment
            //uniformCellSizes: false
            Layout.rowSpan: 1
            Layout.columnSpan: 1
            layoutDirection: Qt.LeftToRight

            Rectangle {
                id: rectangle1
                width: 200
                height: 200
                visible: true
                color: "#353637"
                Layout.preferredWidth: 69
                Layout.fillHeight: true
                Layout.fillWidth: true

                RowLayout {
                    id: rowLayout1
                    anchors.fill: parent
                    spacing: 0

                    ColumnLayout {
                        id: columnLayout1
                        width: 145
                        anchors.left: rowLayout1.alignment
                        anchors.top: rowLayout1.alignment
                        anchors.bottom: rowLayout1.alignment
                        clip: true
                        // ListView {
                        //     id: list45
                        //     width: 100
                        //     height: 100
                        //     anchors.fill: columnLayout1.alignment
                        //     smooth: false
                        //     model: ["Общие", "Аппарт", "Видеосвязь", "Управление", "Дополнительно"]
                        //     delegate: TabButton {
                        //         height: 30
                        //         text: modelData
                        //         anchors.left: list45.left
                        //         //anchors.right: parent.right
                        //         leftPadding: 15
                        //         rightPadding: 90
                        //         padding: 0
                        //         font.preferShaping: true
                        //         font.hintingPreference: Font.PreferDefaultHinting
                        //         font.family: "Arial"
                        //         //font.bold: true
                        //         font.pointSize: 12

                        //         checked: index === 0 ? true : false
                        //         onClicked: stackLayout.currentIndex = index
                        //     }
                        // }
                    }

                    Rectangle {
                        id: rectangle2
                        width: 200
                        height: 200
                        color: "#262626"
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        StackLayout {
                            id: stackLayout
                            anchors.fill: parent
                            anchors.leftMargin: 22
                            currentIndex: 0

                            Column {
                                id: column
                                width: 200
                                height: 400

                                RowLayout {
                                    id: rowLayout2
                                    width: 100
                                    height: 40
                                    anchors.left: parent.left
                                    anchors.leftMargin: 0
                                    //uniformCellSizes: false
                                    layoutDirection: Qt.LeftToRight
                                    spacing: 5

                                    CheckBox {
                                        id: checkBox
                                        width: 80
                                        text: qsTr("")
                                        scale: 0.842
                                        tristate: false
                                        checkState: Qt.Unchecked
                                        display: AbstractButton.IconOnly
                                        clip: false
                                    }
                                    Label {
                                        id: label1
                                        color: "#ffffff"
                                        text: qsTr("Значение 1")
                                        font.pointSize: 11
                                    }
                                }

                                RowLayout {
                                    id: rowLayout3
                                    width: 100
                                    height: 40

                                    CheckBox {
                                        id: checkBox1
                                        width: 80
                                        text: qsTr("")
                                        tristate: false
                                        scale: 0.842
                                        display: AbstractButton.IconOnly
                                        clip: false
                                        checkState: Qt.Unchecked
                                    }
                                    Label {
                                        id: label2
                                        color: "#ffffff"
                                        text: qsTr("Значение 2")
                                        font.pointSize: 11
                                    }
                                }

                                RowLayout {
                                    id: rowLayout5
                                    width: 100
                                    height: 40

                                    CheckBox {
                                        id: checkBox3
                                        width: 80
                                        text: qsTr("")
                                        tristate: false
                                        scale: 0.842
                                        display: AbstractButton.IconOnly
                                        clip: false
                                        checkState: Qt.Unchecked
                                    }
                                    Label {
                                        id: label4
                                        color: "#ffffff"
                                        text: qsTr("Значение 3")
                                        font.pointSize: 11
                                    }
                                }

                                RowLayout {
                                    id: rowLayout4
                                    width: 100
                                    height: 40

                                    CheckBox {
                                        id: checkBox2
                                        width: 80
                                        text: qsTr("")
                                        tristate: false
                                        scale: 0.842
                                        display: AbstractButton.IconOnly
                                        clip: false
                                        checkState: Qt.Unchecked
                                    }
                                    Label {
                                        id: label3
                                        color: "#ffffff"
                                        text: qsTr("Значение 4")
                                        font.pointSize: 11
                                    }
                                }

                                RowLayout {
                                    id: rowLayout6
                                    width: 100
                                    height: 40
                                    spacing: 26

                                    Label {
                                        id: label5
                                        width: 100
                                        height: 21
                                        color: "#ffffff"
                                        text: qsTr("Значение 5")
                                        font.pointSize: 11
                                    }

                                    Slider {
                                        id: slider
                                        width: 223
                                        value: 0.5
                                    }

                                    Label {
                                        id: label6
                                        width: 100
                                        height: 21
                                        color: "#ffffff"
                                        text: qsTr("50")
                                        font.pointSize: 11
                                    }
                                }
                            }

                            Column {
                                id: column1
                                width: 200
                                height: 400

                                RowLayout {
                                    id: rowLayout60
                                    width: 100
                                    height: 40
                                    spacing: 26

                                    Label {
                                        id: label50
                                        width: 100
                                        height: 21
                                        color: "#ffffff"
                                        text: joyxr
                                        font.pointSize: 11
                                    }

                                    Slider {
                                        id: slider0
                                        width: 223
                                        value: 0.5
                                    }

                                    Label {
                                        id: label60
                                        width: 100
                                        height: 21
                                        color: "#ffffff"
                                        text: slider0.value
                                        font.pointSize: 11
                                    }
                                }
                            }

                            Column {
                                id: column2
                                width: 200
                                height: 400
                            }

                            Column {
                                id: column3
                                width: 200
                                height: 400
                            }

                            Column {
                                id: column4
                                width: 200
                                height: 400
                            }
                        }
                    }
                }
            }
        }

        Row {
            id: row
            width: 200
            height: 400
            layer.format: ShaderEffectSource.RGB
            topPadding: 0
            rightPadding: 0
            spacing: 11
            padding: 0
            antialiasing: true
            clip: false
            layoutDirection: Qt.RightToLeft
            Layout.preferredHeight: 50
            Layout.fillWidth: true

            Button {
                id: button4
                text: qsTr("Отмена")
                font.strikeout: false
                font.underline: false
                font.bold: false
                font.pointSize: 10
                onClicked: settWind.close()

            }
            Button {
                id: button3
                text: qsTr("ОК")
                font.strikeout: false
                font.underline: false
                font.bold: false
                font.pointSize: 10
                onClicked: {
                    GUI.updateSett();

                }

            }
        }
    }
    states: [
        State {
            name: "clicked"
        }
    ]
}
}
