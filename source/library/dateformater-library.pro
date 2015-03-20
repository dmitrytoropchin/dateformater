include(../../dateformater.pri)

QT = core

TEMPLATE = lib
TARGET = $$DATEFORMATER_LIB_NAME

VERSION = $$DATEFORMATER_LIB_VERSION

CONFIG += DATEFORMATER_CONFIG

CODECFORSRC = UTF-8

DEFINES += DATEFORMATER_LIBRARY

INCLUDEPATH += \
    source

DATEFORMATER_PUBLIC_HEADERS = \
    source/dateformater/dateformater_common.h \
    source/dateformater/dateformaterbase.h \
    source/dateformater/dateformaterstandard.h \
    source/dateformater/dateformaterhumanreadable.h

DATEFORMATER_PRIVATE_HEADERS =

DATEFORMATER_SOURCES = \
    source/dateformater_common.cpp \
    source/dateformaterstandard.cpp \
    source/dateformaterhumanreadable.cpp

HEADERS += \
    $$DATEFORMATER_PUBLIC_HEADERS \
    $$DATEFORMATER_PRIVATE_HEADERS

SOURCES += \
    $$DATEFORMATER_SOURCES

RESOURCES = \
    resource/dateformater_resources.qrc

TRANSLATIONS = \
    resource/locale/dateformater_en.ts \
    resource/locale/dateformater_ru.ts

INSTALL_HEADERS = \
    $$CARDVIEW_PUBLIC_HEADERS

target.path = $$INSTALL_LIBS_DIR

header.files =  $$INSTALL_HEADERS
header.path = $$INSTALL_INCLUDES_DIR

INSTALLS = target header
