#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include <QAbstractListModel>

#include "gallery-core_global.h"

class GALLERYCORESHARED_EXPORT AlbumModel : public QAbstractListModel
{
public:
    AlbumModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
};

#endif // ALBUMMODEL_H
