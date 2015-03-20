include(../../dateformater.pri)

QT = core

TEMPLATE = app
TARGET = $$DATEFORMATER_LIB_NAME-example

INCLUDEPATH += \
    $$DATEFORMATER_LIB_DIR/source

LIBS += \
    -L$$DATEFORMATER_LIB_DIR -l$$DATEFORMATER_LIB_NAME

SOURCES = \
    main.cpp
