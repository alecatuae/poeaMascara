# Lembrete

Para evitar que nossos usuários fiquem espostos e que não esqueçam de se protegerem em época e pós pantemina, devidimos criar um dispositivo capaz de Lembra-lo de se proteger.  

Este projeto de IoT identifica com acelerometro a movimentão continua da pessoa e a lembra de utilizar a máscara e usar alcool em Gel.

Também mede constantemente a temperatura do usuário e o alerta se há temperatura acima ou abaixo de 36 graus por um determinado período de tempo.

Este projeto pode ser implantado em uma pulseira inteligente ou um APP instalado em um Smart Watch moderno como o Apple Watch ou Samsung Galaxy Watch.  

## O Prototipo 

### Arduino

<img src="https://github.com/alecatuae/poeaMascara/blob/master/img/arduino-UNO.png">

Pela facilidade de simulação decidios utilizar o Arduino UNO, sensores e componentes eletrônicos para a prova de conceito. 

### ThinkerCAD

<img src="https://github.com/alecatuae/poeaMascara/blob/master/img/TinkerCAD.jpg" width="200">

Como não teriamos tempo habil para encomendar, comprar e receber as peças e componentes eletronicos para realizar a prova de conceito descidimos utilizar o simulador de Arduino do TinkerCAD.

O TinkerCAD é um programa on-line gratuito de simulação de Arduino que roda em um navegador da web.
Ele é conhecido por sua simplicidade e facilidade de uso.


### Scketch

<img src="https://github.com/alecatuae/poeaMascara/blob/master/img/Desenhoinformativo.PNG">



### Componentes Necessários

<img src="https://github.com/alecatuae/poeaMascara/blob/master/img/componentes.PNG">

Observação: O Componente Sparkfun MMA7361 Breakout, simula um acelerometro. Na lista principal do ThinkerCAD ele não é encontrado. Encontrei este componente dentro de um projeto publico no proprio ThinkerCAD o qual importamos para usar no projeto. Link para o projeto importado: https://www.tinkercad.com/things/e1uPGe1SFGW-copy-of-copy-of-152-accelerometer

### Como funciona um acelerômetro
Um acelerômetro funciona com o princípio do efeito piezoelétrico, que é a capacidade de alguns cristais gerarem tensão elétrica por resposta a uma pressão mecânica. Agora Imagine uma caixa com uma bola pequena dentro dela, como na imagem abaixo.

![Imagem](https://github.com/alecatuae/poeaMascara/blob/master/img/exemplo_func_acelerometro.png)

Figura 01: Exemplificação do funcionamento interno de um acelerômetro
Fonte: DiY Hacking

As paredes desta caixa são feitas com cristais piezoelétricos. Sempre que você inclina a caixa, a bola é forçada a se mover na direção da inclinação, devido à gravidade. A parede em que a bola colide cria pequenas correntes conforme ele toca em alguma das seis paredes do cubo. Cada par de paredes corresponde a um eixo no espaço 3D: eixos X, Y e Z. Dependendo da corrente produzida a partir das paredes piezoelétricas, podemos determinar a direção da inclinação e sua magnitude.

Referência: https://autocorerobotica.blog.br/aprenda-a-utilizar-o-acelerometro-mpu6050/

## Como Funciona

### Tela de boas Vindas

1. Ao ligar a simulação, mensagens de boas vindas aparecerá para o usuário.

<img src="https://github.com/alecatuae/poeaMascara/blob/master/img/ola.png">

Em background, aguardará de forma passiva a conexão com o APP. 

Para esta simulação, vamos utilizar a serial para a entrada e saida de dados.

Um código numérico na entrada da serial simula o handshake entre o app e o device.

2. Na tela principal mostra-se a temperatura corporal do usuário.

<img src="https://github.com/alecatuae/poeaMascara/blob/master/img/temperatura.PNG">

3. Detectando que o usuário deu determinado numero de passos seguidos, uma mensagem é gerada na tela **lembrando o usuário de usar a mascará e usar alcool em gel**.
    - Para chamar a atenção à mensagem o dispositivo vibrará até que o usuário interaja com o dispositivo clicando no botão reset.
    <img src="https://github.com/alecatuae/poeaMascara/blob/master/img/useamascara.PNG">

###### Como simular

- Clique no componente Acelerometro até que a mensagem apareça no display.

<img src="https://github.com/alecatuae/poeaMascara/blob/master/img/sensorAcelerometro.PNG">      