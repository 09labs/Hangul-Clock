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
  //Serial.println(TT.hours);
  //Serial.println(tim);
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
  
  // put your setup code here, to run once:
  //rtc.halt(false);
  //rtc.writeProtect(false);
  
  // Setup Serial connection
  Serial.begin(9600);

  // The following lines can be commented out to use the values already stored in the DS1302
  //rtc.setDOW(FRIDAY);        // Set Day-of-Week to FRIDAY
  //rtc.setDate(TT.days, TT.months, TT.years);
  //rtc.setTime(TT.hours, TT.mins, TT.secs);
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
