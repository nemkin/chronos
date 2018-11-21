import QtQuick 2.7
import QtQuick.Controls 2.0

ListView {

    model: class_view_model

    delegate: Row {

        Text {
       
            text: m_name 
            width: 200
            height: 30
        }
        Text {
       
            text: m_count 
            width: 200
            height: 30
        }

        Text {
       
            text: m_class_type 
            width: 200
            height: 30
        }

        Text {
       
            text: m_course 
            width: 200
            height: 30
        }

    }
}

