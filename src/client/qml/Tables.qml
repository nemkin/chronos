import QtQuick 2.7
import QtQuick.Controls 2.0

Item {

    Rectangle {

        id: rectangle

        anchors.top: parent.top
        anchors.bottom: parent.bottom

        width: 200

        color: "white"

        Column {

            id: column

            anchors.fill: parent

            Button {
                
                anchors.left: parent.left
                anchors.right: parent.right

                height: 30
                text: "Timeslots"

                background: Rectangle {

                    color: parent.down ? "#d0d0d0" : "#e0e0e0"
                    border.color: "white"
                }
            }

            Button {
                
                anchors.left: parent.left
                anchors.right: parent.right

                height: 30
                text: "Locations"

                background: Rectangle {

                    color: parent.down ? "#d0d0d0" : "#e0e0e0"
                    border.color: "white"
                }
            }

            Button {
                
                anchors.left: parent.left
                anchors.right: parent.right

                height: 30
                text: "Class Types"

                background: Rectangle {

                    color: parent.down ? "#d0d0d0" : "#e0e0e0"
                    border.color: "white"
                }
            }

            Button {
                
                anchors.left: parent.left
                anchors.right: parent.right

                height: 30
                text: "Years"

                background: Rectangle {

                    color: parent.down ? "#d0d0d0" : "#e0e0e0"
                    border.color: "white"
                }
            }

            Button {
                
                anchors.left: parent.left
                anchors.right: parent.right

                height: 30
                text: "Rooms"

                background: Rectangle {

                    color: parent.down ? "#d0d0d0" : "#e0e0e0"
                    border.color: "white"
                }
            }

            Button {
                
                anchors.left: parent.left
                anchors.right: parent.right

                height: 30
                text: "Departments"

                background: Rectangle {

                    color: parent.down ? "#d0d0d0" : "#e0e0e0"
                    border.color: "white"
                }
            }

            Button {
                
                anchors.left: parent.left
                anchors.right: parent.right

                height: 30
                text: "Courses"

                background: Rectangle {

                    color: parent.down ? "#d0d0d0" : "#e0e0e0"
                    border.color: "white"
                }
            }

            Button {
                
                anchors.left: parent.left
                anchors.right: parent.right

                height: 30
                text: "Classes"

                background: Rectangle {

                    color: parent.down ? "#d0d0d0" : "#e0e0e0"
                    border.color: "white"
                }
            }

            Button {
                
                anchors.left: parent.left
                anchors.right: parent.right

                height: 30
                text: "Faculty Members"

                background: Rectangle {

                    color: parent.down ? "#d0d0d0" : "#e0e0e0"
                    border.color: "white"
                }
            }

            Button {
                
                anchors.left: parent.left
                anchors.right: parent.right

                height: 30
                text: "Licenses"

                background: Rectangle {

                    color: parent.down ? "#d0d0d0" : "#e0e0e0"
                    border.color: "white"
                }
            }

        }

     }
    
     Rectangle {
        id: separator
        width: 4
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: rectangle.right
        color: "#222222"
    }

    Rectangle {

        id: top_buttons
        anchors.left: separator.right
        anchors.top: parent.top
        anchors.right: parent.right
        
        height: 30

        color: "white"
        
        Row {
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            Text {
                text: "Classes"
                verticalAlignment: Text.AlignVCenter
                anchors.top: parent.top
                anchors.bottom: parent.bottom
            }
        }

        Row {

            anchors.right: parent.right 
            anchors.top: parent.top
            anchors.bottom: parent.bottom

            Button {
                text: "Add"
                width: 100
                anchors.top: parent.top
                anchors.bottom: parent.bottom
            }

        }
    }
 
     Rectangle {
 
        anchors.left: separator.right
        anchors.top: top_buttons.bottom
        anchors.bottom: parent.bottom
        anchors.right: parent.right
       
        color: "#555555"
 
        ClassView {

            id: class_view

            anchors.fill: parent         

            
        }
    }
}

