import QtQuick 2.11
import QtQuick.Controls 2.2

import number.roman 1.0

ApplicationWindow {
    id: appWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Romanum")

    ConvertForm {
        id: convertForm
        exit.onClicked: Qt.quit();
        roman.onTextChanged: {
            arabic.text = converter.convert(roman.text)
        }
    }

    RomanConverter {
        id: converter
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
