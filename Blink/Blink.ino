const int LIGHT_PIN = 16;
const int BUTTON_PIN = 0;

int previousState = 0;
int lightMode = 1;
int buttonState = 0;

// pulse specific variables
int maxDelay = 25;
int currentDelay = 15;
int direction = -1;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
    buttonState = digitalRead(BUTTON_PIN);
    
    if (previousState == HIGH && buttonState == LOW) {
      lightMode++;
      if(lightMode >= 7){ 
        lightMode = 0;
      }
    }
    
  previousState = buttonState;


  switch(lightMode){
    case 0: // off
      digitalWrite(LIGHT_PIN, LOW); 
      break;
    case 1: // on
      digitalWrite(LIGHT_PIN, HIGH);
      break;
    case 2: // pulse
      digitalWrite(LIGHT_PIN, HIGH); 
      delay(1);
      digitalWrite(LIGHT_PIN, LOW);
      delay(currentDelay);
      
      if(direction == -1 && currentDelay <= 0) {
        delay(200);
        direction = 1;
      } else if(direction == 1 && currentDelay >= maxDelay){
        delay(200);
        direction = -1;
      }
      currentDelay += direction;
      break;
    case 3: // blink faster
      digitalWrite(LIGHT_PIN, HIGH); 
      delay(500);
      digitalWrite(LIGHT_PIN, LOW);
      delay(500); 
      break;
    case 4: // blink faster
      digitalWrite(LIGHT_PIN, HIGH); 
      delay(250);
      digitalWrite(LIGHT_PIN, LOW);
      delay(250); 
      break;   
    case 5: // blink faster
      digitalWrite(LIGHT_PIN, HIGH); 
      delay(125);
      digitalWrite(LIGHT_PIN, LOW);
      delay(125); 
      break;   
   case 6: // blink faster
      digitalWrite(LIGHT_PIN, HIGH); 
      delay(50);
      digitalWrite(LIGHT_PIN, LOW);
      delay(50); 
      break;  
  }    
}
