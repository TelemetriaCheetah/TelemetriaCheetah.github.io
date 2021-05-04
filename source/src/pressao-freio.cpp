//Biblioteca
//.h
#ifndef PRESSAOFREIOS_H	//Verificar a existencia de outra biblioteca com esse nome
#define PRESSAOFREIOS_H	//Definir o nome da biblioteca como "PressaoFreios"
#include "Arduino.h" //Incluir biblioteca do arduino para ser ultilizada
#include "math.h"

class TesteFreios{

  private:
    int _PIN;	//Objeto criado (Sensor de Pressao de Freios)
    float map(float x, float min, float max, float out_min, float out_max);

  public:
    TesteFreios();	//Criação do objeto
    TesteFreios(int);	//Criação do objeto com parametros

    float getPress(); //Função para calcular a pressao
    int getAnalog();
};
#endif
//.cpp
#include "PressaoFreios.h"

TesteFreios::TesteFreios(int PIN) { //recebendo informações da biblioteca TesteFreios.h
 _PIN = PIN;
  pinMode (_PIN, INPUT);	//Inicio do sinal _PIN como INPUT
}

float TesteFreios::map(float x, float min, float max, float out_min, float out_max) {
  return (x - min) * (out_max - out_min) / (max - min) + out_min;
}
float TesteFreios::getPress(){
  float getPress = map((float)analogRead(_PIN), 102.3, 920.7, 0.0, 80.0);
  getPress = constrain(getPress, 0.0, 80.0);
  return getPress;
}

int TesteFreios::getAnalog(){
  return analogRead(_PIN);
}
