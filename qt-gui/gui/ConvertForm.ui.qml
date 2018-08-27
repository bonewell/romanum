import QtQuick 2.4
import QtQuick.Controls 2.2
import number.roman 1.0

Item {
    id: item1
    width: 400
    height: 400
    property alias exit: exit
    property alias roman: roman_value
    property alias arabic: arabic_value

    Grid {
        id: grid
        anchors.bottom: exit.top
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottomMargin: 10
        rows: 3
        columns: 2

        Text {
            id: roman_label
            text: qsTr("Roman number:")
            font.pixelSize: 28
        }

        TextInput {
            id: roman_value
            width: 150
            font.pixelSize: 28
            validator: RomanValidator {
            }
        }

        Text {
            id: arabic_label
            text: qsTr("Arabic number:")
            font.pixelSize: 28
        }

        Text {
            id: arabic_value
            font.pixelSize: 28
        }
    }

    Button {
        id: exit
        x: 91
        y: 20
        text: qsTr("Exit")
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
    }
}
