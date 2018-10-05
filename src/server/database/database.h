#include <QSqlDatabase>

namespace chronos {

class Database {

public:

    Database();
    void test();

private:

    QSqlDatabase _db;
};

}
