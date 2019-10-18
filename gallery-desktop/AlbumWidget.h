#ifndef ALBUMWIDGET_H
#define ALBUMWIDGET_H

#include <QWidget>
#include <QModelIndex>

class AlbumModel;
class PictureModel;
class QItemSelectionModel;
class ThumbnailProxyModel;

namespace Ui {
class AlbumWidget;
}

class AlbumWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlbumWidget(QWidget *parent = nullptr);
    ~AlbumWidget();

    void setAlbumModel(AlbumModel *albumModel);
    void setAlbumselectionmodel(QItemSelectionModel* albumSelectionModel);
    void setPictureModel(ThumbnailProxyModel *pictureModel);
    void setPictureSelectionModel(QItemSelectionModel *pictureSelectionModel);

signals:
    void pictureActivated(const QModelIndex &index);

private slots:
    void deleteAlbum();
    void editAlbum();
    void addPictures();

private:
    void clearUi();
    void loadAlbum(const QModelIndex &albumIndex);

private:
    Ui::AlbumWidget *ui;
    AlbumModel *mAlbumModel;
    QItemSelectionModel *mAlbumSelectionModel;
    ThumbnailProxyModel *mPictureModel;
    QItemSelectionModel *mPictureSelectionModel;
};

#endif // ALBUMWIDGET_H
