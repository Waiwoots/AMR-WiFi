class TxRxTask : public Task { 
protected:


void setup() {
  
}

void loop() {

delay(1500);


StaticJsonDocument<200> doc;
  doc["Mux1"] = Mux1;
  doc["Mux2"] = Mux2;
  doc["Mux3"] = Mux3;
  doc["Mux4"] = Mux4;
  doc["Mux5"] = Mux5;
  doc["reboot"] = reboot;
JsonObject  root =doc.as<JsonObject>();



 serializeJson(doc, Serial);
 
 

 
//
       String Readdata;  

}

private:


int R =0;  
    
} tx_rx_task;
