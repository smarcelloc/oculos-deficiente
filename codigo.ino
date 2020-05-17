#define ECHO 12
#define TRIG 11
#define ECHO_LEFT 10
#define TRIG_LEFT 9
#define SOUND 13

#define DELAY 150

float pulse, dist, pulse_left, dist_left, short_dist;

void trigPulse(int _trigs){
  digitalWrite(_trigs,HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigs,LOW);
}

void setup() { 
  pinMode(ECHO,INPUT);
  pinMode(TRIG,OUTPUT);
  digitalWrite(TRIG,LOW);
  pinMode(ECHO_LEFT,INPUT);
  pinMode(TRIG_LEFT,OUTPUT);
  digitalWrite(TRIG_LEFT,LOW);
  pinMode(SOUND,OUTPUT);
}

void loop() {
  trigPulse(TRIG);
  pulse = pulseIn(ECHO, HIGH);
  trigPulse(TRIG_LEFT);
  pulse_left = pulseIn(ECHO_LEFT, HIGH);
  dist = pulse/58.82;
  dist_left = pulse_left/58.82;
  if(dist < dist_left){
    short_dist = dist;
  }else{
    short_dist = dist_left;
  }
 emitSound(short_dist);  
}

void emitSound(float _dist){
  if(_dist <= 180 && _dist >= 80){
    digitalWrite(SOUND,HIGH);
      delay(DELAY);
      digitalWrite(SOUND,LOW);
      delay(DELAY);
    }else if(_dist < 80 && _dist >= 3){
      digitalWrite(SOUND,HIGH);
      delay(DELAY*2);
    }else if(_dist > 180){
      digitalWrite(SOUND,LOW);
      delay(DELAY*2);  
    }
}