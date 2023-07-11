class JsonTask : public Task { 
protected:


void setup() {
  
}

void loop() {
  
     //////////////////Led.. blink//////////////   
   
   unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
    digitalWrite(LedGreenOut, ledState);
  }
//////////////////Led.. blink//////////////  
  if (chat.available()) 
  {
 StaticJsonDocument    <512> doc;     
 DeserializationError error = deserializeJson(doc, chat);
//6  DechatizationError error = dechatizeMsgPack(doc, chat);
 if (error == DeserializationError::Ok) 
    {

      json = "OK" ;
      Mux1 = doc["Mux1"];
      Mux2 = doc["Mux2"];
      Mux3 = doc["Mux3"];
      Mux4 = doc["Mux4"];
      Mux5 = doc["Mux5"];
      reboot = doc["reboot"];
      Serial.println(Mux1);
      Serial.println(Mux2);
      Serial.println(Mux3);
      Serial.println(Mux4);
      Serial.println(Mux5);
      Serial.println(reboot);
      if (reboot == 191){
        ESP.restart();
         }
             else if(reboot == 999 ){ /// 999 หมายถึง OTA             
                   StaticJsonDocument<200> doc;
                      doc["SSID"] = WiFi.SSID();
                      doc["PASSWORD"] = WiFi.psk();
                       Serial.print("Return :");
                       Serial.println("USER & Password");
                               
                  JsonObject  root =doc.as<JsonObject>();
                  serializeJson(doc, chat);              
                 }

      
    }

  
  else 
    {
      // Print error to the "debug" chat port
      Serial.print("dechatizeJson() returned ");
      Serial.println(error.c_str());
      json = "ON Good" ;
  
      // Flush all bytes in the "link" chat port buffer
      while (chat.available() > 0)
        chat.read();
    }
}
    
} 
       
 
private:


  
    
} json_task;
