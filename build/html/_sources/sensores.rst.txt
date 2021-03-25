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
. Esse sensor usa a comunicação `Dallas OneWire <https://www.maximintegrated.com/en/design/technical-documents/tutorials/1/1796.html>`_.

*Especificações e características*

* `Datasheet <https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf>`__
* Tensão de operação: 3 – 5,5VDC
* Faixa de medição: -55°C a 125° celsius (recomenda-se no máximo 100º)
* Precisão: ±0,5° celsius
* Resolução: 9 ou 12 bits (configurável)
* Período de atualização: menor que 750ms
* Encapsulamento em aço inoxidável
* Dimensão do encapsulamento: 6mm x 50mm
* Comprimento do cabo: 1m

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



Diagrama de conexões
=====================

.. image:: images/diagrama.png
  :align: center


Referências
================

* https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-de-temperatura-ds18b20-prova-dagua-do-tipo-sonda
* https://www.arduinoecia.com.br/sensor-de-temperatura-mlx90614-arduino/
* https://www.filipeflop.com/produto/sensor-de-temperatura-ir-mlx90614/
