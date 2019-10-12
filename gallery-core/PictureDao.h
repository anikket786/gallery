#ifndef PICTUREDAO_H
#define PICTUREDAO_H

#include <memory>
#include <vector>

class QSqlDatabase;
class Picture;

class PictureDao
{
public:
    explicit PictureDao(QSqlDatabase& database);
    void init() const;

    void addPictureInAlbum(int albbumId, Picture& picture) const;
    void removePicture(int id) const;
    void removePictureForAlbum(int albumId) const;
    std::unique_ptr<std::vector<std::unique_ptr<Picture>>> picturesForAlbum(int albumId) const;

private:
    QSqlDatabase& mDatabase;
};

#endif // PICTUREDAO_H
