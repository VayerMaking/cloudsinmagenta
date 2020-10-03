int left_btn = 5;
int right_btn = 4;
int left_strip_r = 0;
int right_strip_r = 2;
int left_strip_g = 14;
int right_strip_g = 12;
int left_strip_b = 13;
int right_strip_b = 15;
int brake = 16;
int left_btn_state;
int right_btn_state;
int left_strip_state;
int right_strip_state;
int brake_state;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(left_btn, INPUT);
  pinMode(right_btn, INPUT);
  pinMode(brake, INPUT);
  pinMode(left_strip_r, OUTPUT);
  pinMode(right_strip_r, OUTPUT);
  pinMode(left_strip_g, OUTPUT);
  pinMode(right_strip_g, OUTPUT);
  pinMode(left_strip_b, OUTPUT);
  pinMode(right_strip_b, OUTPUT);
  // Set outputs to LOW
  digitalWrite(left_strip_r, LOW);
  digitalWrite(right_strip_r, LOW);
  digitalWrite(left_strip_g, LOW);
  digitalWrite(right_strip_g, LOW);
  digitalWrite(left_strip_b, LOW);
  digitalWrite(right_strip_b, LOW);


}

void loop(){

left_btn_state = digitalRead(left_btn);
right_btn_state = digitalRead(right_btn);

if(left_btn_state == HIGH){
  analogWrite(left_strip_r, 255);
  analogWrite(left_strip_g, 100);
  analogWrite(left_strip_b, 0);
  left_strip_state = HIGH;
  Serial.println("levo");
}else{
  analogWrite(left_strip_r, 0);
  analogWrite(left_strip_g, 0);
  analogWrite(left_strip_b, 0);
  left_strip_state = LOW;
  Serial.println("nelevo");

}

if(right_btn_state == HIGH){
  analogWrite(right_strip_r, 255);
  analogWrite(right_strip_g, 100);
  analogWrite(right_strip_b, 0);
  right_strip_state = HIGH;
  Serial.println("desno");

}else{
  analogWrite(right_strip_r, 0);
  analogWrite(right_strip_g, 0);
  analogWrite(right_strip_b, 0);
  right_strip_state = LOW;
  Serial.println("nedesno");

}

}
