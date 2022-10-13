void command() {
  server.onNotFound(handleNotFound);
  server.on("/bt", bt_handler);
  server.on("/f2", f2_handler);
  server.on("/sit", sit_handler);
  server.on("/fun", fun_handler);
  server.on("/stand", stand_handler);
  server.on("/stop", stop_handler);
  server.on("/forw", f3_handler);
  server.on("/back", back_handler);
  server.on("/left", left_handler);
  server.on("/right", right_handler);
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  slider = server.uri();
  Serial.print("slider:"); Serial.println(slider);
  if (slider.indexOf ("slider") != -1) {
    Serial.println("2");
    char ii = slider.charAt(7);
    String iii;     iii += ii;
    ii = slider.charAt(8);  iii += ii;
    int i = iii.toInt() - 2;

    slider = slider.substring(9);
    if (i >= 9)  slider = slider.substring(1);
    Sliderr[i] = slider.toInt();
    for (uint8_t i = 0; i < server.args(); i++) {
      message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    }
    server.send(404, "text/plain", message);
    // server.send(200, "text/plain", "ok");
    mypwm(SERVOPORT[i], Sliderr[i], 0);//  Serial.print("i:"); Serial.print(SERVOPORT[i]);  Serial.print("     slider:"); Serial.println(Sliderr[i]);
  }
}
