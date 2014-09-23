// Codigo do prototipo

#include <Client.h>
#include <Ethernet.h>
#include <Server.h>
#include <Udp.h>
#include <SPI.h>
#define echoPin 5
#define trigPin 4

const float CELSIUS_BASE = 0.4887585532746823069403714565; //Base de conversão para Graus 
const int LM35 = A0; // Pino Analogico onde vai ser ligado ao pino 2 do LM35

byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 
  192, 168, 25, 10 };
EthernetServer server(80);
int conta_caracter=0 ;
int max_linha = 80; 
String linha_de_entrada = String(max_linha) ;
boolean LEDON = false ;
const int ledUmRele =  7;
const int ledDoisRele =  6;
int temperatura;

void setup()
{
  Serial.begin(9600) ;
  Ethernet.begin(mac, ip);
  server.begin();
  pinMode(ledUmRele, OUTPUT);
  pinMode(ledDoisRele, OUTPUT);
  
  pinMode(echoPin,INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop()
{
  EthernetClient client = server.available();
  if (client) {

    boolean current_line_is_blank = true;
    conta_caracter=0 ;
    linha_de_entrada="" ;

    while (client.connected()) {
      if (client.available()) {
        // recebe um caracter enviado pelo browser
        char c = client.read();
        // se a linha não chegou ao máximo do armazenamento 
        // então adiciona o caractere a linha de entrada
        if(linha_de_entrada.length() < max_linha) {
          linha_de_entrada.concat(c) ; 
        }  

        // Se foi recebido um caracter linefeed - LF
        // e a linha está em branco , a requisição http encerrou.
        // Assim é possivel iniciar o envio da resposta

        if (c == '\n' && current_line_is_blank) {
          // envia uma resposta padrão ao header http recebido
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          // começa a enviar o formulário
          client.print("<html>") ;
          client.print("<body bgcolor = \"#FF8800\">");

          client.println("<h1><center><font color=\"#FFFFFF\" size=\"10\">SkyON</font></center></h1>"); 
          
          client.println("<h3><center><font color=\"#FFFFFF\" size=\"5\">Equipe</font></center></h3><hr/>");
          client.println("Yelken Heckman");
          client.println("Antonio Fernandes");
          client.println("Maria Palloma");
          client.println("Lidiane Monteiro");
          client.println("<hr/>");
          
          
          client.println("<h3><center><font color=\"#FFFFFF\" size=\"5\">Dados coletados no prototipo</font></center></h3>");
          temperatura = analogRead(0);          
          client.print("<h3> Temperatura: ");
          client.print(readTemperature());
          
          client.print("</h3>");
          digitalWrite(trigPin, LOW);
          delayMicroseconds(2);
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          long duration = pulseIn(echoPin, HIGH);
          long distancia = duration / 29 /2;
          
          client.print("<h3> Altitude: ");
          client.print(distancia);
          client.print("m");
          
          client.print("</h3>");      
          client.print("<h3> Vento forte: ");
          client.print(digitalRead(8));
          client.print("</h3>");

          client.print("</h3>");      
          client.print("<h3> Luminosidade: ");
          client.print(analogRead(1));
          client.print("</h3>");          
       
          //          client.println("<br>") ;
          client.println("<hr/>");
          client.println("<h3><center><font color=\"#FFFFFF\" size=\"5\">Controle dos sensores</font></center></h3>");
          client.println("<br>") ;
          client.println("<h2>SENSOR 1</h2>");
          client.println("<br>") ;
          client.println("<form method=get name=LED>") ;

          client.println("LIGA <input ")  ;
          // verifica o status do led e ativa o radio button 
          // correspondente
          if(LEDON) {
            client.println("checked='checked'") ;
          }
          client.println("name='LED' value='ON' type='radio' >");

          client.println("DESLIGA <input ")  ;
          if(!LEDON) {
            client.println("checked='checked'") ;
          }
          client.println("name='LED' value='OFF' type='radio' >");
          // exibe o botão do formulário
          client.println("<br><br><br><hr/> <br><input type=submit value='ATUALIZA'></form>") ;
          
          //Led 2
          client.println("<br>") ;
          client.println("<h2>SENSOR 2</h2>");
          client.println("<br>") ;
          client.println("<form method=get name=LED>") ;
          client.println("LIGA <input ")  ;
          // verifica o status do led e ativa o radio button 
          // correspondente
          if(LEDON) {
            client.println("checked='checked'") ;
          }
          client.println("name='LEDDOIS' value='ON' type='radio' >");

          client.println("DESLIGA <input ")  ;
          if(!LEDON) {
            client.println("checked='checked'") ;
          }
          client.println("name='LEDDOIS' value='OFF' type='radio' >");
          // exibe o botão do formulário
          client.println("<br><br><br><hr/> <br><input type=submit value='ATUALIZA'></form>") ;
          // Fim Led 2
          
          
          client.println("</body>") ;
          client.println("</html>");

          break;
        }

        if (c == '\n') {
          // se o caracter recebido é um linefeed então estamos começando a receber uma 
          // nova linha de caracteres

          // Analise aqui o conteudo enviado pelo submit
          if(linha_de_entrada.indexOf("GET") != -1 ){
            // se a linha recebida contem GET e LED=ON enão guarde o status do led
            if(linha_de_entrada.indexOf("LED=ON") != -1 ){ 
              digitalWrite(ledUmRele, LOW);
              Serial.print('1');

              LEDON=true;
            }
            if(linha_de_entrada.indexOf("LED=OFF") != -1 ){ 
              // se a linha recebida contem GET e LED=OFF enão guarde o status do led
              digitalWrite(ledUmRele, HIGH);
              Serial.print('0');
              LEDON=false ;
            }
            
            if(linha_de_entrada.indexOf("LEDDOIS=ON") != -1 ){ 
              digitalWrite(ledDoisRele, LOW);
              Serial.print('1');

              LEDON=true;
            }
            if(linha_de_entrada.indexOf("LEDDOIS=OFF") != -1 ){ 
              // se a linha recebida contem GET e LED=OFF enão guarde o status do led
              digitalWrite(ledDoisRele, HIGH);
              Serial.print('0');
              LEDON=false ;
            }
          }

          current_line_is_blank = true;
          linha_de_entrada="" ;

        } 
        else if (c != '\r') {
          // recebemos um carater que não é linefeed ou retorno de carro 
          // então recebemos um caracter e a linha de entrada não está mais vazia
          current_line_is_blank = false;
        }
      }
    }
    // dá um tempo para  o browser receber os caracteres
    delay(1);
    client.stop();
  }
}

float readTemperature(){
  return (analogRead(LM35) * CELSIUS_BASE); 
}
