Manual do usuário
********************

O sistema supervisório da equipe é o programa responsável por armazenar, apresentar e analisar as informações de telemetria fornecidas pelos sensores do
veículo, fornecendo feedbacks essenciais para os outros subsistemas durante as fases de construção, testes e competição. Esses dados são coletados por
microcontroladores especializados no carro e enviados por comunicação sem fio (telemetria em tempo real) ou guardados em um cartão SD de bordo para aquisição posterior,
e ao serem recebidos pelo supervisório são transferidos para um banco de dados relacional localizado no servidor próprio do Cheetah E-Racing.

Esse pequeno tutorial é destinado à qualquer membro do Cheetah que deseje utilizar o sistema de telemetria nos dispostivos oficiais da equipe ou em seu próprio equipamento pessoal.

Servidor
==========

O servidor utiliza o node.js para as funções de conexão serial, comunicação com o banco de dados e gerenciamento de páginas estáticas. Para inicializar o servidor,
execute o comando

.. code-block:: c++
  :linenos:

  npm install

no diretório raiz, e aguarde o processo de instalação dos módulos. Após a conclusão, inicialize o servidor usando

.. code-block:: c++
  :linenos:

  node https.js

A porta configurada para conexões é a 2000, para acessar a página inicial do supervisório utilize a url http://<endereço-ip-do-servidor>:2000.

.. note::

   O endereço ip pode ser substituído por localhost nos casos onde a máquina do servidor é a mesma do cliente.


Dashboard
============

Visão Geral
---------------

Foto aq

Uso
======

precisa do supervisório primeiro rs
