/* Faire clignoter et crier un fantôme */
#include "SimpleBLE.h"

#define SON 21
#define DEL 22

SimpleBLE ble;

int broches[2] = {SON, DEL};
int delai[2] = {0, 0};
long unsigned int chrono[2] = {0, 0};

 void setup() {
  Serial.begin(115200);
  ble.begin("Fantome");

  // Utilisons le contrôleur de diodes intégré
  ledcSetup(0, 5000, 8);
  ledcSetup(1, 5000, 8);
  ledcAttachPin(SON, 0);
  ledcAttachPin(DEL, 1);
  pinMode(0, INPUT);
  
  randomSeed(analogRead(0));
 }

void loop() {
  for (int i=0; i < 2; i++) {
    if (millis() - chrono[i] > delai[i]) {
      ledcWrite(0, random(0, 255));
      ledcWrite(0, random(0, 255));
      delai[i] = random(100, 3000);
      chrono[i] = millis();
    }
  }
}
