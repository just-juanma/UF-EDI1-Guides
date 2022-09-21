#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma region Ejercicio 1

typedef enum { ROJA, VERDE } eColor;
typedef enum { RESET, ESTADO_A, ESTADO_B, ESTADO_C } eEstado1;
typedef enum { INACTIVO, ACTIVO } eSensor;
void ejercicio1(void); 
int FSM_ManejoSensor(void); 
int estadoSensor(void); 
void encenderAlarma(void); 
void apagarAlarma(void); 
int medicionSensor(void);
int encenderLuz(eColor luz);
int apagarLuz(eColor luz);

#pragma endregion

#pragma region Ejercicio 2

typedef enum { RESET, CERRADO, ABRIENDO, ABIERTO, CERRANDO } eEstado2; 
typedef enum { APAGADO, CERRANDO, ABRIENDO } eMotor;
void ejercicio2(void);
void setEstadoMotor(eMotor estado);
bool sensorCerrado(void);
bool sensorAbierto(void);
bool botonPresionado(void);

#pragma endregion
