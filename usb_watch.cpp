// test_cxx.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include "libusb/UsbDevice.h"

int main(int argc, char* argv[]) {
    std::vector<libusb_class_code> validClassCodes;
    UsbDevice::open(NULL, NULL, validClassCodes);
    std::vector<UsbDevice> usbList = UsbDevice::getList(true);
    printf("======================================== USB Device List\n");
    for (size_t i = 0; i < usbList.size(); ++i) {
        UsbDevice usb = usbList[i];
        printf("[%d]\n", i + 1);
        printf("     address = %d, busNumber = %d, portNumber = %d\n", usb.address, usb.busNumber, usb.portNumber);
        printf("     classCode = %d, %s\n", usb.classCode, usb.className().c_str());
        printf("     vendorId = %04x, productId = %04x\n", usb.vendorId, usb.productId);
        printf("     manufacturer = %s, product = %s, serialNumber = %s\n", usb.manufacturer.c_str(), usb.product.c_str(), usb.serialNumber.c_str());
    }
    return 0;
}
