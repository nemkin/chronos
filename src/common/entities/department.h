#include <QObject>
#include <QString>

namespace chronos {

class Department {

public:
    
    Department(
        int p_id,
        QString p_name,
        int p_timestamp,
        bool p_is_deleted
    );

    QString name() const;
               

private:

    int _id;
    QString _name;
    int _timestamp;
    bool _is_deleted;
    
};

}
