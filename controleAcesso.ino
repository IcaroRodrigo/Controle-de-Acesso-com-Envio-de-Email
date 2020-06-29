//Programa : RFID - Controle de Acesso leitor RFID
//Autor : FILIPEFLOP
 
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
LiquidCrystal lcd(6, 7, 5, 4, 3, 2); 
 
char st[20];
 
void setup() 
{
  Serial.begin(9600);   // Inicia a serial
  SPI.begin();      // Inicia  SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
  //Define o número de colunas e linhas do LCD:  
  lcd.begin(16, 2);  
  mensageminicial();
}
 
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Mostra UID na serial 
  //Serial.print("UID da tag :");// ADEQUAÇÃO DO CÓDIGO
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  //Serial.println();
  conteudo.toUpperCase();
  if (conteudo.substring(1) == "4C AC A6 35") //UID 1 - Chaveiro
  { 
  
  
  //ALTERAÇÃO REALIZADA PARA ADEQUAÇÃO DO SCRIPT DESENVOLVIDO POR FILIPEFLOP, AO MEU PROPOSITO DE TRAFEGAR O CONTEUDO VIA SERIAL E EFETUAR LEITURA 
  //DA PORTA VIA PHP E ENVIAR UM EMAIL DE ALERTA
  
    Serial.println("Sucesso: Icaro,Cartao:"+ conteudo.substring(1));
    Serial.println();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ola Icaro !");
    lcd.setCursor(0,1);
    lcd.print("Acesso liberado!");
    delay(3000);
    mensageminicial();
  }
  else{
    Serial.println("Erro:" + conteudo.substring(1));
    Serial.println();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(conteudo.substring(1));
    lcd.setCursor(0,1);
    lcd.print("Acesso Negado !");
    delay(3000);
    mensageminicial();
   }
   
   //FIM DA ALTERAÇÃO
} 
 
void mensageminicial()
{
  lcd.clear();
  lcd.print(" Aproxime o seu");  
  lcd.setCursor(0,1);
  lcd.print("cartao do leitor");  
}
