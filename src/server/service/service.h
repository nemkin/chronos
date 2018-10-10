#pragma once

#ifndef __SERVICE__H__
#define __SERVICE__H__

#include <QByteArray>

namespace chronos {

class Service {

public:

    Service();

    QByteArray reply_to(QByteArray message);

private:
 

};

}

#endif //__SERVICE__H__

