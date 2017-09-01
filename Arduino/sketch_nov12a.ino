
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);
float radius = 30; // 바퀴당 이동 거리를 확인 하기 위해 자전거 바퀴의 반지름을 입력해 줍니다.(Cm 단위)
float circle = (2 * radius * 3.14) / 100;  // 자전거 바퀴의 둘레를 계산(단위를 m로 바꿔주기 위해 100을 나눕니다.)

float bySpeed = 0; // 자전거의 속도
float ckTime = 0;  // 리드스위치가 
float uckTime = 0; // Unckecked
float cycleTime = 0;  // 리드스위치가 인식이 안됬을 시간 부터 인식됬을 때까지의 시간
float distance = 0; // 자전거의 누적 이동 거리
float lcdDis = 0; // 자전거의 이동 거리를 LCD출력에 맞게 바꿔즌 값.(단위 수정 or 소숫점 제거)

int count = 0;  // 리드스위치의 노이즈를 제거하기 위해 카운트를 넣어줍니다.
boolean temp = 0;  // 리드 스위치가 닫혔는지 확인하는 변수
int sendCounter = 0; //블루투스 전송 카운터

int wheel_rotate = 0;

int test2 = 0;
int test1 = 0;
int test3 = 0;
int test4 = 0;
void setup(){
Serial.begin(9600);  // 측정된 값을 시리얼 모니터로 확인하기 위해 bps를 설정해 줍니다.
BTSerial.begin(9600);

pinMode(8, INPUT);
pinMode(9, INPUT);
}

void loop(){
  boolean check = digitalRead(A0); // 리드스위치의 상태를 확인합니다.
  if(digitalRead(8)){
    wheel_rotate = 1;
  }
  else if(digitalRead(9))
  {
    wheel_rotate = -1;
  }
  else{
    wheel_rotate = 0;
  }
  if(check == 1 && temp == 0){  // 리드 스위치가 열릴 때(닫힘 -> 열림)
    ckTime = millis();  // 시간을 확인해서 저장합니다.
    temp = 1;  // temp값을 1로 바꿔줍니다.(리드스위치가 열려있는 상태값 저장)
  }
  
  else if(check == 0 && temp == 1 && count > 5){  // 리드 스위치가 닫히고(열림 -> 닫힘), 노이즈 방지 카운트가 5이상일때
    uckTime = millis();  // 시간을 확인해서 저장합니다.
      
    cycleTime = (uckTime - ckTime)/1000;
    // 열릴 때 시각과 닫힐 때 시각의 차를 이용하여 바퀴가 한바퀴 돌때 걸린 시간을 계산합니다.
    bySpeed = (circle / cycleTime) * 3.6 ; // 바퀴가 한바퀴 돌때의 거리와 시간을 가지고 속도를 구해줍니다.(단위는 Km/h입니다.)
    temp = 0; 
    count = 0; 
    distance += circle;  // 한바퀴 돌았으면 이동거리를 누적 이동거리에 더해줍니다.
  }
  
  if(check == 1){  // 리드 스위치가 열려있으면 카운트를 1씩 증가 시켜 줍니다.
    count++;
    
    if(bySpeed >0.0f){
      bySpeed-=0.1f;
      if(bySpeed < 0.0f){
        bySpeed = 0;
      }
    }
    
  }
  
  test1 = (int)bySpeed;
  test2 = (int)((bySpeed-((float)test1))*100.0f);
  test3 = (int)distance;
  test4 = (int)((distance-((float)test3))*100.0f);
  Serial.print("Speed : ");
  
  Serial.print(bySpeed);
  Serial.println(" km/h");// 시리얼 모니터를 이용하여 속도를 확인합니다.
  char s[3];
  if(sendCounter > 10){
    BTSerial.write(itoa(test1,s,10));
    BTSerial.write(".");
    BTSerial.write(itoa(test2,s,10));
    BTSerial.write("/");
    BTSerial.write(itoa(wheel_rotate,s,10));
    BTSerial.write("/");
    BTSerial.write(itoa(test3,s,10));
    BTSerial.write(".");
    BTSerial.write(itoa(test4,s,10));
    BTSerial.write("\n");
    sendCounter = 0;
  }
  else{
    sendCounter++;
  }
}

