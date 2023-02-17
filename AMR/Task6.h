
class Snmp2Task : public Task { 
protected:






void setup() {
//Serial1.println("SNMP Task..");
      

  api_status = Agentuino.begin();
  //
  if ( api_status == SNMP_API_STAT_SUCCESS ) {
    //
    Agentuino.onPduReceive(pduReceived);
    //
//   delay(10);
    //
    return;
  } 
  //
 // delay(10);

}

void loop() {

         
      
        







   
  locServices7 = Mux1 ;
  locServices8 = Power1;
  locServices9 = Current1;
  locServices10 = Hz1 ;
  locServices12 = Volt1 ;

  locServices13 = Mux2 ;
  locServices14 = Power2;
  locServices15 = Current2;
  locServices16 = Hz2 ;
  locServices17 = Factor2 ;
  locServices18 = Volt2 ;

  locServices19 = Mux3 ;
  locServices20 = Power3;
  locServices21 = Current3;
  locServices22 = Hz3 ;
  locServices23 = Factor3 ;
  locServices24 = Volt3 ;

  locServices25 = Mux4 ;
  locServices26 = Power4;
  locServices27 = Current4;
  locServices28 = Hz4 ;
  locServices29 = Factor4 ;
  locServices30 = Volt4;

  locServices31 = Mux5 ;
  locServices32 = Power5;
  locServices33 = Current5;
  locServices34 = Hz5 ;
  locServices35 = Factor5 ;
  locServices36 = Volt5;

 // udp.begin(161);
 // Serial.println("SNMP Task..2");
 // listen/handle for incoming SNMP requests

 
  Agentuino.listen();
  //
  // sysUpTime - The time (in hundredths of a second) since
  // the network management portion of the system was last
  // re-initialized.


  
  if ( millis() - prevMillis >1000 ) {
    // increment previous milliseconds
    prevMillis += 1000;
    //
    // increment up-time counter
    locUpTime += 100;
    /*      if ( locUpTime > 60480000){
      
              ESP.restart() ; 
              }
       */  
    
  }
}
private:



}snmp2_task;
