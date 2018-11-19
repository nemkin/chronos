import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Window 2.0

Window {

    id: window

    visible: true
    title: "Chronos"

    width: 800
    height: 600

    Loader {

        id: loader
    
        sourceComponent: login

        anchors.fill: parent
    }

    
    Component {

        id: tables

        Tables {

            anchors.fill: parent
        }
    }

    Component {

        id: login

        Login {
            
            anchors.fill: parent
    
            onSuccess: {
                
                window.width = Screen.desktopAvailableWidth;
                window.height = Screen.desktopAvailableHeight;
                
                window.x = 0;
                window.y = 0;

                loader.sourceComponent = tables
            } 
        }
    }

    Component.onCompleted: {

        x = Screen.width / 2 - width / 2;
        y = Screen.height / 2 - height / 2;
    }
    
}
