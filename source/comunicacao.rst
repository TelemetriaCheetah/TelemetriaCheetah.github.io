Protocolos de Comunicação
****************************

(Texto introdutorio)

Tabela de Comunicações
==========================
.. image:: images/tab_comunicacao.png
  :align: center

CAN
================

CAN,  Controller  Area  Network,  é  uma  especificação  de  interconexão  e  protocolo  para comunicação  que  está  sendo  utilizada  em  larga  escala  pela  indústria  automobilística. 
Devido  a queda no custos dos circuitos eletrônicos e aprimoramento nos conhecimentos das aplicações CAN, tivemos um crescimento significativo de 20 milhões de nós CAN em uso mundial,
no ano de 1997, para cerca de 120 milhões no  ano 2000. O protocolo CAN  é,  certamente, o principal protocolo de barramento em veículos na Europa.  

Uma  rede  CAN  pode  interligar  até  2032  dispositivos,  sendo  que  o  limite  prático  é  de aproximadamente  110  dispositivos,  onde cada  dispositivo  é tratado  como  um  nó
da  rede.  No  nível físico,  o  link  serial  mais  usado  é  composto  de  dois  fios,  o  sinal  tem  característica  diferencial,  é capaz  de  operar  até  1  Mbps,  tendo  
restrições  de  velocidade  em  virtude  da  distância  entre  os  nós. Para uma rede com extensão de 1 km, a velocidade por ser reduzida até 50Kbps. Cada nó ligado a este link 
serial é capaz de “ouvir”, simultaneamente a outros nós, os dados transmitidos na rede. A escrita, porém, é uma operação permitida somente para um dispositivo por vez. 

O acesso ao barramento é manipulado através do avançado protocolo de comunicação serial Carrier  Sense  Multiple  Access  /  Collision  Detection  (CSMA/CD).  Isto  significa  que 
a  colisão  de mensagens é evitada através de arbitragem bit a bit, sem perda de tempo. Há  dois  estados  do  barramento:  "dominante"  e  "recessivo".  A  lógica  do  barramento  
usa  o mecanismo  "Wired-AND",  que  quer  dizer,  os  “bits  dominantes”  (equivalente  ao  nível  lógico “Zero”) sobrepõem os “bits recessivos" (equivalente ao nível lógico "Um"). 

.. image:: images/can1.png
  :align: center


As   linhas   do   barramento   são   chamadas   "CAN_H"   e   "CAN_L".   As   duas   linhas   do barramento  CAN_H  e  CAN_L  são  controladas  pelos  nós  com  um  sinal  diferencial.  
O  par  de  fios trançado é terminado com um resistor tipicamente de 120 Ohms em cada ponta da linha. Devido à transmissão operar de forma diferencial, o CAN é resistente à interferência
eletromagnética, porque ambas  as  linhas  do  barramento  são  afetadas  da  mesma  maneira,  o  que  deixa  o  sinal  diferencial inalterado. Para reduzir ainda mais a sensibilidade
contra a interferência eletromagnética, as linhas podem  ser  protegidas  adicionalmente  por  uma  malha  blindada.  Isto  também  reduz  a  irradiação eletromagnética    do    próprio  
barramento,    especialmente    em    altas    taxas    de    transmissão. 

As especificações originais do CAN (Versões 1.0, 1.2 e 2.0A) especificam um identificador de  mensagem  de  11  bits.  Isto  é  conhecido  como  "CAN  Padrão”.  Os  Quadros  de
Dados  e Quadros  Remotos  que  contêm  um  identificador  de  11  bits  são  por  este  motivo  chamados  de Quadros  Padrões.  Com  estes  quadros,  2048  mensagens  diferentes 
podem  ser  identificadas.  A especificação V2.0A foi atualizada (versão 2.0B ) para remover esta possível limitação de número de  mensagem  e,  com  isto,  atender  ao  padrão  
SAE  J1939  para  o  uso  do  CAN  em  caminhões.  A versão 2.0B do CAN é chamada "CAN Estendido”.

.. image:: images/can2.png
  :align: center

O  quadro  começa  com  um  bit  dominante  de  “Início  de  Quadro”  (Start  of  Frame)  para sincronização  de  todos  os  nós  receptores.  O  bit  “Início  de  Quadro”  é  
seguido  pelo  Campo  de Arbitragem  (Arbitration  Field)  que  consiste  em  12  bits:  os  11  bits  do  identificador  que  refletem  o conteúdo  e  prioridade  da  mensagem 
mais  o  bit  de  “Pedido  de  Transmissão  Remota”  (Remote Transmission Request, ou RTR) usado para distinguir um Quadro de Dados (RTR = dominante) de um Quadro Remoto (RTR = recessivo).
 
O segundo  campo  é o Campo de Controle (Control Field) e consiste  em  6 bits. O primeiro bit deste campo é chamado de bit IDE (Identificador de Extensão) e está em estado dominante para especificar 
que  o  quadro  é  um  quadro  padrão.  O  bit  seguinte  é  reservado  e  definido  como  um  bit dominante.  Os  4  bits  restantes  do  Campo  de  Controle  são  o  Código  de  Tamanho  de  Dados  (Data Length Code, ou DLC) 
e especifica o número de bytes de dados contido na mensagem (0 - 8 bytes). 

O  dados  enviados  seguem  no  Campo  de  Dados  (Data  Field)  cujo  tamanho  é  definido  pelo DLC acima (0, 8, 16,...., 56 ou 64 bits). 

Em seguida vem o Campo de Redundância Cíclica (Cyclic Redundancy  Field,  ou  CRC  Field),  usado  para  descobrir  possíveis  erros  de  transmissão.  O  Campo CRC consiste em uma sucessão de 15 bits CRC, completada por um bit 
delimitador recessivo. 

O terceiro campo é o Campo de Reconhecimento (Acknowledge Field). Durante esta janela o nó que está transmitindo a mensagem envia um bit recessivo. Qualquer nó que tenha recebido um quadro  sem  erro  
reconhece  a  correta  recepção  do  quadro  mandando  de  volta  um  bit  dominante (independente do nó estar configurado para aceitar aquela mensagem específica ou não). Com isto, pode-se concluir que o CAN pertence
ao grupo de protocolos “in-bit-response”. Em seguida vem o bit delimitador que é recessivo e não pode ser reescrito por um bit dominante. Sete  bits  recessivos  (Fim  de  Quadro)  finalizam  o  Quadro  de  Dados.  
Entre  dois  quadros  o barramento deve permanecer no mínimo três bits recessivos. Se nenhum nó quiser mais transmitir, o barramento permanece no estado de repouso (Bus Idle). 

I²C
==========================
Descrição
------------
O modo de funcionamento do protocolo I2C é baseado na interação entre elementos seguindo a hierarquia mestre/escravo, ou seja, quando temos vários dispositivos se comunicando segundo esta premissa, pelo menos um destes deve atuar como mestre e os demais serão escravos. A função do mestre consiste em realizar a coordenação de toda a comunicação, ou seja, colocar em prioridade qual informação deve ser enviada primeiro de acordo com os requisitos.
Está é a forma da estrutura:

.. image:: images/i2c.png
  :align: center
  
O barramento de comunicação I2C pode ser dividido em duas formas:
->SDA (Serial Data), o qual, é responsável pela troca de dados entre os dispositivos do arranjo
->SCL (Serial Clock), possui a função de sincronizar os dispositivos e garantir a confiabilidade do sistema.
Para distinguir cada sensor e ou modulo é necessário saber o endereço de barramento no qual deve ser único para cada, por isso é necessário utilizar um programa de busca para saber está informação e se for necessário alterá-lo.

Analógica
==========================
Descrição
------------
A comunicação é utilizada quando uma grandeza pode assumir infinitos valores de acordo com o tempo, como temperatura, pressão e umidade. Entretanto os controladores leem apenas valores digitais, por isso é necessário converter de acordo com sensor e ou modulo uma forma de transformação.
Um conversor A/D quantifica o valor analógico conforme a quantidade de bits da sua resolução. A resolução de um conversor A/D é dada pela seguinte equação:

.. image:: images/analog.png
  :align: center

Vref: Tensão de referência do conversor A/D
N: número de Bits do conversor.

Digital
==========================
Descrição
------------
A comunicação digital é aquela que as respostas da 0 ou 1, ou seja, trabalha com valores verdadeiros e falsos. Por padrão os pinos digitais dos controladores estão configurados como entradas digitais, porém, para ficar mais explícito na programação, deve-se configurar o pino como entrada. Dessa forma o pino é colocado em um estado de alta impedância, equivalente a um resistor de 100 MegaOhms em serie com o circuito a ser monitorado. Dessa forma, o pino absorve uma corrente muito baixa do circuito que está monitorando. Devido a essa característica de alta impedância, quando um pino colocado com entrada digital encontrasse flutuando (sem ligação definida), o nível de tensão presente nesse pino fica variando não podendo ser determinado um valor estável devido a ruido elétrico e até mesmo capacitância de entrada do pino. Para resolver esse problema é necessário colocar um resistor de pull up (ligado a +5V) ou um resistor de pull down (ligado a GND) conforme a necessidade. Esses resistores garantem nível lógico estável quando por exemplo uma tecla não está pressionada. Geralmente utiliza-se um resistor de 10K para esse propósito.

OneWire
==========================
Descrição
------------
1-Wire é um tipo de comunicação, um sistema de barramento projetado pela Dallas Semiconductor Corpo. que provê dados de baixa velocidade, sinalização e sinal único de energia.[1] 1-Wire tem um conceito similar ao do I²C, mas com taxas mais baixas de dados e maior alcance. O 1-Wire é basicamente um acessório pequeno e utilizado em funções digitais e também em instrumentos de medição de temperatura (termômetro). Uma rede de dispositivos 1-Wire associados com um Mestre, é chamada de MicroLan.

Um diferencial do barramento 1-Wire é o fato de utilizar apenas dois cabos: dados e GND. Para isso, o dispositivo 1-Wire dispõe de um capacitor de 800 pF para armazenar carga e alimentar o dispositivo durante os períodos onde o cabo de dados estiver sendo usado para o tráfego de dados.

Uart
==========================
Descrição
------------
É um protocolo utilizado por muitos microcontroladores, pois é responsável pela conversão da comunicação paralela em serial, que na maioria das vezes é convertida em outro protocolo como por exemplo o controlador da placa BlackBoard ou Arduino Uno, que utiliza o protocolo UART mas tem o protocolo convertido para USB.
Funcionamento: o pino de transmissão (Tx) do protocolo envia um pacote de bits que será interpretado bit a bit pelo pino receptor. Cada pacote enviado contém 1 start bit que indica o início da mensagem, 1 ou 2 stop bits para indicar o final da mensagem, 5 a 9 bits de informação e 1 bit de paridade para evitar a recepção de erros.
Ligação: por ser uma comunicação assíncrona a comunicação é feita por dois pinos Rx/Tx que dependem do baud rate como referência.

.. image:: images/uart.png
  :align: center

SPI
==========================
Descrição
------------
A comunicação SPI possui algumas características básicas. Primeiramente os sinais de comunicação possuem uma direção fixa e definida. Isso significa que sempre existem dois transistores definindo o estado de um pino (Push-Pull). Essa característica é uma das grandes diferenças entre outras comunicações seriais como I2C e OneWire, que possuem um mesmo barramento de dados para os sinais de entrada e saída através do esquema de dreno-aberto (Pull-Up).
Apesar de utilizar dois sinais de comunicação de dados em vez de um, é possível atingir velocidades maiores de comunicação. Isso porque há pouca deformação do sinal.
Outra característica é que toda troca de dados acontece sempre em ambas as direções. Em outras palavras, cada bit trocado entre o Master e um Slave traz um bit do Slave para o Master. Dessa forma, definimos que a comunicação é sempre full-duplex

.. image:: images/spi.png
  :align: center

O sinal de SS da SPI funciona como Seleção de Escravo (Slave Select). É um sinal ativo em nível baixo, o que significa que o dispositivo é selecionado quando este pino se encontra em nível baixo. No entanto, muitos dispositivos utilizam este sinal como sincronismo de frame. Dessa forma, é um sinal importante que deve ser respeitado.