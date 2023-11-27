// Bibliotecas necessárias
#include <IRremote.h>

// Define o pino do sensor infravermelho
const int pinoSensorIR = 2;

// Define o pino de controle da lâmpada
const int pinoLampada = 13; // Por exemplo, use o pino 13 para uma lâmpada LED

// Define o tempo em milissegundos durante o qual a lâmpada ficará acesa após detectar movimento
const unsigned long tempoAceso = 10000; // 10 segundos

IRrecv receptor(pinoSensorIR);
decode_results resultados;

void setup() {
  pinMode(pinoLampada, OUTPUT);
  digitalWrite(pinoLampada, LOW); // Desliga a lâmpada no início

  receptor.enableIRIn(); // Inicializa o receptor de infravermelho
  Serial.begin(9600);
}

void loop() {
  if (receptor.decode(&resultados)) {
    if (resultados.value == 0xFFA25D) { // Substitua pelo código do seu controle remoto
      digitalWrite(pinoLampada, HIGH); // Liga a lâmpada
      delay(tempoAceso);
      digitalWrite(pinoLampada, LOW); // Desliga a lâmpada
    }
    receptor.resume(); // Recebe o próximo código IR
  }
}
