#include <QApplication>

#include "database/database.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    chronos::Database db;

    db.test();

    return a.exec();
}
