import QtQuick 1.0

Rectangle {
    width: 360
    height: 360
    Text {
        anchors.centerIn: parent
        text: "Hello World"
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Column {
        id: column1
        x: -25
        y: 67
        width: 200
        height: 400
        opacity: 0
    }
    states: [
        State {
            name: "State1"

            PropertyChanges {
                target: column1
                opacity: 1
            }
        }
    ]
}
