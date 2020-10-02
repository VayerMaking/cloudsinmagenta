int left_btn = 1;
int right_btn = 2;
int left_strip_r = 3;
int right_strip_r = 4;
int left_strip_g = 5;
int right_strip_g = 6;
int left_strip_b = 7;
int right_strip_b = 8;
int brake = 0;
bool left_btn_state;
bool right_btn_state;
bool left_strip_state;
bool right_strip_state;
bool brake_state;

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

if(left_btn_state == 1){
  analogWrite(left_strip_r, 255);
  analogWrite(left_strip_g, 100);
  analogWrite(left_strip_b, 0);
  left_strip_state = 1;
}else{
  analogWrite(left_strip_r, 0);
  analogWrite(left_strip_g, 0);
  analogWrite(left_strip_b, 0);
  left_strip_state = 0;
}

if(right_btn_state == 1){
  analogWrite(right_strip_r, 255);
  analogWrite(right_strip_g, 100);
  analogWrite(right_strip_b, 0);
  right_strip_state = 1;
}else{
  analogWrite(right_strip_r, 0);
  analogWrite(right_strip_g, 0);
  analogWrite(right_strip_b, 0);
  right_strip_state = 0;
}

}
