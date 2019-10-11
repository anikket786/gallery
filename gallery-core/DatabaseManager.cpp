#include "DatabaseManager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

void DatabaseManager::debugQuery(const QSqlQuery& query){
    if(query.lastError().type() == QSqlError::ErrorType::NoError){
        qDebug() << "Query OK: " <<query.lastQuery();
    }
    else{
        qWarning() <<"Query KO: " <<query.lastError().text();
        qWarning() <<"Query text: " <<query.lastQuery();
    }
}

DatabaseManager& DatabaseManager::instance(){
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::DatabaseManager(const QString& path) : mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
                                                        albumDao(*mDatabase)
{
    mDatabase->setDatabaseName(path);
    mDatabase->open();

    albumDao.init();
}

DatabaseManager::~DatabaseManager(){
    mDatabase->close();
    delete mDatabase;
}

