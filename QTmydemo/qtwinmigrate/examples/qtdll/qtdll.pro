TEMPLATE     = lib
CONFIG	    += dll
SOURCES	     = main.cpp \
    ../../../test6-3muti - single-simple/muti_window/formdoc.cpp \
    ../../../test6-3muti - single-simple/muti_window/formdoc.cpp \
    helpWindowSub.cpp \
    qtHelpwindow/formdoc.cpp

TARGET	     = qtdialog
DLLDESTDIR   = $$[QT_INSTALL_PREFIX]/bin

include(../../src/qtwinmigrate.pri)

HEADERS += \
    helpWindowSub.h \
    qtHelpwindow/formdoc.h
