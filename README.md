# Lembrete

Para evitar que nossos usuários fiquem espostos e que não esqueçam de se protegerem em época e pós pantemina, devidimos criar um dispositivo capaz de Lembra-lo de se proteger.  

Este projeto de IoT identifica com acelerometro a movimentão continua da pessoa e a lembra de utilizar a máscara e usar alcool em Gel.

Também mede constantemente a temperatura do usuário e o alerta se há temperatura acima ou abaixo de 36 graus por um determinado período de tempo.

Este projeto pode ser implantado em uma pulseira inteligente ou um APP instalado em um Smart Watch moderno como o Apple Watch ou Samsung Galaxy Watch.  

## O Prototipo 

### Arduino
![Imagem](https://github.com/alecatuae/poeaMascara/blob/master/img/arduino-UNO.png | width=200)

Decidios utilizar o Arduino UNO, sensores e componentes eletrônicos para simular a prova de conceito. 

### ThinkerCAD
![Imagem](https://github.com/alecatuae/poeaMascara/blob/master/img/TinkerCAD.jpg | width=200)

Para simular o projeto utilizamos o Thinkercad.
O Tinkercad é um programa on-line gratuito de simulação de Arduino que roda em um navegador da web.
Ele é conhecido por sua simplicidade e facilidade de uso.


## Como funciona um acelerômetro
Um acelerômetro funciona com o princípio do efeito piezoelétrico, que é a capacidade de alguns cristais gerarem tensão elétrica por resposta a uma pressão mecânica. Agora Imagine uma caixa com uma bola pequena dentro dela, como na imagem abaixo.

![Imagem](https://github.com/alecatuae/poeaMascara/blob/master/img/exemplo_func_acelerometro.png)

Figura 01: Exemplificação do funcionamento interno de um acelerômetro
Fonte: DiY Hacking

As paredes desta caixa são feitas com cristais piezoelétricos. Sempre que você inclina a caixa, a bola é forçada a se mover na direção da inclinação, devido à gravidade. A parede em que a bola colide cria pequenas correntes conforme ele toca em alguma das seis paredes do cubo. Cada par de paredes corresponde a um eixo no espaço 3D: eixos X, Y e Z. Dependendo da corrente produzida a partir das paredes piezoelétricas, podemos determinar a direção da inclinação e sua magnitude.

### Referencia: https://autocorerobotica.blog.br/aprenda-a-utilizar-o-acelerometro-mpu6050/