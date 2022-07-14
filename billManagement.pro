QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addinvoicewindow.cpp \
    addnewproductwindow.cpp \
    app.cpp \
    chooseinvoicewindow.cpp \
    chooseproductwindow.cpp \
    deleteproductdbwindow.cpp \
    deleteproductwindow.cpp \
    editexstingproductwindow.cpp \
    editinvoicewindow.cpp \
    editproductwindow.cpp \
    filterwindow.cpp \
    incoming_domestic.cpp \
    incoming_foreign.cpp \
    invoice.cpp \
    invoicedatabasewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    outcoming_domestic.cpp \
    outcoming_foreign.cpp \
    product.cpp \
    productdatabasewindow.cpp

HEADERS += \
    addinvoicewindow.h \
    addnewproductwindow.h \
    app.h \
    chooseinvoicewindow.h \
    chooseproductwindow.h \
    deleteproductdbwindow.h \
    deleteproductwindow.h \
    editexstingproductwindow.h \
    editinvoicewindow.h \
    editproductwindow.h \
    filterwindow.h \
    incoming_domestic.h \
    incoming_foreign.h \
    invoice.h \
    invoicedatabasewindow.h \
    mainwindow.h \
    outcoming_domestic.h \
    outcoming_foreign.h \
    product.h \
    productdatabasewindow.h

FORMS += \
    addinvoicewindow.ui \
    addnewproductwindow.ui \
    chooseinvoicewindow.ui \
    chooseproductwindow.ui \
    deleteproductdbwindow.ui \
    deleteproductwindow.ui \
    editexstingproductwindow.ui \
    editinvoicewindow.ui \
    editproductwindow.ui \
    filterwindow.ui \
    invoicedatabasewindow.ui \
    mainwindow.ui \
    productdatabasewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.txt
