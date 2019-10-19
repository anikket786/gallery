#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GalleryWidget;
class PictureWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void displayGallery();
    void displayPicture(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    GalleryWidget *mGalleryWidget;
    PictureWidget *mPictureWidget;
    QStackedWidget *mStackWidget;
};
#endif // MAINWINDOW_H
