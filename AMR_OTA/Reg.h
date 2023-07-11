
const char* ssid    ;
const char* password ;


String Site = ("AMR_OTA");
static char locLocation[20]    = "AMR_OTA" ; //   ใช้สำหรับ SNMP


//String Mac_Address = "E8:DB:84:DC:E8:7E";  //ESP.getChip  14477438
String Mac_Address ;  //ESP.getChip  14477438
byte mac[6] ;


int FW_VERSION = 3 ;

String UpdateTime = "30-5-2023";
//const char* firmwareUrlBase = "http://10.0.1.223/firmware/";
const char* firmwareUrlBase = "http://www.doopper.com/amr/firmware/";
String firmware_name = ""+String(Site)+".ino.nodemcu";






 #define Total_of_Reg  40  //30ค่าเดิม

 
  # define Address1 31 //Power Consumption (kWh)  OK
    # define Address2 8//Active Power  W  OK
      # define Address3 3//L1 Current A
       # define Address4 4//L2 Current A
        # define Address5 5//L3 Current A
         # define Address6 7//Frequency  Hz        
          # define Address7 6 //power factor
            # define Address8 0 //Volt
  
 #define Reg_1   Address1     /////////////////Mux1///////////////////
 #define Reg_2   Address2      /////////////////Mux1///////////////////
 #define Reg_3    Address3        /////////////////Mux1///////////////////
 #define Reg_4    Address4              /////////////////Mux1///////////////////
  #define Reg_5   Address5                   /////////////////Mux1///////////////////
 #define Reg_6    Address6                         /////////////////Mux1/////////////////// 
 #define Reg_7    Address7
 #define Reg_8    Address8

 
 #define Reg_9    Address1
  #define Reg_10  Address2
 #define Reg_11  Address3
 #define Reg_12    Address4
 #define Reg_13   Address5
 #define Reg_14   Address6
 #define Reg_15    Address7
  #define Reg_16   Address8


  
 #define Reg_17   Address1
 #define Reg_18    Address2
  #define Reg_19    Address3
 #define Reg_20    Address4
 #define Reg_21    Address5
  #define Reg_22  Address6
 #define Reg_23   Address7
 #define Reg_24    Address8

  #define Reg_25    Address1
 #define Reg_26   Address2
 #define Reg_27   Address3
  #define Reg_28  Address4
 #define Reg_29   Address5
 #define Reg_30    Address6
  #define Reg_31    Address7
   #define Reg_32   Address8

  #define Reg_33    Address1
 #define Reg_34  Address2
 #define Reg_35  Address3
  #define Reg_36  Address4
 #define Reg_37   Address5
  #define Reg_38    Address6
  #define Reg_39   Address7
  #define Reg_40   Address8


uint16_t Reg_addr[40] = {
                     
                        Reg_1,
                        Reg_2,
                        Reg_3,
                        Reg_4,   
                        Reg_5,                          
                        Reg_6,
                        Reg_7,
                        Reg_8,
                        Reg_9,
                        Reg_10,
                       Reg_11,
                         Reg_12,
                         Reg_13,
                        Reg_14,
                        Reg_15,
                        Reg_16,   
                        Reg_17,                          
                        Reg_18,
                        Reg_19,
                        Reg_20,
                        Reg_21,
                        Reg_22,
                        Reg_23,
                         Reg_24,
                        Reg_25,
                        Reg_26,
                        Reg_27,
                        Reg_28,   
                        Reg_29,                          
                        Reg_30,
                        Reg_31,
                         Reg_32,
                         Reg_33,
                        Reg_34,
                        Reg_35,
                        Reg_36,   
                        Reg_37,                          
                        Reg_38,
                        Reg_39,
                        Reg_40,
                       
                      
};
float Data_Slave[Total_of_Reg];
//uint8_t Data_Slave[Total_of_Reg];
