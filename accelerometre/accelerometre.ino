
int X = A0;
int Y = A1;
int Z = A2;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

//  int x = analogRead(X);
//  delay(1);
//  int y = analogRead(Y);
//  delay(1);
//  int z = analogRead(Z);

  Serial.print("x: ");
  Serial.print(velocity(X));
  Serial.print("\n");
  //delay(10);
//  Serial.print(" y: ");
//  Serial.print(velocity(Y));
//  Serial.print("\t");
//
//  Serial.print(" z: ");
//  Serial.print(velocity(Z));
//  Serial.println("\t");
  
}

float velocity(int PIN){
  int N = 100;
  int tab[N];
  float somme = 0;
  for(int i=0;i<N;i++){
    int prev_a = analogRead(PIN);
    delay(1);
    int new_a = analogRead(PIN);
    tab[i] = (new_a - prev_a);
    somme += tab[i];
  }
  float vel = somme/N;
  return vel;
}
