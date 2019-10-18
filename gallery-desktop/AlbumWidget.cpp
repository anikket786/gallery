#include "AlbumWidget.h"
#include "ui_AlbumWidget.h"
#include "PictureModel.h"
#include "AlbumModel.h"
#include "ThumbnailProxyModel.h"

#include <QItemSelectionModel>

AlbumWidget::AlbumWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlbumWidget),
    mAlbumModel(nullptr),
    mAlbumSelectionModel(nullptr),
    mPictureModel(nullptr),
    mPictureSelectionModel(nullptr)
{
    ui->setupUi(this);
    clearUi();
    ui->thumbnailListView->setSpacing(5);
    ui->thumbnailListView->setResizeMode(QListView::Adjust);
    ui->thumbnailListView->setFlow(QListView::LeftToRight);
    ui->thumbnailListView->setWrapping(true);

    connect(ui->thumbnailListView, &QListView::doubleClicked, this, &AlbumWidget::pictureActivated);
    connect(ui->deleteButton, &QPushButton::clicked, this, &AlbumWidget::deleteAlbum);
    connect(ui->editButton, &QPushButton::clicked, this, &AlbumWidget::editAlbum);
    connect(ui->addPicturesButton, &QPushButton::clicked, this, &AlbumWidget::addPictures);
}

AlbumWidget::~AlbumWidget()
{
    delete ui;
}
