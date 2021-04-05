Introdução
************************

O sistema de telemetria do CE-21 é projetado para receber, interpretar e visualizar dados diagnósticos do veículo equipe durante os testes e competições.
A figura abaixo mostra uma versão simplificada da arquitetura implementada:

.. image:: images/overview.png
  :width: 300
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
   :widths: 10 25 30 30
   :header-rows: 1

   * - Código
     - Nome
     - Grandeza medida
     - Sensor empregado
   * - SD1
     - Inertia Switch
     - chave simples
     - sei n rs
   * - SD2
     - Brake Over Travel Switch
     - chave simples
     - sei n rs

.. list-table:: Medição
  :widths: 10 25 30 30
  :header-rows: 1

  * - Código
    - Nome
    - Grandeza medida
    - Sensor empregado
  * - SA1
    - Throttle Position Sensor
    - Resistência
    - sei n rs
  * - SA2
    - Throttle Position Sensor
    - Resistência
    - sei n rs
  * - SA3
    - Brake System Encoder
    - Resistência
    - sei n rs
  * - SA4
    - Sensor Indutivo
    - Pulsos elétricos
    - sei n rs
