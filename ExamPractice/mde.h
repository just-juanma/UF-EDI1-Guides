#pragma once
#include <"driver.h">

int32_t tiempoLavado;
int32_t tiempoCentrifugado;

enum eEstado { RESET, STANDBY, CENTRIFUGANDO, LAVANDO, LLENANDO_TANQUE };

void mdeTanque(eEstado estado);