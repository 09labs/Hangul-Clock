# Hangul Clock

한글시계 프로젝트입니다. 단국대학교 학술동아리 연구방에서 지원받아 제작한 프로젝트입니다.
프로젝트 참여자 - 김승권(팀장), 유정훈, 황주원, 차동준

V 1.0 - 기존 한글시계에서 버튼을 추가하여 색을 변경하는 기능을 추가하였습니다. RGB 각각 12단계로 조절이 가능합니다.


English

Korean(Hangul) Clock Project. 09room is electrical and electronic community. 09room supported this project.
Project Manager - Seung Gwon, Kim
Project Member - Jeong Hoon, You / Joowon, Hwang / Dong Joon, Cha

V 1.0 - Originally Hangul clock has a function that display time. But i added a button. 
So you can change a color R, G, B 12 levels.

made by Seung Gwon, Kim


# 아두이노 필수 라이브러리 설치

아두이노 IDE설치 후 DS1302 리이브러리(Henning Karlsen)와 Thread 라이브러리, Adafruit NeoPixel 라이브러리를 추가합니다.

DS1302 - http://www.rinkydinkelectronics.com/library.php?id=5
Thread - 아두이노IDE -> 스케치  -> 라이브러리 포함하기 -> 라이브러리 관리 -> Thread 검색 후 추가
Adafruit NeoPixel - https://github.com/adafruit/Adafruit_NeoPixel

Github에서 다운받으신 압축파일은 아두이노 IDE - 스케치 - 라이브러리 포함하기 - .ZIP 라이브러리 추가 기능을 사용하시면 됩니다.

# 아두이노 함수 설명

hourChange(hours, minutes) - hours와 minutes에 따라 '시'에 해당하는 네오픽셀을 변경합니다.

minuteChange(minutes) - minutes에 따라 '분'에 해당하는 네오픽셀을 변경합니다.

resetLED() - 1분에 한 번씩 호출하는 함수로 네오픽셀을 전부 초기화합니다.

setTimee(input) - input은 String type으로 "12:23:33"과 같은 형태로 구성된 문자열에서
시, 분, 초를 분리하여 클래스 private 변수에 값을 저장합니다.

blinkSec() - 1초에 한번씩 '초'에 해당하는 네오픽셀을 점멸시킵니다. 전체 주기는 2초입니다.

AMPM(uint8_t hours) - hours의 값에 따라서 오전, 오후 값을 바꿔 표기합니다.

updateTime() - 시간을 갱신시킵니다.

  blinkSec();
  AMPM(_time.hours);
  hourChange(_time.hours,_time.minutes);
  minuteChange(_time.minutes);
  pixels.show();
  if((_time.secs != _old_secs) && _time.secs == 0){
    resetLED();
  }
  _old_secs = _time.secs;

# PCB 주문방법

Gerber 폴더에 있는 파일을 PCB 주문제작업체에 보내면 알아서 해줍니다.

부품리스트

Arduino Nano - 1EA (http://storefarm.naver.com/ic11401/products/650416459)
USB Micro breakout board - 1EA (https://goo.gl/hY34n9)
DS1302 - 1EA (http://storefarm.naver.com/ic11401/products/646964977)

WS2812 - 36EA (http://goo.gl/elRKqF) ****꼭 4핀짜리로 구매할 것!!!****
네오픽셀 Strip - LED 간격이 1.65cm인 것을 선택할 것 (http://www.devicemart.co.kr/1328620)

WS2812와 네오픽셀 스트립 중 하나만 구입하면 됩니다!

0805 Ceramic Capacitor 100nF - 36EA (http://www.devicemart.co.kr/8191)
0805 Chip resistor 10K ohm - 3EA (http://www.devicemart.co.kr/19263)
12x12mm Tact switch - 3EA (http://www.devicemart.co.kr/35853)
Pin Header Socket 2.54mm 1x15 Straight - 2EA (http://www.devicemart.co.kr/12497)
Pin Header Socket 2.54mm 1x5 Straight - 2EA (http://www.devicemart.co.kr/12494)
Molex 5045 3pin - 1EA (http://www.devicemart.co.kr/462)
Molex 5051 3pin - 1EA (http://www.devicemart.co.kr/501)
Molex 5051 crimp - 3EA (http://www.devicemart.co.kr/5464)

업체로부터 지원을 받아 제작한 글이 아님을 알려드립니다.



