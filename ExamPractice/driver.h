#pragma once
#include <stdio.h>
#include <stdint.h>

int32_t botonInicio;
int32_t botonCancelar;
int32_t cuentaTiempo;
int32_t sensorTanqueLleno;

// ejercicio 4
uint8_t* registro_hardware;

void AbrirValvulaAgua();
void CerrarValvulaAgua();
void ActivarMotorLavado();
void ApagarMotorLavado();
void ActivarMotorCentrifugado();
void ApagarMotorCentrifugado();