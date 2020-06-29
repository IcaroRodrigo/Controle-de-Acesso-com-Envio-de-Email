# Controle-de-Acesso-com-Envio-de-Email
<ṕ>Controle de Acesso desenvolvido utilizando a Ardino Uno, Leitor RFID RC522 com tags rfid, Display LDC 16x2 e um potenciômetro para realizar
o controle da insensidade da luz do display.<p>

<p>O comportamento do software consistem em identificar uma e RFID e exibir uma mensagem  no display. Para realizar o envio do e-mail a informação 
da leitura das tags RFID são trafegadas pela porta serial até o computador conectado.</p>

<p>Um script desenvolvido em php efetua a leitura da porta serial, e dispara um e-mail de alerta para com a mensagem informando quem acessou a empresa, casa
e afins e o horario, em caso de falha, envia o e-mail informando que houve uma tentativa de acesso não autorizada e o horario.</p>

<p>O código para construção do software do controle de acesso foi inspirado no tutorial https://www.filipeflop.com/blog/controle-acesso-leitor-rfid-arduino/ </p>

<p> Neste link https://www.youtube.com/watch?v=OwG1-yWZOmo&t=8s  voce visualiza o comportamento do controle de acesso</p>


