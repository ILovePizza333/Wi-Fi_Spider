void bt_handler() {
  server.send(200, "text/plain", "ok");
  //  stand_handler();
  delay (100);
  mypwm(1, 130, 0);
  mypwm(2, 30, 0);
  mypwm(4, 100, 0);
  mypwm(5, 10, 0);
  mypwm(7, 180, 0);
  mypwm(6, 170, 0);
  int i = 0;
  while (i < 6) {
    i++;
    mypwm(8, 100, 3);
    delay(100);
    mypwm(8, 20, 3);
    delay(100);
  }

}

void start_handler() {
  server.send(200, "text/plain", "ok");
  for (int i = 0; i < 12; i++) {
    mypwm(i, servo_stand[i] + 30, 0);
    delay(100);
    mypwm(i, servo_stand[i], 0);
  }
  Serial.println("start");
  delay(200);

}
void stop_handler() {
  server.send(200, "text/plain", "ok");
  Move =0;
  Serial.println("stop");
}
void forw_handler() {
  server.send(200, "text/plain", "ok");
  Move =1;
  int sp = 100;
  mypwm(7, 180, 0);
  mypwm(6, 140, 0);
  mypwm(7, servo_stand[7], 0);
  delay(sp);
  mypwm(4, 180, 0);
  mypwm(3, 140, 0);
  mypwm(4, servo_stand[4], 0);
  delay(sp);
  mypwm(10, 180, 0);
  mypwm(9, 160, 0);
  mypwm(10, servo_stand[10], 0);
  delay(sp);
  mypwm(1, 180, 0);
  mypwm(0, 160, 0);
  mypwm(1, servo_stand[1], 0);
  delay(sp);
  stand_handler();
  Serial.println("forw");
}
void back_handler() {
  server.send(200, "text/plain", "ok");
  Move =2;
  int sp = 100;
  mypwm(10, 180, 0);
  mypwm(9, 60, 0);
  mypwm(10, servo_stand[10], 0);
  delay(sp);
  mypwm(1, 180, 0);
  mypwm(0, 60, 0);
  mypwm(1, servo_stand[1], 0);
  delay(sp);
  mypwm(7, 180, 0);
  mypwm(6, 40, 0);
  mypwm(7, servo_stand[7], 0);
  delay(sp);
  mypwm(4, 180, 0);
  mypwm(3, 40, 0);
  mypwm(4, servo_stand[4], 0);
  delay(sp);
  stand_handler();
  Serial.println("back");
}
void left_handler() {
  server.send(200, "text/plain", "ok");
  Move =3;
  int sp = 100;
  mypwm(4, 180, 0);
  mypwm(3, 140, 0);
  mypwm(4, servo_stand[4], 0);
  delay(sp);
  mypwm(1, 180, 0);
  mypwm(0, 140, 0);
  mypwm(1, servo_stand[1], 0);
  delay(sp);
  mypwm(10, 180, 0);
  mypwm(9, 40, 0);
  mypwm(10, servo_stand[10], 0);
  delay(sp);
  mypwm(7, 180, 0);
  mypwm(6, 40, 0);
  mypwm(7, servo_stand[7], 0);
  delay(sp);
  stand_handler();
  Serial.println("left");
}
void right_handler() {
  server.send(200, "text/plain", "ok");
  Move =4;
  int sp = 100;
  mypwm(7, 180, 0);
  mypwm(6, 140, 0);
  mypwm(7, servo_stand[7], 0);
  delay(sp);
  mypwm(10, 180, 0);
  mypwm(9, 140, 0);
  mypwm(10, servo_stand[10], 0);
  delay(sp);
  mypwm(1, 180, 0);
  mypwm(0, 40, 0);
  mypwm(1, servo_stand[1], 0);
  delay(sp);
  mypwm(4, 180, 0);
  mypwm(3, 40, 0);
  mypwm(4, servo_stand[4], 0);
  delay(sp);
  stand_handler();
  Serial.println("right");
}
void stand_handler() {
  server.send(200, "text/plain", "ok");
  for (int i = 0; i < 12; i++) {
    mypwm(i, servo_stand[i], 0);
    //  pwm.setPWM(SERVOPORT[i], 0, servo_stand[i]);
    //   delay(250);
  }
  Serial.println("stand");
  delay(200);

}
void sit_handler() {
  server.send(200, "text/plain", "ok");
  for (int i = 0; i < 12; i++) {
    //  pwm.setPWM(SERVOPORT[i], 0, servo_sit[i]);
    mypwm(i, servo_sit[i], 0);
    //delay(250);
  }
  Serial.println("sit");
  delay(200);
}
