class ModbusTask : public Task { 
protected:

    void setup() { 
  
    }


void loop() {



                        



//Serial1.println("Modbus Task..");

 ///////////////////////////////////// Update By Waiwoot////////////////
 int S = 0 ;

              
             for (char i = 0; i < 40 ; i++) // 6 is  total Register
               {        
               
           ////////////////////////////////////////////   This Loop for 5 Mux   Open this comment !!
              
               if (i == 8 ||i == 16 ||i == 24||i == 32 )
                 {                 
                 ID_Slave = ID_Slave +1 ;  
                //  ID_Slave = ID_Slave ;                    
                  S = S+1 ;    
               }
             else
                    {            
                  ID_Slave = 1+S;                 
             
                                }                                  
            
        ////////////////////////////////////////////////    This Loop for 5 Mux  Open this comment !!
                
                     
          
                 Data_Slave [i] = Read_Slave_float(ID_Slave, Reg_addr[i]);
                 delay(100);
              //
               } 
               
          //     y = (y+6);  
                 
                 
                 
     ////////////////////////////////////////////

   //   unsigned long  randNumber1 = random(9234567890);          
     //    Mux1       = randNumber1;
          Mux1    = (Data_Slave[0]);  //Power Consumtion
        Power1     = (Data_Slave[1]/10);  //Active Power Consumtion
       Current1   = (Data_Slave[2])/1000;  //Current L1  A
       Current2   = (Data_Slave[3])/1000;  //Current L1  A
       Current3   = (Data_Slave[4])/1000;  //Current L1  A       
       Hz1        = (Data_Slave[5])*0.1;  //Frequency  Hz
       Factor1    = (Data_Slave[6])/100;  // Power Factor
       Volt1      = (Data_Slave[7])*0.1;     //Volt

       
   //   unsigned long     randNumr2 = random(9234567890); 
        Mux2    = (Data_Slave[8]);
        Power2     = (Data_Slave[9]/10);  //Volt L1 V
       Current4   = (Data_Slave[10])/1000;  //Current L1  A
       Current5   = (Data_Slave[11])/1000;  //Current L1  A
       Current6   = (Data_Slave[12])/1000;  //Current L1  A     
       Hz2        = (Data_Slave[13])*0.1;  //Frequency  Hz
       Factor2     = (Data_Slave[14])/100; // Active Power W    
       Volt2    = (Data_Slave[15])*0.1;

  //     unsigned long     randNumber3 = random(9234567890); 
         Mux3    = (Data_Slave[16]);
        Power3     = (Data_Slave[17]/10);  //Volt L1 V
       Current7   = (Data_Slave[18])/1000;  //Current L1  A
       Current8   = (Data_Slave[19])/1000;  //Current L1  A
       Current9   = (Data_Slave[20])/1000;  //Current L1  A     
       Hz3        = (Data_Slave[21])*0.1;  //Frequency  Hz
       Factor3    = (Data_Slave[22])/100;  // Active Power W 
       Volt3    = (Data_Slave[23])*0.1;

//   unsigned long     randNumber4 = random(9234567890); 
         Mux4    = (Data_Slave[24]);
        Power4     = (Data_Slave[25]/10);  //Volt L1 V
       Current10   = (Data_Slave[26])/1000;  //Current L1  A
       Current11  = (Data_Slave[27])/1000;  //Current L1  A
       Current12  = (Data_Slave[28])/1000;  //Current L1  A     
       Hz4        = (Data_Slave[29])*0.1;  //Frequency  Hz
       Factor4     = (Data_Slave[30])/100;  // Active Power W
       Volt4    = (Data_Slave[31])*0.1;

   //       unsigned long     randNumber5 = random(9234567890); 
      

           Mux5    = (Data_Slave[32]);
        Power5     = (Data_Slave[33]/10);  //Volt L1 V
       Current13   = (Data_Slave[34])/1000;  //Current L1  A
       Current14   = (Data_Slave[35])/1000;  //Current L1  A
       Current15   = (Data_Slave[36])/1000;  //Current L1  A     
       Hz5        = (Data_Slave[37])*0.1;  //Frequency  Hz
       Factor5     = (Data_Slave[38])/100;  // Active Power W
       Volt5    = (Data_Slave[39])*0.1;

  /*
             Mux5    = 0 ;
        Power5     = 0 ;  //Volt L1 V
       Current13   = 0 ;  //Current L1  A
       Current14   = 0 ;  //Current L1  A
       Current15   = 0 ;  //Current L1  A     
       Hz5        = 0 ;  //Frequency  Hz
       Factor5     = 0 ;  // Active Power W
       Volt5    = 0 ;          
            
     */     
            
      //      }    
    //        ID_Slave = 1 ; 
     //      y = 0 ;
}

private:
///////////////////////////VOID MODBUS READING /////////////////////////////////
   int ID_Slave = 1 ;
/*
  
  float HexTofloat1(uint32_t x) //แอดเดส 6แปลงทศนิยม 2ตำแหน่ง 
           {  
             uint32_t a   = (x *10)/10;
             return (a);  
                        }
                     
      float HexTofloat2(uint32_t x)//แปลง ส่วนของ Power Consumption
           {     
             uint32_t a = x;
              return (a);   
                         }

      float HexTofloat3(uint32_t x)
           {     
            //return (*(float*)&x);
             int a= 0 ;
             a= (x+a) ; 
            return (a);   
                         }
                         
     uint32_t FloatTohex(float x)
            {
               return (*(uint32_t*)&x);
                                       }

     float HexTofloat7(uint32_t x)
          {     
            //return (*(float*)&x);
             int a= 0 ;    
             a= (x*0.1) ; 
             return (a);   
                         }

                         */
//----------------------------------   


float Read_Slave_float(char addr , uint16_t REG)
   {
     float i = 0;
     uint8_t j;
 
     uint16_t data[2];
     uint32_t value =0;
////Serial.println(ID_Slave);
   
   node.begin(ID_Slave ,Serialnode);// communicate with Modbus slave ID over Serial (port SofwareSerial)

 //    result = node.readHoldingRegisters (REG,8); /// Modbus function 0x03 Read Holding Registers

    result = node.readHoldingRegisters (REG,2); /// Modbus function 0x03 Read Holding Registers

//if (result == node.ku8MBInvalidSlaveID) // 224
//if (result == node.ku8MBInvalidFunction)  //225
//if (result == node.ku8MBResponseTimedOut)  //226
//if (result == node.ku8MBInvalidCRC)  //227

/* static const uint8_t  ModbusMaster::ku8MBIllegalFunction = 0x01  Modbus protocol illegal function exception.  
static const uint8_t  ModbusMaster::ku8MBIllegalDataAddress = 0x02  Modbus protocol illegal data address exception.  
static const uint8_t  ModbusMaster::ku8MBIllegalDataValue = 0x03  Modbus protocol illegal data value exception. 
static const uint8_t  ModbusMaster::ku8MBSlaveDeviceFailure = 0x04  Modbus protocol slave device failure exception.  
static const uint8_t  ModbusMaster::ku8MBSuccess = 0x00  ModbusMaster success.  
static const uint8_t  ModbusMaster::ku8MBInvalidSlaveID = 0xE0  ModbusMaster invalid response slave ID exception.  
static const uint8_t  ModbusMaster::ku8MBInvalidFunction = 0xE1  ModbusMaster invalid response function exception.  
static const uint8_t  ModbusMaster::ku8MBResponseTimedOut = 0xE2  ModbusMaster response timed out exception.  
static const uint8_t  ModbusMaster::ku8MBInvalidCRC = 0xE3  ModbusMaster invalid response CRC exception. More...
*/
   
  if (result == node.ku8MBSuccess) 
     {
         for (j = 0; j < 2; j++)
             {
               data [j] = node.getResponseBuffer(j);
                                                    }   
                value = data[0];
                value = value << 16;
                value = value + data[1]; 
                 //หรือ value = data[0]<<16|data[1];  
            /*
                if (REG == 3 || REG == 9|| REG == 15 || REG == 21 || REG == 27)  //เช็คและเลือก แอดเดสที่ต้องแปลงหน่วยและค่า 
                   {   
                     i = HexTofloat7 (value);//เช็คและเลือก แอดเดสที่ต้องแปลงหน่วยและค่า Power Consumption                        }
                                   }                            
                    else  
                  if (REG==2) {              
                     i = HexTofloat2 (value);//เช็คและเลือก แอดเดสที่ต้องแปลงหน่วยและค่า Power Consumption
                                    } 
                     else   
                   if ( REG == 4 || REG == 10|| REG == 16 || REG == 22 || REG == 26) {              
                     i = HexTofloat7 (value);//เช็คและเลือก แอดเดสที่ต้องแปลงหน่วยและค่า Power Factor *0.1
                                    }  
                                   
                         else {
         
                              //  i = HexTofloat3 (value);

                                 i = value;
                                   }                
                      */  

// Serial.print ("Connect Modbus Ok. ReG...> ");Serial.print ("="); Serial.print (i);Serial.println (":");   
     
     return value ;
  } 
   else
   {
    delay(300);
  return 0 ;
   }
}

///////////////////// Write Value to Modbus


///////////////////////////VOID MODBUS READING /////////////////////////////////
    
    
} modbus_task;
