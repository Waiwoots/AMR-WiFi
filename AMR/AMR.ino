


#include <ArduinoOTA.h>
#include <UIPEthernet.h>

#include <ArduinoJson.h>

#include <Streaming.h>         // Include the Streaming library
#include <SPI.h>
#include <MemoryFree.h>
#include <UIPAgentuino.h> 

#include <SoftwareSerial.h>
#include <ESP8266httpUpdate.h>



#include <FS.h>
#include <LittleFS.h>
//#include <SPIFFS.h>
#include <ModbusMaster.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "Reg.h";
#include "logo.h";

#include <Scheduler.h> 
#include<Task.h>

#include <EEPROM.h>

 /*
#define NET_ENC28J60_EIR          0x1C
#define NET_ENC28J60_ESTAT        0x1D
#define NET_ENC28J60_ECON1        0x1F
#define NET_ENC28J60_EIR_RXERIF   0x01
#define NET_ENC28J60_ESTAT_BUFFER 0x40
#define NET_ENC28J60_ECON1_RXEN   0x04


#define iwdg_init_ms(N)
*/

unsigned long  CHECK_PERIOD =604800000 ; //54000360 = 15 DAY
#define ETH_RS_PIN D4
//unsigned long timer;




unsigned long previousMillis,previousMillis2 = 0;        // will store last time LED was updated
long s, mo, h, d, m, y, mm, ss, hh, _mo, yy;
long sec;



String inStr; 
String Website,data,XML,Javascript;
//int Rand,Rand2,Rand3,Rand4,Rand5;
 String LOGO  ;

ModbusMaster node;

SoftwareSerial Serialnode(D3, D0); 


int x ;


int ModbusSet = 0;  
boolean stateSend = 0;

LiquidCrystal_I2C lcd(0x27,20,4);

  //byte mac[] = {0x54,0x34,0x41,0x30,0x30,0x30};
  byte ip[4];
  byte subnet[4];
  byte gateway[4];

  String myIP ;
  String mySubnet ;
  String myGateWay ;
  String myMac ;

 // int LanFailCount = 0;
  ADC_MODE(ADC_VCC);


//EthernetServer  server(80);

EthernetServer server = EthernetServer(80);
EthernetClient  client;






   int changingNumber = 1;
   int settableNumber = 0;





static char sysDescr[] PROGMEM      = "1.3.6.1.2.1.1.1.0";  // read-only  (DisplayString)

static char sysUpTime[] PROGMEM     = "1.3.6.1.2.1.1.3.0";  // read-only  (TimeTicks)
// .iso.org.dod.internet.mgmt.mib-2.system.sysContact (.1.3.6.1.2.1.1.4)
static char sysContact[] PROGMEM    = "1.3.6.1.2.1.1.4.0";  // read-write (DisplayString)
// .iso.org.dod.internet.mgmt.mib-2.system.sysName (.1.3.6.1.2.1.1.5)
static char sysName[] PROGMEM       = "1.3.6.1.2.1.1.5.0";  // read-write (DisplayString)
// .iso.org.dod.internet.mgmt.mib-2.system.sysLocation (.1.3.6.1.2.1.1.6)
static char sysLocation[] PROGMEM   = "1.3.6.1.2.1.1.6.0";  // read-write (DisplayString)
// .iso.org.dod.internet.mgmt.mib-2.system.sysServices (.1.3.6.1.2.1.1.7)
static char sysServices[] PROGMEM   = "1.3.6.1.2.1.1.7.0";  // read-only  (Integer)
static char sysServices1[] PROGMEM   = "1.3.6.1.2.1.1.7.1";  // read-only  (Integer)
static char sysServices2[] PROGMEM   = "1.3.6.1.2.1.1.7.2";  // read-only  (Integer)
static char sysServices3[] PROGMEM   = "1.3.6.1.2.1.1.7.3";  // read-only  (Integer)
static char sysServices4[] PROGMEM   = "1.3.6.1.2.1.1.7.4";  // read-only  (Integer)
static char sysServices5[] PROGMEM   = "1.3.6.1.2.1.1.7.5";  // read-only  (Integer)
static char sysServices6[] PROGMEM   = "1.3.6.1.2.1.1.7.6";  // read-only  (Integer)

static char sysServices7[] PROGMEM   = "1.3.6.1.2.1.1.7.7.1.1";  // read-only  (Integer)
static char sysServices8[] PROGMEM   = "1.3.6.1.2.1.1.7.7.1.2";  // read-only  (Integer)
static char sysServices9[] PROGMEM   = "1.3.6.1.2.1.1.7.7.1.3";  // read-only  (Integer)
static char sysServices10[] PROGMEM   = "1.3.6.1.2.1.1.7.7.1.4";  // read-only  (Integer)
static char sysServices11[] PROGMEM   = "1.3.6.1.2.1.1.7.7.1.5";  // read-only  (Integer)
static char sysServices12[] PROGMEM   = "1.3.6.1.2.1.1.7.7.1.6";  // read-only  (Integer)

static char sysServices13[] PROGMEM   = "1.3.6.1.2.1.1.7.7.2.1";  // read-only  (Integer)
static char sysServices14[] PROGMEM   = "1.3.6.1.2.1.1.7.7.2.2";  // read-only  (Integer)
static char sysServices15[] PROGMEM   = "1.3.6.1.2.1.1.7.7.2.3";  // read-only  (Integer)
static char sysServices16[] PROGMEM   = "1.3.6.1.2.1.1.7.7.2.4";  // read-only  (Integer)
static char sysServices17[] PROGMEM   = "1.3.6.1.2.1.1.7.7.2.5";  // read-only  (Integer)
static char sysServices18[] PROGMEM   = "1.3.6.1.2.1.1.7.7.2.6";  // read-only  (Integer)

static char sysServices19[] PROGMEM   = "1.3.6.1.2.1.1.7.7.3.1";  // read-only  (Integer)
static char sysServices20[] PROGMEM   = "1.3.6.1.2.1.1.7.7.3.2";  // read-only  (Integer)
static char sysServices21[] PROGMEM   = "1.3.6.1.2.1.1.7.7.3.3";  // read-only  (Integer)
static char sysServices22[] PROGMEM   = "1.3.6.1.2.1.1.7.7.3.4";  // read-only  (Integer)
static char sysServices23[] PROGMEM   = "1.3.6.1.2.1.1.7.7.3.5";  // read-only  (Integer)
static char sysServices24[] PROGMEM   = "1.3.6.1.2.1.1.7.7.3.6";  // read-only  (Integer)

static char sysServices25[] PROGMEM   = "1.3.6.1.2.1.1.7.7.4.1";  // read-only  (Integer)
static char sysServices26[] PROGMEM   = "1.3.6.1.2.1.1.7.7.4.2";  // read-only  (Integer)
static char sysServices27[] PROGMEM   = "1.3.6.1.2.1.1.7.7.4.3";  // read-only  (Integer)
static char sysServices28[] PROGMEM   = "1.3.6.1.2.1.1.7.7.4.4";  // read-only  (Integer)
static char sysServices29[] PROGMEM   = "1.3.6.1.2.1.1.7.7.4.5";  // read-only  (Integer)
static char sysServices30[] PROGMEM   = "1.3.6.1.2.1.1.7.7.4.6";  // read-only  (Integer)

static char sysServices31[] PROGMEM   = "1.3.6.1.2.1.1.7.7.5.1";  // read-only  (Integer)
static char sysServices32[] PROGMEM   = "1.3.6.1.2.1.1.7.7.5.2";  // read-only  (Integer)
static char sysServices33[] PROGMEM   = "1.3.6.1.2.1.1.7.7.5.3";  // read-only  (Integer)
static char sysServices34[] PROGMEM   = "1.3.6.1.2.1.1.7.7.5.4";  // read-only  (Integer)
static char sysServices35[] PROGMEM   = "1.3.6.1.2.1.1.7.7.5.5";  // read-only  (Integer)
static char sysServices36[] PROGMEM   = "1.3.6.1.2.1.1.7.7.5.6";  // read-only  (Integer)
// Arduino defined OIDs
// .iso.org.dod.internet.private (.1.3.6.1.4)
// .iso.org.dod.internet.private.enterprises (.1.3.6.1.4.1)
// .iso.org.dod.internet.private.enterprises.arduino (.1.3.6.1.4.1.36582)
//
//
// RFC1213 local values
static char locDescr[]              = "Automatic Meter  Reading";  // read-only (static)
//static char locObjectID[]         = "1.3.6.1.3.2009.0";                       // read-only (static)
static uint32_t locUpTime           = 0;                                        // read-only (static)
static char locContact[20]          = "AMR";                         // should be stored/read from EEPROM - read/write (not done for simplicity)
static char locName[20]             = "TPBS";                              // should be stored/read from EEPROM - read/write (not done for simplicity)
//static char locLocation[20]         = site ;                         // should be stored/read from EEPROM - read/write (not done for simplicity)
static int32_t locServices          = 6;                                        // read-only (static)


                                      // read-only (static)



  
//locServices1,
static int32_t locServices1,locServices2,locServices3,locServices4,locServices5,locServices6; 

static int32_t locServices7,locServices8,locServices9,locServices10; 
static int32_t locServices11,locServices12,locServices13,locServices14,locServices15; 
static int32_t locServices16,locServices17,locServices18,locServices19,locServices20;  
static int32_t locServices21,locServices22,locServices23,locServices24,locServices25; 
static int32_t locServices26,locServices27,locServices28,locServices29,locServices30; 
static int32_t locServices31,locServices32,locServices33,locServices34,locServices35,locServices36; 
uint32_t prevMillis = millis();
char oid[SNMP_MAX_OID_LEN];
SNMP_API_STAT_CODES api_status;
SNMP_ERR_CODES status;

void pduReceived()
{
  SNMP_PDU pdu;
  api_status = Agentuino.requestPdu(&pdu);
  //
  if ((pdu.type == SNMP_PDU_GET || pdu.type == SNMP_PDU_GET_NEXT|| pdu.type == SNMP_PDU_SET ) // || pdu.type == SNMP_PDU_SET
    && pdu.error == SNMP_ERR_NO_ERROR && api_status == SNMP_API_STAT_SUCCESS ) {
    //
    pdu.OID.toString(oid);
    // Implementation SNMP GET NEXT
    if ( pdu.type == SNMP_PDU_GET_NEXT ) {
      char tmpOIDfs[SNMP_MAX_OID_LEN];
      if ( strcmp_P( oid, sysDescr ) == 0 ) {  
        strcpy_P ( oid, sysUpTime ); 
        strcpy_P ( tmpOIDfs, sysUpTime );        
        pdu.OID.fromString(tmpOIDfs);  
      } else if ( strcmp_P(oid, sysUpTime ) == 0 ) {  
        strcpy_P ( oid, sysContact );  
        strcpy_P ( tmpOIDfs, sysContact );        
        pdu.OID.fromString(tmpOIDfs);          
      } else if ( strcmp_P(oid, sysContact ) == 0 ) {  
        strcpy_P ( oid, sysName );  
        strcpy_P ( tmpOIDfs, sysName );        
        pdu.OID.fromString(tmpOIDfs);                  
      } else if ( strcmp_P(oid, sysName ) == 0 ) {  
        strcpy_P ( oid, sysLocation );  
        strcpy_P ( tmpOIDfs, sysLocation );        
        pdu.OID.fromString(tmpOIDfs);                  
      } else if ( strcmp_P(oid, sysLocation ) == 0 ) {  
        strcpy_P ( oid, sysServices );  
        strcpy_P ( tmpOIDfs, sysServices );        
        pdu.OID.fromString(tmpOIDfs);                  
      } else if ( strcmp_P(oid, sysServices ) == 0 ) {  
        strcpy_P ( oid, sysServices1 );
        strcpy_P ( tmpOIDfs, sysServices1 );        
        pdu.OID.fromString(tmpOIDfs);        
      } else if ( strcmp_P(oid, sysServices1 ) == 0 ) {  
        strcpy_P ( oid, sysServices2 );
        strcpy_P ( tmpOIDfs, sysServices2 );        
        pdu.OID.fromString(tmpOIDfs);     
      } else if ( strcmp_P(oid, sysServices2 ) == 0 ) {  
        strcpy_P ( oid, sysServices3 );
        strcpy_P ( tmpOIDfs, sysServices3 );        
        pdu.OID.fromString(tmpOIDfs);       
      } else if ( strcmp_P(oid, sysServices3 ) == 0 ) {  
        strcpy_P ( oid, sysServices4 );
        strcpy_P ( tmpOIDfs, sysServices4 );        
        pdu.OID.fromString(tmpOIDfs);        
      } else if ( strcmp_P(oid, sysServices4 ) == 0 ) {  
        strcpy_P ( oid, sysServices5);
        strcpy_P ( tmpOIDfs, sysServices5 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices5 ) == 0 ) {  
        strcpy_P ( oid, sysServices6);
        strcpy_P ( tmpOIDfs, sysServices6 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices6 ) == 0 ) {  
        strcpy_P ( oid, sysServices7);
        strcpy_P ( tmpOIDfs, sysServices7 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices7 ) == 0 ) {  
        strcpy_P ( oid, sysServices8);
        strcpy_P ( tmpOIDfs, sysServices8 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices8) == 0 ) {  
        strcpy_P ( oid, sysServices9);
        strcpy_P ( tmpOIDfs, sysServices9 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices9 ) == 0 ) {  
        strcpy_P ( oid, sysServices10);
        strcpy_P ( tmpOIDfs, sysServices10 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices10 ) == 0 ) {  
        strcpy_P ( oid, sysServices11);
        strcpy_P ( tmpOIDfs, sysServices11 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices11 ) == 0 ) {  
        strcpy_P ( oid, sysServices12);
        strcpy_P ( tmpOIDfs, sysServices12 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices12 ) == 0 ) {  
        strcpy_P ( oid, sysServices13);
        strcpy_P ( tmpOIDfs, sysServices13 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices13 ) == 0 ) {  
        strcpy_P ( oid, sysServices14);
        strcpy_P ( tmpOIDfs, sysServices14 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices14 ) == 0 ) {  
        strcpy_P ( oid, sysServices15);
        strcpy_P ( tmpOIDfs, sysServices15 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices15 ) == 0 ) {  
        strcpy_P ( oid, sysServices16);
        strcpy_P ( tmpOIDfs, sysServices16 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices16 ) == 0 ) {  
        strcpy_P ( oid, sysServices17);
        strcpy_P ( tmpOIDfs, sysServices17 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices17 ) == 0 ) {  
        strcpy_P ( oid, sysServices18);
        strcpy_P ( tmpOIDfs, sysServices18 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices18 ) == 0 ) {  
        strcpy_P ( oid, sysServices19);
        strcpy_P ( tmpOIDfs, sysServices19 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices19 ) == 0 ) {  
        strcpy_P ( oid, sysServices20);
        strcpy_P ( tmpOIDfs, sysServices20 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices20 ) == 0 ) {  
        strcpy_P ( oid, sysServices21);
        strcpy_P ( tmpOIDfs, sysServices21 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices21 ) == 0 ) {  
        strcpy_P ( oid, sysServices22);
        strcpy_P ( tmpOIDfs, sysServices22 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices22 ) == 0 ) {  
        strcpy_P ( oid, sysServices23);
        strcpy_P ( tmpOIDfs, sysServices23 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices23 ) == 0 ) {  
        strcpy_P ( oid, sysServices24);
        strcpy_P ( tmpOIDfs, sysServices24 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices24 ) == 0 ) {  
        strcpy_P ( oid, sysServices25);
        strcpy_P ( tmpOIDfs, sysServices25 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices25 ) == 0 ) {  
        strcpy_P ( oid, sysServices26);
        strcpy_P ( tmpOIDfs, sysServices26 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices26 ) == 0 ) {  
        strcpy_P ( oid, sysServices27);
        strcpy_P ( tmpOIDfs, sysServices27);        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices27) == 0 ) {  
        strcpy_P ( oid, sysServices28);
        strcpy_P ( tmpOIDfs, sysServices28 );        
        pdu.OID.fromString(tmpOIDfs);   

            
      }else if ( strcmp_P(oid, sysServices28 ) == 0 ) {  
        strcpy_P ( oid, sysServices29);
        strcpy_P ( tmpOIDfs, sysServices29 );        
        pdu.OID.fromString(tmpOIDfs);   

            

            
      }else if ( strcmp_P(oid, sysServices29 ) == 0 ) {  
        strcpy_P ( oid, sysServices30);
        strcpy_P ( tmpOIDfs, sysServices30 );        
        pdu.OID.fromString(tmpOIDfs);   

            

            
      }else if ( strcmp_P(oid, sysServices30 ) == 0 ) {  
        strcpy_P ( oid, sysServices31);
        strcpy_P ( tmpOIDfs, sysServices31 );        
        pdu.OID.fromString(tmpOIDfs);   

            

            
      }else if ( strcmp_P(oid, sysServices31 ) == 0 ) {  
        strcpy_P ( oid, sysServices32);
        strcpy_P ( tmpOIDfs, sysServices32 );        
        pdu.OID.fromString(tmpOIDfs);   

            

            
      }else if ( strcmp_P(oid, sysServices32 ) == 0 ) {  
        strcpy_P ( oid, sysServices33);
        strcpy_P ( tmpOIDfs, sysServices33 );        
        pdu.OID.fromString(tmpOIDfs);   

            

            
      }else if ( strcmp_P(oid, sysServices33 ) == 0 ) {  
        strcpy_P ( oid, sysServices34);
        strcpy_P ( tmpOIDfs, sysServices34 );        
        pdu.OID.fromString(tmpOIDfs);   

         

            
      }else if ( strcmp_P(oid, sysServices34 ) == 0 ) {  
        strcpy_P ( oid, sysServices35);
        strcpy_P ( tmpOIDfs, sysServices35 );        
        pdu.OID.fromString(tmpOIDfs);   

         

            
      }else if ( strcmp_P(oid, sysServices35 ) == 0 ) {  
        strcpy_P ( oid, sysServices36);
        strcpy_P ( tmpOIDfs, sysServices36 );        
        pdu.OID.fromString(tmpOIDfs);   

         

            
      } else if ( strcmp_P(oid, sysServices36 ) == 0 ) {       
        strcpy_P ( oid, "1.0" );    

          
      }else {
          int ilen = strlen(oid);
          if ( strncmp_P(oid, sysDescr, ilen ) == 0 ) {
            strcpy_P ( oid, sysDescr ); 
            strcpy_P ( tmpOIDfs, sysDescr );        
            pdu.OID.fromString(tmpOIDfs); 
          } else if ( strncmp_P(oid, sysUpTime, ilen ) == 0 ) {
            strcpy_P ( oid, sysUpTime ); 
            strcpy_P ( tmpOIDfs, sysUpTime );        
            pdu.OID.fromString(tmpOIDfs); 
          } else if ( strncmp_P(oid, sysContact, ilen ) == 0 ) {
            strcpy_P ( oid, sysContact ); 
            strcpy_P ( tmpOIDfs, sysContact );        
            pdu.OID.fromString(tmpOIDfs); 
          } else if ( strncmp_P(oid, sysName, ilen ) == 0 ) {
            strcpy_P ( oid, sysName ); 
            strcpy_P ( tmpOIDfs, sysName );        
            pdu.OID.fromString(tmpOIDfs);   
          } else if ( strncmp_P(oid, sysLocation, ilen ) == 0 ) {
            strcpy_P ( oid, sysLocation ); 
            strcpy_P ( tmpOIDfs, sysLocation );        
            pdu.OID.fromString(tmpOIDfs);    
            } else if ( strncmp_P(oid, sysServices, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices ); 
            strcpy_P ( tmpOIDfs, sysServices );        
            pdu.OID.fromString(tmpOIDfs);  
            }else if ( strncmp_P(oid, sysServices1, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices1 ); 
            strcpy_P ( tmpOIDfs, sysServices1 );        
            pdu.OID.fromString(tmpOIDfs);  
            }else if ( strncmp_P(oid, sysServices2, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices2 ); 
            strcpy_P ( tmpOIDfs, sysServices2 );        
            pdu.OID.fromString(tmpOIDfs);  
            }else if ( strncmp_P(oid, sysServices3, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices3 ); 
            strcpy_P ( tmpOIDfs, sysServices3 );        
            pdu.OID.fromString(tmpOIDfs);  
            }else if ( strncmp_P(oid, sysServices4, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices4 ); 
            strcpy_P ( tmpOIDfs, sysServices4 );        
            pdu.OID.fromString(tmpOIDfs);  
            }else if ( strncmp_P(oid, sysServices5, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices5 ); 
            strcpy_P ( tmpOIDfs, sysServices5 );        
            pdu.OID.fromString(tmpOIDfs);  
            }else if ( strncmp_P(oid, sysServices6, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices6 ); 
            strcpy_P ( tmpOIDfs, sysServices6 );        
            pdu.OID.fromString(tmpOIDfs);  
            } 
            else if ( strncmp_P(oid, sysServices7, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices7 ); 
            strcpy_P ( tmpOIDfs, sysServices7 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices8, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices8 ); 
            strcpy_P ( tmpOIDfs, sysServices8 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices9, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices9 ); 
            strcpy_P ( tmpOIDfs, sysServices9 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices10, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices10 ); 
            strcpy_P ( tmpOIDfs, sysServices10 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices11, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices11 ); 
            strcpy_P ( tmpOIDfs, sysServices11 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices12, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices12 ); 
            strcpy_P ( tmpOIDfs, sysServices12 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices13, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices13 ); 
            strcpy_P ( tmpOIDfs, sysServices13 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices14, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices14 ); 
            strcpy_P ( tmpOIDfs, sysServices14 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices15, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices15 ); 
            strcpy_P ( tmpOIDfs, sysServices15 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices16, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices16 ); 
            strcpy_P ( tmpOIDfs, sysServices16 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices17, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices17 ); 
            strcpy_P ( tmpOIDfs, sysServices17 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices18, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices18 ); 
            strcpy_P ( tmpOIDfs, sysServices18 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices19, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices19 ); 
            strcpy_P ( tmpOIDfs, sysServices19 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices20, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices20 ); 
            strcpy_P ( tmpOIDfs, sysServices20 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices21, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices21 ); 
            strcpy_P ( tmpOIDfs, sysServices21);        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices22, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices22 ); 
            strcpy_P ( tmpOIDfs, sysServices22 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices23, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices23 ); 
            strcpy_P ( tmpOIDfs, sysServices23 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices24, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices24 ); 
            strcpy_P ( tmpOIDfs, sysServices24 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices25, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices25 ); 
            strcpy_P ( tmpOIDfs, sysServices25 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices26, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices26 ); 
            strcpy_P ( tmpOIDfs, sysServices26 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices27, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices27 ); 
            strcpy_P ( tmpOIDfs, sysServices27 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices28, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices28 ); 
            strcpy_P ( tmpOIDfs, sysServices28 );        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices29, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices29 ); 
            strcpy_P ( tmpOIDfs, sysServices29);        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices30, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices30 ); 
            strcpy_P ( tmpOIDfs, sysServices30);        
            pdu.OID.fromString(tmpOIDfs);  
            }else if ( strncmp_P(oid, sysServices31, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices31 ); 
            strcpy_P ( tmpOIDfs, sysServices31);        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices32, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices32 ); 
            strcpy_P ( tmpOIDfs, sysServices32);        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices33, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices33 ); 
            strcpy_P ( tmpOIDfs, sysServices33);        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices34, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices34 ); 
            strcpy_P ( tmpOIDfs, sysServices34);        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices35, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices35 ); 
            strcpy_P ( tmpOIDfs, sysServices35);        
            pdu.OID.fromString(tmpOIDfs);  
            } else if ( strncmp_P(oid, sysServices36, ilen ) == 0 ) {
            strcpy_P ( oid, sysServices36 ); 
            strcpy_P ( tmpOIDfs, sysServices36);        
            pdu.OID.fromString(tmpOIDfs);  
            }     
      } 
    }
    // End of implementation SNMP GET NEXT / WALK
    
    if ( strcmp_P(oid, sysDescr ) == 0 ) {
      // handle sysDescr (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
       //response packet from set-request - object is read-only
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locDescr
        status = pdu.VALUE.encode(SNMP_SYNTAX_OCTETS, locDescr);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      //
    } else if ( strcmp_P(oid, sysUpTime ) == 0 ) {
      // handle sysName (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locUpTime
        status = pdu.VALUE.encode(SNMP_SYNTAX_TIME_TICKS, locUpTime);       
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      //
    } else if ( strcmp_P(oid, sysName ) == 0 ) {
      // handle sysName (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read/write
        status = pdu.VALUE.decode(locName, strlen(locName)); 
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      } else {
        // response packet from get-request - locName
        status = pdu.VALUE.encode(SNMP_SYNTAX_OCTETS, locName);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      //
    } else if ( strcmp_P(oid, sysContact ) == 0 ) {
      // handle sysContact (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read/write
        status = pdu.VALUE.decode(locContact, strlen(locContact)); 
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      } else {
        // response packet from get-request - locContact
        status = pdu.VALUE.encode(SNMP_SYNTAX_OCTETS, locContact);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      //
    } else if ( strcmp_P(oid, sysLocation ) == 0 ) {
      // handle sysLocation (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read/write
        status = pdu.VALUE.decode(locLocation, strlen(locLocation)); 
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      } else {
        // response packet from get-request - locLocation
        status = pdu.VALUE.encode(SNMP_SYNTAX_OCTETS, locLocation);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      //
    } else if ( strcmp_P(oid, sysServices) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      //
    }else if ( strcmp_P(oid, sysServices1) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        //response packet from set-request - object is read-only
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices1);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      //
    }else if ( strcmp_P(oid, sysServices2) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices2);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      //
    }else if ( strcmp_P(oid, sysServices3) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices3);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      //
    }else if ( strcmp_P(oid, sysServices4) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices4);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      //
    }else if ( strcmp_P(oid, sysServices5) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {

      // response packet from set-request - object is read-only
         
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY; 
     
        
      } else {
             // response packet from get-request - locServices
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices5);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;    
          
      }
      //
    }else if ( strcmp_P(oid, sysServices6) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices6);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices7) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices7);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }  
      }else if ( strcmp_P(oid, sysServices8) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices8);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices9) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices9);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices10) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices10);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices11) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices11);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices12) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices12);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices13) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices13);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices14) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices14);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices15) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices15);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices16) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices16);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices17) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices17);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices18) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices18);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices19) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices19);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices20) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices20);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices21) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices21);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices22) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices22);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices23) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices23);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices24) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices24);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices25) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices25);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices26) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices26);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices27) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices27);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices28) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices28);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices29) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices29);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      }else if ( strcmp_P(oid, sysServices30) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices30);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      
      
      //
    }else if ( strcmp_P(oid, sysServices31) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices31);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      
      
      //
    }else if ( strcmp_P(oid, sysServices32) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices32);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      
      
      //
    }else if ( strcmp_P(oid, sysServices33) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices33);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      
      
      //
    }else if ( strcmp_P(oid, sysServices34) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices34);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      
      
      //
    }else if ( strcmp_P(oid, sysServices35) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices35);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      
      
      //
    }else if ( strcmp_P(oid, sysServices36) == 0 ) {
      // handle sysServices (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
          
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locServices

        //ESP.restart() ;  
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, locServices36);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      
      
      //
    } else {
      // oid does not exist
      // response packet - object not found
      pdu.type = SNMP_PDU_RESPONSE;
      pdu.error = SNMP_ERR_NO_SUCH_NAME;
    }
    //
    Agentuino.responsePdu(&pdu);
  }
  //
 //Agentuino.freePdu(&pdu);
  //
}
////////////////////////////////////snmp2/////////////////////

//#define LedGreen 9
//#define LedRed   8


//unsigned int regs[TOTAL_NO_OF_REGISTERS];


unsigned int data0,data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18,data19,
             data20,data21,data22,data23,data24,data25,data26,data27,data28,data29,data30,Power,PowerMux1, A_PowerMux1,PowerMux2,PowerMux3,PowerMux4,PowerMux5,Volt,Volt_Point,Hz,HZ,Hz_Point;

        //uint8_t Mux1,Mux2,Mux3,Mux4,Mux5,Mux6;
   
      unsigned long  Mux1 ,Mux2,Mux3,Mux4,Mux5,reboot;

      uint32_t  Volt1 ,Hz1 ,Power1,
                Volt2 ,Hz2 ,Power2,
                Volt3 ,Hz3 ,Power3,
                Volt4 ,Hz4 ,Power4,
                Volt5 ,Hz5 ,Power5;

        float Factor1,Factor2,Factor3,Factor4,Factor5,Current1,Current2,Current3,Current4,Current5,Current6,Current7,Current8,Current9,Current10,Current11,Current12,Current13,Current14,Current15;
      //   String  factor1,factor2,factor3,factor4,factor5;
               
      
 
        uint8_t result;
        uint16_t REG ;
        
         //unsigned long Mux1,Mux2,Mux3,Mux4,Mux5;
        uint8_t   xBlink_type = 0;   // 0: กระพริบช้า, 1: กระพริบเร็ว



 // digitalWrite(led, 1);

///////////////////// void Task 1//////////////
#include "Task1.h";
#include "Task2.h";
#include "Task3.h";
#include "Task4.h";

#include "Task6.h";




//----
void setup() {
//  Serial.begin(9600,SERIAL_8N1);// ยกเลิก Debug ใช้สื่อสารติดต่อระว่าง ESP8266(1) กับ ESP8266(2)
   
    Serial.begin(4800);// ยกเลิก Debug ใช้สื่อสารติดต่อระว่าง ESP8266(1) กับ ESP8266(2)///
 
    
   while (!Serial) continue;
 // Serial1.begin(9600);//  ** Modbus Module
 // void begin(long speed, int stopbits = 2, char parity = 'E', int databits=5);
  pinMode(D0, OUTPUT);  // For TX Modbus
  pinMode(D3, OUTPUT);  // For RX Modbus
  Serialnode.begin(4800,SWSERIAL_8N2); // Modbus   Speed parameter
 // customSerial->begin(9600, CSERIAL_8E2); 
  
//  Serial.println("Start...");



////////////////////////EEPROM/////////////
Serial.println("BEGIN");
Serial.print("ESP.getChip:");
Serial.println(ESP.getChipId());
Site = Id_Station(ESP.getChipId());
EEPROM.begin(512);

delay(500);
   pinMode(D7, INPUT_PULLUP);
delay(200);   
   int buttonState = digitalRead(D7); // อ่านค่าสถานะขาD3
   
 
if  ( buttonState == LOW)//เงื่อนไขการกดสวิท เรียกค่าดีฟอลด์
   {
    byte ipDef[]      = {192,168,1,100};
    byte gatewayDef[] = {192,168,1,1};
    byte subnetDef[]  = {255,255,255,0};

                int j = 4;
                int k = 8;
       
          for (int i = 0 ; i < 4; i++ ) {
               EEPROM.put(i,ipDef[i]);                  
               EEPROM.put(j,gatewayDef[i]);
               EEPROM.put(k,subnetDef[i]);                     
       /*        Serial.print(i);Serial.print(" : ");Serial.println(ipDef[i]);
               Serial.print(j);Serial.print(" : ");Serial.println(gatewayDef[i]);
               Serial.print(k);Serial.print(" : ");Serial.println(subnetDef[i]);
        */
               j++ ;
               k++ ;
           
          //   Serial.print("update: ");Serial.println(ipDef[i]); 


          

  // actually write the content of byte-array cache to
  // hardware flash.  flash write occurs if and only if one or more byte
  // in byte-array cache has been changed, but if so, ALL 512 bytes are 
  // written to flash
    EEPROM.commit();  


    
           }
      }
      else
        {  Serial.print("D7 Not Low");
          }

                int j = 4;
                int k = 8;
           for ( int i=0 ; i < 4; i++ ){      
               EEPROM.get(i,ip[i]);  
               EEPROM.get(j,gateway[i]);
               EEPROM.get(k,subnet[i]);              
           //    Serial.print(i);Serial.print("  : ");Serial.println(ip[i]);
           //    Serial.print(j);Serial.print("  : ");Serial.println(gateway[i]);
          //     Serial.print(k);Serial.print("  : ");Serial.println(subnet[i]);

               j++ ;
               k++ ;
               }

        myIP = ""+String(ip[0])+"."+String(ip[1])+"."+String(ip[2])+"."+String(ip[3]);
        mySubnet   = ""+String(subnet[0])+"."+String(subnet[1])+"."+String(subnet[2])+"."+String(subnet[3]);
        myGateWay  = ""+String(gateway[0])+"."+String(gateway[1])+"."+String(gateway[2])+"."+String(gateway[3]);
        myMac      = ""+String(mac[0])+"."+String(mac[1])+"."+String(mac[2])+"."+String(mac[3])+"."+String(mac[4])+"."+String(mac[5]);


Serial.print(myIP);

delay(2000);

////////////////////////EEPROM/////////////


  Ethernet.begin(mac, ip, subnet, gateway);
//httpUpdater.setup(&httpServer, update_path, update_username, update_password);
  
  server.begin();

  if(!LittleFS.begin()){
     Serial.println("An Error has occurred while mounting SPIFFS");
     return;
}


 

 ///////////////////////LCD Set UP//////////////
    
    //lcd.init();

    lcd.begin();// initialize the LCD  
    lcd.backlight();// Turn on the blacklight and print a message. 
   //  LoGO///
   lcd.clear();
    lcd.createChar(0, customChar1);
    lcd.createChar(1, customChar2);
    lcd.createChar(2, customChar3);
    lcd.createChar(3, customChar4);
    lcd.createChar(4, customChar5);
    lcd.createChar(5, customChar6);
    lcd.createChar(7, customChar6);
    lcd.setCursor(12,0);
    lcd.write((uint8_t)0);
    lcd.write((uint8_t)1);
    lcd.write((uint8_t)2);
    lcd.setCursor(12,1);
    lcd.write((uint8_t)3);
    lcd.write((uint8_t)4);
    lcd.write((uint8_t)5);
   // LOGO//
    lcd.setCursor(2,0);
    lcd.print("A.M.R.");
    lcd.setCursor(0,1);
    lcd.print("TPBS Eng.."); 
    delay(5000); 
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Booting....");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("IP");
    lcd.setCursor(0,1);
    lcd.print(myIP);
    delay(3000);
    lcd.clear();
    lcd.print("Gatway");
    lcd.setCursor(0,1);
    lcd.print(myGateWay);
    delay(3000);
    lcd.clear();
    lcd.print("SubNetMask");
    lcd.setCursor(0,1);
    lcd.print(mySubnet);
  //  delay(3000);
  //  lcd.clear();
      
      delay(3000); 
    //  onbacklight ();
//  lcd.noBacklight(); //ปิดไฟ หน้าจอ แบคไลท์
///////////////////////LCD Set UP//////////////


  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_SPIFFS
      type = "filesystem";
    }

    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
  ArduinoOTA.begin();

 ///////////////   

//ArduinoOTA.begin(Ethernet.localIP());


 
 
 
    
  Scheduler.start(&lcd_task);
  Scheduler.start(&tx_rx_task);
  Scheduler.start(&modbus_task);    
  Scheduler.start(&web_task);

  Scheduler.start(&snmp2_task);
// Scheduler.start(&backlight_task);

   Scheduler.begin();  
  
 

   
}


void loop() {

  }

 


/*
void eth_reset() { 
  
  //LanFailCount =  LanFailCount +1 ;
 // if (LanFailCount > 10)
  //{
   
 // }else
  
  pinMode(ETH_RS_PIN, OUTPUT);
  digitalWrite(ETH_RS_PIN, LOW);
  delay(100);
  digitalWrite(ETH_RS_PIN, HIGH);
  pinMode(ETH_RS_PIN, INPUT);
  
 ESP.restart();
  
 // Ethernet.begin(mac, ip, subnet, gateway);
//  server.begin();
  
  ////////////////SNMP//////////////
  //  api_status = Agentuino.begin();
  //
 // if ( api_status == SNMP_API_STAT_SUCCESS ) {
    //
 //   Agentuino.onPduReceive(pduReceived);
    //
//    delay(10);
    //
 //   return;
//  }
  ///////////////SNMP//////////////
  
 // Serial.print(F("WEB server is at "));
//  Serial.println(Ethernet.localIP());
 

}
*/
