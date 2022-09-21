#include "gbl.h"

eEstado estado = RESET;

int main(void) {
    ejercicio1();
    return 0;
}

void ejercicio1() {
    while(1) {
        switch(estado) {
            case ESTADO_A:
                if(estadoSensor() == INACTIVO) {
                    estado = ESTADO_A;
                    encenderAlarma();
                }
                else {
                    apagarAlarma();
                }
                
        }
    }

 }