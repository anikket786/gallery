#include "AlbumListwidget.h"
#include "ui_AlbumListWidget.h"
#include "AlbumModel.h"

#include <QInputDialog>

AlbumListWidget::AlbumListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlbumListWidget),
    mAlbumModel(nullptr)
{
    ui->setupUi(this);
    connect(ui->createAlbumButton, &QPushButton::clicked, this, &AlbumListWidget::createAlbum);
}

AlbumListWidget::~AlbumListWidget()
{
    delete ui;
}

void AlbumListWidget::setModel(AlbumModel *model){
    mAlbumModel = model;
    ui->albumList->setModel(mAlbumModel);
}

void AlbumListWidget::setSelectionModel(QItemSelectionModel *selectionModel){
    ui->albumList->setSelectionModel(selectionModel);
}

void AlbumListWidget::createAlbum(){
    if(!mAlbumModel){
        return;
    }
    bool ok;
    QString albumName = QInputDialog::getText(this,
                                              "Create a new Album",
                                              "Choose a name",
                                              QLineEdit::Normal,
                                              "New Album",
                                              &ok);
    if(ok && !albumName.isEmpty()){
        Album album(albumName);
        QModelIndex createdIndex = mAlbumModel->addAlbum(album);
        ui->albumList->setCurrentIndex(createdIndex);
    }
}




















