#ifndef DATABAEMANAGER_H
#define DATABAEMANAGER_H

#include <QString>
#include "AlbumDao.h"

class QSqlDatabase;
class QSqlQuery;

const QString DATABASE_FILENAME = "gallery.db";

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    ~DatabaseManager();
    static void debugQuery(const QSqlQuery& query);

protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    QSqlDatabase *mDatabase;

public:
    const AlbumDao albumDao;
};

#endif // DATABAEMANAGER_H
