QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    qstd.cpp \
    alien.cpp \
    evolutionnary_process.cpp \
    gene_schtroumpf.cpp \
    gene_tentacles.cpp \
    main.cpp \
    mainwindow.cpp \
    parameters.cpp

HEADERS += \
    qstd.h \
    alien.h \
    evolutionnary_process.h \
    gene_schtroumpf.h \
    gene_tentacles.h \
    mainwindow.h \
    parameters.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    mutations_aliens_fr_FR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
