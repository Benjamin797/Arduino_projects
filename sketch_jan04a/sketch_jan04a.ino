include <SPI.h>
#include <ACAN2515Settings.h> /* Pour les reglages  */
#include <ACAN2515.h>         /* Pour le controleur */
#include <CANMessage.h>       /* Pour les messages  */

static const uint8_t MCP2515_CS  = 10;//pin CS
static const uint8_t MCP2515_INT = 2;//pin INT

ACAN2515 controleurCAN(MCP2515_CS, SPI, MCP2515_INT);//nv objet

static const uint32_t FREQUENCE_DU_QUARTZ = 8ul * 1000ul * 1000ul;
static const uint32_t FREQUENCE_DU_BUS_CAN = 125ul * 1000ul;

CANMessage messageCANEmission;
CANMessage messageCANReception;

void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  Serial.begin(115200);
  ACAN2515Settings configuration(FREQUENCE_DU_QUARTZ, FREQUENCE_DU_BUS_CAN);
  configuration.mRequestedMode = ACAN2515Settings::LoopBackMode;
  const uint32_t codeErreur = controleurCAN.begin(configuration, [] { controleurCAN.isr(); });
        if (codeErreur != 0) {
        Serial.print("Erreur : 0x");
        Serial.println(codeErreur, HEX);
        while (1);
      }
      else {
        Serial.println("OK !");
      }
    }
}

void loop() {
  // put your main code here, to run repeatedly:
    if (controleurCAN.receive(messageCANReception)) {
    /* Message recu */
    Serial.println("recu !");
    
}
