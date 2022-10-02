#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum eEstado { RESET, STANDBY, CENTRIFUGANDO, LAVANDO, LLENANDO_TANQUE };

int32_t botonInicio;
int32_t botonCancelar;
int32_t cuentaTiempo;
int32_t sensorTanqueLleno;
int32_t tiempoLavado; // FALTA AGREGAR ESTA VARIABLE EN EL ARCHIVO "driver.h"
int32_t tiempoCentrifugado; // FALTA AGREGAR ESTA VARIABLE EN EL ARCHIVO "driver.h"
eEstado estado = RESET;

void mdeTanque();
void AbrirValvulaAgua();
void CerrarValvulaAgua();
void ActivarMotorLavado();
void ApagarMotorLavado();
void ActivarMotorCentrifugado();
void ApagarMotorCentrifugado();
