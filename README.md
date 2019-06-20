# AutomacaoCerveja

## Autores

Êmili Bohrer

Filipe Gonçalves

Julio Fronczak

Paulo Duarte

## Visão geral

Sistema embarcado para auxiliar na automação da preparação de cervejas Pale Ale.

## Modelagem

O sistema foi modelado como um conjunto de máquinas de estado, com o auxílio do software de Model Checking UPPAAL.

A implementação conta com uma máquina de estados principal (Processo), três máquinas de estados dos sistemas periféricos (Controlador, Leds e Sensor de Temperatura) e três máquinas de estados dos processos de preparação da cerveja (brassagem, fervura e recirculação).

## Implementação

O sistema foi desenvolvido em C++ e será utilizado como uma biblioteca para a plataforma Arduino.

