const int motorPin = 9;     //상수 선언 : 모터 핀 번호
const int ledPin = 10;     //상수 선언 : LED 핀번호

void setup() {
	pinMode(motorPin, OUTPUT);
	pinMode(ledPin, OUTPUT);
	Serial.begin(9600);
	
}

void loop() {

	int speed;//속도 값
	int chk;//CHECK 값
	while (Serial.available() == 0) {}
	speed = Serial.parseInt();//속도 입력
	spiningMotor(speed);//입력 받은 속도로 DC모터 출력


	while (Serial.available() == 0) {}
	chk = Serial.parseInt();
	led(chk);


}

void led(int chk)
{
	if (chk == true)
		digitalWrite(ledPin, HIGH);
	else
		digitalWrite(ledPin, LOW);


}
void spiningMotor(int speed)
{

	speed = constrain(speed, 0, 255);     //속도를 PWM 출력 값 범위로 고정

	analogWrite(motorPin, speed);         //speed만큼으로 모터 돌리기

	//speed : 값을 출력
	Serial.print("speed : ");
	Serial.println(speed);

}
