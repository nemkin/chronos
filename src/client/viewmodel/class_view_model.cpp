#include "class_view_model.h"

#include "model/manual/database_service.h"

using namespace chronos;

ClassViewModel::ClassViewModel() {

    _classes = DatabaseService::instance().get_classes();
}

QVariant ClassViewModel::data(const QModelIndex &index, int role) const {

    auto c = _classes[index.row()];
     
    switch(role) {
    
        case 0: return QString::number(c.id());
        case 1: return QString::fromStdString(c.name());
        case 2: return QString::number(c.class_type_id());
        case 3: return QString::number(c.course_id());
        default: return QVariant();
    } 
}

QHash<int, QByteArray> ClassViewModel::roleNames() const {

    QHash<int, QByteArray> ret;

    ret[0] = "m_id";
    ret[1] = "m_name";
    ret[2] = "m_class_type_id";
    ret[3] = "m_course_id";

    return ret;
}

int ClassViewModel::rowCount(const QModelIndex &) const {

    return _classes.size();
}

