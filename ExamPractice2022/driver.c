#include "driver.h"

void AbrirValvulaAgua() {
	int8_t mask = 0x1;
	*registro_hardware |= (mask << 7);
}

void CerrarValvulaAgua() {
	int8_t mask = 0x0;
	*registro_hardware &= (~mask << 7);
}

void ActivarMotorLavado() {
	int8_t mask = 0x0;
	*registro_hardware &= (~mask << 6);
}

void ApagarMotorLavado() {
	int8_t mask = 0x1;
	*registro_hardware |= (mask << 6);
}

void ActivarMotorCentrifugado() {
	int8_t mask = 0x3;
	*registro_hardware |= mask;
}

void ApagarMotorCentrifugado() {
	int8_t mask = 0x3;
	*registro_hardware &= ~mask;
}