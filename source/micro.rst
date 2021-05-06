Hardware
************************
Essa seção documenta os aspectos técnicos da implementação do hardware. 


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


Testes
=========================

CAN e microcontroladores
-------------------------------


Teste para validação da comunicação CAN entre os microcontroladores e transceivers do projeto.

* **Data:** 03/05/2021
* **Autor:** Caio Tácito Borges da Costa
* **Relatório:** :download:`Baixar relatório em PDF </docs/teste_can.pdf>`
* **Código Fonte:** :download:`Baixar código fonte em ZIP </docs/src.zip>`


Referências
==================
