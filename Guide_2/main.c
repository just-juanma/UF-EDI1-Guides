#include "gbl.h"

int main() {
	//exercise1();
	//exercise2(12);
	/* //exercise 3
	float num = -12.3; fieldsFloat_t temp = exercise3(-12.3);
	printf("Number: 0x%x\n", *(unsigned int*)&num);
	printf("Sign: 0x%x\n", temp.sign);
	printf("Exponent 0x%x\n", temp.exponent);
	printf("Mantissa: 0x%x\n", temp.mantissa);	
	*/
	return 0;
}

void exercise1() {
	int16_t num1 = 0x00FF, num2 = 0x0012;
	printf("num1: 0x%x\t  num2: 0x%x\tAnd operator result: 0x%x\t  Or operator result: 0x%x\t  Xor result: 0x%x\n", num1, num2, num1 & num2, num1 | num2, num1 ^ num2);
	num1 = 0x005F; num2 = 0x00FA;
	printf("num1: 0x%x\t  num2: 0x%x\tAnd operator result: 0x%x\t  Or operator result: 0x%x\t  Xor result: 0x%x\n", num1, num2, num1 & num2, num1 | num2, num1 ^ num2);
	num1 = 0xAA55; num2 = 0x55AA;
	printf("num1: 0x%x  num2: 0x%x\tAnd operator result: 0x%x\t  Or operator result: 0x%x  Xor result: 0x%x\n", num1, num2, num1 & num2, num1 | num2, num1 ^ num2);
	num1 = 0xFFFF; num2 = 0x1212;
	printf("num1: 0x%x  num2: 0x%x\tAnd operator result: 0x%x\t  Or operator result: 0x%x  Xor result: 0x%x\n", num1, num2, num1 & num2, num1 | num2, num1 ^ num2);
	printf("It is possible to observe how in the numbers 0xFF and 0xFFFFFFFFFFFFFF if they are passed to binary all 1 is obtained, reason why in the AND operator the number 2 (12 and 1212) will be maintained. However, in the or operator, the opposite happens, since there will always be a 1 to complete\n");
}

void exercise2(int8_t num) { printBin8(num); }

void printBin8(int8_t num) {
	uint8_t mask = sizeof(num) * 8 - 1; // bitmask
	while (mask >= 0) 
		printf("%d", (num >> mask--) & 1); // I scroll the bit mask from left to right comparing its least significant bit with 1 (to know what to print)
	// repeat this function for 16 and 32 bits
}

void printBin16(int16_t num) {
	uint16_t mask = sizeof(num) * 8 - 1;
	while (mask >= 0)
		printf("%d", (num >> mask--) & 1);
}

void printBin32(int32_t num) {
	uint32_t mask = sizeof(num) * 8 - 1;
	while (mask >= 0)
		printf("%d", (num >> mask--) & 1);
}

fieldsFloat_t exercise3(float num) { printFieldsFloat(num); }

fieldsFloat_t printFieldsFloat(float num) {
	fieldsFloat_t temp;
	uint32_t maskSign = 0x80000000;
	uint32_t maskExp = 0x7F800000;
	uint32_t maskMan = 0x007FFFFF;
	temp.sign = (*(unsigned int*)&num & maskSign) >> 31;
	temp.sign = (*(unsigned int*)&num & maskExp) >> 23;
	temp.sign = (*(unsigned int*)&num & maskMan);
	return temp;
}