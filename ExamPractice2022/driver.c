#include "driver.h"

void AbrirValvulaAgua() {
	uint8_t mask = 0x1;
	*registro_hardware |= (mask << 7);
}

void CerrarValvulaAgua() {
	uint8_t mask = 0x1;
	*registro_hardware &= ~(mask << 7);
}

void ActivarMotorLavado() {
	uint8_t mask = 0x1;
	*registro_hardware &= ~(mask << 5);
}

void ApagarMotorLavado() {
	uint8_t mask = 0x1;
	*registro_hardware |= (mask << 5);
}

void ActivarMotorCentrifugado() {
	uint8_t mask = 0x3;
	*registro_hardware |= mask;
}

void ApagarMotorCentrifugado() {
	uint8_t mask = 0x3;
	*registro_hardware &= ~mask;
}
