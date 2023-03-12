 class LCDTask : public Task { 
protected:
    void setup() {

    }
    void loop() {


     
lcd.clear();         
        lcd.setCursor(0,0); lcd.print("Mux1  : NBT");          
        lcd.setCursor(0,1); lcd.print("Power");         lcd.setCursor(8,1);  lcd.print(Mux1); 
        lcd.setCursor(0,2); lcd.print("Consumption:");  lcd.setCursor(12,2); lcd.print(Power1);               
        lcd.setCursor(0,3); lcd.print("Current:");      lcd.setCursor(10,3); lcd.print(Current1);           
        delay(1500); 

lcd.clear();
        lcd.setCursor(0,0);lcd.print("Mux2  : Army");          
        lcd.setCursor(0,1);lcd.print("Power");          lcd.setCursor(8,1);  lcd.print(Mux2); 
        lcd.setCursor(0,2);lcd.print("Consumption:");   lcd.setCursor(12,2); lcd.print(Power2);                
        lcd.setCursor(0,3);lcd.print("Current:");       lcd.setCursor(10,3); lcd.print(Current2);          
        delay(1500);
         
 lcd.clear();
        lcd.setCursor(0,0);lcd.print("Mux3  : MCOT");          
        lcd.setCursor(0,1);lcd.print("Power");          lcd.setCursor(8,1);  lcd.print(Mux3); 
        lcd.setCursor(0,2);lcd.print("Consumption:");   lcd.setCursor(12,2); lcd.print(Power3);                
        lcd.setCursor(0,3);lcd.print("Current:");       lcd.setCursor(10,3); lcd.print(Current3);          
        delay(1500);

 lcd.clear();
        lcd.setCursor(0,0);lcd.print("Mux4  : TPBS");          
        lcd.setCursor(0,1);lcd.print("Power");          lcd.setCursor(8,1);  lcd.print(Mux4); 
        lcd.setCursor(0,2);lcd.print("Consumption:");   lcd.setCursor(12,2); lcd.print(Power4);                
        lcd.setCursor(0,3);lcd.print("Current:");       lcd.setCursor(10,3); lcd.print(Current4);          
        delay(1500);
         
         
lcd.clear();
        lcd.setCursor(0,0);lcd.print("Mux5  : Army");          
        lcd.setCursor(0,1);lcd.print("Power");         lcd.setCursor(8,1);   lcd.print(Mux5); 
        lcd.setCursor(0,2);lcd.print("Consumption:");  lcd.setCursor(12,2);  lcd.print(Power5);                
        lcd.setCursor(0,3);lcd.print("Current:");      lcd.setCursor(10,3);  lcd.print(Current5);      

        delay(1500);
        
  lcd.clear();

        lcd.setCursor(0,0);lcd.print("Ip:");          lcd.setCursor(5,0);   lcd.print(myIP);      
        lcd.setCursor(0,1);lcd.print("Sn");          lcd.setCursor(5,1);   lcd.print(mySubnet); 
        lcd.setCursor(0,2);lcd.print("Gw:");          lcd.setCursor(5,2);  lcd.print(myGateWay);                
  //      lcd.setCursor(0,3);lcd.print("Mc:");          lcd.setCursor(5,3);  lcd.print(myMac);        
        delay(1800);      

 lcd.clear();
    lcd.setCursor(4,3);
    lcd.print("Site:"+Site);
    lcd.createChar(0, customChar1);
    lcd.createChar(1, customChar2);
    lcd.createChar(2, customChar3);
    lcd.createChar(3, customChar4);
    lcd.createChar(4, customChar5);
    lcd.createChar(5, customChar6);
  //  lcd.createChar(7, customChar6);
    lcd.setCursor(8,0);
    lcd.write((uint8_t)0);
    lcd.write((uint8_t)1);
    lcd.write((uint8_t)2);
    lcd.setCursor(8,1);
    lcd.write((uint8_t)3);
    lcd.write((uint8_t)4);
    lcd.write((uint8_t)5);
 delay(2000); 
     
 
     

    } 
private:
    uint8_t state;
    


    
} lcd_task;
