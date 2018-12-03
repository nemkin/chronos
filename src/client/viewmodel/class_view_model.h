#pragma once

#ifndef __CLASS_VIEWMODEL__H__
#define __CLASS_VIEWMODEL__H__

#include <map>
#include <vector>

#include <QAbstractListModel>

#include "model/generated/entities/class.h"

namespace chronos {

class ClassViewModel : public QAbstractListModel {

public:

    ClassViewModel();

    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &index) const override;

private:

    std::vector<Class> _classes;

};

}

#endif //__CLASS_VIEWMODEL__H__

