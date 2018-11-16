import QtQuick 2.0
import QtQuick.Window 2.0

Window {

    visible: true
    title: "Chronos"
    
    width: 800
    height: 600

    Column {

        Row {

            Text { text: "User:" }

            Rectangle {

                border.color: "black"
                width: 100
                height: 30 

                TextInput {
                    anchors.fill: parent
                }
            }
        }

        Row {

            Text { text: "Password:" }

            Rectangle {

                border.color: "black"
                width: 100
                height: 30 

                TextInput {
                    anchors.fill: parent
                }
            }
        }

        Row {

            Text { text: "IP:" }

            Rectangle {

                border.color: "black"
                width: 100
                height: 30 

                TextInput {
                    anchors.fill: parent
                }
            }
        }

        Row {

            Text { text: "Database:" }

            Rectangle {

                border.color: "black"
                width: 100
                height: 30 

                TextInput {
                    anchors.fill: parent
                }
            }
        }
   
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}
