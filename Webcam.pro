#-------------------------------------------------
#
# Project created by QtCreator 2015-08-25T10:16:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Webcam
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui \
-lopencv_shape \
-lopencv_stitching \
-lopencv_objdetect \
-lopencv_superres \
-lopencv_videostab \
-lopencv_calib3d \
-lopencv_features2d \
-lopencv_videoio \
-lopencv_video \
-lopencv_photo \
-lopencv_ml \
-lopencv_imgproc \
-lopencv_flann \
-lopencv_hal \

