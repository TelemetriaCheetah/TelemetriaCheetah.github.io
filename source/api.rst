Programação embarcada
***********************

Para facilitar a programação, reduzir a quantidade de código repetido e manter a organização dos programas das diversas placas de telemetria, optou-se por criar algumas bibliotecas que agregam várias funções úteis para o projeto.


Cheetah (Arduino)
=======================

A biblioteca Cheetah é composta pelo arquivo header Cheetah.h e pelo arquivo fonte Cheetah.cpp. Sua implementação utiliza a Arduino.h como base, e portanto é limitada ao uso em conjunto com o framework arduino.
Os métodos públicos das classes estão descritos abaixo:

CheetahSerial
+++++++++++++++++++

A classe CheetahSerial lida com as comunicações seriais entre o microcontrolador e o rádio.

.. cpp:function:: void addAnalogSensor(uint16_t value)

Adiciona um valor inteiro de 16 bits ao buffer da biblioteca.
    
.. cpp:function:: void addDigitalSensor(uint8_t value)

Adiciona ao buffer da biblioteca um valor inteiro de 8 bits que representa o estado lógico (0 ou 1) de um sensor ou varíavel. Será empacotado em grupos de 8 bits para a transmissão, LIFO.

.. cpp:function:: void sendPayload()

Envia o pacote de informações para a saída UART.

Acelerometro
++++++++++++++++++++++++++++++

.. cpp:function:: uint16_t* leituraVariaveis();

Retorna um vetor com 7 inteiros de 16 bits contendo as informações lidas do sensor acelerômetro

.. list-table:: 
  :widths: 1 1 1 1 1 1 1
  :header-rows: 1

  * - 0
    - 1
    - 2 
    - 3
    - 4
    - 5
    - 6
  * - ACCX
    - ACCY
    - ACCZ
    - TMP
    - GYRX
    - GYRY
    - GYRZ

CheetahCAN
++++++++++++++++++

.. cpp:function:: uint8_t beginCAN()

Inicializa o MCP2515

.. cpp:function:: void addToPayload8(byte value)

Adiciona ao buffer interno da biblioteca um valor inteiro de 8 bits (Um campo CAN).

.. cpp:function:: void addToPayload16(uint16_t value)

Adiciona ao buffer interno da biblioteca um valor inteiro de 16 bits (2 campos CAN).

.. cpp:function:: void setMsgId(uint16_t value)

Configura o ID CAN da próxima mensagem.

.. cpp:function:: uint8_t sendMessage(uint16_t id)

Envia o buffer CAN.

.. cpp:function:: bool readMessage()

Retorna verdadeiro quando receber uma mensagem do barramento.

.. cpp:function:: uint16_t getMsgId()

Retorna o ID da última mensagem recebida.

.. cpp:function:: uint16_t getMsgLen()

Retorna o DLC da últma mensagem recebida.

.. cpp:function:: byte* getMsg()

Retorna um vetor contendo os dados da última mensagem recebida.

CelulaDeCarga
++++++++++++++++++

.. cpp:function:: uint16_t testeCelula()

Inicia uma rotina de calibração e teste da célula de carga conectada.

.. cpp:function:: uint16_t readCellValue()

Retorna o valor com tara lido da célula de carga.