// use `USB Host Shield Library 2.0` lib by Oleg Mazurov / Kristian Sloth Lauszus
#include <hidboot.h>
#include <usbhub.h>
#include <SPI.h>

USB Usb;
HIDBoot<USB_HID_PROTOCOL_KEYBOARD> HidKeyboard(&Usb);

class KbdRptParser : public KeyboardReportParser {
  protected:
    void OnKeyPressed(uint8_t key) {
      Serial.print("Key: ");
      Serial.println((char)key);
    }
};

KbdRptParser Prs;

void setup() {
  Serial.begin(9600);
  Serial.println("USB Host Shield Ready — plug in a USB keyboard");

  if (Usb.Init() == -1) {
    Serial.println("USB Host init failed");
    while (1);
  }

  HidKeyboard.SetReportParser(0, &Prs);
}

void loop() {
  Usb.Task();
}
