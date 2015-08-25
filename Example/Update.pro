# Include the QSimpleUpdater files
include($$PWD/../QSimpleUpdater/QSimpleUpdater.pri)
TARGEt = Update

# Include the QtWidgets module
QT += widgets script

# Define the source code
FORMS += example.ui
HEADERS += example.h
SOURCES += example.cpp
