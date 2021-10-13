Sensores
************************

Nessa página estão listados os sensores que compõe o subsistema de telemetria do
Cheetah E-Racing. Aqui você encontra informações sobre as características físicas,
especificações técnicas, implementação de software e uso geral de cada um deles.
Datasheets e Application Notes também são referenciados de acordo com a necessidade.

Bibliotecas (Arduino)
======================

Essa seção lista as bibliotecas necessárias para utilizar os sensores em um ambiente Arduino. A instalação é simples, e requer apenas
a extração dos arquivos que devem ser baixados nos links abaixo para a pasta Arduino/libraries.

* `OneWire <https://blogmasterwalkershop.com.br/arquivos/libs/OneWire.zip>`_
* `DallasTemperature <https://blogmasterwalkershop.com.br/arquivos/libs/DallasTemperature.zip>`_
* `Adafruit-MLX90614 <https://github.com/adafruit/Adafruit-MLX90614-Library/tree/1.1.1>`_


Unidade de medida inercial
============================

Descrição
------------

Nesse módulo GY-521 você tem em uma mesma placa um acelerômetro e um giroscópio de alta precisão, tudo isso controlado por um 
único CI, o MPU-6050. São 3 eixos para o acelerômetro e 3 eixos para o giroscópio, sendo ao todo 6 graus de liberdade (6DOF). 
Além disso esta placa tem um sensor de temperatura embutido no CI, permitindo medições entre -40 e +85 ºC. Possui alta precisão
devido ao conversor analógico digital de 16-bits para cada canal. Portanto o sensor captura os canais X, Y e Z ao mesmo tempo. 
Essa placa utiliza o protocolo I2C para transmissão de dados.

Objetivo
------------

Utilizamos o giroscópio para o monitoramento da orientação, direção, movimentação angular e rotação do veículo. 
O acelerômetro terá a finalidade de medir a aceleração, ângulo de inclinação, rotação, vibração, colisão e gravidade do veículo. 

**Especificações e características**

* `Datasheet <https://cdn.awsli.com.br/945/945993/arquivos/MPU-6050_DataSheet_V3%204.pdf>`__
* Tensão de Operação: 3-5V
* Conversor AD 16 bits
* Faixa do Giroscópio: ±250, 500, 1000, 2000°/s
* Faixa do Acelerômetro: ±2, ±4, ±8, ±16g
* Dimensões: 20 x 16 x 2 mm

Uso
-----

A comunicação com o microcontrolador usa a interface I2C, por meio dos pinos SCL e SDA do sensor. Nos pinos XDA e XCL você pode 
ligar outros dispositivos I2C. A alimentação do módulo pode variar entre 3 e 5v, mas para melhores resultados e precisão recomenda-se 
utilizar 5v.



Sensor HALL
======================

Descrição
------------

Há no carro 1 sensor hall modelo DHAB S/118,basicamente transdutor que ficar posicionado próximos dos AIR´s.


**Especificações e características**

* `Datasheet <https://res.cloudinary.com/fastron-electronics/image/upload/v1534659891/LEM/Datasheets/dhab_s_137.pdf>`__
* Sensor transdutor
* Saída: 0.25 - 4.75V (2.5Vref)
* Temperatura operacional: -40°C - 70°C
* Precisão CH1 @ 25 Deg C: 15%(0A),0,7%(25A),1,3%(75A)
* Precisão CH2 @ 25 Deg C: 3%(0A),9%(500A),15%(900A),20%(1000A)
* Tensão de operação: 5 VDC



Uso
-----

Falar sobre a implementação no Cheetah aqui

Código de teste (Arduino IDE)
--------------------------------

.. code-block:: c++
  :linenos:



Objetivo
------------
O objetivo deste sensor é identificar a corrente positiva, funcionando com um transdutor que,quando sob a aplicação de um campo magnético,
responde com uma variação em sua tensão de saída.Esta variação de corrente fornecida pela bateria induz um campo magnético, que  induz corrente
no sensor hall.


Temperatura - Freios
======================

Descrição
------------

Há no carro 4 sensores infravermelhos, que são sensores de temperatura do modelo
mlx90614 e fabricante Melexis, posicionados em cada roda próximo aos
discos de freio. Os sensores utilizam comunicação `I²C <http://www.univasf.edu.br/~romulo.camara/novo/wp-content/uploads/2013/11/Barramento-e-Protocolo-I2C.pdf>`_.

**Especificações e características**

* `Datasheet <https://img.filipeflop.com/files/download/Datasheet_MLX90614.pdf>`__
* Sensor de temperatura IR infravermelho
* Controlador MLX90614ESF
* Saída com resolução de 10-bit PWM
* Faixa de temperatura ambiente: -40 a 125°C
* Faixa de temperatura para objetos: -70 a 380°C
* Precisão: ±0,5°C
* Tensão de operação: 3VDC
* Dimensões: 17 x 11,5 x 6 mm

.. warning::
  O sensor vem calibrado de fábrica para trabalhar com objetos com emissividade 1. É necessário alterar esse valor
  de acordo com a emissividade do material medido.

Uso
-----

Falar sobre a implementação no Cheetah aqui

Código de teste (Arduino IDE)
--------------------------------

.. code-block:: c++
  :linenos:

  //Programa: Sensor de temperatura I2C MLX90614 Arduino
  //Autor: Arduino e Cia
  #include <Wire.h>
  #include <Adafruit_MLX90614.h>
  Adafruit_MLX90614 mlx = Adafruit_MLX90614();

  double temp_amb;
  double temp_obj;
  void setup()
  {
    Serial.begin(9600);
    Serial.println("Sensor de temperatura MLX90614");
    //Inicializa o MLX90614
    mlx.begin();
  }
  void loop()
  {
    //Leitura da temperatura ambiente e do objeto
    //(para leitura dos valores em Fahrenheit, utilize
    //mlx.readAmbientTempF() e mlx.readObjectTempF() )
    temp_amb = mlx.readAmbientTempC();
    temp_obj = mlx.readObjectTempC();
    //Mostra as informacoes no Serial Monitor
    Serial.print("Ambiente = ");
    Serial.print(temp_amb);
    Serial.print("*CtObjeto = ");
    Serial.print(temp_obj); Serial.println("*C");
    //Aguarda 1 segundo ate nova leitura
    delay(1000);
  }


Objetivo
------------

O objetivo do sensor é saber a temperatura dos freios durante a corrida para que a subequipe
de freios possa conferir com os dados teóricos e ver a porcentagem de erro.
O sensor sabe a temperatura especifica e a do ambiente.

Infravermelho - Rotação
==========================

Descrição
------------

Os sensores infravermelhos de rotação utilizam um par de emissor e receptor IR para detectar a transição entre cores. O cubo de rodas é pintado num padrão "zebra" , alternando entre cor preta e branca, e 
cada transição gera um pulso rising ou falling edge que é convertido em sinal elétrico pelo fototransistor conectado ao microcontrolador. O tempo entre pulsos é então computado e utilizando o raio conhecido do 
conjunto pneu-roda é possível calcular a velocidade angular de cada roda.

Objetivo
-------------
Determinar a velocidade individual de cada roda.

Imagem
------------

.. image:: images/tcrt5000.png
  :width: 200px

**Especificações e características**

* `Datasheet <https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwjuvuOIoMjzAhWaH7kGHVlPAJ0QFnoECAUQAQ&url=https%3A%2F%2Fwww.vishay.com%2Fdocs%2F83760%2Ftcrt5000.pdf&usg=AOvVaw06pdXVi5M862u-8RP206i7>`__
* Tensão de alimentação: 5Vdc
* Corrente direta do led emissor: 60mA
* Tensão máxima coletor emissor do transistor: 70V
* Corrente máxima de coletor:	100mA
* Tamanho da onda de operação: 950mm
* Distância máxima de detecção: 25mm

Uso
-----

São instalados no cubo de rodas em um suporte rosqueado e a ligação é feita até a placa de telemetria de rodas.


Código de teste (Arduino IDE)
--------------------------------

.. code-block:: c++
  :linenos:

  #define led 10
  #define saidaSensor 7

  int Time;
  int lasTime;
  int difference;
  int IsUpdated;

  void setup(){
    Time = lasTime = difference = 0;
    pinMode(led, OUTPUT); // Pino para ativar o led
    pinMode(saidaSensor, INPUT); // Pino para ler o sinal no coletor do fototransistor
    Serial.begin(9600); // Inicializa a porta serial com baud rate de 9600
  }

Display
==========================

Descrição
------------

O display utilizado no veículo é um tablet android de 7 polegadas da marca multilaser. Seu sistema operacional (Lineage OS) 
é modificado para melhorar a performance e habilitar funções de baixo nível para a conexão serial

Objetivo
---------------

O display mostra as informações de telemetria no painel do carro durante a sua operação em testes e competições. Durante a fase de construção e enquanto o veículo está em manutenção o 
display pode ser utilizado para alterar configurações ou rodar a versão completa do sistema supervisório.

Imagem
------------

.. image:: images/tabletm7.png
  :width: 200px


**Especificações e características**

* `Datasheet <as>`__

Uso
-----

O código que roda no tablet está integrado ao servidor do sistema supervisório, e sua conexão é feita através do barramento CAN do veículo.


Pressão de freios
==========================

Descrição
------------

O sensor da linha de freios é um transdutor que converte em um sinal elétrico a pressão na linha

Objetivo
---------------

Além da coleta de dados, o sensor da linha de freios é utilizado no BSPD, para garantir que o piloto não está acelerando e freando ao mesmo tempo.

Imagem
---------

.. image:: images/cebolinha.png
  :width: 200px

**Especificações e características**

* `Datasheet (ainda não temos) <as>`__

Uso
-----

No veículo estão instalados 4 sensores de pressão de freios: um em cada cilindro mestre, um na linha de freios traseira e outro na dianteira. O sinal de saída do sensor varia de 0,5 a 4,5 V e é ligado 
nos microcontroladores mais próximos de cada instalação.

Código de teste (Arduino IDE)
--------------------------------

Utilizar código de exemplo do analogRead na IDE.

SD
==========================

Descrição
------------

Modelo do modulo do sensor SD genérico, com micro SD da SanDisk. Comunicação pela interface SPI, pinos MOSI, MISO, SCLK e CS. Como o modulo vai direto na placa central, não se utiliza conector.

**Especificações e características**

https://www.embarcados.com.br/modulo-tiny-rtc-i2c-parte-1/ (Datasheet do modelo semelhante)



Uso
-----

O modulo funciona com uma tensão de 5V..
Pinos utilizados são: Vcc 5V; GND; MOSI; MISO; SCLK; CS(SS). Cada microcontrolador tem pinos pré-selecionado, o indicador no código da serie(grupo) dos pinos é indicada pelo CS.


Código de teste (Arduino IDE)
--------------------------------

.. code-block:: c++
  :linenos:

Objetivo
------------

O cartão SD é utilizado na armazenarão de dados. Apesar de não ser o meio mais rápido, eficiente e rápido de se armazenar, é o método mais seguro. Mesmo com a utilização em paralelo de outros métodos, o SD com o modulo é uma medida de precaução, coso aconteça algo com os dados recolhidos nos outros meios, os dados armazenados no SD estão seguros. Inicialmente sendo um plano de segurança.

GPS
==========================

Descrição
------------

Modelo do modulo do sensor GPS, Adafruit Ultimatr GPS Breakout V3. Comunicação pela interface serial, pinos TX e RX. Como o modulo vai direto na placa central, não se utiliza conector.

**Especificações e características**

https://learn.adafruit.com/adafruit-ultimate-gps/downloads (datasheetes)

* `Datasheet <as>`__

Uso
-----

O modulo funciona com uma tensão tanto de 3.3V, quanto de 5V.
Pinos utilizados são: Vcc(3.3V ou 5V) ; GND; TX; RX;
Para a melhor recepção do sinal no modulo, se utiliza uma antena externa. Porém mesmo assim em diversos locais ocorre falha na recepção.


Código de teste (Arduino IDE)
--------------------------------

.. code-block:: c++
  :linenos:


Objetivo
------------

O GPS fornece diversos dados para serem coletados, o modulo é um receptor de dados do NMEA. Podemos obter o tempo(ano,  mês, dia, hora, minuto e segundo). Além da localização(latitude, longitude, altitude e ângulo), em que podemos mapear o percurso do veiculo. Também é medido a velocidade  em knots.

Encoder
==========================

Descrição
------------

Encoder é um sensores eletro-mecânicos, cuja funcionalidade é transformar movimento mecânico angular ou linear em uma série de pulsos analógicos ou digitais elétricos.

**Especificações e características**


* `Datasheet <as>`__

Uso
-----


Código de teste (Arduino IDE)
--------------------------------

.. code-block:: c++
  :linenos:


Objetivo
------------

Com a utilização de encoders, é possível quantizar distâncias, controlar velocidades, medir ângulos, número de rotações, realizar posicionamentos, rotacionar braços robóticos e etc.
Como exemplo no Cheetah medimos o angulo de rotação do volante do carro.


TPS
==========================

Descrição
------------

O Sensor de Posição da Borboleta (Throttle Position Sensor – TPS) é utilizado para monitorar a posição do acelerador em um veículo.
Através do TPS, o inversor obtém informações instantâneas da posição da borboleta permitindo à central identificar a potência que o condutor está requerendo.
Essas informações são utilizadas para determinar o torque requerido do motor, a proporção de frenagem regenerativa aplicada e para o brake pedal plausability test.

Foto
------------

.. image:: images/tps.jpg
  :align: center
  :width: 300px

**Especificações e características**

* `Datasheet <https://www.ds.ind.br/media/linhas/08/04/1_64e828aa0007739df167c3c58a5293e9.pdf>`__

Uso
-----

O TPS envia as informações para um microcontrolador, e tem o sinal convertido para o barramento CAN.

Código de teste (Arduino IDE)
--------------------------------

.. code-block:: c++
  :linenos:

  /*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
  */

  // These constants won't change. They're used to give names to the pins used:
  const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
  const int analogOutPin = 9; // Analog output pin that the LED is attached to

  int sensorValue = 0;        // value read from the pot
  int outputValue = 0;        // value output to the PWM (analog out)

  void setup() {
    // initialize serial communications at 9600 bps:
    Serial.begin(9600);
  }

  void loop() {
    // read the analog in value:
    sensorValue = analogRead(analogInPin);
    // map it to the range of the analog out:
    outputValue = map(sensorValue, 0, 1023, 0, 255);
    // change the analog out value:
    analogWrite(analogOutPin, outputValue);

    // print the results to the Serial Monitor:
    Serial.print("sensor = ");
    Serial.print(sensorValue);
    Serial.print("\t output = ");
    Serial.println(outputValue);

    // wait 2 milliseconds before the next loop for the analog-to-digital
    // converter to settle after the last reading:
    delay(2);
  }

Diagrama de conexões
======================

.. image:: images/diagrama.png
  :align: center


Referências
================

* https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-modulo-adaptador-i2c-para-display-lcd-16x2-20x4
* https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-de-temperatura-ds18b20-prova-dagua-do-tipo-sonda
* https://www.arduinoecia.com.br/sensor-gy-80-arduino-acelerometro-bussola-barometro/
* https://www.arduinoecia.com.br/sensor-de-temperatura-mlx90614-arduino/
* https://www.filipeflop.com/produto/sensor-de-temperatura-ir-mlx90614/
* https://www.filipeflop.com/blog/relogio-rtc-ds1307-arduino/
* https://ensus.com.br/extensometria-strain-gauge-o-que-e-quando-utilizar/
