#include <QSqlDatabase>
#include <QList>

#include "common/entities/department.h"

namespace chronos {

class Database {

public:

    Database();

    QList<Department> get_departments();

    void test();
    void init();
    void drop();

private:

    QSqlDatabase _db;
};

}
