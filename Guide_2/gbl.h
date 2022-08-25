#define _CRT_SECURE_NO_WARNINGS
/* Digital Electronics 1
Guide 2: Combinational and low-level operators
Note: all exercises that consist in the development of a function must be in a separate file with its corresponding header.
They must also have a program that tests the operation with different input values. */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct fieldsFloat {
	uint8_t sign;
	uint8_t exponent;
	uint32_t mantissa;
} fieldsFloat_t;

void exercise1();
void exercise2(int8_t num); void printBin8(int8_t num); void printBin16(int16_t num); void printBin32(int32_t num);
fieldsFloat_t exercise3(float num); fieldsFloat_t printFieldsFloat(float num);
void exercise4a(); void exercise4b(); void exercise4c(); void exercise4d(); void exercise4e();
void exercise5();
void exercise6(); int32_t turnOffBit(uint32_t var, uint8_t nBit); int32_t turnOnBit(uint32_t var, uint8_t nBit); uint32_t consultBit(uint32_t var, uint8_t nBit); int32_t invertBit(uint32_t var, uint8_t nBit);
