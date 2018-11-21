#include "class_view_model.h"

#include "model/manual/database_service.h"

using namespace chronos;

ClassViewModel::ClassViewModel() {

    _classes = DatabaseService::instance().get_classes();
    _class_types = DatabaseService::instance().get_class_types_map();
    _courses = DatabaseService::instance().get_courses_map();
}

QVariant ClassViewModel::data(const QModelIndex &index, int role) const {

    auto c = _classes[index.row()];
     
    switch(role) {
    
        case 0: return QString::fromStdString(c.name());
        case 1: return c.count();
        case 2: return QString::fromStdString(_class_types.at(c.class_type_id()).name());
        case 3: return QString::fromStdString(_courses.at(c.course_id()).name());
        default: return QVariant();
    } 
}

QHash<int, QByteArray> ClassViewModel::roleNames() const {

    QHash<int, QByteArray> ret;

    ret[0] = "m_name";
    ret[1] = "m_count";
    ret[2] = "m_class_type"; //id
    ret[3] = "m_course"; //id

    return ret;
}

int ClassViewModel::rowCount(const QModelIndex &) const {

    return _classes.size();
}

