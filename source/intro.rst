Introdução
*******************

O sistema de telemetria do CE-21 é projetado para receber, interpretar e visualizar dados diagnósticos do veículo da equipe durante os testes e competições.
O hardware é composto por 6 placas de circuito:

#. **Telemetria frontal:** Montada no painel do carro. É responsável por coletar dados de sensores da região frontal e é conectada ao display LCD;
#. **Telemetria traseira:** Montada nos tubos de chassi na traseira do veículo. É a principal placa de telemetria, coleta todos os dados e os envia por rádio para os computadores conectados;
#. **Placas das rodas:** São montadas em cada roda do carro e recebem dados dos sensores de rotação e temperatura dos discos de freio.

O diagrama abaixo mostra uma versão simplificada da arquitetura implementada:

.. image:: images/overview.png
  :width: 320
  :align: center

Modos de operação
================================

O software é desenvolvido para trabalhar em 3 modos distintos:

#. **Tempo Real**: É utilizado nos testes e competições para receber as informações coletadas dos sensores enquanto o carro está na pista. A transmissão de dados ocorre via rádio e vários dispositivos (clientes) podem se conectar ao servidor ao mesmo tempo, permitindo que vários membros da equipe trabalhem em conjunto monitorando indicadores vitais do veículo. Para possibilitar análises posteriores, esse modo também salva todos os valores recebidos no banco de dados da equipe.
#. **Simulação**: A simulação trabalha com dados coletados e armazenados no banco de dados do servidor, recebidos do rádio (em condições normais) ou importados do cartão de memória embarcado (em caso de perda de sinal de rádio / backup). Esse modo permite que o usuário escolha um intervalo de tempo específico, como por exemplo uma volta na pista, e veja todos os dados relevantes do período em forma de gráficos.
#. **Espectador**: O modo espectador é uma versão especial do modo de tempo real que mostra apenas algumas informações do sistema de telemetria. Pode ser utilizado para permitir que não-membros possam acompanhar dados não-confidenciais do veículo durante um teste através de uma rede WiFi específica.

Dados coletados
==========================

Para garantir a organização do software, utiliza-se um código universal específico para cada sensor:

* Primeira letra: 'S';
* Segunda letra: 'A' para sensores de medição ou 'D' para sensores discretos;
* Número: Um número inteiro único que identifica o sensor.

A tabela abaixo lista todos os sensores registrados:

.. list-table:: Discretos
   :widths: 10 25 30 25
   :header-rows: 1

   * - Código
     - Nome
     - Descrição
     - Subsistema
   * - SD1
     - Inertia Switch
     - Detecção de impacto
     - Circuito de desligamento
   * - SD2
     - BOTS (Brake Over Travel Switch)
     - Curso do pedal de freio
     - Circuito de desligamento
   * - SD3
     - Sinal do BMS (Battery Managenent System)
     - Verificação de erro do BMS
     - Circuito de desligamento
   * - SD4
     - Sinal do IMD (Insulation Monitoring Device)
     - Verificação de erro do IMD
     - Circuito de desligamento
   * - SD5
     - Latch do BSPD
     - Estado do latch do BSPD
     - Circuito de segurança
   * - SD6
     - Latch do BMS
     - Estado do latch do BMS
     - Circuito de segurança
   * - SD7
     - Latch do IMD
     - Estado do latch do IMD
     - Circuito de segurança
   * - SD8
     - Reset mestre
     - Estado do reset mestre
     - Circuito de segurança
   * - SD9
     - Reset secundário
     - Estado do reset secundário
     - Circuito de segurança
   * - SD10
     - Estado do circuito de desligamento
     - Monitora a saída do circuito de desligamento
     - Circuito de segurança
   * - SD11
     - TSMS
     - Chave do sistema de tração
     - Circuito de desligamento
   * - SD12
     - GLVMS
     - Chave do sistema de baixa tensão
     - Circuito de desligamento
   * - SD13
     - Botão direito
     - Botão de desligamento
     - Circuito de desligamento
   * - SD14
     - Interlock da bateria
     - Interlock da bateria
     - Circuito de desligamento
   * - SD15
     - Botão esquerdo
     - Botão de desligamento
     - Circuito de desligamento
   * - SD16
     - Interlock do HVD
     - Interlock do HVD
     - Circuito de desligamento
   * - SD17
     - Botão frontal
     - Botão de desligamento
     - Circuito de desligamento


.. list-table:: Medição
  :widths: 1 1 1 1
  :header-rows: 1

  * - Código
    - Nome
    - Descrição
    - Subsistema
  * - SA1
    - Throttle Position Sensor
    - Porcentagem de atuação do pedal do acelerador
    - Powertrain
  * - SA2
    - Throttle Position Sensor
    - Porcentagem de atuação do pedal do acelerador
    - Powertrain
  * - SA4
    - Sensor reflexivo infravermelho
    - Rotação da roda frontal direita
    - Freios
  * - SA5
    - Sensor reflexivo infravermelho
    - Rotação da roda frontal esquerda
    - Freios
  * - SA6
    - Sensor reflexivo infravermelho
    - Rotação da roda traseira direita
    - Freios
  * - SA7
    - Sensor reflexivo infravermelho
    - Rotação da roda traseira esquerda
    - Freios
  * - SA8
    - Sensor de temperatura infravermelho
    - Temperatura do centro do disco de freio frontal direito
    - Freios
  * - SA9
    - Sensor de temperatura infravermelho
    - Temperatura da borda do disco de freio frontal direito
    - Freios
  * - SA10
    - Sensor de temperatura infravermelho
    - Temperatura do centro do disco de freio frontal esquerdo
    - Freios
  * - SA11
    - Sensor de temperatura infravermelho
    - Temperatura da borda do disco de freio frontal esquerdo
    - Freios
  * - SA12
    - Sensor de temperatura infravermelho
    - Temperatura do centro do disco de freio traseiro direito
    - Freios
  * - SA13
    - Sensor de temperatura infravermelho
    - Temperatura da borda do disco de freio traseiro direito
    - Freios
  * - SA14
    - Sensor de temperatura infravermelho
    - Temperatura do centro do disco de freio traseiro esquerdo
    - Freios
  * - SA15
    - Sensor de temperatura infravermelho
    - Temperatura da borda do disco de freio traseiro esquerdo
    - Freios
  * - SA16
    - Encoder do volante
    - Ângulo de rotação do volante
    - Suspensão
  * - SA17
    - Latitude (GNSS)
    - Valor da latitude obtida por satélite
    - Telemetria
  * - SA18
    - Longitude (GNSS)
    - Valor da longitude obtida por satélite
    - Telemetria
  * - SA19
    - Contagem de satélites (GNSS)
    - Número de satélites da constelação na linha de visada
    - Telemetria
  * - SA20
    - HDOP (GNSS)
    - Diluição horizontal de precisão da constelação
    - Telemetria
  * - SA21
    - Acelerômetro (IMU)
    - Valor da aceleração no eixo X
    - Telemetria
  * - SA22
    - Acelerômetro (IMU)
    - Valor da aceleração no eixo Y
    - Telemetria
  * - SA23
    - Acelerômetro (IMU)
    - Valor da aceleração no eixo Z
    - Telemetria
  * - SA24
    - Giroscópio (IMU)
    - Valor da velocidade angular em relação ao eixo X
    - Telemetria
  * - SA25
    - Giroscópio (IMU)
    - Valor da velocidade angular em relação ao eixo Y
    - Telemetria
  * - SA26
    - Giroscópio (IMU)
    - Valor da velocidade angular em relação ao eixo Z
    - Telemetria
  * - SA27
    - Magnetômetro (IMU)
    - Valor da intensidade do campo magnético no eixo X
    - Telemetria
  * - SA28
    - Magnetômetro (IMU)
    - Valor da intensidade do campo magnético no eixo Y
    - Telemetria
  * - SA29
    - Magnetômetro (IMU)
    - Valor da intensidade do campo magnético no eixo Z
    - Telemetria
  * - SA30
    - Temperatura (IMU)
    - Temperatura da placa de telemetria traseira
    - Telemetria
  * - SA31
    - Corrente (BMS)
    - Corrente total do acumulador
    - Powertrain
  * - SA32
    - Tensão instantânea (BMS)
    - Tensão atual do acumulador
    - Powertrain
  * - SA33
    - Tensão aberta (BMS)
    - Tensão de circuito aberto do acumulador
    - Powertrain
  * - SA34
    - SOC (BMS)
    - Estado de carga do acumulador
    - Powertrain
  * - SA35
    - SSOC (BMS)
    - Estado de carga simulado do acumulador
    - Powertrain
  * - SA36
    - Amp hours (BMS)
    - Capacidade do acumulador
    - Powertrain
  * - SA37
    - Health (BMS)
    - Estado de saúde do acumulador
    - Powertrain
  * - SA38
    - Temperatura alta (BMS)
    - Temperatura da célula mais quente
    - Powertrain
  * - SA39
    - Temperatura baixa (BMS)
    - Temperatura da célula mais fria
    - Powertrain
  * - SA40
    - Temperatura média (BMS)
    - Temperatura média das células
    - Powertrain
  * - SA41
    - Temperatura interna (BMS)
    - Temperatura interna do BMS
    - Powertrain
  * - SA42
    - Tensão alta (BMS)
    - Maior tensão registrada no acumulador
    - Powertrain
  * - SA43
    - Tensão baixa (BMS)
    - Menor tensão registrada no acumulador
    - Powertrain
  * - SA44
    - Tensão média (BMS)
    - Média das tensões das células
    - Powertrain
  * - SA45
    - Resistência alta (BMS)
    - Maior resistência interna registrada no acumulador
    - Powertrain
  * - SA46
    - Resistência baixa (BMS)
    - Menor resistência interna registrada no acumulador
    - Powertrain
  * - SA47
    - Resistência média (BMS)
    - Média das resistências internas das células
    - Powertrain
  * - SA48
    - IDs temperatura (BMS)
    - Identificadores das células com maior e menor temperatura
    - Powertrain
  * - SA49
    - IDs tensão (BMS)
    - Identificadores das células com maior e menor tensão
    - Powertrain
  * - SA50
    - IDs resistência (BMS)
    - Identificadores das células com maior e menor resistência
    - Powertrain
  * - SA51
    - Fan speed (BMS)
    - Velocidade do ventilador do acumulador
    - Powertrain
  * - SA52
    - 12V (BMS)
    - Tensão de alimentação do BMS
    - Powertrain
  * - SA53
    - Isolamento (BMS)
    - Medida de Shortest wave
    - Powertrain
  * - SA54
    - ADC1 (BMS)
    - Medida do ADC1
    - Powertrain
  * - SA55
    - Tensão GLV
    - Tensão na bateria de baixa tensão
    - Telemetria
  * - SA56
    - RPM (Inversor)
    - Rotação do motor (P0002)
    - Powertrain
  * - SA57
    - Corrente (Inversor)
    - Corrente do motor (P0003)
    - Powertrain
  * - SA58
    - Frequência (Inversor)
    - Frequência do motor (P0005)
    - Powertrain
  * - SA59
    - Estado (Inversor)
    - Estado do Inversor (P0006)
    - Powertrain
  * - SA60
    - Tensão (Inversor)
    - Tensão de saída do inversor (P0007)
    - Powertrain
  * - SA61
    - Velocidade (Inversor)
    - Velocidade do veículo (P0008)
    - Powertrain
  * - SA62
    - Torque (Inversor)
    - Torque no motor (P0009)
    - Powertrain
  * - SA63
    - Temperatura (Inversor)
    - Temperatura do MOSFET (P0030)
    - Powertrain
  * - SA64
    - Temperatura (Inversor)
    - Temperatura do MOSFET 2 (P0033)
    - Powertrain
  * - SA65
    - Temperatura (Inversor)
    - Temperatura do ar interno (P0034)
    - Powertrain
  * - SA66
    - Sobrecarga (Inversor)
    - Sobrecarga do motor (P0037)
    - Powertrain
  * - SA67
    - Alarme (Inversor)
    - Alarme atual (P0048)
    - Powertrain
  * - SA68
    - Falha atual (Inversor)
    - Número da falha atual (P0049)
    - Powertrain
  * - SA69
    - Falha anterior (Inversor)
    - Última falha registrada (P0050)
    - Powertrain
  * - SA70
    - Sensor Hall GLV
    - Corrente na bateria de baixa
    - Telemetria
  * - SA71
    - IMD PWM
    - Saída PWM do IMD
    - Circuito de segurança
  * - SA71
    - IMD PWM
    - Saída PWM do IMD
    - Circuito de segurança
  * - SA72
    - Setpoint do cebolinha
    - Tensão de comparação do cebolinha
    - Circuito de segurança
  * - SA73
    - Setpoint do sensor hall
    - Tensão de comparação do sensor hall
    - Circuito de segurança
  * - SA74
    - Cebolinha
    - Saída do cebolinha
    - Circuito de segurança
  * - SA75
    - Sensor hall
    - Saída do sensor hall
    - Circuito de segurança
  * - SA76
    - Pressão de freios 2
    - Pressão do cilindro mestre 1
    - Telemetria
  * - SA77
    - POST
    - Estado do self test
    - Circuito de segurança
  * - SA78
    - Pressão de freios 3
    - Pressão do cilindro mestre 2
    - Telemetria
  * - SA79
    - Pressão de freios 4
    - Pressão na linha de freios frontal
    - Telemetria

Comunicação CAN
====================

.. list-table:: CAN
  :widths: 1 1 1 1 1 1
  :header-rows: 1

  * - ID
    - Microcontrolador
    - Mensagem 1
    - Mensagem 2
    - Mensagem 3
    - Mensagem 4

  * - 0x00
    - Telemetria Frontal
    - TPS 1 (SA1)
    - TPS 2 (SA2)
    - Pressão dos freios (SA76)
    - Flags Inversor (Especial)
  * - 0x01
    - Roda Frontal Esquerda
    - Temperatura Roda (SA10)
    - Temperatura Roda (SA11)
    - Rotação (SA5)
    - N/A
  * - 0x02
    - Roda Frontal Direita
    - Temperatura Roda (SA8)
    - Temperatura Roda (SA9)
    - Rotação (SA4)
    - N/A
  * - 0x03
    - Roda Traseira Esquerda
    - Temperatura Roda (SA14)
    - Temperatura Roda (SA15)
    - Rotação (SA7)
    - N/A
  * - 0x04
    - Roda Traseira Direita
    - Temperatura Roda (SA12)
    - Temperatura Roda (SA13)
    - Rotação (SA6)
    - N/A
  * - 0x05
    - Telemetria Frontal
    - SD1 + SD2 + SD17
    - Volante (SA16)
    - Pressão de freios (SA78)
    - Pressão de freios (SA79)
  * - 0x06
    - Circuito de Segurança
    - SD3 ... SD10
    - IMD PWM (SA71)
    - Setpoint Cebolinha (SA72)
    - Setpoint Hall (SA73)
  * - 0x07
    - Circuito de Segurança
    - Cebolinha (SA74)
    - Sensor Hall (SA75)
    - Estado do Self Test (SA77)
    - N/A
  * - 0x08
    - BMS
    - Corrente (SA31)
    - Tensão Instantânea (SA32)
    - Tensão de C.Aberto (SA33)
    - State of Charge (SA34)
  * - 0x09
    - BMS
    - S State of Charge (SA35)
    - Capacidade Restante (SA36)
    - Health (SA37)
    - Maior Temperatura (SA38)
  * - 0x10
    - BMS
    - Menor Temperatura (SA39)
    - Temperatura Média (SA40)
    - Temperatura Interna (SA41)
    - Maior Tensão (SA42)
  * - 0x11
    - BMS
    - Menor Tensão (SA43)
    - Tensão Média (SA44)
    - Maior Resistência (SA45)
    - Menor Resistência (SA46)
  * - 0x12
    - BMS
    - Resistência Média (SA47)
    - IDs Temperatura (SA48)
    - IDs Tensão (SA49)
    - IDs Resistência (SA50)
  * - 0x13
    - BMS
    - Fan Speed (SA51)
    - Tensão de entrada (SA52)
    - Isolamento (SA53)
    - ADC1 (SA54)
  * - 0x14
    - Inversor
    - RPM (SA56)
    - Corrente (SA57)
    - Frequência (SA58)
    - Estado (SA59)
  * - 0x15
    - Inversor
    - Tensão saída (SA60)
    - Velocidade (SA61)
    - Torque (SA62)
    - Temperatura FET1 (SA63)
  * - 0x16
    - Inversor
    - Temperatura FET2 (SA64)
    - Temperatura Interna (SA65)
    - Sobrecarga (SA66)
    - Alarme (SA67)
  * - 0x17
    - Inversor
    - Falha Atual (SA68)
    - Falha Anterior (SA69)
    - N/A
    - N/A
  * - 0x18
    - SMS
    - Pressão da célula (SB01)
    - Tensão da célula (SB02)
    - Corrente da célula (SB03)
    - Temp da célula (SB04)
  * - 0x19
    - SMS
    - Temp da célula (SB04)
    - Temp da célula (SB05)
    - Temp da célula (SB06)
    - Temp da célula (SB07)
  * - 0x20
    - SMS
    - Temp da célula (SB08)
    - Temp da célula (SB09)
    - Temp da célula (SB010)
    - Temp da célula (SB011)

Flags inversor
====================

  Configuração da flag de comandos para o inversor. Observar ordem dos bits (Little-endian).

.. list-table:: 
  :widths: 1 1
  :header-rows: 1
  
  * - Posição 
    - Valor
  * - Bit 00
    - Acelerador
  * - Bit 01
    - Freio
  * - Bit 02
    - Ready to Drive
  * - Bit 03
    - Botão Brian
  * - Bit 04
    - N/A
  * - Bit 05
    - N/A
  * - Bit 06
    - N/A
  * - Bit 07
    - N/A
  * - Bit 08
    - N/A
  * - Bit 09
    - N/A
  * - Bit 10
    - N/A
  * - Bit 11
    - N/A
  * - Bit 12
    - N/A
  * - Bit 13
    - N/A
  * - Bit 14
    - N/A
  * - Bit 15
    - N/A

Placas
=============================

Descrição em construção! - Lembrar de adicionar (caiotbc)

.. list-table::
  :widths: 1 1 1 1
  :header-rows: 1

  * - Código
    - Nome
    - Descrição
    - Micro
  * - TEL01
    - Telemetria traseira
    - Placa de aquisição principal
    - ESP32
  * - TEL02
    - Telemetria frontal
    - Placa de aquisição frontal
    - ESP32 e STM32F103C8T6
  * - TEL03
    - Conjunto de Rodas 1
    - Sensores da roda frontal esquerda
    - STM32F103C8T6
  * - TEL04
    - Conjunto de Rodas 2
    - Sensores da roda frontal direita
    - STM32F103C8T6
  * - TEL05
    - Conjunto de Rodas 3
    - Sensores da roda traseira esquerda
    - STM32F103C8T6
  * - TEL06
    - Conjunto de Rodas 4
    - Sensores da roda traseira direita
    - STM32F103C8T6
  * - TEL07
    - Isolação inversor
    - Placa de isolação do inversor
    - STM32F103C8T6
  

Características elétricas
=============================

A tabela abaixo detalha o consumo elétrico dos sensores e placas do subsistema de telemetria:

.. list-table:: Placas
  :widths: 1 1 1 1 1
  :header-rows: 1

  * - Placa
    - Localização 
    - Tensão de alimentação 
    - Corrente nominal 
    - Potência nominal 
  * - TEL01 - Telemetria traseira
    - Caixa de tele traseira
    - 12V
    - 1 A * EM ESTUDO 
    - 12W
  * - TEL02 - Telemetria frontal
    - Atrás do painel
    - 12V
    - 1 A * EM ESTUDO 
    - 12 W
  * - TEL03 a TEL 06 - Rodas
    - Na manga
    - 5V
    - 200 mA
    - 1 W
  * - TEL07 - Isolação inversor
    - Caixa de isolação
    - 12V
    - 300 mA
    - 3,6 W
    
.. list-table:: Sensores
  :widths: 1 1 1 1 1
  :header-rows: 1

  * - Sensor
    - Placa
    - Tensão de alimentação 
    - Corrente nominal 
    - Potência nominal 
  * - SA76 - Cebolinha frontal
    - TEL02 - Telemetria frontal
    - 5V
    - 20 mA
    - 100 mW
  * - SA74 - Cebolinha traseiro
    - Circuito de segurança
    - 5V
    - 20 mA
    - 100 mW
  * - SA1 - TPS 1
    - TEL02 - Telemetria frontal
    - 5V
    - Não tem , estimado 20mA
    - 100 mW
  * - SA2 - TPS 2
    - TEL02 - Telemetria frontal
    - 5V
    - Não tem , estimado 20mA
    - 100 mW
  * - SA70 - Hall GLV
    - TEL01 - Telemetria traseira
    - 5V
    - 15 mA
    - 75 mW
  * - SA16 - Encoder volante
    - TEL02 - Telemetria frontal
    - 5V
    - 5 mA
    - 25 mW

Diagrama de blocos
==========================
.. image:: images/sensors.png
  :align: center
  :width: 600
