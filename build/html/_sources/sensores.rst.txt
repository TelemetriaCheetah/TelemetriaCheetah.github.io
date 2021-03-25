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

Temperatura - Dutos de ar
==========================

Descrição
------------

São usados 2 sensores de temperatura do modelo DS18B20 da Dallas Semiconductors, posicionados no início e no final do duto de ar
. Esse sensor usa a comunicação `OneWire <https://www.maximintegrated.com/en/design/technical-documents/tutorials/1/1796.html>`__.

*Especificações e características*

* `Datasheet <https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf>`__
* Tensão de operação: 3 – 5,5VDC
* Faixa de medição: -55°C a 125° celsius (recomenda-se no máximo 100º)
* Precisão: ±0,5° celsius
* Resolução: 9 ou 12 bits (configurável)
* Período de atualização: menor que 750ms

Uso
-----

Falar sobre a implementação no Cheetah aqui

Código de teste (Arduino IDE)
--------------------------------

.. code-block:: c++
  :linenos:

  #include <OneWire.h> //INCLUSÃO DE BIBLIOTECA
  #include <DallasTemperature.h> //INCLUSÃO DE BIBLIOTECA

  #define DS18B20 7 //DEFINE O PINO DIGITAL UTILIZADO PELO SENSOR

  OneWire ourWire(DS18B20); //CONFIGURA UMA INSTÂNCIA ONEWIRE PARA SE COMUNICAR COM O SENSOR
  DallasTemperature sensors(&ourWire); //BIBLIOTECA DallasTemperature UTILIZA A OneWire

  void setup()
  {
    Serial.begin(9600); //INICIALIZA A SERIAL
    sensors.begin(); //INICIA O SENSOR
    delay(1000); //INTERVALO DE 1 SEGUNDO
  }

  void loop()
  {
    sensors.requestTemperatures();//SOLICITA QUE A FUNÇÃO INFORME A TEMPERATURA DO SENSOR
    Serial.print("Temperatura: "); //IMPRIME O TEXTO NA SERIAL
    Serial.print(sensors.getTempCByIndex(0)); //IMPRIME NA SERIAL O VALOR DE TEMPERATURA MEDIDO
    Serial.println("*C"); //IMPRIME O TEXTO NA SERIAL
    delay(250);//INTERVALO DE 250 MILISSEGUNDOS
  }

Objetivo
------------

Objetivo do sensor validar os sidepods (dutos) é verificar o quão efetivo é o
resfriamento da caixa de bateria, local para onde estão voltados os dutos. Para
isso são necessários 2 sensores DS18B20 para dois testes diferentes: no primeiro,
que será realizado avaliando somente um duto de cada vez, um sensor seria colocado
na entrada do duto e o outro na saída, para que seja obtida a diferença entre essas
temperaturas. Dessa forma é possível verificar a geometria escolhida dos dutos
comparando com dados de simulações. No segundo teste os sensores serão colocados
nas laterais da caixa de bateria, onde incide o ar vindo dos dutos. Assim serão
coletados os dados de temperatura da caixa de baterias com e sem dutos. Dessa
forma sendo verificada a eficiência dos dutos no carro.


Temperatura - Freios
======================

Descrição
------------

Há no carro 4 sensores infravermelhos, que são sensores de temperatura do modelo
mlx90614 e fabricante Melexis, posicionados em cada roda próximo aos
discos de freio. Os sensores utilizam comunicação `I²C <http://www.univasf.edu.br/~romulo.camara/novo/wp-content/uploads/2013/11/Barramento-e-Protocolo-I2C.pdf>`_.

*Especificações e características*

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
  //Define o endereco I2C do display e qtde de colunas e linhas
  LiquidCrystal_I2C lcd(0x3B, 16, 2);
  //Array que desenha o simbolo de grau
  byte grau[8] = {B00110, B01001, B01001, B00110,
                  B00000, B00000, B00000, B00000,};
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

Indutivo
==========================

Usamos 4 sensores indutivos do modelo PS2-12GI50-E2-Ex fabricante Sense, com
comunicação `OneWire <https://www.maximintegrated.com/en/design/technical-documents/tutorials/1/1796.html>`__. Usado para saber a velocidade de cada pneu,
ficam acoplados um em cada roda perto dos furos da roda fônica,
não é necessário um conector especifico irão para o chicote e do chicote para as placas.

Descrição
------------

*Especificações e características*

* `Datasheet <https://www.sense.com.br/produtos/detalhes/10398/por/1/1/sensores/sensores-indutivos-tubulares-standard/PS2-12GI50-E2-Ex>`__
* Tensão de alimentação: 10 a 30Vcc
* Ripple: ±10 %
* Corrente de consumo: <10 mA
* Diâmetro: 	M12
* Distancia sensora: 2 mm
* Montagem 	Embutida
* Histerese: ± 5 %
* Repetibilidade: 	<0,01 mm
* Distancia operacional: 1,62 mm
* Alvo padrão: 12x12 mm
* Peso: 	110 g

Uso
-----

O sensor funciona com uma tensão de 12V, utilizam-se resistores para diminuir e enviar um sinal de 3v para o microcontrolador,
também é necessário ficar uma distância de 3mm (Verificar datasheet). Recebemos as informações a partir de interrupções, logo temos varias maneiras de saber sua velocidade como:

.. image:: images/indutivo_formula.png
  :align: center

Mas no programa usamos a velocidade a partir de funções de tempo.

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

Objetivo
------------

Objetivo do sensor Indutivo é saber a velocidade média, análises gerais como ponto de frenagens,
acelerações, comparações de voltas para a correção de pilotagem

Relógio de tempo real
==========================

Descrição
------------
O módulo de relógio em tempo real fornece informações precisas de horário para o microcontrolador embarcado,
através do protocolo `I²C <http://www.univasf.edu.br/~romulo.camara/novo/wp-content/uploads/2013/11/Barramento-e-Protocolo-I2C.pdf>`_.
*Especificações e características*

* `Datasheet <https://datasheets.maximintegrated.com/en/ds/DS1307.pdf>`__
* Computa segundos, minutos, horas, dias da semana, dias do mês, meses e anos (de 2000 a 2099).
* 56 bytes de SRAM que podem ser usadas como RAM extendida do microcontrolador.
* Circuito de detecção de falha de energia.
* Consome menos de 500nA no modo bateria com oscilador em funcionamento.
* Faixa de temperatura: -40°C a +85°C.
* Dimensões: 27 x 28 x 8,4mm

Uso
-----

Código de teste (Arduino IDE)
--------------------------------

.. code-block:: c++
  :linenos:

  //Programa : Relogio com modulo RTC DS1307
  //Autor : FILIPEFLOP

  //Carrega a biblioteca do RTC DS1307
  #include <DS1307.h>

  //Modulo RTC DS1307 ligado as portas A4 e A5 do Arduino
  DS1307 rtc(A4, A5);

  void setup()
  {
    //Aciona o relogio
    rtc.halt(false);

    //As linhas abaixo setam a data e hora do modulo
    //e podem ser comentada apos a primeira utilizacao
    rtc.setDOW(FRIDAY);      //Define o dia da semana
    rtc.setTime(20, 37, 0);     //Define o horario
    rtc.setDate(6, 6, 2014);   //Define o dia, mes e ano

    //Definicoes do pino SQW/Out
    rtc.setSQWRate(SQW_RATE_1);
    rtc.enableSQW(true);

    Serial.begin(9600);
  }

  void loop()
  {
    //Mostra as informações no Serial Monitor
    Serial.print("Hora : ");
    Serial.print(rtc.getTimeStr());
    Serial.print(" ");
    Serial.print("Data : ");
    Serial.print(rtc.getDateStr(FORMAT_SHORT));
    Serial.print(" ");
    Serial.println(rtc.getDOWStr(FORMAT_SHORT));

    //Aguarda 1 segundo e repete o processo
    delay (1000);
  }


Objetivo
------------

O RTC é essencialmente utilizado na organização dos dados, fornecendo um horário e
uma data com precisão e baixo consumo.  Informando ano, mês, dia, hora(formato 12 ou 24),
minuto e segundo, com as devidas correções de mês e ano. Em caso de falha de energia
ele automaticamente aciona a bateria para evitar perda de dados.

Diagrama de conexões
=====================

.. image:: images/diagrama.png
  :align: center


Referências
================

* https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-de-temperatura-ds18b20-prova-dagua-do-tipo-sonda
* https://www.arduinoecia.com.br/sensor-de-temperatura-mlx90614-arduino/
* https://www.filipeflop.com/produto/sensor-de-temperatura-ir-mlx90614/
* https://www.filipeflop.com/blog/relogio-rtc-ds1307-arduino/
