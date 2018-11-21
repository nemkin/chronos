#include "tables.h"

#include "model/manual/database_service.h"

using namespace chronos;

Tables::Tables(
    QQmlContext *p_root_context,
    QObject *parent
) :
    QObject(parent),
    _root_context(p_root_context) {

}

void Tables::logged_in() {

    _class_view_model = std::make_unique<ClassViewModel>();

    _root_context -> setContextProperty("class_view_model", _class_view_model.get());
}
