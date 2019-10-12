#include "AlbumDao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QVariant>
#include <Album.h>
#include "Databasemanager.h"

typedef std::unique_ptr<std::vector<std::unique_ptr<Album>>> unique_ptr_vector;

AlbumDao::AlbumDao(QSqlDatabase& database) : mDatabase(database)
{

}

void AlbumDao::init() const{
    if(!mDatabase.tables().contains("albums")){
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE albums (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
    }
}

void AlbumDao::addAlbum(Album& album) const{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO albums (name) VALUES (:name)");
    query.bindValue(":name", album.name());
    query.exec();
    album.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
}

void AlbumDao::updateAlbum(const Album& album) const{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE albums name = (:name) WHERE id = (:id)");
    query.bindValue(":name", album.name());
    query.bindValue(":id", album.id());
    query.exec();
    DatabaseManager::debugQuery(query);
}

void AlbumDao::removeAlbum(int id) const{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM albums WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

unique_ptr_vector AlbumDao::albums() const{
    QSqlQuery query("SELECT * FROM albums", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr_vector list;
    while(query.next()){
        std::unique_ptr<Album> album;
        album->setId(query.value("id").toInt());
        album->setName(query.value("name").toString());
        list->push_back(std::move(album));
    }
    return list;
}


















