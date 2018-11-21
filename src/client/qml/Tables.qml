import QtQuick 2.7
import QtQuick.Controls 2.0

Item {

    Rectangle {

        anchors.top: parent.top
        anchors.bottom: parent.bottom

        width: 200

        color: "grey"

        Column {

            id: column

            anchors.fill: parent

            Button {
                
                anchors.left: parent.left
                anchors.right: parent.right

                height: 30
                text: "Awesomeness ++"

                background: Rectangle {

                    color: parent.down ? "#d0d0d0" : "#e0e0e0"
                    border.color: "white"
                }
            }
        }
       
        ClassView {

            id: class_view

            anchors.left: column.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right

            boundsBehavior: Flickable.StopAtBounds

            ScrollBar.vertical: ScrollBar {}
        }
    }
}

