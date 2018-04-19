TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    accdb/file.cpp \
    accdb/utils.cpp \
    accdb/headerpage.cpp \
    accdb/page.cpp \
    accdb/tablepage.cpp \
    accdb/datapage.cpp

HEADERS += \
    accdb/file.h \
    accdb/utils.h \
    accdb/column.h \
    accdb/page.h \
    accdb/tablepage.h \
    accdb/tbldef.h \
    accdb/headerpage.h \
    accdb/datapage.h
