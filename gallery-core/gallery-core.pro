#-------------------------------------------------
#
# Project created by QtCreator 2019-10-11T00:00:07
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = gallery-core
TEMPLATE = lib
CONFIG += lib c++11

DEFINES += GALLERYCORE_LIBRARY

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        Album.cpp \
        AlbumDao.cpp \
        AlbumModel.cpp \
        DatabaseManager.cpp \
        Picture.cpp \
        PictureDao.cpp \
        PictureModel.cpp

HEADERS += \
        Album.h \
        AlbumDao.h \
        AlbumModel.h \
        DatabaseManager.h \
        Picture.h \
        PictureDao.h \
        PictureModel.h \
        gallery-core_global.h 
