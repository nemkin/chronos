import QtQuick 2.7
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item {

    id: root
    signal success()

    Rectangle {

        id: left_side

        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        width: parent.width/2

        Text {

            id: left_side_text

            text: "CHRONOS"
            font.pixelSize: 40
            
            anchors.centerIn: parent
        }
    }

    Rectangle {

        id: middle
       
        property real margin_size: 0.1
 
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: left_side.right

        anchors.topMargin: parent.height * margin_size
        anchors.bottomMargin: parent.height * margin_size

        border.color: "grey"
        color: "grey"

        width: 2
    }

    Item {

        id: right_side

        anchors.left: middle.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: parent.width/2 - middle.width

        Text {

            id: status_message

            width: 290

            wrapMode: Text.Wrap

            anchors.bottom: column.top
            anchors.bottomMargin: 10

            anchors.horizontalCenter: column.horizontalCenter

            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignBottom
        }

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
                        text: "nemkin"

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
                        text: "nemkin"

                        anchors.fill: parent
                        padding: 5
                        echoMode: TextInput.Password

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
                        text: "10.240.2.125"

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
                        text: "chronos"

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

            Rectangle {

                color: "grey"

                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom

                width: button.width

                Button {
                    
                    id:button

                    text: "Connect"
                    onClicked: {

                        if (LoginViewModel.ok_pressed(user.text, password.text, ip.text, database.text)) {

                            status_message.text = "Successful connection!"
                            status_message.color = "green"
                            login_animation.running = true

                        } else {

                            status_message.text = LoginViewModel.last_error();                            
                            status_message.color = "red"
                        }
                    }

                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom

                }
            }
        }
    }

    SequentialAnimation {
           
        id: login_animation
        running: false
        onStopped: root.success() 

        property real speed: 0.8

        ParallelAnimation {
 
            NumberAnimation {
                
                target: middle
                property: "opacity"
                to: 0.5
                duration: 700*login_animation.speed + 100
            } 

            NumberAnimation {
                
                target: middle
                property: "margin_size"
                to: 0.03
                duration: 700*login_animation.speed + 100
            }
        }

        ParallelAnimation {
           
            NumberAnimation {

                target: right_side
                property: "opacity"
                to: 0.0
                duration: 300*login_animation.speed
            } 

            NumberAnimation {
                
                target: middle
                property: "opacity"
                to: 0.0
                duration: 300*login_animation.speed
            } 
  
            NumberAnimation {
                
                target: middle
                property: "margin_size"
                to: 0.0
                duration: 500*login_animation.speed
            }

            NumberAnimation {
                
                target: left_side
                property: "width"
                to: parent.width
                duration: 1500
            } 

        }

        PauseAnimation {

            duration: 250
        }

        ColorAnimation {

            target: left_side_text
            property: "color"
            to: "grey"
            duration: 500
        }

        ColorAnimation {

            target: left_side_text
            property: "color"
            to: "black"
            duration: 600
        }

        PauseAnimation {

            duration: 700
        }

    }
}

