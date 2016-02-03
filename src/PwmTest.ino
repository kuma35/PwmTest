//testing pwm servos.
//by kuma35

#include <Servo.h>

#define SERVO_0 3

#define RS405CB

#ifdef RS405CB
#define SERVO_TYPE	"RS405CB"
#define SERVO_MIN	560	// 取説より。+144度
#define SERVO_MAX	2480	// 取説より。-144度
#endif


Servo My_servo;
int Servo_pin = SERVO_0;

void re_attach(Servo *servop, int pin) {
  Servo_pin = pin;
  servop->detach();
  servop->attach(pin);
  Serial.print(F("assgin to "));
  Serial.println(Servo_pin);
}

void setup()
{
  Serial.begin(9600);
  My_servo.attach(Servo_pin);
  Serial.println(F("SERVO for " SERVO_TYPE));
  Serial.print(F("assgin to "));
  Serial.println(Servo_pin);
}

unsigned char Last_char;

void loop()
{
  if (Serial.available() > 0) {
    delay(10);
    Last_char = (unsigned char)Serial.read();
    switch(Last_char) {
    case '0':	// servo 0 is pin 3
      re_attach(&My_servo, 3);
      break;
    case '1':	// servo 1 is pin 5
      re_attach(&My_servo, 5);
      break;
    case '2':	// servo 2 is pin 6
      re_attach(&My_servo, 6);
      break;
    case '3':	// servo 3 is pin 9
      re_attach(&My_servo, 9);
      break;
    case '4':	// servo 4 is pin 10
      re_attach(&My_servo, 10);
      break;
    case '5':	// servo 5 is pin 11
      re_attach(&My_servo, 11);
      break;
    case 'h':	// help
    case '?':
      Serial.println(F("\r\nh:Help, ?:help, i:mIn, a:mAx, c:Center"));
      break;
    case 'i':
      Serial.println(F("i"));
      My_servo.writeMicroseconds(SERVO_MIN);
      break;
    case 'a':
      Serial.println(F("a"));
      My_servo.writeMicroseconds(SERVO_MAX);
      break;
    case 'c':
      Serial.println(F("c"));
      My_servo.writeMicroseconds((SERVO_MIN+SERVO_MAX)/2);
      break;
    default:
      Serial.println(F("unknown"));
      break;
    }
  }
}