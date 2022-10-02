#include "driver.h"

int main() {
	while (1)
	{
		mdeTanque();
	}
}

void mdeTanque() {
	switch (estado) {
	case RESET:
		estado = STANDBY;
		break;
	case STANDBY:
		if (botonInicio == 1) {
			AbrirValvulaAgua();
			estado = LLENANDO_TANQUE;
		}
		break;
	case LLENANDO_TANQUE:
		if (botonCancelar == 1) {
			CerrarValvulaAgua();
			estado = STANDBY;
		}
		else if (sensorTanqueLleno == 1) {
			CerrarValvulaAgua();
			ActivarMotorLavado();
			cuentaTiempo = 0;
			estado = LAVANDO;
		}
		break;
	case LAVANDO:
		if (botonCancelar == 1) {
			ApagarMotorLavado();
			estado = STANDBY;
		}
		else if (cuentaTiempo >= tiempoLavado) {
			ApagarMotorLavado();
			ActivarMotorCentrifugado();
			cuentaTiempo = 0;
			estado = CENTRIFUGANDO;
		}
		break;
	case CENTRIFUGANDO:
		if (cuentaTiempo >= tiempoCentrifugado || botonCancelar == 1) {
			ApagarMotorCentrifugado();
			estado = STANDBY;
		}
		break;
	default:
		estado = RESET;
		break;
	}
}