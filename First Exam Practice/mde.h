#pragma once
#include "driver.h"

int32_t tiempoLavado;
int32_t tiempoCentrifugado;

typedef enum eEstado { RESET, STANDBY, CENTRIFUGANDO, LAVANDO, LLENANDO_TANQUE } eEstado;

void mdeTanque(eEstado estado);