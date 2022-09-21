#include "gbl.h"

eEstado1 estado1 = RESET; 
eEstado2 estado2 = RESET;

int main(void) {
    // ejercicio1();
    ejercicio2();
    return 0;
}

void ejercicio1() {
    while(1) {
        switch(estado1) {
            case RESET:
                estado1 = ESTADO_A;
                break;
            case ESTADO_A:
                if(estadoSensor() == INACTIVO) {
                    estado1 = ESTADO_A;
                    encenderAlarma();
                }
                else {
                    estado1 = ESTADO_B;
                    apagarAlarma();
                }
                break;
            case ESTADO_B:
                if(estadoSensor() == INACTIVO) {
                    estado1 = ESTADO_A;
                    encenderAlarma();
                }
                else if(medicionSensor() < 100) {
                    estado1 = ESTADO_B;
                    apagarLuz(ROJA);
                    encenderLuz(VERDE);
                }
                else {
                    estado1 = ESTADO_C;
                    apagarLuz(VERDE);
                    encenderLuz(ROJA);
                }
            case ESTADO_C:
                if(estadoSensor() == INACTIVO) {
                    estado1 = ESTADO_A;
                    encenderAlarma();
                }
                else if(estadoSensor() >= 100) {
                    estado1 = ESTADO_C;
                    apagarLuz(VERDE);
                    encenderLuz(ROJA);
                }
                else {
                     estado1 = ESTADO_B;
                    apagarLuz(ROJA);
                    encenderLuz(VERDE);                   
                }
                break;
            default:
                estado1 = RESET;
                break;
        }
    }
 }

 void ejercicio2(void) {
    switch (estado2)
    {
    case RESET:
        estado2 = CERRADO;
        break;
    case CERRADO:
        if(botonPresionado() == true) {
            estado2 = ABRIENDO;
            setEstadoMotor(ABRIENDO);
        } 
        else { // en caso de que no se presione el boton
            estado2 = CERRADO;
        }
        break;
    case ABRIENDO:
        if(botonPresionado() == true) {
            estado2 = CERRANDO;
            setEstadoMotor(CERRANDO);
        }
        else if(sensorAbierto() == false) {
            estado2 = ABRIENDO;
        }
        else { // en caso de que no se presione el boton, o bien se prenda el sensor
            estado2 = ABIERTO;
            setEstadoMotor(APAGADO);
        }
        break;
    case ABIERTO:
        if(botonPresionado() == true) {
            estado2 = CERRANDO;
            setEstadoMotor(CERRANDO);
        }
        else { // en caso de que no se presione el boton
            estado2 = ABIERTO;
        }
        break;
    case 4: // no me toma CERRANDO, lo confunde con CERRADO.. idk
        if(botonPresionado() == true) { 
            estado2 = ABRIENDO;
            setEstadoMotor(ABRIENDO);
        }
        else if(sensorCerrado() == true) {
            estado2 = CERRADO;
            setEstadoMotor(APAGADO);
        }
        else { // en caso de que no se presione el boton, o bien no se prenda el sensor
            estado2 = CERRANDO;
        }
        break;
    
    default:
        estado2 = RESET;
        break;
    }
 }