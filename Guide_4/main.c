#include "gbl.h"

eEstado estado = RESET;

int main(void) {
    ejercicio1();
    return 0;
}

void ejercicio1() {
    while(1) {
        switch(estado) {
            case RESET:
                estado = ESTADO_A;
                break;
            case ESTADO_A:
                if(estadoSensor() == INACTIVO) {
                    estado = ESTADO_A;
                    encenderAlarma();
                }
                else {
                    estado = ESTADO_B;
                    apagarAlarma();
                }
                break;
            case ESTADO_B:
                if(estadoSensor() == INACTIVO) {
                    estado = ESTADO_A;
                    encenderAlarma();
                }
                else if(medicionSensor() < 100) {
                    estado = ESTADO_B;
                    apagarLuz(ROJA);
                    encenderLuz(VERDE);
                }
                else {
                    estado = ESTADO_C;
                    apagarLuz(VERDE);
                    encenderLuz(ROJA);
                }
            case ESTADO_C:
                if(estadoSensor() == INACTIVO) {
                    estado = ESTADO_A;
                    encenderAlarma();
                }
                else if(estadoSensor() >= 100) {
                    estado = ESTADO_C;
                    apagarLuz(VERDE);
                    encenderLuz(ROJA);
                }
                else {
                     estado = ESTADO_B;
                    apagarLuz(ROJA);
                    encenderLuz(VERDE);                   
                }
                break;
            default:
                estado = RESET;
                break;
        }
    }

 }