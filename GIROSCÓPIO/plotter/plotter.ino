// Projeto para Criar / Ler Arquivos .txt junto ao Cartão SD Arduino
// Módulo MPU6050 GIROSCÓPIO

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>

Adafruit_MPU6050 mpu; 
File Myfile ;

 
int pinoSS = 10; // Pin 53 para Mega / Pin 10 para UNO
 
void setup() { // Executado uma vez quando ligado o Arduino

 Serial.begin(115200); // Define BaundRate
  while (!Serial) {
    delay(10); // will pause Zero, Leonardo, etc until serial console opens
  }

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("");

  
pinMode(pinoSS, OUTPUT); // Declara pinoSS como saída
if (SD.begin()) { // Inicializa o SD Card
Serial.println("SD Card pronto para uso."); // Imprime na tela

}
else {
Serial.println("Falha na inicialização do SD Card.");
return;
}
 
Myfile = SD.open("Monitoramento.txt", FILE_WRITE); // Cria / Abre arquivo .txt
 {
if (Myfile) { // Se o Arquivo abrir imprime:
Serial.println("Escrevendo no Arquivo .txt"); // Imprime na tela
Myfile.println(!mpu.begin()); // Escreve no Arquivo
Myfile.close(); // Fecha o Arquivo após escrever
Serial.println("Terminado."); // Imprime na tela
Serial.println(" ");


else {     // Se o Arquivo não abrir
Serial.println("Erro ao Abrir Arquivo .txt"); // Imprime na tela
}
 
myFile = SD.open("usina.txt"); // Abre o Arquivo
 
if (myFile) {
Serial.println("Conteúdo do Arquivo:"); // Imprime na tela
 
while (myFile.available()) { // Exibe o conteúdo do Arquivo
Serial.write(myFile.read());
}
 
myFile.close(); // Fecha o Arquivo após ler
}
 
else {
Serial.println("Erro ao Abrir Arquivo .txt"); // Imprime na tela
}
 
}
 
void loop() {
 
// Como a função é executada somente uma vez, esta área permanece em branco
 
}
