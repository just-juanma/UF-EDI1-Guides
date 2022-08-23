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
	//exercise4a();
	//exercise4b();
	//exercise4c();
	//exercise4d();
	//exercise4e();
	//exercise5();
	exercise6();
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
	int8_t mask = sizeof(num) * 8 - 1; // bitmask
	while (mask >= 0) 
		printf("%d", (num >> mask--) & 1); // I scroll the bit mask from left to right comparing its least significant bit with 1 (to know what to print)
	// repeat this function for 16 and 32 bits
}

void printBin16(int16_t num) {
	int16_t mask = sizeof(num) * 8 - 1;
	while (mask >= 0)
		printf("%d", (num >> mask--) & 1);
}

void printBin32(int32_t num) {
	int32_t mask = sizeof(num) * 8 - 1;
	while (mask >= 0)
		printf("%d", (num >> mask--) & 1);
}

fieldsFloat_t exercise3(float num) { printFieldsFloat(num); }

fieldsFloat_t printFieldsFloat(float num) {
	fieldsFloat_t temp;
	uint32_t maskSign = 0x80000000;
	uint32_t maskExp = 0x7F800000;
	uint32_t maskMan = 0x007FFFFF;
	temp.sign = (*(unsigned int*)&num & maskSign) >> sizeof(num) * 8 - 1;
	temp.exponent = (*(unsigned int*)&num & maskExp) >> 23;
	temp.mantissa = (*(unsigned int*)&num & maskMan);
	return temp;
}

void exercise4a() {
	int8_t var1 = 53;
	int8_t var2 = var1 * -1;
	int8_t var3 = ~var1;
	printf("var1 decimal: %d, hexadecimal 0x%x, binary ", var1, var1); printBin8(var1);
	printf("\nvar2 decimal: %d, hexadecimal 0x%x, binary ", var2, var2); printBin8(var2);
	printf("\nvar3 decimal: %d, hexadecimal 0x%x, binary ", var3, var3); printBin8(var3);
	printf("\nThe difference is due to the +1 that is added in the two's complement, which should not be added in the negation\n");
}

void exercise4b() {
	int16_t mask = 0xF0F0;
	int16_t var1 = 0x5A5A;
	printf("AND operation hexadecimal 0x%x, binary ", mask & var1); printBin16(mask & var1);
	printf("\n&& is a logical bool operator, and there is a difference of precendence (which operators get evaluated first). However, as in binary, it is activated in case both are 1. The * operator is used with decimal base numbers, and the multiplication of decimals is different from going number by number in binary\n");
}

void exercise4c() {
	int16_t var1 = 0xA0A0;
	int16_t var2 = 0x00FF;
	printf("OR operation hexadecimal 0x%x, binary ", var1 | var2); printBin16(var1 | var2);
	printf("\n|| is a logical 'if' operator, and there is a difference of precendence (which operators get evaluated first). However, as in binary, it is activated in case one of both is 1. The + operator is used with decimal base numbers, and the sum of decimals is different from going number by number in binary\n");
}

void exercise4d() {
	int16_t var1 = 0xFF00;
	int16_t var2 = 0x6060;
	printf("XOR operation hexadecimal 0x%x, binary ", var1 ^ var2); printBin16(var1 ^ var2); putchar('\n');
}

void exercise4e() {
	int16_t var1 = 0x5A5A;
	int16_t var2 = 0xA5A5;
	int16_t resLog = var1 & var2;
	int16_t resBool = var1 && var2;
	printf("The difference is that resLog evaluated the AND number by number, but the bool, seeing that both numbers are different from 0 (true), returns true, which represents 1 (by convention)\n");
}

void exercise5() {
	uint32_t LPC1769 = 0x46C0440; // I chose to use (for example) channel: 5, clock: 0110 1100, burst: 0, PDN: running (1), start: 010, edge: flank (0)
	uint32_t burstMask = 0x46C8440;
	printf("Selected input 1 of the ADC to be converted: "); printBin32(LPC1769 | burstMask); // 1 guaranteed
	uint32_t clockValue = LPC1769 << 8; // remove the SEL channel
	printf("\nClock value (as an integer): %d\n", clockValue >> 24); // take the clock to the end and print it
	uint32_t flankMask = 0x2710;
	printf("Flank value (inverted): "); printBin32(LPC1769 ^ flankMask);  // if edge is 0, it will be 1. but, if the edge is 1, it will be 1
	uint32_t PDNMask = 0x400;
	printf("\nADC in low power mode: "); printBin32(LPC1769 & ~PDNMask); // 0 guaranteed
}

void exercise6() {
	int32_t nError = turnOffBit(0x100000000, 4);
	putchar('\n');
	nError = turnOnBit(0x8000000, 5);
}

int32_t turnOffBit(uint32_t var, uint8_t nBit) {
	uint32_t mask = 1 << sizeof(var) * 8 - nBit;
	if (nBit <= 32) {
		printBin32(var & ~mask);
		return 0;
	}
	else
		return 1;
}

int32_t turnOnBit(uint32_t var, uint8_t nBit) {
	uint32_t mask = 1 << sizeof(var) * 8 - nBit;
	if (nBit <= 32) {
		printBin32(var | mask);
		return 0;
	}
	else
		return 1;
}