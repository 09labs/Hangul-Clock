#include "Arduino.h"
#include "Hangul.h"

Hangul::Hangul(uint8_t pin, uint8_t numpixels){
  _pin = pin;
  _numpixels = numpixels;
}
void Hangul::AMPM(uint8_t hours){
  if(hours == 0 || hours == 24)
  {
    pixels.setPixelColor(0,color);
    pixels.setPixelColor(1,color);
    pixels.setPixelColor(2,pixels.Color(0,0,0));
  }
  else if(hours >= 12 && hours <=23)
  {
    pixels.setPixelColor(0,color);
    pixels.setPixelColor(1,pixels.Color(0,0,0));
    pixels.setPixelColor(2,color);
  }
  else if(hours < 12 && hours >= 1)
  {
    pixels.setPixelColor(0,color);
    pixels.setPixelColor(1,color);
    pixels.setPixelColor(2,pixels.Color(0,0,0));
  }
  else;
}
void Hangul::hourChange(uint8_t hours, uint8_t minutes){
  uint8_t ConvertHour = 0;

  if(hours >= 12){
    ConvertHour = hours - 12;
  }
  else{
    ConvertHour = hours;
  }
  switch(ConvertHour)
  {
    case 0:
    {
      pixels.setPixelColor(6, color);
      pixels.setPixelColor(7, pixels.Color(0,0,0));
      pixels.setPixelColor(8, color);
      for(int i = 9 ; i < 20 ; i++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      break;
    }
    case 1:
    {
      pixels.setPixelColor(6, pixels.Color(0,0,0));
      pixels.setPixelColor(7, color);
      for(int i = 8 ; i < 20 ; i++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      break;
    }
    case 2:
    {
      pixels.setPixelColor(6, pixels.Color(0,0,0));
      pixels.setPixelColor(7, pixels.Color(0,0,0));
      pixels.setPixelColor(8, color);
      for(int i = 9 ; i < 20 ; i++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      break;
    }
    case 3:
    {
      pixels.setPixelColor(6, pixels.Color(0,0,0));
      pixels.setPixelColor(7, pixels.Color(0,0,0));
      pixels.setPixelColor(8, pixels.Color(0,0,0));
      pixels.setPixelColor(9, color);
      for(int i = 10 ; i < 20 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      
      break;
    }
    case 4:
    {
      pixels.setPixelColor(6, pixels.Color(0,0,0));
      pixels.setPixelColor(7, pixels.Color(0,0,0));
      pixels.setPixelColor(8, pixels.Color(0,0,0));
      pixels.setPixelColor(9, pixels.Color(0,0,0));
      pixels.setPixelColor(10, color);
      for(int i = 11 ; i < 20 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      
      break;
    }
    case 5:
    {
      pixels.setPixelColor(6, pixels.Color(0,0,0));
      pixels.setPixelColor(7, pixels.Color(0,0,0));
      pixels.setPixelColor(8, pixels.Color(0,0,0));
      pixels.setPixelColor(9, pixels.Color(0,0,0));
      pixels.setPixelColor(10, pixels.Color(0,0,0));
      pixels.setPixelColor(11, color);
      pixels.setPixelColor(12, pixels.Color(0,0,0));
      pixels.setPixelColor(13, color);
      for(int i = 14 ; i < 20 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      
      break;
    }
    case 6:
    {
      for(int i = 6 ; i < 12 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      pixels.setPixelColor(12, color);
      pixels.setPixelColor(13, color);
      for(int i = 14 ; i < 20 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      break;
    }
    case 7:
    {
      for(int i = 6 ; i < 14 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      pixels.setPixelColor(14, color);
      pixels.setPixelColor(15, color);
      for(int i = 16 ; i < 20 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      break;
    }
    case 8:
    {
      for(int i = 6 ; i < 16 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      pixels.setPixelColor(16, color);
      pixels.setPixelColor(17, color);
      pixels.setPixelColor(18, pixels.Color(0,0,0));
      pixels.setPixelColor(19, pixels.Color(0,0,0));
      
      break;
    }
    case 9:
    {
      for(int i = 6 ; i < 18 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      pixels.setPixelColor(18, color);
      pixels.setPixelColor(19, color);
      break;
    }
    case 10:
    {
      pixels.setPixelColor(6, color);
      for(int i = 7 ; i < 20 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      break;
    }
    case 11:
    {
      pixels.setPixelColor(6, color);
      pixels.setPixelColor(7, color);
      for(int i = 8 ; i < 20 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      break;
    }
    case 12:
    {
      pixels.setPixelColor(6, color);
      pixels.setPixelColor(7, pixels.Color(0,0,0));
      pixels.setPixelColor(8, color);
      for(int i = 9 ; i < 20 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      break;
    }
    default:{break;}
  }
  pixels.setPixelColor(20, color);
}

void Hangul::minuteChange(uint8_t minutes){
  uint8_t one = 0;
  one = minutes % 10;
  if(minutes >= 10 && minutes < 20){
    for(int i = 21 ; i < 25 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
    pixels.setPixelColor(25, color);
  }
  else if(minutes >= 20 && minutes < 30){
    for(int i = 21 ; i < 24 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
    pixels.setPixelColor(24, color);
    pixels.setPixelColor(25, color);
  }
  else if(minutes >= 30 && minutes < 40){
    for(int i = 21 ; i < 23 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
    pixels.setPixelColor(23, color);
    pixels.setPixelColor(24, pixels.Color(0,0,0));
    pixels.setPixelColor(25, color);
  }
  else if(minutes >= 40 && minutes < 50){
    pixels.setPixelColor(21, pixels.Color(0,0,0));
    pixels.setPixelColor(22, color);
    pixels.setPixelColor(23, pixels.Color(0,0,0));
    pixels.setPixelColor(24, pixels.Color(0,0,0));
    pixels.setPixelColor(25, color);
  }
  else if(minutes >= 50 && minutes < 60){
    pixels.setPixelColor(21, color);
    pixels.setPixelColor(22, pixels.Color(0,0,0));
    pixels.setPixelColor(23, pixels.Color(0,0,0));
    pixels.setPixelColor(24, pixels.Color(0,0,0));
    pixels.setPixelColor(25, color);
  }
  else;
  if(one == 0 && minutes == 0)
  {
    for(int i = 21 ; i < 26 ; i ++)
    {
      pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
  }
  else{
    if(one == 1){
      for(int i = 26 ; i < 34 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      pixels.setPixelColor(34, color);
    }
    else if(one == 2){
      for(int i = 26 ; i < 33 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      pixels.setPixelColor(33, color);
      pixels.setPixelColor(34, pixels.Color(0,0,0));
    }
    else if(one == 3){
      for(int i = 26 ; i < 32 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      pixels.setPixelColor(32, color);
      pixels.setPixelColor(33, pixels.Color(0,0,0));
      pixels.setPixelColor(34, pixels.Color(0,0,0));
    }
    else if(one == 4){
      for(int i = 26 ; i < 31 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      pixels.setPixelColor(31, color);
      pixels.setPixelColor(32, pixels.Color(0,0,0));
      pixels.setPixelColor(33, pixels.Color(0,0,0));
      pixels.setPixelColor(34, pixels.Color(0,0,0));
    }
    else if(one == 5){
      for(int i = 26 ; i < 30 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      pixels.setPixelColor(30, color);
      pixels.setPixelColor(31, pixels.Color(0,0,0));
      pixels.setPixelColor(32, pixels.Color(0,0,0));
      pixels.setPixelColor(33, pixels.Color(0,0,0));
      pixels.setPixelColor(34, pixels.Color(0,0,0));
    }
    else if(one == 6){
      for(int i = 26 ; i < 29 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      pixels.setPixelColor(29, color);
      for(int i = 30 ; i < 35 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
    }
    else if(one == 7){
      for(int i = 26 ; i < 28 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      pixels.setPixelColor(28, color);
      for(int i = 29 ; i < 35 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
    }
    else if(one == 8){
      pixels.setPixelColor(26, pixels.Color(0,0,0));
      pixels.setPixelColor(27, color);
      for(int i = 28 ; i < 35 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
    }
    else if(one == 9){
      pixels.setPixelColor(26, color);
      for(int i = 27 ; i < 35 ; i ++)
      {
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
    }
    pixels.setPixelColor(35, color);
  }
  
}
void Hangul::resetLED(){
  for(uint8_t i = 0 ; i < 36 ; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
  }
  
}

void Hangul::setTimee(String input){
  uint8_t Hours, Minutes, Seconds=0;
  uint8_t first_c, seconds_c;

  first_c = input.indexOf(":");
  seconds_c = input.indexOf(":", first_c+1);

  Hours = input.substring(0,first_c).toInt();
  Minutes = input.substring(first_c+1, seconds_c).toInt();
  Seconds = input.substring(seconds_c+1).toInt();  

  _time.hours = Hours;
  _time.minutes = Minutes;
  _time.secs = Seconds;
}
void Hangul::blinkSec(){
  uint8_t b = 0;

  b = _time.secs % 2;
  if(b == 1){
    pixels.setPixelColor(3,color);
    pixels.setPixelColor(4,color);
    pixels.setPixelColor(5,color);
  }
  else{
    pixels.setPixelColor(3,0);
    pixels.setPixelColor(4,0);
    pixels.setPixelColor(5,0);
  }
  
}
void Hangul::updateTime(){

  blinkSec();
  AMPM(_time.hours);
  hourChange(_time.hours,_time.minutes);
  minuteChange(_time.minutes);
  pixels.show();
  if((_time.secs != _old_secs) && _time.secs == 0){
    resetLED();
  }
  _old_secs = _time.secs;
  /*
  _time.secs += 1;
  
  if(_time.secs == 60){
    resetLED();
    _time.secs = 0;
    _time.minutes += 1;
  }
  if(_time.minutes == 60){
    _time.minutes = 0; 
    _time.hours += 1;
  }
  if(_time.hours == 24){
    _time.hours = 0;
  }*/
}

void Hangul::colorChange(){
  uint8_t red, green, blue;
  red = digitalRead(6);
  green = digitalRead(7);
  blue = digitalRead(8);
  
    if((old_r != red) && (red == 1)){
      _red += 10;
      if(_red > 250){
        _red = 0;
      }
      color = pixels.Color(_red, _green, _blue);
      pixels.show();
    }
    

    if((old_g != green) && (green == 1)){
      _green += 10;
      if(_green > 250)
      {
        _green = 0;
      }
      color = pixels.Color(_red, _green, _blue);
      pixels.show();
    }
  
    if((old_b != blue) && (blue == 1)){
      
      _blue += 10;
      if(_blue > 250){
        _blue = 0;
      }
      color = pixels.Color(_red, _green, _blue);
      pixels.show();
    }
  
  old_r = red;
  old_g = green;
  old_b = blue;
}

