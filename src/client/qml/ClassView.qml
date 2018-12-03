import QtQuick 2.7
import QtQuick.Controls 2.0

Item {

    ListView {
    
        model: class_view_model

        anchors.top: header.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    
        spacing: 2
        clip: true

        ScrollBar.vertical: ScrollBar {
                    
            width: 20
        }

        delegate: Rectangle {
    
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.rightMargin: 20
    
            color: "white"
    
            height: 30
    
            Row {
    
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.leftMargin: 10
    
                TextInput {
               
                    text: m_id 
                    width: 30
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    verticalAlignment: TextInput.AlignVCenter
                }
    
                TextInput {
               
                    text: m_name 
                    width: 500
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    verticalAlignment: TextInput.AlignVCenter
                }
    
                TextInput {
          
                    text: m_class_type_id 
                    width: 100
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    verticalAlignment: TextInput.AlignVCenter
                }
    
                TextInput {
          
                    text: m_course_id 
                    width: 100
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    verticalAlignment: TextInput.AlignVCenter
                }
           }
       }
    }

    Rectangle {

        id: header 
        anchors.left: parent.left
        anchors.right: parent.right

        color: "grey"

        height: 30

        Row {

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.leftMargin: 10

            Text {
           
                text: "id"
                width: 30
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
            }

            Text {
           
                text: "name"
                width: 500
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
            }

            Text {
      
                text: "class_type_id"
                width: 100
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
            }

            Text {
      
                text: "course_id"
                width: 100
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                verticalAlignment: Text.AlignVCenter
            }
       }
   }


}
