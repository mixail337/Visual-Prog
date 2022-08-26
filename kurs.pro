QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add.cpp \
    daily.cpp \
    favorite.cpp \
    main.cpp \
    mainwindow.cpp \
    search.cpp \
    sql.cpp

HEADERS += \
    add.h \
    daily.h \
    favorite.h \
    mainwindow.h \
    search.h \
    sql.h

FORMS += \
    add.ui \
    daily.ui \
    favorite.ui \
    mainwindow.ui \
    search.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
