# Arduino — Lâmpada controlada por controlo remoto infravermelho

Sketch para Arduino que liga uma lâmpada (ou LED) durante 10 segundos quando o receptor infravermelho recebe um código específico de um controlo remoto.

## Como funciona

1. O receptor IR lê os sinais no pino `2`.
2. Quando o código recebido é `0xFFA25D`, o pino `13` (lâmpada/LED) fica a `HIGH`.
3. Passados 10 segundos (`tempoAceso`), a lâmpada volta a desligar.

## Hardware

| Componente | Pino |
|---|---|
| Receptor infravermelho | 2 |
| Lâmpada / LED (via relé ou resistência) | 13 |

## Utilização

1. Instale a biblioteca **IRremote** no Arduino IDE.
2. Abra `arduino_ir.cpp` como sketch e carregue-o na placa.
3. Abra o Monitor Série (9600 baud) para ver os códigos do seu controlo.
4. Se o seu controlo enviar outro código, altere o valor `0xFFA25D` em `loop()`.

> Nota: o código está escrito para a API antiga da IRremote (`decode_results`); com versões 3.x ou superiores, adapte para `IrReceiver`.
