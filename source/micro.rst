Hardware
************************
Essa seção documenta os aspectos técnicos da implementação do hardware. 


Testes
=========================

CAN e microcontroladores
-------------------------------


Teste para validação da comunicação CAN entre os microcontroladores e transceivers do projeto.

* **Data:** 03/05/2021
* **Autor:** Caio Tácito Borges da Costa
* **Relatório:** :download:`Baixar relatório em PDF </docs/teste_can.pdf>`
* **Código Fonte:** :download:`Baixar código fonte em ZIP </docs/src.zip>`

CAN e BMS
-------------------------------

Teste para validação da comunicação CAN entre os microcontroladores e o BMS do carro.

* **Data:** 03/05/2021
* **Autor:** Caio Tácito Borges da Costa
* **Relatório:** :download:`Baixar relatório em PDF </docs/can_oficina.pdf>`

.. code-block:: c++
  :linenos:

  /* Código fonte para teste de comunicação CAN - BMS
  * Não esquecer de configurar os pinos no config.h
  * Plataforma: ATmega2560
  * Autor: Caio Tácito
  * Data: 03/05/2021
  * CHEETAHPORRA!
  */
  #include "Cheetah.h"

  //Instanciando objetos
  CheetahCAN can;
  CheetahSerial serial;

  void setup()
  {
    //Incializa serial
    Serial.begin(115200);
    //Inicializa CAN
    can.beginCAN();
  }

  void loop()
  {
    //Verifica se há mensagem disponível
    if(can.readMessage())
    {
      //Guarda a mensagem em um vetor
      byte* dados = can.getMsg();
      //Converte os valores para 8 bits shiftando e fazendo OR
      //E depois os adiciona ao buffer serial
      serial.addAnalogSensor(dados[0] | dados[1]<<8);
      serial.addAnalogSensor(dados[2] | dados[3]<<8);
      serial.addAnalogSensor(dados[4] | dados[5]<<8);
      serial.addAnalogSensor(dados[6] | dados[7]<<8);
      //Envia os dados para a serial
      serial.sendPayload();
    }
  }
  

Referências
==================

NASCIMENTO, Lucas de Camargo. PROTOCOLO DE COMUNICAÇÃO CAN E SUAS APLICAÇÕES NA INDÚSTRIA AUTOMOBILÍSTICA. Orientador: André Luís Faustino da Silva. 2006. TCC (Engenharia Elétrica - Graduação) - Universidade São Francisco de Itatiba - SP, [S. l.], 2006.