Supervisório
*****************

Nessa seção está documentado o código do sistema supervisório para torná-lo facilmente acessível a qualquer membro do Cheetah E-Racing interessado no seu funcionamento.
Nenhum conhecimento prévio é estritamente necessário para acompanhá-lo, porém qualquer experiência com linguagens de programação e desenvolvimento web será útil.

Git
===================
O primeiro passo para trabalhar no sistema supervisório é obter o código. É possível baixar como um .zip no github
da equipe, porém isso torna difícil o controle de versionamento e a organização entre os membros. Assim, a melhor maneira é instalar
o git no PC e fazer um clone do seu fork do repositório.

Instalando o git
----------------

Linux
+++++++++++++++++++
O jeito mais rápido de instalar o git é utilizando o gerenciador de pacotes da sua distribuição. Em sistemas baseados em debian (Ubuntu/Pop OS/Mint/Raspberry PI OS), basta
executar como superusuário:

.. code-block:: bash
  :linenos:

  sudo apt update && sudo apt install git

Windows
+++++++++++++++++++

Para instalar o git no Windows, siga as instruções no site oficial: https://git-scm.com/

Criando um fork
----------------

Após criar uma conta no github, acesse a página do supervisório do cheetah: https://github.com/TelemetriaCheetah/Supervisorio
Em seguida, basta clicar no botão de fork

.. image:: images/print1.png
  :align: center

.. note::
  O fork é uma cópia do repositório vinculada à sua conta de usuário, e é nele que as modificações devem ser feitas. Alterar o código utilizando
  a conta do cheetah diretamente é uma prática que deve ser evitada ao máximo, pois impossibilita o controle do responsável por cada modificação.

Criando chaves SSH
----------------------

Para enviar seu código ao github, é necessário se autenticar no site. A autenticação por usuário/senha está sendo desativada aos poucos, e deixará de
funcionar em breve (Se você está lendo isto no futuro, é provável que já tenha sido desativada). Portanto, é necessário utilizar outro método de autenticação,
e uma maneira simples de fazer isso é adicionando chaves SSH à sua conta do github. Para gerar um par de chaves pública/privada, abra o terminal / powershell e
execute o comando:

.. code-block:: bash
  :linenos:

  ssh-keygen

O par de chaves gerado é salvo por padrão na sua pasta de usuário dentro de .ssh . Dentro da pasta, abra o arquivo de chave pública (o que termina com .pub) e copie seu conteúdo. Em seguida, vá até a sua
página do github e siga os passos:

.. note::

  Caso a pasta esteja oculta, vocẽ deve habilitar a opção de visualizar arquivos
  ocultos no seu gerenciador de arquivos.

Abra as configurações da contas

.. image:: images/print2.png
  :align: center

Vá até a opção de chaves SSH e GPG

.. image:: images/print3.png
  :align: center

Clique em adicionar nova chave SSH

.. image:: images/print4.png
  :align: center

Dê um título de sua preferência e cole a chave pública copiada no campo key

.. image:: images/print5.png
  :align: center

Clonando o repositório
------------------------

Para criar uma cópia local do seu repositório, copie o link no botão "code", lembrando que é necessário selecionar a opção "SSH":

.. image:: images/print6.png
  :align: center

Em seguida, abra o terminal / git shell (o git shell pode ser aberto clicando com o botão direito do mouse em um espaço branco dentro de uma pasta qualquer do Windows) e execute o comando:

.. code-block:: bash
  :linenos:

  git clone <cole o link que você copiou aqui>

Git Commit
-------------

Após realizar as alterações no código local, é necessário enviá-las ao repositório remoto (github). Para isso, abra o terminal / git shell dentro da pasta clonada e execute os comandos:

.. code-block:: bash
  :linenos:

  git add -A
  git commit -m "Escreva aqui uma mensagem breve explicando as alterações realizadas desde o último commit"
  git push origin main

Caso queira ver quais alterações fazem parte ou não do commit, use o comando

.. code-block:: bash
  :linenos:

  git status

Atualizando o repositório
------------------------------

Para garantir que você está trabalhando na versão mais recente do código, é necessário sincronizar o seu fork com o repositório original (comumente chamado de upstream). Para isso,
adicione o repositório original no seu git:

.. code-block:: bash
  :linenos:

  git remote add upstream <link para repositório do cheetah>
  git fetch upstream

Feito isso, você deve executar o comando abaixo toda vez que alguma alteração for realizada por outra pessoa no repositório do Cheetah:

.. code-block:: bash
  :linenos:

  git pull upstream main

Criando um pull request
--------------------------

Finalmente, para submeter suas alterações para o repositório upstream, basta criar um pull request clicando em "pull requests" e em seguida "criar novo pull request".
O request deve ser aprovado pelo mantenedor do repositório oficial do Cheetah.

Instalando o node
=====================

A tecnologia principal utilizada para o backend do sistema supervisório é o node.js:

Linux
------

Em sistemas baseados em debian (Ubuntu/Pop OS/Mint/Raspberry PI OS), basta
executar como superusuário:
sudo apt update && sudo apt install nodejs

Windows
---------

Para instalar o node no Windows, siga as instruções no site oficial: https://nodejs.org/en/download/

Instalando o MySQL
=====================

Linux
--------
Em sistemas baseados em debian (Ubuntu/Pop OS/Mint/Raspberry PI OS), basta
executar como superusuário:

sudo apt update && sudo apt install apache2 mariadb-server phpmyadmin

Windows
-------------

No Windows, é possível baixar pacotes que incluem todas as ferramentas necessárias para rodar um servidor apache com MySQL/MariaDB e php
em um único executável. Um exemplo recomendado é o WAMP (Windows Apache MySQL PHP) server, que pode ser baixado no link: https://www.wampserver.com/en/

Tutoriais de programação
====================================

O sistema supervisório é escrito utilizando javascript para o frontend e backend, portanto javascript é a linguagem que deve ser o foco dos estudos. Para
a formatação do site são utilizados HTML5 e CSS, e portanto é necessário possuir conhecimento dessas linguagens também. Além disso,
os dados coletados são armazenados em um banco de dados MySQL, e familiaridade com queries SQL é bastante útil. Seguem abaixo alguns links relevantes sobre os assuntos:

* https://www.urionlinejudge.com.br URI Online Judge - para treinar algoritmos e básico de programação
* https://developer.mozilla.org/pt-BR/docs/Learn/Getting_started_with_the_web/JavaScript_basics JavaScript básico - documentação da Mozilla
* https://www.youtube.com/watch?v=vrSEt5J4q2Y&list=PLbA-jMwv0cuWbas947cygrzfzHIc7esmp Curso javascript básico - youtube
* https://www.youtube.com/watch?v=CjQMi8mv2Do Introdução ao node.js - youtube
* https://www.youtube.com/watch?v=BhJu05tUo-M Introdução ao MySQL - youtube
* https://www.youtube.com/watch?v=Em0R3csNMVE&list=PLhkO7OMKgT_p3VoB47VHdLGpYTzxYTv8R Introdução HTML5 e CSS - youtube


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
