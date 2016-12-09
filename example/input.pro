#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T10:31:29
#
#-------------------------------------------------

QT       += core gui network sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET              = InputTool
TEMPLATE            = app
MOC_DIR             = temp/moc
RCC_DIR             = temp/rcc
UI_DIR              = temp/ui
OBJECTS_DIR         = temp/obj
DESTDIR             = bin
win32:RC_FILE       = main.rc
PRECOMPILED_HEADER  = myhelper.h

include($$PWD/../src/input/input.pri)
include($$PWD/../src/inputnew/inputnew.pri)
include($$PWD/../src/inputnum/inputnum.pri)
include($$PWD/../src/inputuser/inputuser.pri)

SOURCES += main.cpp\
        frminputtool.cpp

HEADERS  += myhelper.h \
        frminputtool.h

FORMS    += frminputtool.ui

RESOURCES += \
    main.qrc

CONFIG += qt warn_off release

#execute once to copy the database file to the OUT_PWD floder
win32 {
    src_file = $$PWD\\py.db
    dst_file = $$OUT_PWD\\bin\\py.db
    src_file ~= s,/,\\,g
    dst_file ~= s,/,\\,g
    system(copy /y $$src_file $$dst_file)
}

unix {
    src_file = $$PWD/py.db
    dst_file = $$OUT_PWD/bin/py.db
    system(cp -r -f $$src_file $$dst_file)
}

DISTFILES += \
    ../readme.txt
