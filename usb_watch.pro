TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += $$PWD/libusb/platform-win32/libusb-1.0.a

HEADERS += \
        libusb/libusb.h \
        libusb/UsbDevice.h

SOURCES += \
        libusb/UsbDevice.cpp \
        usb_watch.cpp
