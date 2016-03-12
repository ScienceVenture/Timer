/**
 * This code is intended to be used for a workshop for students in 
 * grades 5 - 9. To faciliate learning it has been made as simple as 
 * possible. 
 */

int DIGIT_OFF = HIGH;
int DIGIT_ON = LOW;

int SEG_ON = HIGH;
int SEG_OFF = LOW;

int BUTTON_DOWN = LOW; 
int BUTTON_UP = HIGH; 

int DIGIT_DELAY = 5; 
int NUMBER_DELAY = 1000;  

int D1 = 0;
int D2 = 1;
int D3 = 2;
int D4 = 3; 

int SEG_A = 4;
int SEG_B = 5;
int SEG_C = 6;
int SEG_D = 7; 
int SEG_E = 8; 
int SEG_F = 9; 
int SEG_G = 10; 
int SEG_DP = 11; 

int BUTTON = 12;

int BUZZER = 13; 

/**
 * Shows a number n on digit d. 
 * 
 * The number n must be between 0 and 9.
 * The digit d must be between 1 and 4. 
 */
void show_digit(int n, int d){

  // first reset all digits
  digitalWrite(D1, DIGIT_OFF);
  digitalWrite(D2, DIGIT_OFF);
  digitalWrite(D3, DIGIT_OFF);
  digitalWrite(D4, DIGIT_OFF);

  if(d == D1){
    
    //Turn ON digit 1
    digitalWrite(D1, DIGIT_ON);
    
  }else if(d == D2){

    // Turn ON digit 2
    digitalWrite(D2, DIGIT_ON);

  }else if(d == D3){

    // Turn ON digit 3
    digitalWrite(D3, DIGIT_ON);
    
  }else if(d == D4){

    // Turn ON digit 4
    digitalWrite(D4, DIGIT_ON);
    
  }

  // Turn OFF all segements
  digitalWrite(SEG_A, SEG_OFF);
  digitalWrite(SEG_B, SEG_OFF);
  digitalWrite(SEG_C, SEG_OFF);
  digitalWrite(SEG_D, SEG_OFF);
  digitalWrite(SEG_E, SEG_OFF);
  digitalWrite(SEG_F, SEG_OFF);
  digitalWrite(SEG_G, SEG_OFF);
  digitalWrite(SEG_DP, SEG_OFF);

  if(n == 0){

    // Turn on segments: A, B, C, D, E, F to make digit 0
    digitalWrite(SEG_A, SEG_ON);
    digitalWrite(SEG_B, SEG_ON);
    digitalWrite(SEG_C, SEG_ON);
    digitalWrite(SEG_D, SEG_ON);
    digitalWrite(SEG_E, SEG_ON);
    digitalWrite(SEG_F, SEG_ON);

  }else if(n == 1){

    // Turn on segments: B, C to make digit 1
    digitalWrite(SEG_B, SEG_ON);
    digitalWrite(SEG_C, SEG_ON);

  }else if(n == 2){

    // Turn on segments: A, B, G, D, E to make digit 2
    digitalWrite(SEG_A, SEG_ON);
    digitalWrite(SEG_B, SEG_ON);
    digitalWrite(SEG_G, SEG_ON);
    digitalWrite(SEG_E, SEG_ON);
    digitalWrite(SEG_D, SEG_ON);

  }else if(n == 3){

    // Turn on segments: A, B, G, D, C to make digit 3
    digitalWrite(SEG_A, SEG_ON);
    digitalWrite(SEG_B, SEG_ON);
    digitalWrite(SEG_G, SEG_ON);
    digitalWrite(SEG_C, SEG_ON);
    digitalWrite(SEG_D, SEG_ON);

  }else if(n == 4){

    // Turn on segments: F, G, B, C to make digit 4
    digitalWrite(SEG_F, SEG_ON);
    digitalWrite(SEG_G, SEG_ON);
    digitalWrite(SEG_B, SEG_ON);
    digitalWrite(SEG_C, SEG_ON);
  }else if(n == 5){

    // Turn on segments: A, F, G, C, D to make digit 5
    digitalWrite(SEG_A, SEG_ON);
    digitalWrite(SEG_F, SEG_ON);
    digitalWrite(SEG_G, SEG_ON);
    digitalWrite(SEG_C, SEG_ON);
    digitalWrite(SEG_D, SEG_ON);

  }else if(n == 6){

    // Turn on segments: A, C, D, E, F, G to make digit 6
    digitalWrite(SEG_A, SEG_ON);
    digitalWrite(SEG_C, SEG_ON);
    digitalWrite(SEG_D, SEG_ON);
    digitalWrite(SEG_E, SEG_ON);
    digitalWrite(SEG_F, SEG_ON);
    digitalWrite(SEG_G, SEG_ON);

  }else if(n == 7){

    // Turn on segments: A, B, C to make digit 7
    digitalWrite(SEG_A, SEG_ON);
    digitalWrite(SEG_B, SEG_ON);
    digitalWrite(SEG_C, SEG_ON);

  }else if(n == 8){

    // Turn on segments: A, B, C, D, E, F, G to make digit 8
    digitalWrite(SEG_A, SEG_ON);
    digitalWrite(SEG_B, SEG_ON);
    digitalWrite(SEG_C, SEG_ON);
    digitalWrite(SEG_D, SEG_ON);
    digitalWrite(SEG_E, SEG_ON);
    digitalWrite(SEG_F, SEG_ON);
    digitalWrite(SEG_G, SEG_ON);

  }else if(n == 9){

    // Turn on segments: A, B, C, D, F, G to make digit 9
    digitalWrite(SEG_A, SEG_ON);
    digitalWrite(SEG_B, SEG_ON);
    digitalWrite(SEG_C, SEG_ON);
    digitalWrite(SEG_D, SEG_ON);
    digitalWrite(SEG_F, SEG_ON);
    digitalWrite(SEG_G, SEG_ON);

  }
  
}

/**
 * shows a number on the display once for 100 ms
 *
 * the number n must be between 0 and 9999
 */ 
void show_number(int n){
    
    int x = 0; 

    int tmp = n; 

    int loop_reps = NUMBER_DELAY/(4 * DIGIT_DELAY); 

    while(x < loop_reps){

        tmp = n; 

        show_digit(tmp % 10, D1); 
        tmp = tmp / 10; 

        delay(DIGIT_DELAY);

        show_digit(tmp % 10, D2); 
        tmp = tmp / 10; 

        delay(DIGIT_DELAY);

        show_digit(tmp % 10, D3); 
        tmp = tmp / 10; 

        delay(DIGIT_DELAY);

        show_digit(tmp % 10, D4); 

        delay(DIGIT_DELAY);

        x++; 

        // This entire loop takes ~ 4 * DIGITAL_DELAY ms
    }

    // This entire function takes ~ NUMBER_DELAY * 4 * DIGIT_DELAY ms

}

/**
 * Makes sounds with the buzzer, plays through several 
 * tones for every. 
 */
void do_buzzer(){

    int i, j; 

    while(1){

        for(i = 1200; i > 800; i = i-50){

            for(j = 0; j < 100; j++){

                digitalWrite(BUZZER, HIGH);

                delayMicroseconds(i);

                digitalWrite(BUZZER, LOW);

                delayMicroseconds(i);

            }

        }

    }

}

void setup() {

  // Control digits
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  // Segments of digits
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_DP, OUTPUT);

  // Button
  pinMode(BUTTON, INPUT_PULLUP); 

  // Buzzer
  pinMode(BUZZER, OUTPUT);

}

void loop() {

    digitalWrite(13, LOW); 
    int current = 10; 

    int button = BUTTON_UP;  
    
    while(current > 0){

        button = digitalRead(BUTTON); 

        if(button == BUTTON_DOWN){

            NUMBER_DELAY = 200; 
            current = current + 1; 

        }else{

            NUMBER_DELAY = 500; 
            current = current - 1; 

        }

        show_number(current); 

    }

    do_buzzer(); 

}
