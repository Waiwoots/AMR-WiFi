class SendTask : public Task { 
protected:


void setup() {



   
  
}

void loop() {
 

 
 // digitalWrite(2, HIGH);
Serial.print("Version :");Serial.println(FW_VERSION);

  delay(5000); 
      

if (x <= 10)
  {

      boolean is_even;

   //   if( is_even = x%2 && json== "OK" )

       if( is_even = x%2 && json== "OK"  )
  //     if( is_even = x%2  )
         {            
        
          String url = "http://www.doopper.com/nodemcu/"+String(Site) + String("/update.php?TX=") + String(Site) + String("&Mux1=")+ String(Mux1)+ String("&Mux2=")+ String(Mux2)+ String("&Mux3=")+ String(Mux3)+String("&Mux4=")+ String(Mux4)+String("&Mux5=")+ String(Mux5);              
         // String fingerprint = "58 e4 77 51 ab ff 86 3b de 1a d0 4d ab 42 88 d6 bc ce 58 3b";     
           delay(5000);
           Serial.println(url);
           http.begin(client,url); //HTTP
           int httpCode = http.GET();
            if (httpCode > 0)
              {
                Serial.printf("[HTTP] GET... code: %d\n", httpCode);
                  if (httpCode == HTTP_CODE_OK) 
                    {
                      String payload = http.getString();
                      Serial.println(payload);
                      if (payload == ("reboot")){
                        ESP.restart();
                      }
                      
                    }
              }
              else          
                  {
                    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
                  }
                              http.end();
                              delay(300);
          }
                else{
                      Serial.print("Event Time To Delay =");Serial.println(x);Serial.println(json);
                      delay(2000);
                    }       
                 
                   
    
     delay(4000);          
     x++;
     
  }   
               
         
  //-----------------------------------------//

  else

    //-----------------------------------------//
  {
     boolean is_even;

      if( !is_even&& json== "OK"  )
         {            
         
          String url = "http://www.doopper.com/nodemcu/"+String(Site) + String("/add.php?TX=") + String(Site) + String("&Mux1=")+ String(Mux1)+ String("&Mux2=")+ String(Mux2)+ String("&Mux3=")+ String(Mux3)+String("&Mux4=")+ String(Mux4)+String("&Mux5=")+ String(Mux5);              
                 
           delay(5000);
           Serial.println(url);
           http.begin(client,url); //HTTP
           int httpCode = http.GET();
            if (httpCode > 0)
              {
                Serial.printf("[HTTP] GET... code: %d\n", httpCode);
                  if (httpCode == HTTP_CODE_OK) 
                    {
                      String payload = http.getString();
                      Serial.println(payload);
                    }
              }
              else          
                  {
                    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
                  }
                              http.end();
                              delay(300);
          }
                else{
                      Serial.print("Add Time   =");Serial.println(x);
                      delay(2000);
                    }       
                 
                   
    
     delay(4000);          
     x= 1;


}

 } //End void Loop

private:

int  x = 1; //ค่าเริ่มต้น ของการกำหนด Loop Update.php & Add.php
WiFiClient client;
HTTPClient  http;


} send_task;
