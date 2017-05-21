#include "Hangul.h"
#include <DS1302.h>
#include <Thread.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN 5
#define NUMPIXELS 36
Thread myThread = Thread();
DS1302 rtc(11,10,9);
Hangul hangul(PIN, NUMPIXELS);

String tim="";
uint8_t flag = 0;
String d, t;
struct timerr{
  int years;
  int months;
  int days;
  int hours;
  int mins;
  int secs;
};
timerr TT;
void callBack(){
  tim = rtc.getTimeStr();
  hangul.blinkSec();
  Serial.println(tim);
  }
void setup() {
  myThread.onRun(callBack);
  myThread.setInterval(1000);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif

  d = __DATE__;
  t = __TIME__;
  
  hangul.pixels.begin();
  

  int d_first = d.indexOf(" ");
  int d_seconds = d.indexOf(" ", d_first+1);
  int t_first = t.indexOf(":");
  int t_seconds = t.indexOf(":",t_first+1);
  
  TT.months = d.substring(0,d_first).toInt();
  TT.days = d.substring(d_first+1, d_seconds).toInt();
  TT.years = d.substring(d_seconds+1).toInt();
  TT.hours = t.substring(0,t_first).toInt();
  TT.mins = t.substring(t_first+1,t_seconds).toInt();
  TT.secs = t.substring(t_seconds+1).toInt();
  
   
  // Setup Serial connection
  Serial.begin(9600);
  //rtc.halt(false);
  //rtc.writeProtect(false);   
  //rtc.setDOW(FRIDAY);
  //rtc.setDate(TT.days, TT.months, TT.years);
  //rtc.setTime(TT.hours, TT.mins, TT.secs);
  /*
  RTC에 해당하는 주석을 모두 해제할 경우 RTC모듈에 시간이 기록됩니다
  요일을 설정하고 싶으면 setDOW안의 단어를 변경하세요.
  주석을해제한뒤업로드하면DS1302에시간이기록됩니다
  시리얼 모니터를 켜서 시간을 확인한 뒤에는 반드시 RTC에 해당하는 부분의 주석처리를 다시 한 뒤 업로드를 해주셔야 정상 작동합니다
  */
  hangul.resetLED();
}

void loop() {
  // 시:분:초  다음과 같은 형식으로 입력하면 시간이 입력됩니다
  // start라고 입력하면 타이머가 시작됩니다

  if(myThread.shouldRun()){
    myThread.run();
  }
  hangul.setTimee(tim);

  hangul.updateTime();
  hangul.colorChange(); 
  
  // put your main code here, to run repeatedly:
  //delay(1000);
}
