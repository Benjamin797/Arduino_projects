
#include <dht11.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <SPI.h>
//sda = A4
//scl= A5

dht11 DHT;
#define DHT11_PIN 4//D4
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  
}

void loop() {
  // put your main code here, to run repeatedly:
  display.clearDisplay();
  display.setTextSize(0);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  DHT.read(DHT11_PIN);
  
  display.print("Humidite: ");
  display.print(DHT.humidity,1);
  display.println(" %");
  
  display.print("Temperature: ");
  display.print(DHT.temperature,1);
  display.println(" C");
  
  
 // display.clearDisplay();
  display.display();
  delay(1000);

}
