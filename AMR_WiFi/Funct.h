String Site ; //--- กำหนดค่า ชื่อสถานี----- //

 String Mac_Station(String MAC) 
     {
         if (MAC == "E8:DB:84:DD:9B:64" ){

            Site =  "PONG";
         }else if(MAC == "E8:DB:84:DD:4C:CC"){  //ESP.getChip: 14523236

            Site =  "PUSANG";
         }else if(MAC == "C4:5B:BE:54:B0:57"){  //ESP.getChip:5550167
            Site =  "CHIANGKHONG";
         }else if(MAC == "E8:DB:84:DC:FC:F5"){  //ESP.getChip:14482677
            Site =  "WIANGPAPAO";
         }else if(MAC == "E8:DB:84:DD:18:5E"){  //ESP.getChip:14489694
            Site =  "MAEAI";
             
         }else if(MAC == "E8:DB:84:DD:55:52"){  //ESP.getChip:14505298
            Site =  "DOITAO";
         }else if(MAC == "E8:DB:84:DD:45:5D"){  //ESP.getChip:14501213

            Site =  "MAESUAI";
         }else if(MAC == "C4:5B:BE:55:2C:21"){  //ESP.getChip:5581857
            Site =  "CHAIPRAKAN";
         }else if(MAC == "E8:DB:84:DD:4B:B8"){  //ESP.getChip:*******
            Site =  "LOMSAK";
         }
         else if(MAC == "E8:DB:84:DD:99:AB"){  //ESP.getChip:14522795
            Site =  "CHIANGMUAN";
         }

         else if(MAC == "E8:DB:84:DD:3E:05"){  //ESP.getChip:14499333
            Site =  "KANTHARALAK";
         }


         
         
         else if(MAC == "9C:9C:1F:47:51:90"){  //ESP.getChip:4673936
            Site =  "PHUWIANG";
         }

         else if(MAC == "E8:DB:84:DD:43:37"){  //ESP.getChip:14500663
            Site =  "NAMSOM";
         }

         else if(MAC == "E8:DB:84:DD:4D:9E"){  //ESP.getChip:14503326

            Site =  "SAMUTSONGKHRAM";
         }
           
         else if(MAC == "E8:DB:84:9B:EA:E0"){  //ESP.getChip: 10218208

            Site =  "CHAIBADAN";
          }

          else if(MAC == "E8:DB:84:DD:93:A8"){  //ESP.getChip: 14521256

            Site =  "PHATO";
          }
           else if(MAC == "E8:DB:84:99:44:E5"){  //ESP.getChip: 10044645

            Site =  "KAPOE";
          }
          else if(MAC == "E8:DB:84:DD:47:9F"){  //ESP.getChip: 14501791


            Site =  "KHURABURI";
          }

         else if(MAC == "C4:5B:BE:54:6A:6C"){  //ESP.getChip: 5532268


            Site =  "PALIAN";
          }

           else if(MAC == "E8:DB:84:DD:43:C2"){  //ESP.getChip: 14500802


            Site =  "KOPHANGAN";
          } 
        

           else if(MAC == "E8:DB:84:DC:F0:93"){  //ESP.getChip:14479507


            Site =  "THALANG";
          } 

               else if(MAC == "E8:DB:84:DC:F7:FB"){  //ESP.getChip:14481403


            Site =  "spare1";  
         //   Site =  "CHAIPRAKAN";// Temp For test
          } 
          else
          
           Site =  "Null"; 
     


     
    return Site; 
  }
