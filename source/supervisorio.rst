Supervisório
*****************

Nessa seção está documentado o código do sistema supervisório para torná-lo facilmente acessível a qualquer membro do Cheetah E-Racing interessado no seu funcionamento.
Nenhum conhecimento prévio é estritamente necessário para acompanhá-lo, porém qualquer experiência com linguagens de programação e desenvolvimento web será útil.

Servidor
===========

O processo de instalação e inicialização do servidor segue os mesmos passos apresentados na seção de manual do usuário.

.. note::

  Para facilitar o processo de desenvolvimento, recomenda-se a utilização do `nodemon <https://www.npmjs.com/package/nodemon>`__. O nodemon é um módulo do node.js que reinicia automaticamente o servidor
  quando algum dos arquivos javascript for alterado, e pode ser ativado utilizando o comando abaixo ao invés do mostrado no manual do usuário:

  .. code-block:: c++
    :linenos:

    nodemon https.js

Módulos
--------

A lista abaixo contém os módulos necessários para a execução do sistema supervisório e uma breve descrição dos seus objetivos:

* `express.js e http - Criação de um servidor http <https://expressjs.com/pt-br/>`__;
* `socket.io - Conexões WebSocket entre servidor e cliente <https:/Conexão com o banco de dados/socket.io/>`__;
* `mysql - Conexão com o banco de dados <https://www.npmjs.com/package/mysql>`__;
* `serialport e readline - Comunicação UART com o rádio <https://www.npmjs.com/package/serialport>`__;
* `path - Operações com arquivos e caminhos no servidor <https://nodejs.org/api/path.html>`__;

.. note::
   Não é necessário (e nem recomendado) instalar os módulos manualmenete, eles já são automaticamente baixados pelo npm install.

Configuração
----------------

Arquivos .json são usados facilitar a edição e visualização das configurações do servidor:

config.json
++++++++++++++++

Arquivo de configurações gerais

* **qtdMedicao** *(inteiro)*: Quantidade de sensores de medição
* **qtdDiscretos** *(inteiro)*: Quantidade de sensores discretos

password.json
++++++++++++++++

Arquivo com as configurações do banco de dados. Este arquivo não está disponível no github por questões de segurança, e pode
ser encontrado no teams da equipe.

* **host** *(string)*: Endereço IPv4 do servidor MySQL/MariaDB
* **user** *(string)*: Nome de usuário
* **password** *(string)*: Senha do usuário
* **database** *(string)*: Nome do banco de dados usado

.. note::

	O nome do banco de dados é fixo em algumas partes do código e deve ser configurado como *telemetriaCheetah*. Há planos para permitir outros nomes no futuro, mas no momento o uso de qualquer outro identificador resultará em uma falha do servidor.

CheetahLinkParser
-------------------------

A classe *CheetahLinkParser* recebe os dados do rádio e os converte para dois vetores com os valores dos sensores discretos e de medição. Sua
implementação é baseada na classe `ByteLength <https://serialport.io/docs/api-parser-byte-length/>`__ do módulo `serialport <https://www.npmjs.com/package/serialport>`__,
e inspirada na classe `api-mode-parser.js <https://github.com/Tesla-UFMG/Interface/blob/master/api-mode-parser.js>`__ da equipe `Tesla UFMG <https://github.com/Tesla-UFMG>`__.

Uso
+++++++++

.. code-block:: javascript

  const CheetahLinkParser = require('./js/CheetahLinkParser');
  new CheetahLinkParser(options);

* *options.length: number* - quantidade de bytes emitidos em cada evento

.. warning::

	O número de bytes passado como argumento deve ser o mesmo emitido pelo módulo serial. Esse valor pode ser consultado diretamente no código do MCU de telemetria (placa frontal) ou calculado utilizando a fórmula:

  .. math::

    qtdBytesSerial = (qtdSensoresMedicao \times 2 + qtdSensoresDiscretos/8) + 2

Exemplo
++++++++++++

O código abaixo imprime os dados recebidos da porta **/dev/ttyACM0** em conjuntos de 8 bits (notação hexadecimal):

.. code-block:: javascript

  const CheetahLinkParser = require('./js/CheetahLinkParser');
  const serialport = require("serialport");
  const ttyPort = "/dev/ttyACM0";
  const port = new serialport(ttyPort,{baudRate:9600});
  const parser = port.pipe(new CheetahLinkParser({length: 12}));
  parser.on("data", (data) =>
  {
    console.log(data);
  });

CheetahLinkFormatter
----------------------------

A classe *CheetahLinkFormatter* é responsável por tratar os dados recebidos do rádio.

Uso
++++

.. code-block:: javascript

  const CheetahLinkFormatter = require('./js/CheetahLinkFormatter');
  var serial = new CheetahLinkFormatter();

Exemplo
++++++++++

O código abaixo imprime um vetor contendo os valores de todos os sensores discretos recebidos do rádio.

.. code-block:: javascript

  const CheetahLinkFormatter = require('./js/CheetahLinkFormatter');
  var serial = new CheetahLinkFormatter();
  parser.on("data", (data) =>
  {
    serial.setData(data , config.qtdMedicao , config.qtdDiscretos);
    console.log(serial.getDigitalArray());
  });

setData
+++++++++

Insere dados brutos no objeto

.. code-block:: javascript

  setData(data, nAnalog, nDigital)

**Argumentos:**

#. **data** *(objeto)* - Objeto contendo os dados do parser serial;
#. **nAnalog** *(inteiro)* - Quantidade de sensores de medição obtida do arquivo config.json
#. **nDigital** *(inteiro)* - Quantidade de sensores discretos obtida do arquivo config.json

getAnalogArray
++++++++++++++++++++

.. code-block:: javascript

  getAnalogArray()

Retorna um vetor de inteiros com os valores de todos os sensores de medição

getDigitalArray
++++++++++++++++++++

.. code-block:: javascript

  getDigitalArray()

Retorna um vetor de inteiros com os valores de todos os sensores discretos

DatabaseHandler
----------------------

Lida com as operações de banco de dados

.. warning::

	Esta classe ainda está sendo implementada e portanto é sujeita a mudanças significativas em um futuro próximo. Garanta que seu código está atualizado!

Uso
++++++

.. code-block:: javascript

  const DatabaseHandler = require('./js/DatabaseHandler');
  const db = new DatabaseHandler();

Exemplo
++++++++++

Este exemplo imprime um vetor com todos os valores do sensor de medição nº 0 disponíveis no banco de dados

.. code-block:: javascript

  const DatabaseHandler = require('./js/DatabaseHandler');
  const db = new DatabaseHandler();
  console.log(db.getSensorArray("A" , 0));

constructor
+++++++++++++++

O constructor da classe inicializa a conexão com o banco de dados utilizando as configurações dos arquivos json.

getSensorArray
++++++++++++++++++++++

Retorna um vetor de inteiros com todos os valores do sensor disponíveis no banco de dados

**Argumentos:**

#. **sensorType** *(string)* - "A" = sensor de medição ; "D" = sensor discreto
#. **sensorCode** *(inteiro)* - id do sensor (consultar config.json em caso de dúvida)

insertIntoDatabase
++++++++++++++++++++++++++

Insere dados no banco de dados.

**Argumentos:**

#. **analogSensor** *(vetor de inteiros)* - vetor contendo valores dos sensores de medição
#. **digitalSensor** *(vetor de inteiros)* - vetor contendo valores dos sensores discretos

Interface Web
==============================

A interface web do sistema supervisório é acessível a qualquer dispositivo conectado na rede WiFi do servidor e capaz de rodar um navegador com suporte ao JavaScript ES6. É otimizada para uso em desktops e laptops,
mas suporte touchscreen está disponível para uso em dispositivos móveis.

Tema e index.js
----------------------

O tema é configurado no arquivo index.js e implementa o modelo de temas do `Material UI <https://material-ui.com/pt/customization/theming/>`_. Nesse arquivo também é adicionado o plano de fundo do site e a formatação CSS padrão.

App.jsx
-------------

O App.jsx é o arquivo principal da interface, e desenha os componentes das barras laterais, do cabeçalho, do rodapé e do componente central escolhido pelo usuário. 

Dashboard
----------------

.. image:: images/interface-web-dashboard.png
  :width: 320
  :align: center


Eletrônica
----------------------

Mecânica 
------------

Mapa
---------------

Controle de Teste
----------------------


Display Painel
======================

Dashboard 
---------------