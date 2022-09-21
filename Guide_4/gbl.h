#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum { ROJO, VERDE } eColor;
typedef enum { RESET, ESTADO_A, ESTADO_B, ESTADO_C } eEstado;
typedef enum { INACTIVO, ACTIVO } eSensor;

#pragma region Ejercicio 1
void ejercicio1(void); 
int FSM_ManejoSensor(void); 
int estadoSensor(void); 
void encenderAlarma(void); 
void apagarAlarma(void); 
int medicionSensor(void);
int encenderLuz(eColor luz);
int apagarLuz(eColor luz);

#pragma endregion