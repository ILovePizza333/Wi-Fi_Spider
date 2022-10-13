void mypwm(int adress, int cord, int del) {//номер в массиве выводов, координата в 0-180, задержка
  cord = map(cord, 0, 180, SERVOMIN, SERVOMAX);
  if (adress == 1 || adress == 4 || adress == 6 || adress == 8 || adress == 9 || adress == 11) {
    cord = map(cord, SERVOMIN, SERVOMAX, SERVOMAX, SERVOMIN);
  }

  // Serial.print(adress); Serial.print(":"); Serial.println(cord);
  int  k = servo_prev[adress];
  while (k > cord) {
    pwm.setPWM(SERVOPORT[adress], 0, k);
    
    k--;
  }
  while (k < cord) {
    pwm.setPWM(SERVOPORT[adress], 0, k);
    
    k++;
  }
  delay(del);
  servo_prev[adress] = cord;
}

void f2_handler() {
   Serial.println("f2");
  server.send(200, "text/plain", "ok");
  Move=5;
  int sp = 100;
  mypwm(4, 180, 0);
  mypwm(3, 140, 0);
  mypwm(4, servo_stand[4], 0);
  delay(sp);
  mypwm(10, 180, 0);
  mypwm(9, 160, 0);
  mypwm(10, servo_stand[10], 0);
  delay(sp);
  stand_handler();
  mypwm(7, 180, 0);
  mypwm(6, 140, 0);
  mypwm(7, servo_stand[7], 0);
  delay(sp);
  mypwm(1, 180, 0);
  mypwm(0, 160, 0);
  mypwm(1, servo_stand[1], 0);
  delay(sp);
  stand_handler();
  Serial.println("forw3");
}
void f3_handler() {
   Serial.println("f3");
  server.send(200, "text/plain", "ok");
  Move=5;
  int sp = 0;//задержка между движениями для удобного просмотра 

 for( int kol=0; kol<3; kol++){
  mypwm(4, 180, sp);
  mypwm(10, 180, sp);
  mypwm(3, 140, sp);
  mypwm(9, 160, sp);
  mypwm(4, servo_stand[4], sp);
  mypwm(10, servo_stand[10], sp);
  stand_handler();
  
  mypwm(7, 180, sp);
  mypwm(1, 180, sp);
  mypwm(6, 140, sp);
  mypwm(0, 160, sp);
  mypwm(7, servo_stand[7], sp);
  mypwm(1, servo_stand[1], sp);
  stand_handler();
  }

  Serial.println("forw3");
}
void fun_handler() {
  server.send(200, "text/plain", "ok");
  
  int sp = 100;

  mypwm(4, 180, 0);
  mypwm(3, 140, 0);
  mypwm(4, servo_stand[4], 0);
  delay(sp);
  mypwm(10, 180, 0);
  mypwm(9, 160, 0);
  mypwm(10, servo_stand[10], 0);
  delay(sp);
  mypwm(7, 180, 0);
  mypwm(6, 140, 0);
  mypwm(7, servo_stand[7], 0);
  delay(sp);
  mypwm(1, 180, 0);
  mypwm(0, 160, 0);
  mypwm(1, servo_stand[1], 0);
  delay(sp);
  stand_handler();
  Serial.println("forw2");

}
