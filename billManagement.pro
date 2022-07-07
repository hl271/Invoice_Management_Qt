QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addinvoice.cpp \
    app.cpp \
    incoming_domestic.cpp \
    incoming_foreign.cpp \
    invoice.cpp \
    main.cpp \
    mainwindow.cpp \
    additem.cpp \
    filter.cpp \
    outcoming_domestic.cpp \
    outcoming_foreign.cpp \
    product.cpp \
    updateitem.cpp

HEADERS += \
    addinvoice.h \
    app.h \
    incoming_domestic.h \
    incoming_foreign.h \
    invoice.h \
    mainwindow.h \
    additem.h \
    filter.h \
    outcoming_domestic.h \
    outcoming_foreign.h \
    product.h \
    updateitem.h

FORMS += \
    addinvoice.ui \
    mainwindow.ui \
    additem.ui \
    filter.ui \
    updateitem.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
