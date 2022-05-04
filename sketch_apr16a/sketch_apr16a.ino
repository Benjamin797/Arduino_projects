

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  count();
  
  delay(1000);
}

void count(){
  static int ctp = 0;
  ctp++;
  Serial.print(ctp);
  
}
