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

#pragma region Ejercicio 3
// Un boton sin rebote es aquel que cuando lo presionamos, se queda presionado hasta que lo volvemos a presionar: SUELTO -> PRESIONADO
// Un boton con rebote es aquel que cuando lo presionamos, vuelve a soltarse: SUELTO -> PRESIONADO -> SUELTO

typedef enum { RESET, SUELTO, PRESIONADO, LEYENDO, LEIDO } eEstado3;
typedef enum { PRESIONADO, SUELTO, LEIDO } eBoton;

void ejercicio3(void);
bool lecturaBoton(void); // indica si el boton se encuetra leido
bool presionBoton(void);
void setEstadoBoton(eBoton);

#pragma endregion