Sensores
************************

Nessa página estão listados os sensores que compõe o subsistema de telemetria do
Cheetah E-Racing. Aqui você encontra informações sobre as características físicas,
especificações técnicas, implementação de software e uso geral de cada um deles.
Datasheets e Application Notes também são referenciados de acordo com a necessidade.

Temperatura
===================

Descrição
------------

Vai ser usado 2 sensores de temperatura do modelo DS18B20, fabricante Dallas
Semiconducors usa a comunicação OneWire, ficam um na frente do duto e outro na parte de trás.

Uso
-----

O sensor funciona com uma tensão de 5v, gnd e sinal (verificar datasheet)

Objetivo
------------

Objetivo do sensor validar os sidepods (dutos) é verificar o quão efetivo é o
resfriamento da caixa de bateria, local para onde estão voltados os dutos. Para
isso é necessário 02 sensores DS18B20 para dois testes diferentes: no primeiro,
que será realizado avaliando somente um duto de cada vez, um sensor seria colocado
na entrada do duto e o outro na saída, para que seja obtida a diferença entre essas
temperaturas. Dessa forma é possível verificar a geometria escolhida dos dutos
comparando com dados de simulações. No segundo teste os sensores serão colocados
nas laterais da caixa de bateria, onde incide o ar vindo dos dutos. Assim serão
coletados os dados de temperatura da caixa de baterias com e sem dutos. Dessa
forma sendo verificada a eficiência dos dutos no carro.

Datasheet
-------------

https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf

LCD
===================

Descrição
------------

Display LED mais o LCD genérico, QC2004A. Comunicação pela interface I2C, pinos
SCL e SDA,  com endereçamento individual. Fixado no painel do carro e ligado,
pelo chicote, direto para aplaca central.

Uso
-----

O modulo funciona com uma tensão de 5V.
Pinos utilizados são: Vcc 5V ; GND; SCL; SDA.

Objetivo
------------

O display LCD é nada mais que um LED que mostra dados. Localizado no painel do carro
para que posamos mostrar ao piloto dados que achamos importantes que ele esteja
constantemente ciente. Os dados são decididos pela equipe.

Datasheet
-------------
