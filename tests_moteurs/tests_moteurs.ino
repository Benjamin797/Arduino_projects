#define ENCA1 18
#define ENCB1 19
#define PWM1 6 //(vitesse)
#define EN1 7  //(sens)


#define ENCA2 2
#define ENCB2 3
#define PWM2 4
#define EN2 5


volatile int pos2 = 0;
volatile int pos1 = 0;

long prevT1 = 0;
float eprev1 = 0;
float eintegral1 = 0;

long prevT2 = 0;
float eprev2 = 0;
float eintegral2 = 0;


void setSpeed(int pwm_pin, float value, int dir, int dir_pin)
{
  analogWrite(pwm_pin, value);
  if (dir == 1)
    digitalWrite(dir_pin, LOW);
  else
    digitalWrite(dir_pin, HIGH);
}




void setup() {
  Serial.begin(9600);
  pinMode(ENCB1, INPUT);
  pinMode(ENCA1, INPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(EN1, OUTPUT);

  pinMode(ENCB2, INPUT);
  pinMode(ENCA2, INPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(EN2, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ENCA2), count2, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCA1), count1, RISING);
}

 int target1 = 1000;
 int target2 = 1000;


void loop() {

  // constantes du PID
  float kp = 1;
  float ki = 0;
  float kd = 0.005;

  // différence de temps
  long currT1 = micros();
  float deltaT1 = (float)(currT1 - prevT1) / 1.0e6;
  prevT1 = currT1;

  long currT2 = micros();
  float deltaT2 = (float)(currT2 - prevT2) / 1.0e6;
  prevT2 = currT2;

           // erreur
  int e1 = pos1 - target1; // si marche pas inverser le sens
  int e2 = pos2 - target2;

  // dérivée
  float dedt1 = (e1 - eprev1) / (deltaT1);
  float dedt2 = (e2 - eprev2) / (deltaT2);

  //intégrale
  eintegral1 = eintegral1 + e1 * deltaT1;
  eintegral2 = eintegral2 + e2 * deltaT2;

  // control signal
  float u1 = kp * e1 + kd * dedt1 + ki * eintegral1;
  float u2 = kp * e2 + kd * dedt2 + ki * eintegral2;

  float pwr1 = fabs(u1);
  float pwr2 = fabs(u2);

  if (pwr1 > 255)
    pwr1 = 255;
  if (pwr2 > 255)
    pwr2 = 255;

  int dir1 = 1;
  if (u1 < 0)
    dir1 = -1;

  int dir2 = -1;
  if (u2 < 0)
    dir2 = 1;

  setSpeed(PWM1, pwr1, dir1, EN1);
  setSpeed(PWM2, pwr2, dir2, EN2);

  eprev1 = e1;
  eprev2 = e2;

  Serial.print("target 1:");
  Serial.print(target1);
  Serial.print("     pos1: ");
  Serial.print(e1);
  Serial.println();
  
  Serial.print("target 2:");
  Serial.print(target2);
  Serial.print("     pos2: ");
  Serial.print(e2);
  Serial.println();

//  setSpeed(PWM1, 100, 1, EN1);
//  setSpeed(PWM2, 100, -1, EN2);
//  delay(5000);

 }

void count2()
{
  if (!digitalRead(ENCB2))
    pos2++;
  else
    pos2--;
}

void count1()
{
  if (!digitalRead(ENCB1))
    pos1++;
  else
    pos1--;
}
