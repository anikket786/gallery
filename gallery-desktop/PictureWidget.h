#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H

#include <QWidget>
#include <QItemSelectionModel>

namespace Ui {
class PictureWidget;
}

class PictureModel;
class QItemSelectionModel;
class ThumbnailProxyModel;

class PictureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PictureWidget(QWidget *parent = nullptr);
    ~PictureWidget() override;

    void setModel(ThumbnailProxyModel *model);
    void setselectionModel(QItemSelectionModel *selectionModel);

signals:
    void backToGallery();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void deletePicture();
    void loadPicture(const QItemSelection &selected);

private:
    void updatePicturePixmap();

private:
    Ui::PictureWidget *ui;
    ThumbnailProxyModel *mModel;
    QItemSelectionModel *mSelectionModel;
    QPixmap mPixmap;
};

#endif // PICTUREWIDGET_H
