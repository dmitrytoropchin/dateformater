include(../dateformater.pri)

TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = library/dateformater-library.pro

equals(BUILD_EXAMPLE, "YES") {
    SUBDIRS += example/dateformater-example.pro
}
