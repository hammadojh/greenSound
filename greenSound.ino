#include <Adafruit_CircuitPlayground.h>

float value;
uint32_t color;
float base = 50;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  value = CircuitPlayground.mic.soundPressureLevel(10);
}

void loop() {

  // set base
  if (CircuitPlayground.leftButton() || CircuitPlayground.rightButton() ){
    base = CircuitPlayground.mic.soundPressureLevel(10);
  }
  
  // Take 10 milliseconds of sound data to calculate
  if (value-base < 10 ) {
    color = 0x00FF00;
    single();
  }else if (value-base < 20) {
    color = 0xFFFF00;
    single();
  }else if (value-base < 30) {
    color = 0xFF7700;
    single();
  }else if (value-base < 40){
    color = 0xFF0000;
    single();
  }else{
    multiple();
  }
  
  value = CircuitPlayground.mic.soundPressureLevel(10);
  delay(100);

}

void single(){

  for (int i = 0 ; i < 10 ; i++){
    CircuitPlayground.setPixelColor(i, color);
  }
  
}

void multiple(){

  for (int k = 0; k <= 10 ; k++){
    
    for (int i = 0 ; i < 10 ; i++){
      CircuitPlayground.setPixelColor(i, 0xFF0000);
    }

    delay(100);
    CircuitPlayground.clearPixels();
    
    for (int i = 0 ; i < 10 ; i++){
      CircuitPlayground.setPixelColor(i, 0x0000FF);
    }

    delay(100);
    CircuitPlayground.clearPixels();
    
  }
  
}
