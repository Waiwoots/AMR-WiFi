  class WebTask : public Task { 

  
protected:


void setup(){
  
  

  
                             }


void loop() {
 

 
  if ((millis() - timer) > NET_ENC28J60_CHECK_PERIOD) {    
  
      uint8_t stateEconRxen = Enc28J60.readReg((uint8_t) NET_ENC28J60_ECON1) & NET_ENC28J60_ECON1_RXEN;
       // ESTAT.BUFFER rised on TX or RX error
       // I think the test of this register is not necessary - EIR.RXERIF state checking may be enough
       uint8_t stateEstatBuffer = Enc28J60.readReg((uint8_t) NET_ENC28J60_ESTAT) & NET_ENC28J60_ESTAT_BUFFER;
       // EIR.RXERIF set on RX error
        uint8_t stateEirRxerif = Enc28J60.readReg((uint8_t) NET_ENC28J60_EIR) & NET_ENC28J60_EIR_RXERIF;
       
       Serial.println("---REGS---");
       Serial.println(stateEconRxen,HEX);
       Serial.println(stateEstatBuffer,HEX);
       Serial.println(stateEirRxerif,HEX);
     if   (!stateEconRxen || (stateEstatBuffer && stateEirRxerif)) {
      
         Serial.println ("ENC28J60 reinit");
//          Enc28J60.init(netConfig->macAddress);
         eth_reset();
       }
    timer = millis();
  
  }
 client = server.available();
    
    if (client) {

       
        while (client.connected()) {
           
            if (client.available()) {
                char c = client.read();
                
         
                
                if (inStr.length() < 100) {
                    inStr += c;
            
                }
                //If the HTTP request is successful
                if (c == '\n') {
                    // Write to the serial monitor for debugging
                   // Serial.println(inStr);
                     if (inStr.indexOf("page1") > 0) {
                         page1();
                       } else if (inStr.indexOf("data.xml") > 0) {
                          xml();                          
                          
                       }else  if (inStr.indexOf("digital7.ttf") > 0) {
                        
                         Font_digital7();
                        
                          

                     
                     
                       }else  if (inStr.indexOf("tpbs.png") > 0) {
        
                         tpbs();

                       }else  if (inStr.indexOf("jquery_migrate.js") > 0) {

                   
                        jquery_migrate();

                        
                       }
                       
                       else if (inStr.indexOf("Status") > 0) {
                          
                          Status();
                          
                       }else  if (inStr.indexOf("seting") > 0) {
                                               
                           seting();
                          
                       }else  if (inStr.indexOf("about") > 0) {
                                               
                          about();
                          
                       } else  if (inStr.indexOf("edit") > 0) {
                         
                         
                         edit();
                                         
                        
                          
                       }else  if (inStr.indexOf("help") > 0) {
                         
                         
                         help();
                                         
                        
                          
                       }else  if (inStr.indexOf("Live_Volt.html") > 0) {
                         
                         
                         Live_Volt();
                                         
                        
                          
                       }else  if (inStr.indexOf("show_Volt.html") > 0) {
                         
                         
                         show_Volt();
                                         
                        
                          
                       }
               /*           else  if (inStr.indexOf("administrator") > 0) {
                         
                         
                         administrator();
                                         
                        
                          
                       }
                    else  if (inStr.indexOf("highcharts.js") > 0) {
                         
                         
                         highcharts();
                                         
                        
                          
                       }else  if (inStr.indexOf("jquery-1.10.1.js") > 0) {
                         
                         
                         jquery();
                                         
                        
                          
                       }
                       */
                       else    if (inStr.indexOf("reboota") > 0) {
                         
                         
                         reboota();
                          // รีบูต ESP8266 A               
                       
                          
                       }else  if (inStr.indexOf("rebootb") > 0) {
                         
                         
                         rebootb();
                         // รีบูต ESP8266 b   

                         
                       
                          
                       }else  if (inStr.indexOf("update") > 0) {
                        
                     upintheair();
                    // ArduinoOTA.handle();           
                     
                       }
                       else  {
                         
                        page1();
                       }
                  inStr="";
                }
            }

            
        }
    //   timer = millis();
    }


}

private:


  
                 void Header() {
                        client.println(F("HTTP/1.1 200 OK"));
                        client.println(F("Content-Type: text/html ;  charset=utf-8"));
                        client.println();  
                                          }


                  void HeaderCss() {
                        client.println(F("HTTP/1.1 200 OK"));
                        client.println(F("Content-Type: text/css"));
                        client.println();  
                                          }  
                                                              
                    void HeaderJava() {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: application/javascript");
                        client.println();  
                                          }  
                    void HeaderPng() {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: image/png");
                        client.println();  
                                          } 



                    void HeaderJpeg() {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: image/jpeg");
                        client.println();  
                                          } 
                      void HeaderGif() {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: image/gif");
                        client.println();  
                                          }  

                 void HeaderTtf() {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: application/x-font-ttf ");
                        client.println();  
                                          } 


                   void HeaderEot() {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: application/vnd.ms-fontobject  ");
                        client.println();  
                                          }                         
                    void HeaderWoff() {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: application/font-woff   application/vnd.ms-fontobject  ");
                        client.println();  
                                          }               

     
                      void HeaderXml() {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/xml ;  charset=utf-8 ");
                        client.println("Cache-Control: no-cache");
                       client.println(" X-Content-Type-Options: nosniff");
                        client.println();  
                                          }                                          
                                          
                    void HeaderOnOff() {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/plain");
                        client.println(); 
                                          }  
                    void HeaderError() {
                        client.println("HTTP/1.1 400 ");
                   //     client.println("Content-Type: text/plain");
                        client.println(); 
                                          }                                         
                   void Html (){
                    
                          client.println(F(" <!DOCTYPE html>\n"));
                             client.println(F("<html manifest='html.appcache'>\n"));
                           //  client.println(F("<html lang='en'>\n"));
                          client.println(F("<head>\n"));
                   //      client.println(F("<script src='jquery_migrate.js?V=101'></script>\n"));
                      //  client.println(F("<meta charset='utf-8' name='viewport' content='width=device-width, initial-scale=1'>\n"));
                          client.println(F("<meta http-equiv='refresh' content='300' charset='utf-8' name='viewport' content='width=device-width, initial-scale=1'>\n"));
                     //   client.println("<link rel='stylesheet' href='https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css'>\n");
                    //    client.println("<link rel='stylesheet' href='font-awesome.min.css'>\n");
                         //   client.println(F("<meta http-equiv='refresh' content='180'>\n"));
                          client.println(F("<title> A M R </title>\n"));
                          client.println(F("<style type='text/css'>\n"));

                         StyleBody();
                         Style();        
                        client.println(F("</style>\n"));
                          client.println(F("</head>\n"));
                              
                     }
                  

                 void StyleBody(){
                          ///////////////////Clock////////////////////////
                             client.println("  *{ "); 
                            //  client.println(" margin: 0;");
                           //  client.println(" padding: 0;");
                              client.println("margin-left: auto;");
                              client.println("margin-right: auto;");
                              client.println("}");
                              ///////////////////////////////////////

                  
                         client.println(F(" body {color:#000000;"));  
                                              
                         client.println(F("background: -webkit-linear-gradient( blue,white);")); /* Safari 5.1 - 6.0 */
                         client.println(F("background: -o-linear-gradient( blue,white);")); /* Opera 11.1 - 12.0 */
                         client.println(F(" background: -moz-linear-gradient( blue,white);")); /* Firefox 3.6 - 15 */
                         client.println(F(" background: linear-gradient(#013567,white);")); /* ????? */
                         client.println("  }");
                         /////////////////////cclock/////////
                           /*         client.println("  height: 100vh;");
                                    client.println(" display: flex;");
                                    client.println(" justify-content: center;");
                                    client.println(" align-items: center;");
                                                   //background: #10101E;
                           */
                       
                                    //////////////////clock/////
                          client.println(".datetime{");
                          client.println("color: #fff;");
                        //  client.println("margin-right: 20px;");
                          client.println("background: #10101E;");
                          client.println("font-family: \"Segoe UI\", sans-serif;");
                          client.println("width: 250px;");
                          client.println("padding: 15px 10px;");
                          client.println("border: 3px solid #2E94E3;");
                          client.println("border-radius: 5px;");
                          client.println("-webkit-box-reflect: below 1px linear-gradient(transparent, rgba(255, 255, 255, 0.1));");
                          client.println("transition: 0.5s;");
                          client.println("transition-property: background, box-shadow;");
                          client.println("}");

                          client.println(".datetime:hover{");
                           client.println("background: #2E94E3;");
                           client.println("box-shadow: 0 0 30px #2E94E3;");
                           client.println("}");

                          client.println(".date{");
                          client.println("font-size: 12px;");
                          client.println("font-weight: 500;");
                          client.println("text-align: center;");
                          client.println("letter-spacing: 3px;");
                          client.println("}");

                            client.println(".time{");
                            client.println("font-size: 35px;");
                         client.println("display: flex;");
                         client.println("justify-content: center;");
                           client.println("align-items: center;");
                            client.println("}");

                            client.println(".time span:not(:last-child){");
                              client.println("position: relative;");
                             client.println("margin: 0 6px;");
                             client.println("font-weight: 300;");
                              client.println("text-align: center;");
                           client.println("letter-spacing: 3px;");
                          client.println("}");

                            client.println(".time span:last-child{");
                         client.println("background: #2E94E3;");
                             client.println("font-size: 30px;");
                             client.println("font-weight: 300;");
                            client.println("text-transform: uppercase;");
                              client.println("margin-top: 10px;");
                              client.println("padding: 0 5px;");
                              client.println("border-radius: 3px;");
                                              client.println("}");
        
                     //////////////////////////
                         //////////////////////////////////////
                         
                    //     client.println(F(" }"));
                         client.println(F("a  { color:#0000FF; }"));
                         client.println(F(" a:visited { color:#800080; }"));
                         client.println(F(" a:hover { color:#008000; }"));
                         client.println(F(" a:active { color:#FF0000; }"));
                                               }
                                
void Style(){
                     client.println(F("#div0{\n"));
                     client.println(F("width:400px;\n"));
                     client.println(F("margin:0 auto;\n"));
                     client.println(F("margin-top:50px;\n"));
                     client.println(F("font-size:200%;\n"));
                     client.println(F("color:powderblue;\n"));
                     client.println(F("}\n"));

                     /////////Fornt///

                      client.println(" @font-face {");
                      client.println(" font-family: 'digital7';");     
                      client.println(" src: url('font/digital7.ttf') format('truetype'); "); 
                      client.println(" }");

                      //////////////// HTML5 CSS3 Hoverable Sidenav /////
                    client.println(" #mySidenav a {");
                    client.println("position: absolute;");
                    client.println("left : -110px;"); // or left
                    client.println("transition: 0.3s;");
                    client.println("padding: 15px;");
                    client.println("width: 100px;");
                    client.println("text-decoration: none;");
                    client.println("font-size: 20px;");
                    client.println("color: white;");
                    client.println("border-radius: 0 5px 5px 0 ;"); // or 5px 0 0 5px
                    client.println("}");

                    client.println("#mySidenav a:hover {");
                    client.println("left: 0;"); // or left
                    client.println("}");

                    client.println("#home {");
                    client.println("top: 20px;");
                    client.println("background-color: #04AA6D;");
                    client.println("}");

                    client.println("#about {");
                    client.println("top: 80px;");
                    client.println("background-color: #2196F3;");
                    client.println("}");

                    client.println("#seting {");
                    client.println("top: 140px;");
                    client.println("background-color: #f44336;");
                    client.println("}");

                    client.println("#help {");
                    client.println("top: 200px;");
                    client.println("background-color: #555;");
                    client.println("}");
//////////////////////////////////////////////////////////////////////

                    client.println("img {");
                    client.println("display: block;");
                    client.println("margin-left: auto;");
                    client.println("margin-right: auto;");
                    client.println("}");
          
                  //   client.println(F(".ST1{color:006600;  font-size:100%; font-family: digital7, sans-serif ;}\n"));
                     client.println(F(".ST1{color:006600;  font-size:100% ;}\n"));
                     client.println(F(".ST2{color:006600; margin-top:1px; font-size:80%; text-align: left }\n"));
                     client.println(F(".ST3{color:EE66AAt; margin-top:1px; margin-left: 300; font-size:100%; }\n"));
                     client.println(F(".ST3A{color:00FFAA; margin-top:1px; margin-left: 350; font-size:100%; }\n"));
                     client.println(F(".ST4{color:0000DD; font-size:100%; text-align: center }\n"));
                     client.println(F(".ST5{color:0000DD; font-size:100%; text-align: center ; background: linear-gradient(#013567,white);}\n"));
                     client.println(F("table {font-family: arial sans-serif; text-align: center; border-collapse: collapse; width: 80%; }\n"));
                     client.println(F("td, th {border: 1px; solid #00EE00; text-align: center; height: 27PX ; }\n"));
                     client.println(F("tr:nth-child(even) {color:#001144; background-color: #E1EBFB; }\n"));

                     client.println(F("li {list-style-type: none;"));
                     client.println(F("client.println(F('client.println(F('client.println(F('font-size: 16pt;"));
                     client.println(F("}"));
                     client.println(F(".mail {"));
                     client.println(F("margin: auto;"));
                     client.println(F("padding-top: 10px;"));
                     client.println(F("padding-bottom: 10px;"));
                     client.println(F("width: 400px;"));
                     client.println(F("background : #D8F1F8;"));
                     client.println(F("border: 1px soild silver;"));
                     client.println(F("}"));
                     client.println(F(".mail h2 {"));
                     client.println(F("margin-left: 38px;"));
                     client.println(F("}"));
                     client.println(F("input {"));
                     client.println(F("font-size: 20pt;"));
                     client.println(F("}"));
                     client.println(F("input:focus, textarea:focus{"));
                     client.println(F("background-color: lightyellow;"));
                     client.println(F("}"));
                     client.println(F("input submit {"));
                     client.println(F("font-size: 12pt;"));
                     client.println(F("}"));
                     client.println(F(".rq {"));
                     client.println(F("color: #FF0000;"));
                     client.println(F("font-size: 10pt;"));
                     client.println(F("}"));

                    


           
                                }
              void menu(){
                      client.println("<div id=\"mySidenav\" class=\"sidenav\">");
                      client.println("<a href=\"/page1\" id=\"home\">Home</a>");
                      client.println("<a href=\"/about\" id=\"about\">About</a>");
                      client.println("<a href=\"seting\" id=\"seting\">Seting</a>");
                      client.println("<a href=\"/help\" id=\"help\">Help</a>");
                      client.println("</div>");

}
                   

void javascriptContent(){
   client.println(F("<SCRIPT>\n"));
   client.println(F("var xmlHttp=createXmlHttpObject();\n"));
   client.println(F("function createXmlHttpObject(){\n"));
   client.println(F("if(window.XMLHttpRequest){\n"));
   client.println(F("xmlHttp=new XMLHttpRequest();\n"));
   client.println(F("}else{\n"));
   client.print(F("xmlHttp=new ActiveXObject('Microsoft.XMLHTTP'); \n"));
  
   client.println(F("}\n"));
   client.println(F("return xmlHttp;\n"));
   client.println(F("}\n"));
   client.println(F("\n"));
   client.println(F("function response(){\n"));
   client.println(F("xmlResponse=xmlHttp.responseXML;\n"));
   client.println(F("xmldoc = xmlResponse.getElementsByTagName('data');\n"));
   client.println(F("message = xmldoc[0].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div1').innerHTML=message;\n"));
   client.println(F("message = xmldoc[1].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div2').innerHTML=message;\n"));
   client.println(F("message = xmldoc[2].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div3').innerHTML=message;\n"));
   client.println(F("message = xmldoc[3].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div4').innerHTML=message;\n"));
   client.println(F("message = xmldoc[4].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div5').innerHTML=message;\n"));   

   client.println(F("message = xmldoc[5].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div6').innerHTML=message;\n"));   
   client.println(F("message = xmldoc[6].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div7').innerHTML=message;\n"));  
   client.println(F("message = xmldoc[7].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div8').innerHTML=message;\n"));    
   client.println(F("message = xmldoc[8].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div9').innerHTML=message;\n"));  
   client.println(F("message = xmldoc[9].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div10').innerHTML=message;\n"));    

   client.println(F("message = xmldoc[10].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div11').innerHTML=message;\n"));   
   client.println(F("message = xmldoc[11].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div12').innerHTML=message;\n"));  
   client.println(F("message = xmldoc[12].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div13').innerHTML=message;\n"));    
   client.println(F("message = xmldoc[13].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div14').innerHTML=message;\n"));  
   client.println(F("message = xmldoc[14].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div15').innerHTML=message;\n"));   

   client.println(F("message = xmldoc[15].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div16').innerHTML=message;\n"));   
   client.println(F("message = xmldoc[16].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div17').innerHTML=message;\n"));  
   client.println(F("message = xmldoc[17].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div18').innerHTML=message;\n"));    
   client.println(F("message = xmldoc[18].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div19').innerHTML=message;\n"));  
   client.println(F("message = xmldoc[19].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div20').innerHTML=message;\n"));

   client.println(F("message = xmldoc[20].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div21').innerHTML=message;\n"));   
   client.println(F("message = xmldoc[21].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div22').innerHTML=message;\n"));  
   client.println(F("message = xmldoc[22].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div23').innerHTML=message;\n"));    
   client.println(F("message = xmldoc[23].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div24').innerHTML=message;\n"));  
   client.println(F("message = xmldoc[24].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div25').innerHTML=message;\n"));  
   
   client.println(F("message = xmldoc[25].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div26').innerHTML=message;\n"));   
   client.println(F("message = xmldoc[26].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div27').innerHTML=message;\n"));  
   client.println(F("message = xmldoc[27].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div28').innerHTML=message;\n"));    
   client.println(F("message = xmldoc[28].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div29').innerHTML=message;\n"));  
   client.println(F("message = xmldoc[29].firstChild.nodeValue;\n"));
   client.println(F("document.getElementById('div30').innerHTML=message;\n"));  
   
   client.println(F("}\n"));
   client.println(F("function process(){\n"));
   client.println(F("xmlHttp.open('GET','data.xml',true);\n"));
   client.println(F("xmlHttp.onreadystatechange=response;\n"));
   client.println(F("xmlHttp.send(null);\n"));
   client.println(F("setTimeout('process()',1000);\n"));
   client.println(F("}\n"));    
   client.println(F("</SCRIPT>\n"));     
  }


void javascriptalert(){
  
       client.println(F("<script language=JavaScript>\n"));
           
      client.println(F("function validate(_frm) {\n")); 
    // 
    // Build the form data 
    // 

  
    client.println(F("var _f='Do you want to submit this data? ';\n"));
  
    client.println(F("var _i =' Ip:' + _frm.ip.value ;\n"));
    client.println(F("var _s =' subnet:' + _frm.subnet.value ;\n"));
    client.println(F("var _g =' gateway:' + _frm.gateway.value ;\n"));
    client.println(F("return confirm(_f+_i+_s+_g);\n"));


    // Show the data to the user 
    // 
   // client.println(F("return confirm(_f+_n+_n+_fd+_n+_l);\n"));

    client.println(F("} \n"));   


    client.println(F("</script >\n"));
     
      }

      void Clock(){


                //////////////////Clock/////////////////
                  client.print("<BR>");
                  client.print("<BR>");

         client.println(" <div class=\"datetime\" >");
        client.println(" <div class=\"date\">");
        client.println(" <span id=\"dayname\">Day</span>,");
        client.println(" <span id=\"month\">Month</span>");
        client.println("  <span id=\"daynum\">00</span>,");
        client.println(" <span id=\"year\">Year</span>");
        client.println(" </div>");
        client.println("  <div class=\"time\">");
        client.println(" <span id=\"hour\">00</span>:");
        client.println(" <span id=\"minutes\">00</span>:");
        client.println(" <span id=\"seconds\">00</span>");
        client.println(" <span id=\"period\">AM</span>");
        client.println(" </div>");
        client.println("  </div>");

            client.println("<script>");
            client.println("function openNewWindow(url) {");
            client.println("window.open(url, 'pukarock', 'width=880, height=550, scrollbars=yes, resizable=yes')");
            client.println("}");
            client.println("</script>");

/*      Clock Of  Mr. S r Ch ////
                    client.println(F("<script>\n"));
                    client.println(F("function startTime() {\n"));
                    client.println(F("var today = new Date();\n"));
                    client.println(F("var h = today.getHours();\n"));
                    client.println(F("var m = today.getMinutes();\n"));
                    client.println(F("var s = today.getSeconds();\n"));
                    client.println(F(" m = checkTime(m);\n"));
                    client.println(F(" s = checkTime(s);\n"));
                    client.println(F("document.getElementById('timezone').innerHTML =today ;\n"));
                    client.println(F(" var t = setTimeout(startTime, 500);\n"));
                    client.println(F("    }\n"));
                    client.println(F("function checkTime(i) {\n"));
                    client.println(F("  if (i < 10) {i = \"0\" + i};\n"));
                    client.println(F(" return i;\n"));
                    client.println(F("}\n"));
                    client.println(F(" </script>\n"));
      */  
  client.println("<script type=\"text/javascript\">");
    client.println("function updateClock(){");
      client.println("var now = new Date();");
      client.println("var dname = now.getDay(),");
          client.println("mo = now.getMonth(),");
          client.println("dnum = now.getDate(),");
          client.println("yr = now.getFullYear(),");
          client.println("hou = now.getHours(),");
          client.println("min = now.getMinutes(),");
          client.println("sec = now.getSeconds(),");
          client.println("pe = \"AM\";");
      
          client.println("if(hou >= 12){");
            client.println("pe = \"PM\";");
          client.println("}");
          client.println("if(hou == 0){");
            client.println("hou = 12;");
          client.println("}");
          client.println("if(hou > 12){");
            client.println("hou = hou - 12;");
          client.println("}");

          client.println("Number.prototype.pad = function(digits){");
            client.println("for(var n = this.toString(); n.length < digits; n = 0 + n);");
            client.println("return n;");
          client.println("}");

          client.println("var months = [\"January\", \"February\", \"March\", \"April\", \"May\", \"June\", \"July\", \"Augest\", \"September\", \"October\", \"November\", \"December\"];");
          client.println("var week = [\"Sunday\", \"Monday\", \"Tuesday\", \"Wednesday\", \"Thursday\", \"Friday\", \"Saturday\"];");
          client.println("var ids = [\"dayname\", \"month\", \"daynum\", \"year\", \"hour\", \"minutes\", \"seconds\", \"period\"];");
          client.println("var values = [week[dname], months[mo], dnum.pad(2), yr, hou.pad(2), min.pad(2), sec.pad(2), pe];");
          client.println("for(var i = 0; i < ids.length; i++)");
          client.println("document.getElementById(ids[i]).firstChild.nodeValue = values[i];");
    client.println("}");

    client.println("function initClock(){");
      client.println("updateClock();");
      client.println("window.setInterval(\"updateClock()\", 1);");
    client.println("}");
    client.println("</script>");


               }

        
void page1() {
    Header(); 
  
    Html();  

    
    
       client.println(F("<body onload='process();initClock();'>"));
      
       javascriptContent(); 
       menu();
   
 //      client.println("<img src='tpbs.png?1001' width='100' height='100' alt='ThaiPBS Logo'>"); 
       client.println("<img src='data:image/png;base64,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' width='100' height='100' alt='ThaiPBS Logo'>"); 
 
         
        client.println("<div id='div0'>Automatic Meter Reading Station"); client.println(Site) ;client.println("</div>");   
      
       client.println(F("<br>\n")); 

              
       client.println(F("<table>\n"));
       client.println(F("<tr><th></th><th>Mux1</th><th>Mux2</th><th>Mux3</th><th>Mux4</th><th>Mux5</th></tr>\n"));
       
       client.println(F("<tr><td class='ST5' >Power Consumption (Wh)</td><td>\n"));
       client.println(F("<p id='div1' class='ST1' > Mux1 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div2' class='ST1' > Mux2 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div3' class='ST1' > Mux3 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div4' class='ST1' > Mux4 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div5' class='ST1' > Mux5 </p>\n" ));
       client.println(F("</td></tr>"));
       
       client.println(F("<tr><td>Active Power(Wh)</td><td>"));
       client.println(F("<p id='div6' class='ST1' > Power1 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div7' class='ST1' > Power2 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div8' class='ST1' > Power3 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div9' class='ST1' > Power4 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div10' class='ST1' > Power5 </p>\n" ));
         client.println(F("</td></tr>"));
      
       
       client.println(F("<tr><td  class='ST5'>Current(A)</td><td>"));
       client.println(F("<p id='div11' class='ST1' > Current1 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div12' class='ST1' > CurrentPower2 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div13' class='ST1' > Current3 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div14' class='ST1' > Current4 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div15' class='ST1' > Current5 </p>\n" ));
       client.println(F("</td></tr>"));
         
       client.println(F("<tr><td>Frequency(H)</td><td>"));
       client.println(F("<p id='div16' class='ST1' > Frequency1 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div17' class='ST1' > Frequency2 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div18' class='ST1' > Frequency3 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div19' class='ST1' > Frequency4 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div20' class='ST1' > Frequency5 </p>\n" ));
       client.println(F("</td></tr>"));

       client.println(F("<tr><td  class='ST5'>Power Factor </td><td>"));
       client.println(F("<p id='div21' class='ST1' > Factor1 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div22' class='ST1' >Factor2 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div23' class='ST1' > Factor3 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div24' class='ST1' > Factor4 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div25' class='ST1' > Factor5 </p>\n" ));
       client.println(F("</td></tr>")); 
       
       client.println(F("<tr><td>Volt (V)</td><td>"));
       client.println(F("<p id='div26' class='ST1'>Volt1 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div27' class='ST1' >Volt2 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div28' class='ST1' >Volt3 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div29' class='ST1' > Volt4 </p>\n" ));
       client.println(F("</td><td>"));
       client.println(F("<p id='div30' class='ST1' > Volt5 </p>\n" ));
         client.println(F("</td></tr>")); 
     
       client.println(F("</table>"));  
  /*     client.println(F("<br>"));
      // client.println(F("<p align='center' class='ST1' > TPBS </p>\n" ));      
         client.println(F("<p align='center' class='ST2' >" ));
 //        client.println(myIPAdress);  
         client.println(F("</p>\n" ));
                
         client.println(F("<p align='center' class='ST2' >" ));
    //     client.println (mySubnet); 
         client.println(F("</p>\n" ));
               
         client.println(F("<p align='center' class='ST2' >" ));
     //    client.println (myGateWay);
         client.println(F("</p>\n" ));
               
         client.println(F("<p align='center' class='ST2' >" ));
    //     client.println (myMac); 
         client.println(F("</p>\n" ));  
        client.println("<p align='center' class='ST1' > ThaiPBS </p>");  
      //  client.println(F("<a href='seting' target='_blank'>Seting</a>"));

    //    client.println(F("<div  id=\"timezone\" class=\"ST4\" ></div>")); 

*/

         Clock();

       /////////////////////////////////////
        client.println(F("</body></html>"));
   
       client.stop();
}
void seting() {
    Header(); 
    javascriptalert() ;
     Html(); 



    


       client.println(F("<body onload='process();initClock();process();'>"));
       menu();
    
      client.println("<img src='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAFIAAABkCAYAAAAVD2crAAAABGdBTUEAAK/INwWK6QAAABl0RVh0U29mdHdhcmUAQWRvYmUgSW1hZ2VSZWFkeXHJZTwAAAdwSURBVHja7J1dbuJIEMc7o7yP5wTraA8QcoKYE4yR9n3gBBPedqWVAGmk3TfgBMD7SiEniDlBnAOsxnuDnhNku6LyUBTd7Q9sY6BLskiwje2f//XVbpKrt7c34exw++AQOJAOpAPpzIF0IB1IB9KZA3k8u3YI9u3Hb7966qWvFnidffznX+lAFgPoq5eRWjpqGSqAkVNkMYCBevmqllAtEwVw4Fy7OEBQILyC+m4UxMTFyHIAJbrxzCWbcgAFqnBQVoUXBxKTyIIAlAhw7cqf/GXMFEuZ1NYIUVZ5rOszhjjGTOwRFU4OjYUXAxLjILixT96uLBaePUiMg1OsBamBCseuRcwH8QGzsUfeBvX1FMS4gJJl3u3PCqQmGxdOKKSrWRVpCc8GpEGFIm9xTWpKWUUWvz5BgADuUaPCXK5MVNypMotfnxjEACFyFUYIUWYAHGFNCbC7ZePhSYPEunCkWbW0jdaggh9ITblE97+sgtziygJj29Kyb4glkV8kfp4dSAWigxB9tkqiK0cFeuveIVk5yz60GCJAeDZA7Fogghu/EIgQB+/qhNhaRSoYfVQUtxjdOc5ZU2YmobMFmQGxq4NiqCmXZR4ZnAVIS2bWQsREtND0141CbBVIBWWKZUpeiKZEZM3kddnVITN2UREhuxjoMNZF4lJRd8btp5rC/CgQDwJp6XV/uleewtcCUeq6D4tyjwaxNEh1MQuxO3xvMoAxx5iVWEqcTIiGxwatgFgKZAGI3HZqPyxXXgyK3gGDEJ9xoKF1EMsmm5VaXtVyr8mWJltqCuJHA8RJAYizNkCsItn4Qj+8L1jyuaOx0hLnIrVdNydEY4lDBirWVY7w1NYiQtxTSw/cy7LZgEEMDBDf+2H2ngliZIHYwf0ag1hZr43uNTNcMHfpRU7gCwPEWAOc99mDJiFWXZBPxHZOYWpzzYX6mn3XdNYDdjh9g2oHGR1O4xArHf3Bi6OBXzI4nqH9e5/ExFx/ZFFtrInTz2I7Je8oyafqYbQNVRlbFxqy9DytMckgrjBk6LUmHr5gCFg38fy6KZCRAaqwqHHG4qcOdqwgDQ1JxcPKYCCOaJWCZLErZhftG9QocZvQUkYNLBDBGhlzbFKRPwGyWPYlhxqnpiTGWkUOcXKM5NIESImuRi0wZGpJBi58QzE/s0CMjhkXGwWJCURXD84z4qego0ekxKExdChaYnWAfGW/6yAmqTta1BixLM0L9Fa4dJ0geSejLcDJz58tBT4t5EOTy58lSGwJZQbIDXHX0NZakqkmPAHJswaJ9pRTtWGWGjVxMWnL0FntIDMuVBI13RviZ0TaxcAC+ewVybO40BXqJbJ5K9XYFMjYArZjSkQGNc5FS60JkElGecR76sTSDS0vFiSC0U0zCTJKJ93sCXnJiuR1o802ZADDK1gJXATIvBAiQzaXVX5v8GRBIoSdkkc3X5G4biejW7pYRebJuJElm28cyK3NUJWBpTRKzXOKNLu3TLsS7J9tIPm+sQO5C2SG6goKuGzr1dg4SDR4uH9bAJJ0IA0unj4RxGI9MsTFPJ3QRSuS28rSd5+MHR0kjuYkmIQ6pxQX26ZIIbZjjIFhoMOBLKDKmLSGm1MD2abv2UACesbnOM61D1BlhN1PH7N57ECWhzkkNWbam//iQJZ0cXBvjJtQjPsuRpbvyQVR5cgp8nCDmJmQ+tKBPECdQ6GfzdYqy/09m9//+DPrYhLsl2GRf//1rbKsC4ps+1DadU6I6bzErDownSwKjxZ6ZU5IHWua9t3qZnRRmTFZr/vGGKyfq+0TtR4mXOkmZj2p9TPyOfCA7QseS2LtOlHbyNpAlnCtQzqTPoKKNZAhg4eG84P3bwicvW3U/uApS/Wq+z4l7PNDLeNaXZtczAs50U/pHVTvj0mG7WHZ8j5RHk5eA4P+Xcc1qolOSoX9EnZsuPgF688/k33guI8kUT0h5BHZJyLeBee1Ets/kwjn0atTkemF0AuNmRvckp93ZpCp/QQqgYKgNlLr7hDwlEDhgxf35Nhj/OyP5Jyoy68gTmNYonGcetcrvtfFUFJ6sKRo1g5YXLKto8+hfUxWCxJDh+QzPFQEfZ4dWY7vgQdgvHwg29Ob+aLWv5Ebs0TPoDcf1n1HFR9UYhUFea+Lg3jXUzWsMUk8MSXAMsALluiSnkEtXO1pSEi7HB/dNSQ3rpcB4z/izpEmPj7iMRrpbAKDYuj7Kw102Par2P1WbETASFI6ZamRxscU+pqVaDNyIxdM7Z7Yfm8nwPPqkBuU1AoyIxHoXDJgSnsgbj3AzwrIPkFG1r8nxx5n1LlpfAxoUlO/f2dJBeJ2mqwgo0dNKDKwxK8dl2RuGLOBh9Qt+wzcbc74GOU4P4iPfP2cxMsQ46cwqLzWGJknPkaai9qI/ekoDyzo0/iYZMTHTY7z4x1XD9U2EPuPd99jNy3W61bkisSdmJ1Il/ycAu0yld6wmJjQUEHi1l5ngWHkynZyaReUsQ2c9ycSBiprZa/cvzy9jGE0B9KBdOZAOpAOpDMH0oFsp/0vwAAlV6oNqCIoTQAAAABJRU5ErkJggg==' width='100' height='100' alt='ThaiPBS Logo'>"); 
 
  
        
       client.println("<div id='div0'>Automatic Meter Reading Station"); client.println(Site) ;client.println("</div>"); 
       client.println(F("<br>"));        
       client.println(F("<p  class='ST1'>NetWork</p>")); 
       client.print(F("<p  class='ST1'>Mac :"));client.print(String(Mac_Address)); client.println(" </p>");  
                         client.println(F("<FORM name=frmNames onsubmit='return validate(document.frmNames)'  action=edit method=get >")); 
                        
                         
            
                         client.println(F("<tr>")); 
                         client.println("<td align='right'> IP_Address:</td><td><input  type='text' name='ip' required pattern='^([0-9]{1,3}\.){3}[0-9]{1,3}$' placeholder='xxx.xxx.xxx.xxx'></td>");                     
                         client.println(F("</tr>")); 

                         client.println(F("<tr>")); 
                         client.println("<td align='right'> SubNetMask:</td><td><input  type='text' name='subnet' required pattern='^([0-9]{1,3}\.){3}[0-9]{1,3}$' placeholder='xxx.xxx.xxx.xxx'></td>");                     
                         client.println(F("</tr>")); 

                         client.println(F("<tr>")); 
                         client.println("<td align='right'> GateWay:</td><td><input  type='text' name='gateway' required pattern='^([0-9]{1,3}\.){3}[0-9]{1,3}$' placeholder='xxx.xxx.xxx.xxx'></td>");                     
                         client.println(F("</tr>")); 
                         client.println(F("<tr>"));
                          client.println(F("<input  name='code' type='hidden' value='TPBS_ADMIN'>")); 
                          client.println(F("</tr>")); 
                         client.println(F("<tr>")); 
                         client.println(F("</td><td><td><INPUT type='submit'  value='submit' > <INPUT type=reset value='Reset'>  </td>")); 
                         client.println(F("</tr>")); 
                         client.println(F("</form>")); 

/*
                                client.println(F("<br>"));
       client.println(F("<p align='center' class='ST1' > TPBS </p>\n" ));  
           
         client.print(F("<p class='ST3' >" )); client.println ("FW_VERSION : "+ String(FW_VERSION));            client.print(F("</p>\n" ));           
               
         client.print(F("<p class='ST3' >" )); client.println ("locUpTime :"+ String(locUpTime/100) + "SEC" );  client.print(F("</p>\n" ));   
              
         client.print(F("<p class='ST3' >" )); client.println ("myIPAdress:"+ myIP);                            client.println(F("</p>\n" ));  
                   
         client.print(F("<p class='ST3' >" ));  client.println ("myGateWay:" + myGateWay);                      client.println(F("</p>\n" ));  
           
         client.print(F("<p class='ST3' >" ));  client.println ("mySubnet :"+ mySubnet);                        client.println(F("</p>\n" ));   
          
         client.print(F("<p class='ST3' >" ));  client.println ("myMac :"+ myMac);                              client.println(F("</p>\n" ));            
         
         client.print(F("<p class='ST3' >" ));  client.println ("LanFailCount :" + String(LanFailCount) );      client.println(F("</p>\n" ));  
           
      */         

                   //////////////////Clock/////////////////

                    //           Clock();

                 /////////////////////////////////////
                 client.println(F("</body></html>"));
   
                 client.stop();
                                  }

void about() {
    Header(); 
    javascriptalert() ;
     Html(); 



    


       client.println(F("<body onload='process();initClock();process();'>"));
       menu();
   
        client.println("<img src='data:image/png;base64,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' width='100' height='100' alt='ThaiPBS Logo'>"); 
 
      
        
       client.println("<div id='div0'>Automatic Meter Reading Station"); client.println(Site) ;client.println("</div>"); 
       client.println(F("<br>"));        
         
          


                                client.println("<br>");
       client.println("<p align='center' class='ST1' > TPBS </p>\n" );  
           
         client.print("<p class='ST3' >FW_VERSION......" ); client.print(String(FW_VERSION));client.println("</p>");  


             sec = (locUpTime/100);
              y   = sec / 31104000;
              yy  = sec % 31104000;
              mo  = yy / 2592000;
             _mo = yy % 2592000;
             d   = _mo / 86400;
             hh  = _mo % 86400;
             h   = hh / 3600;
             mm  = hh % 3600;
             m   = mm / 60;
            ss  = mm % 60;
             s   = ss % 60;
            
               
         client.print("<p class='ST3' >UpTime............"+String(d)+"Day  "+String(h)+"hours  "+String(m)+"minuts");  client.println("</p>");   
              
         client.print("<p class='ST3' >IPAdress.........." ); ;client.print(myIP);client.println("</p>");       
                                
         client.print("<p class='ST3' >GateWay..........." ); client.print(myGateWay); client.println("</p>");                        
           
         client.print("<p class='ST3' >Subnet............" );  client.print(mySubnet); client.println("</p>");         
          
         client.print("<p class='ST3' >Mac..............." );  client.print (Mac_Address); client.println("</p>");                                       
         
         client.print("<p class='ST3' >LanFailCount...." ); client.print(String(LanFailCount) );  client.println("</p>");     
           
               

                   //////////////////Clock/////////////////

                         //      Clock();

                 /////////////////////////////////////
                 client.println(F("</body></html>"));
   
                 client.stop();
                                  }

void help() {
    Header(); 
    javascriptalert() ;
     Html();    


       client.println(F("<body onload='process();initClock();process();'>"));
       menu();   
       client.println("<img src='data:image/png;base64,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' width='100' height='100' alt='ThaiPBS Logo'>"); 
 
       client.println("<div id='div0'>Automatic Meter Reading Station"); client.println(Site) ;client.println("</div>"); 
       client.println(F("<br>"));      

      client.println("<br>");
      client.println("<p align='center' class='ST1' > OID V 1.0 </p>\n" );  
      client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.1.0 Value: Automatic Meter  Reading Type: OctetString </P>" );        
      client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.3.0 Value: UpTime Type: TimeTicks </P>" );    
      client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.4.0 Value: AMR Type: OctetString </P>" );    
      client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.5.0 Value: TPBS Type: OctetString </P>" );  
/*
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.6.0 Value: PONG Type: OctetString </P>" );    
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.0 Value: FW_VERSION  Type: OctetString  </P>" );    
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.1 Value: IP  Type: OctetString </P>" );  
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.2 Value:SubnetMask  Type: OctetString </P>" );  
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.3 Value:GateWay Type: OctetString </P>" );  
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.4 Value: Mac AddressType: OctetString </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.5 Value: 0 Type: Integer </P>" );   
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.6 Value: 0 Type: Integer </P>" ); 
*/
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.1.1 Value: Mux1 Power Consumption (Kw) Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.1.2 Value: Mux1 Active Power (Wh) Type: Integer </P>" );  
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.1.3 Value: Mux1 Current (A) Type: Integer </P>" );  
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.1.4 Value: Mux1 Frequency (Hz) Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.1.5 Value: Mux1 Power Factor Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.1.6 Value: Mux1 Voltage Type: Integer </P>" );   
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.2.1 Value: Mux2 Power Consumption (Kw) Type: Integer </P>" );  
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.2.2 Value: Mux2 Active Power (Wh) Type: Integer </P>" );   
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.2.3 Value: Mux2 Current (A) Type: Integer </P>" );  
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.2.4 Value: Mux2 Frequency (Hz) Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.2.5 Value: Mux2 Power Factor Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.2.6 Value: Mux2 Voltage Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.3.1 Value: Mux3 Power Consumption (Kw) Type: Integer </P>" );
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.3.2 Value: Mux3 Active Power (Wh) Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.3.3 Value: Mux3 Current (A) Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.3.4 Value: Mux3 Frequency (Hz) Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.3.5 Value: Mux3 Power Factor Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.3.6 Value: Mux3 Voltage Type: Integer </P>" );  
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.4.1 Value: Mux4 Power Consumption (Kw) Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.4.2 Value: Mux4 Active Power (Wh) Type: Integer </P>" );  
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.4.3 Value: Mux4 Current (A) Type: Integer </P>" );
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.4.4 Value: Mux4 Frequency (Hz) Type: Integer </P>" );
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.4.5 Value: Mux4 Power Factor Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.4.6 Value: Mux4 Voltage Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.5.1 Value: Mux5 Power Consumption (Kw) Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.5.2 Value: Mux5 Active Power (Wh) Type: Integer </P>" );
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.5.3 Value: Mux5 Current (A) Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.5.4 Value: Mux5 Frequency (Hz) Type: Integer </P>" );
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.5.5 Value: Mux5 Power Factor Type: Integer </P>" ); 
client.print("<p class='ST3' >OID: .1.3.6.1.2.1.1.7.7.5.6 Value: Mux5 Voltage Type: Integer </P>" );   
                   //////////////////Clock/////////////////
                         //      Clock();

                 /////////////////////////////////////
                 client.println(F("</body></html>"));
   
                 client.stop();
                                  }                                      
                                  
void Status() {
    Header(); 
 
    
    uint32_t  ChipId      = ESP.getChipId();
    String CoreVersion    = ESP.getCoreVersion();
    String SdkVersion     = ESP.getSdkVersion();
    uint8_t CpuFreqMHz    = ESP.getCpuFreqMHz();
    uint32_t SketchSize   = ESP.getSketchSize();
    uint32_t FreeSketchSpace  = ESP.getFreeSketchSpace();
    String SketchMD5      = ESP.getSketchMD5();
    uint32_t FChipId     = ESP.getFlashChipId();  
    byte FChipSize       = ESP.getFlashChipSize();
    byte ChipRealSize    = ESP.getFlashChipRealSize();
    int FChipSpeed       = ESP.getFlashChipSpeed();
    uint32_t CycleCount  = ESP.getCycleCount();
     int    Vcc          = ESP.getVcc();

         
  
    client.println(F("<html>\n"));
    client.println(F("<head>\n"));
     client.println(F("<title> A M R </title>\n"));
    client.println(F("<style type='text/css'>\n"));

    StyleBody();
    Style();         
    client.println(F("</style>\n"));
    client.println(F("</head>\n"));
    
    client.println(F("<body onload='process()'>"));
    client.println(F("<div id='div0'>Automatic Meter Reading Station...</div>")); client.println(Site) ;  
       client.println(F("<br>"));        


  
       client.println(F("<br>"));
       client.println(F("<p align='center' class='ST1' > TPBS </p>\n" )); 
            
        
         
         client.println(F("<p class='ST3' >" ));client.print("ChipId :" +String(ChipId) ); client.println(F("</p>\n" ));  
         client.println(F("<p class='ST3' >" ));client.print("CoreVersion :" +String(CoreVersion) ); client.println(F("</p>\n" )); 
         client.println(F("<p class='ST3' >" ));client.print("SdkVersion  :" +String(SdkVersion ) ); client.println(F("</p>\n" ));
         client.println(F("<p class='ST3' >" )); client.print("CpuFreqMHz  :" +String(CpuFreqMHz ) );client.println(F("</p>\n" ));
         client.println(F("<p class='ST3' >" ));client.print("SketchSize  :" +String(SketchSize  ) );client.println(F("</p>\n" ));
         client.println(F("<p class='ST3' >" ));client.print("SketchMD5  :" +String(SketchMD5  ) ); client.println(F("</p>\n" ));                      
         client.println(F("<p class='ST3' >" ));client.print("FChipId :" +String(FChipId) );client.println(F("</p>\n" ));
         client.println(F("<p class='ST3' >" ));client.print("FChipSize :"+ String(FChipSize));client.println(F("</p>\n" ));
         client.println(F("<p class='ST3' >" ));client.print("ChipRealSize :"+ String(ChipRealSize));client.println(F("</p>\n" ));  
         client.println(F("<p class='ST3' >" ));client.print("FChipSpeed :"+ String(FChipSpeed));client.println(F("</p>\n" ));
         client.println(F("<p class='ST3' >" ));client.print("CycleCount :"+ String(CycleCount));client.println(F("</p>\n" ));  
         client.println(F("<p class='ST3' >" ));client.print(" Vcc :"+ String( Vcc ));client.println(F("</p>\n" ));        
              
       
    client.println(F("</body></html>"));
   
    client.stop();
}
void reboota() {
    Header(); 
    javascriptalert() ;

    client.println(F("<html>\n"));
    client.println(F("<head>\n"));
     client.println(F("<title> A M R </title>\n"));
    client.println(F("<style type='text/css'>\n"));

    StyleBody();
    Style();        
    client.println(F("</style>\n"));
    client.println(F("</head>\n"));
    
    client.println(F("<body onload='process()'>"));
    client.println(F("<div id='div0'>Automatic Meter Reading Station...</div>")); client.println(Site) ;  
       client.println(F("<br>"));        
                         client.println(F("<FORM name=frmNames onsubmit='return validate(document.frmNames)'  action=edit method=get >")); 
                        
                         client.println(F("<p  class='ST1'>NetWork</p>")); 
            
                          ESP.restart() ;  
                         client.println(F("<tr>"));
                          client.println(F("<input  name='code' type='hidden' value='TPBS_ADMIN'>")); 
                          client.println(F("</tr>")); 
                         client.println(F("<tr>")); 
                         client.println(F("</td><td><td><INPUT type='submit'  value='submit' > <INPUT type=reset value='Reset'>  </td>")); 
                         client.println(F("</tr>")); 
                         client.println(F("</form>")); 
       client.println(F("<br>"));
           
      
    client.println(F("</body></html>"));
   
    client.stop();
}
void rebootb() {

  reboot =191 ;
  delay(1500);
  reboot = 000 ;
}

void edit() {
    Header(); 
 
    client.println(F("<html>\n"));
    client.println(F("<head>\n"));
     client.println(F("<title> A M R </title>\n"));
    client.println(F("<style type='text/css'>\n"));

    StyleBody();
    Style();        
    client.println(F("</style>\n"));
    client.println(F("</head>\n"));
    
    client.println(F("<body onload='process()'>"));
    client.println(F("<div id='div0'>Automatic Meter Reading Station...</div>")); client.println(Site) ;
       client.println(F("<br>"));        
                   
       client.println(F("<br>"));
       client.println(F("<p align='center' class='ST1' > TPBS </p>\n" ));      
       


                         
                        int a,b,c,d;               
                        for (int i = 0; i < inStr.length(); i++) 
                              { if (inStr.substring(i, i + 1) == "="  )
                                   { for ( a=i; i < inStr.length(); i++) 
                                        {if (inStr.substring(i, i + 1) == "&"  )
                                            { 
                                               value1 = inStr.substring(a+1,i); //////////////
                                              // value1.replace('.',',');    
                                                 for ( b=i; i < inStr.length(); i++) 
                                                      {if (inStr.substring(i, i + 1) == "="  )
                                                            {for ( b=i; i < inStr.length(); i++) 
                                                                  {if (inStr.substring(i, i + 1) == "&"  )
                                                                       {                    
                                                                           value2 = inStr.substring(b+1,i);////////////
                                                                        //    value2.replace('.',',');   
                                                                              for ( c =i; i < inStr.length(); i++)       
                                                                                   {if (inStr.substring(i, i + 1) == "="  )    
                                                                                      {for ( c=i; i < inStr.length(); i++)    
                                                                                           {if (inStr.substring(i, i + 1) == "&"  )
                                                                                              value3 = inStr.substring(c+1,i);////////////
                                                                                       //       value3.replace('.',',');  
                                                                                                       }
                                                                                                    
                                                                                                break;
                                                                                             }
                                                                                           
                                                                                           }
                                                                                      break;
                                                                                   }
                                                                            } 
                                                                        break;
                                                                    }
                                                               }
                                        
                                                        break;
                                                        }
                                                 }                                                           
                                      break;
                                      
                                  }
                                     
                              }
                         
                          client.println("<br />");                           
                          client.println ("IP : invalid ");
                          client.println("<br />");
                          client.println ("SubNet : invalid   ");
                           client.println("<br />");
                          client.println ("GateWay : invalid");
                               
 
 ////////////////////////////////////////// 

  
   str_IP = value1; 
   char charBuf[16];
   str_IP.toCharArray(charBuf, 16);  // คัดลอกอักขระของชุดอักขระไปยังตัวแปร charBuf
   splint_string(charBuf); // เรียกใช้งานฟังชั่น Splint String

   str_SN = value2; 
   char charBuf2[16];
   str_SN.toCharArray(charBuf2, 16);  // คัดลอกอักขระของชุดอักขระไปยังตัวแปร charBuf
   splint_string2(charBuf2); // เรียกใช้งานฟังชั่น Splint String

   str_GW = value3; 
   char charBuf3[16];
   str_GW.toCharArray(charBuf3, 16);  // คัดลอกอักขระของชุดอักขระไปยังตัวแปร charBuf
   splint_string3(charBuf3); // เรียกใช้งานฟังชั่น Splint String


 
if ( inStr.indexOf("code=TPBS_ADMIN") > 0)//ตรวจสอบฟรอ่มมาจากภายใน
 {
                int j = 4;
                int k = 8;
       
        for (int i = 0 ; i < 4; i++ ) {
               EEPROM.put(i,ipWeb[i]);                  
               EEPROM.put(j,gatewayWeb[i]);
               EEPROM.put(k,subnetWeb[i]);                   
               j++ ;
               k++ ;         
              EEPROM.commit();   
             
                  
               
                   
                
           }

                        delay(1000);
                        ESP.restart() ;   
}
     
   
              
              client.println(F("<p  class='ST3' >" ));
              client.println (" Fail...."); 
        //      client.println (inStr); 
             client.println(F("</p>\n" ));
       
    client.println(F("</body></html>"));
   
    client.stop();
    
}

void xml() {
  HeaderXml();  
  client.println(F("<?xml version='1.0'?>"));
  client.println(F("<xmldata>"));
  client.println(F("<data>"));
  client.println(Mux1);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Mux2);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Mux3);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Mux4);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Mux5);
  client.println(F("</data>"));  
  
  client.println(F("<data>"));
  client.println(Power1);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Power2);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Power3);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Power4);
  client.println(F("</data>")); 
  client.println(F("<data>"));
  client.println(Power5);
  client.println(F("</data>"));

  client.println(F("<data>"));
  client.println(Current1);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Current2);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Current3);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Current4);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Current5);
  client.println(F("</data>"));  

   client.println(F("<data>"));
  client.println(Hz1 );
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Hz2);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Hz3);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Hz4);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Hz5);
  client.println(F("</data>"));  

  
   client.println(F("<data>"));
  client.println(Factor1 );
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Factor2);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Factor3);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Factor4);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Factor5);
  client.println(F("</data>"));  

  client.println(F("<data>"));
  client.println(Volt1 );
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Volt2);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Volt3);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Volt4);
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(Volt5);
  client.println(F("</data>")); 
  client.println(F("</xmldata>"));
   /* client.println(F("<data>"));
  client.println(F("data3"));
  client.println(F("</data>"));
  client.println(F("<data>"));
  client.println(F("data1"));
  client.println(F("</data>"));*/
 
 
  client.stop();
}


   void Live_Volt(){
            Header    ();  
     client.println("<html>");
    client.println("<head>");
    client.println("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">");
    client.println("<title>AMD .. Voltage</title>");
    client.println("<script type=\"text/javascript\" src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js\"></script>");
    client.println("<script type=\"text/javascript\" src=\"https://code.highcharts.com/highcharts.js\"></script>");
    client.println("<script>");
    client.println("var chart; // global");
  
    /**
     * Request data from the server, add it to the graph and set a timeout to request again
     */
    client.println("function requestData() {");
    client.println("$.ajax({");
        //url: 'live-server-data.php', 
    client.println(" url: 'show_Volt.php', ");
    client.println("success: function(point) {");
    client.println("var series = chart.series[0],");
    client.println(" shift = series.data.length > 50; // shift if the series is longer than 20");
    
          // add the point
    client.println("chart.series[0].addPoint(eval(point), true, shift);");
          
          // call it again after one second
    client.println("setTimeout(requestData, 5000);");  
    client.println("},");
    client.println("cache: false");
    client.println("});");
    client.println(" }");
      
    client.println("$(document).ready(function() {");
    client.println("chart = new Highcharts.Chart({");
    client.println("chart: {");
          
    client.println("renderTo: 'container',");          
    client.println("defaultSeriesType: 'spline',");
          //defaultSeriesType: 'pie',
    client.println("events: {");
    client.println("load: requestData");
    client.println("}");
    client.println(" },");
    client.println("title: {");
    client.println("text: 'ChiangMon ',");
    client.println("align: 'center'");                       
    client.println("},");
    client.println("subtitle: {");
    client.println("text: '( Volt )'");
    client.println("},");
    client.println("xAxis: {");
    client.println("type: 'datetime',");
    client.println("tickPixelInterval: 150,");
    client.println("maxZoom: 20 * 1000");
    client.println("},");
    client.println("yAxis: {");
    client.println("minPadding: 0.2,");
    client.println("maxPadding: 0.2,");
    client.println("title: {");
    client.println("text: 'Value',");
    client.println("margin: 80");
    client.println("}");
    client.println(" },");
    client.println("series: [{");
    client.println("name: 'Voltage',");
    client.println("data: []");
      
    client.println(" }]");
    client.println("}); ");  
    client.println("});");
 
    client.println("</script>");

    client.println("</head>");
    client.println("<body>");
    

    client.println("<div id=\"container\" style=\"width:800px; height: 400px; margin: 0 auto\"></div>");

   client.println("</body>");
   client.println("</html>");
                   
              client.stop();
                  }

void show_Volt(){
            Header    ();  


    client.println("<html>");
    client.println("<head>");
    client.println("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">");
    client.println("<title>AMD .. Voltage</title>");

                     client.println(F("<script>\n"));
                    client.println(F("function startTime() {\n"));
                    client.println(F("var today = new Date();\n"));
                    client.println(F("var h = today.getHours();\n"));
                    client.println(F("var m = today.getMinutes();\n"));
                    client.println(F("var s = today.getSeconds();\n"));
                    client.println(F(" m = checkTime(m);\n"));
                    client.println(F(" s = checkTime(s);\n"));
                    client.println(F("document.getElementById('timezone').innerHTML =today ;\n"));
                    client.println(F(" var t = setTimeout(startTime, 500);\n"));
                    client.println(F("    }\n"));
                    client.println(F("function checkTime(i) {\n"));
                    client.println(F("  if (i < 10) {i = \"0\" + i};\n"));
                    client.println(F(" return i;\n"));
                    client.println(F("}\n"));
                    client.println(F(" </script>\n"));

    client.println("</head>");
    client.println("<body>");
    
   //int $x = time() * 1000+25200000;          
  client.print("[");
 // client.print($x);  
  client.print(",");
  client.print(Volt1);
  client.println("]");
client.println("<div id='timezone'> Time</div>");



   client.println("</body>");
   client.println("</html>");
                   
 
   
              client.stop();
                  }    
/*
void highcharts(){
            HeaderJava    ();  
            readFile("/highcharts.js");            
              client.stop();
                  }    
    

  

  void administrator(){
            Header();  
            readFile("/administrator.html");            
              client.stop();
                  }
 */                  
void tpbs(){
            HeaderPng ();  
            readFile("/tpbs.png");            
              client.stop();
                  }
void jquery_migrate(){
            HeaderJava ();  
            readFile("/jquery_migrate.js");            
              client.stop();
                  }
                  

                 
   void Font_digital7(){
            HeaderTtf();  
            readFile("/digital7.ttf");            
              client.stop();
                  }

void readFile(const char * path) {
  Serial.printf("Reading file: %s\n", path);

  File file = LittleFS.open(path, "r");
  if (!file) {
    Serial.println("Failed to open file for reading");
    return;
  }

  Serial.print("Read from file: ");
  while (file.available()) {

  
    client.write(file.read());
    
  }
  file.close();
}
void writeFile(const char * path, const char * message) {
  Serial.printf("Writing file: %s\n", path);

  File file = LittleFS.open(path, "w");
  if (!file) {
    Serial.println("Failed to open file for writing");
    return;
  }
  if (file.print(message)) {
    Serial.println("File written");
  } else {
    Serial.println("Write failed");
  }
  delay(2000); // Make sure the CREATE and LASTWRITE times are different
  file.close();
}
void renameFile(const char * path1, const char * path2) {
  Serial.printf("Renaming file %s to %s\n", path1, path2);
  if (LittleFS.rename(path1, path2)) {
    Serial.println("File renamed");
  } else {
    Serial.println("Rename failed");
  }
}

void listDir(const char * dirname) {
  Serial.printf("Listing directory: %s\n", dirname);

  Dir root = LittleFS.openDir(dirname);

  while (root.next()) {
    File file = root.openFile("r");
    Serial.print("  FILE: ");
    Serial.print(root.fileName());
    Serial.print("  SIZE: ");
    Serial.print(file.size());
    time_t cr = file.getCreationTime();
    time_t lw = file.getLastWrite();
    file.close();
    struct tm * tmstruct = localtime(&cr);
    Serial.printf("    CREATION: %d-%02d-%02d %02d:%02d:%02d\n", (tmstruct->tm_year) + 1900, (tmstruct->tm_mon) + 1, tmstruct->tm_mday, tmstruct->tm_hour, tmstruct->tm_min, tmstruct->tm_sec);
    tmstruct = localtime(&lw);
    Serial.printf("  LAST WRITE: %d-%02d-%02d %02d:%02d:%02d\n", (tmstruct->tm_year) + 1900, (tmstruct->tm_mon) + 1, tmstruct->tm_mday, tmstruct->tm_hour, tmstruct->tm_min, tmstruct->tm_sec);
  }
}

///////////////// spiffs//////////////////

/*
void readFile(fs::FS &fs, const char * path){
    Serial.printf("Reading file: %s\r\n", path);

    File file = fs.open(path);
    if(!file || file.isDirectory()){
        Serial.println("- failed to open file for reading");
        return;
    }

    Serial.println("- read from file:");
  while(file.available()){

  // ใช้ write ถ้าใช้ read จะผล เป็น ตัวเลข ไบรนารี หรือ ฐาน 16 แทน    
  client.write(file.read()); 

        
  }
}   


 void listDir(fs::FS &fs, const char * dirname, uint8_t levels){
    Serial.printf("Listing directory: %s\r\n", dirname);

    File root = fs.open(dirname);
    if(!root){
        Serial.println("- failed to open directory");
        return;
    }
    if(!root.isDirectory()){
        Serial.println(" - not a directory");
        return;
    }

    File file = root.openNextFile();
    while(file){
        if(file.isDirectory()){
            Serial.print("  DIR : ");
            Serial.println(file.name());
            if(levels){
                listDir(fs, file.name(), levels -1);
            }
        } else {
            Serial.print("  FILE: ");
            Serial.print(file.name());
            Serial.print("\tSIZE: ");
            Serial.println(file.size());
        }
        file = root.openNextFile();
    }
}
*/
/////////////////////  spiffs/////////////



/////////////////// ฟั้งชั่นแปลง String เป็น ค่า อารเรย์/////////


void splint_string(char sz[]){  // สร้างฟังชันต์ชื่อ splint_string กำหนดตัวแปรนำเข้าชื่อ sz ชนิด char แบบอาเรย์
  char *p = sz;  // สร้างตัวแปรชื่อ p ชนิด Pointer มีค่าเท่ากับ sz
  char *str;  // สร้างตัวแปรชื่อ str ชนิด Pointer
  int counter = 0;  // สร้างตัวแปรชื่อ counter ชนิด int สำหรับทำการนับครั้งที่ตัด
  int Num;
  while ((str_IP= strtok_r(p, ".", &p)) != NULL){  // วนทำลูป while ซ้ำ โดยเรียกฟังชันต์ strtok_r() โดยทำการตัดค่าใน p เมื่อเจอเครื่องหมาย','
    counter++;
  //  Serial.print(counter + String(". "));  // แสดงผลจำนวนครั้งที่ตัด
 
     int  a = counter-1 ;
     Num = str_IP.toInt();
    
     client.println("<br />");    
    
    ipWeb[a] = {Num} ;
    
   // client.print(ipWeb[a]);
   // Serial.println(); // แสดงผลค่าที่ตัดได้
  }
  counter = 0;  // เคลียร์ค่าใน counter เป็น 0
}
void splint_string2(char sz[]){  // สร้างฟังชันต์ชื่อ splint_string กำหนดตัวแปรนำเข้าชื่อ sz ชนิด char แบบอาเรย์
  char *p = sz;  // สร้างตัวแปรชื่อ p ชนิด Pointer มีค่าเท่ากับ sz
  char *str;  // สร้างตัวแปรชื่อ str ชนิด Pointer
  int counter = 0;  // สร้างตัวแปรชื่อ counter ชนิด int สำหรับทำการนับครั้งที่ตัด
  int Num2;
  while ((str_SN= strtok_r(p, ".", &p)) != NULL){  // วนทำลูป while ซ้ำ โดยเรียกฟังชันต์ strtok_r() โดยทำการตัดค่าใน p เมื่อเจอเครื่องหมาย','
    counter++;
  //  Serial.print(counter + String(". "));  // แสดงผลจำนวนครั้งที่ตัด
 
     int  a = counter-1 ;
     Num2 = str_SN.toInt();
    
     client.println("<br />");    
    
    subnetWeb[a] = {Num2} ;
    
   // client.print(ipWeb[a]);
   // Serial.println(); // แสดงผลค่าที่ตัดได้
  }
  counter = 0;  // เคลียร์ค่าใน counter เป็น 0
}
void splint_string3(char sz[]){  // สร้างฟังชันต์ชื่อ splint_string กำหนดตัวแปรนำเข้าชื่อ sz ชนิด char แบบอาเรย์
  char *p = sz;  // สร้างตัวแปรชื่อ p ชนิด Pointer มีค่าเท่ากับ sz
  char *str;  // สร้างตัวแปรชื่อ str ชนิด Pointer
  int counter = 0;  // สร้างตัวแปรชื่อ counter ชนิด int สำหรับทำการนับครั้งที่ตัด
  int Num3;
  while ((str_GW= strtok_r(p, ".", &p)) != NULL){  // วนทำลูป while ซ้ำ โดยเรียกฟังชันต์ strtok_r() โดยทำการตัดค่าใน p เมื่อเจอเครื่องหมาย','
    counter++;
  //  Serial.print(counter + String(". "));  // แสดงผลจำนวนครั้งที่ตัด
 
     int  a = counter-1 ;
     Num3 = str_GW.toInt();
    
     client.println("<br />");    
    
    gatewayWeb[a] = {Num3} ;
    
   // client.print(ipWeb[a]);
   // Serial.println(); // แสดงผลค่าที่ตัดได้
  }
  counter = 0;  // เคลียร์ค่าใน counter เป็น 0
}







     String value1, value2,value3,value4;  
     String str_IP,str_SN,str_GW;
     byte      ipWeb[4]  ;
     byte gatewayWeb[4]  ;
     byte subnetWeb[4]   ;
         
    ADC_MODE(ADC_VCC)
    int ChipId ,FChipId , FChipSize  , FChipSpeed , CycleCount , Vcc ;
   



}web_task;
