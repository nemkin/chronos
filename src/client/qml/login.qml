import QtQuick 2.7
import QtQuick.Window 2.0
import QtQuick.Controls 2.0

Window {

    visible: true
    title: "Chronos"

    width: 800
    height: 600

    Component.onCompleted: {

        x = Screen.width / 2 - width / 2;
        y = Screen.height / 2 - height / 2;
    }

    Item {

        id: left_side

        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        width: parent.width/2


        Text {

            text: "CHRONOS"
            font.pixelSize: 40
            
            anchors.centerIn: parent
        }
    }

    Rectangle {

        id: middle
        
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        anchors.horizontalCenter: parent.horizontalCenter

        anchors.topMargin: parent.height * 0.1
        anchors.bottomMargin: parent.height * 0.1

        border.color: "grey"

        width: 2
    }

    Item {

        id: right_side

        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        
        width: parent.width/2

        Column {

            id: column

            anchors.centerIn: parent
            spacing: 10

            Row {

                spacing: 20

                Text {

                    text: "User:"

                    width: 70
                    height: 30

                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                }

                Rectangle {

                    border.color: "grey"
                    width: 200
                    height: 30 

                    TextInput {

                        id: user
                        focus: true

                        anchors.fill: parent
                        padding: 5

                        verticalAlignment: TextInput.AlignVCenter
                        KeyNavigation.tab: password
                    }
                }
            }

            Row {

                spacing: 20

                Text { 

                    text: "Password:"

                    width: 70
                    height: 30

                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                }

                Rectangle {

                    border.color: "grey"
                    width: 200
                    height: 30 

                    TextInput {

                        id: password

                        anchors.fill: parent
                        padding: 5

                        verticalAlignment: TextInput.AlignVCenter
                        KeyNavigation.tab: ip
                    }
                }

            }

            Row {

                spacing: 20

                Text {
                
                    text: "IP:"

                    width: 70
                    height: 30

                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                }

                Rectangle {

                    border.color: "grey"
                    width: 200
                    height: 30 

                    TextInput {

                        id: ip

                        anchors.fill: parent
                        padding: 5

                        verticalAlignment: TextInput.AlignVCenter
                        KeyNavigation.tab: database
                    }
                }

            }

            Row {

                spacing: 20

                Text { 
                    
                    text: "Database:"

                    width: 70
                    height: 30

                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                }

                Rectangle {

                    border.color: "grey"
                    width: 200
                    height: 30 

                    TextInput {

                        id: database

                        anchors.fill: parent
                        padding: 5

                        verticalAlignment: TextInput.AlignVCenter
                        KeyNavigation.tab: user
                    }
                }
            }
        }

        Item {

            height: 30
            width: 290

            anchors.top: column.bottom
            anchors.topMargin: 40

            anchors.right: column.right

            Button {

                text: "Connect"
                onClicked: LoginViewModel.ok_pressed(user.text, password.text, ip.text, database.text);

                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom

            }
        }
       
    }
}
