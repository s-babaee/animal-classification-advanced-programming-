QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add.cpp \
    addobj.cpp \
    amphibian.cpp \
    bird.cpp \
    delete.cpp \
    edit.cpp \
    fish.cpp \
    main.cpp \
    mainwindow.cpp \
    mammal.cpp \
    reptile.cpp \
    show.cpp \
    special.cpp \
    window2.cpp

HEADERS += \
    add.h \
    addobj.h \
    amphibian.h \
    bird.h \
    delete.h \
    edit.h \
    fish.h \
    mainwindow.h \
    mammal.h \
    reptile.h \
    show.h \
    special.h \
    window2.h

FORMS += \
    add.ui \
    addobj.ui \
    amphibian.ui \
    bird.ui \
    delete.ui \
    edit.ui \
    fish.ui \
    mainwindow.ui \
    mammal.ui \
    reptile.ui \
    show.ui \
    special.ui \
    window2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
