#include "gbl.h"

int main(void) { // uncomment on the exercise you want to try, and comment on the others (I recommend using breakpoints)
 //	exercise1();
 //	exercise2();
 // exercise3();
 //	exercise4();
 //	exercise5();
 // /* exercise 6 first part */ int16_t var = 0x7FFF; exercise6(var); printf("There is no difference other than the printing format (hexadecimal or decimal)\n"); exercise6(++var); printf("In addition to increasing the value by 1, it happens that the signed int variable reaches its maximum range of positive values (2^15 - 1), then it makes a kind of 'flip' back to its smallest value\n");
 // /* exercise 6 second part */ int16_t var = 0x0000; exercise6(var); printf("There is no difference other than the printing format (hexadecimal or decimal)\n"); exercise6(--var); printf("In addition to decreasing the value by 1, it happens that the unsigned int variable reaches its minimum range of values (0), then it makes a kind of 'flip' back to its largest value\n");
 // exercise7();
 // exercise8();
 // exercise 9 skipped, since it will not be considered in the exam
	exercise10();
 
	return 0;
}

void exercise1() {
	char varChar = 0;
	int varInt = 0;
	short int varShort = 0;
	int long varLong = 0;
	long long int varLongLong = 0;
	float varFloat = 0;
	double varDouble = 0;

	short int tamChar = sizeof(varChar);
	short int tamShort = sizeof(varShort);
	short int tamInt = sizeof(varInt);
	short int tamLong = sizeof(varLong);
	short int tamLongLong = sizeof(varLongLong);
	short int tamFloat = sizeof(varFloat);
	short int tamDouble = sizeof(varDouble);

	printf("Variables in bytes, by means of sizeof():\n");
	printf("Char: %d (decimal), %x (hexadecimal), %o (octal)\n", tamChar, tamChar, tamChar);
	printf("Short: %d (decimal), %x (hexadecimal), %o (octal)\n", tamShort, tamShort, tamShort);
	printf("Int: %d (decimal), %x (hexadecimal), %o (octal)\n", tamInt, tamInt, tamInt);
	printf("Long: %d (decimal), %x (hexadecimal), %o (octal)\n", tamLong, tamLong, tamLong);
	printf("Long Long: %d (decimal), %x (hexadecimal), %o (octal)\n", tamLongLong, tamLongLong, tamLongLong);
	printf("Float: %d (decimal), %x (hexadecimal), %o (octal)\n", tamFloat, tamFloat, tamFloat);
	printf("Double: %d (decimal), %x (hexadecimal), %o (octal)\n", tamDouble, tamDouble, tamDouble);
	printf("Do not resize if a variable is unsigned\n");
}

void exercise2() {
    int8_t var8 = 0;
    int16_t var16 = 0;
    int32_t var32 = 0;
    int64_t var64 = 0;

    short int tamVar8 = sizeof(var8);
    short int tamVar16 = sizeof(var16);
    short int tamVar32 = sizeof(var32);
    short int tamVar64 = sizeof(var64);

    printf("Variables in bytes, by means of sizeof():\n");
    printf("Int of 8: %d (decimal), %x (hexadecimal), %o (octal)\n", tamVar8, tamVar8, tamVar8);
    printf("Int of 16: %d (decimal), %x (hexadecimal), %o (octal)\n", tamVar16, tamVar16, tamVar16);
    printf("Int of 32: %d (decimal), %x (hexadecimal), %o (octal)\n", tamVar32, tamVar32, tamVar32);
    printf("Int of 64: %d (decimal), %x (hexadecimal), %o (octal)\n", tamVar64, tamVar64, tamVar64);
}

void exercise3() {
	int n1, n2, i, * num = NULL;
	printf("Enter 2 integer numbers:\n");
	(void)scanf("%d %d", &n1, &n2);
	if (n1 > n2) {
		num = calloc(n1, sizeof(int));
		if (!num) return;
		for (i = 0; i < n1 - n2 + 1; i++) {
			num[i] = n2 + i;
			printf("Number [%d]: %d (decimal), %x (hexadecimal), %o (octal)\n", i, num[i], num[i], num[i]);
		}
		free(num);
	}
	else if (n2 > n1) {
		num = calloc(n2, sizeof(int));
		if (!num) return;
		for (i = 0; i < n2 - n1 + 1; i++) {
			num[i] = n2 + i;
			printf("Number [%d]: %d (decimal), %x (hexadecimal), %o (octal)\n", i, num[i], num[i], num[i]);
		}
		free(num);
	}
	else {
		printf("Two identical numbers are not valid\n");
	}
}

void exercise4() { exercise3Modified(); }

void exercise3Modified() {
	int n1, n2, i, * num = NULL;
	printf("Enter 2 integer numbers:\n");
	(void)scanf("%d %d", &n1, &n2);
	if (n1 > n2) {
		num = calloc(n1, sizeof(int));
		if (!num) return;
		for (i = 0; i < n1 - n2 + 1; i++) {
			num[i] = n2 + i;
			printf("Number [%d]: %d (decimal), %x (hexadecimal), %o (octal)", i, num[i], num[i], num[i]);
			printBin8(num[i]);
		}
		free(num);
	}
	else if (n2 > n1) {
		num = calloc(n2, sizeof(int));
		if (!num) return;
		for (i = 0; i < n2 - n1 + 1; i++) {
			num[i] = n1 + i;
			printf("Number [%d]: %d (decimal), %x (hexadecimal), %o (octal)", i, num[i], num[i], num[i]);
			printBin8(num[i]);
		}
		free(num);
	}
	else {
		printf("Two identical numbers are not valid\n");
	}
}

void printBin8(int8_t num) {
	int remainder = 0, resul = num, i = 0, size = 0, temp = 0, * arr = calloc(size, sizeof(int));
	if (!arr) return;
	while (resul) {
		remainder = resul % 2;
		arr = (int*)realloc(arr, sizeof(int) * ++size);
		if (!arr) return;
		arr[i++] = remainder;
		resul /= 2;
	}
	for (i = 0; i < size / 2; i++) {
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
	printf(", ");
	for (i = 0; i < 8 - size; i++) {
		printf("0");
	}
	for (i = 0; i < size; i++) {
		printf("%d", arr[i]);
	}
	printf(" (8 bits binary / 1 byte)\n");
	free(arr);
}

void printBin16(int16_t num) {
	int remainder = 0, resul = num, i = 0, size = 0, temp = 0, * arr = calloc(size, sizeof(int));
	if (!arr) return;
	while (resul) {
		remainder = resul % 2;
		arr = (int*)realloc(arr, sizeof(int) * ++size);
		if (!arr) return;
		arr[i++] = remainder;
		resul /= 2;
	}
	for (i = 0; i < size / 2; i++) {
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
	printf(", ");
	for (i = 0; i < 16 - size; i++) {
		printf("0");
	}
	for (i = 0; i < size; i++) {
		printf("%d", arr[i]);
	}
	printf(" (16 bits binary / 2 bytes)\n");
	free(arr);
}

void printBin32(int32_t num) {
	int rest = 0, resul = num, i = 0, size = 0, temp = 0, * arr = calloc(size, sizeof(int));
	if (!arr) return;
	while (resul) {
		rest = resul % 2;
		arr = (int*)realloc(arr, sizeof(int) * ++size);
		if (!arr) return;
		arr[i++] = rest;
		resul /= 2;
	}
	for (i = 0; i < size / 2; i++) {
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
	printf(", ");
	for (i = 0; i < 32 - size; i++) {
		printf("0");
	}
	for (i = 0; i < size; i++) {
		printf("%d", arr[i]);
	}
	printf(" (32 bits binary / 4 bytes)\n");
	free(arr);
}

void exercise5() { // to print the number in binary I use part of the exercise 4
	char bin32[32] = { 0 };
	int32_t decimal;
	printf("Enter a binary number:\n");
	(void)scanf("%s", &bin32);
	decimal = binaryDecimal(bin32);
	printf("%d (decimal), %o (octal)", decimal, decimal); printBin32(decimal);
}

int32_t binaryDecimal(char* number_string) {
	int i, digit = 0, exponent = strlen(number_string) - 1, decimal = 0;
	for (i = 0; i < strlen(number_string); i++) {
		digit = number_string[i] - '0'; // thanks adri for the idea <3
		decimal += digit * pow(2, exponent--);
	}
	return decimal;
}

void exercise6(int16_t numberRepresent) { printEnterContent(numberRepresent); }

void printEnterContent(int16_t numberRepresent) {
	printf("16 bits unsigned int (hexa): %x\n", numberRepresent);
	printf("16 bits unsigned int (decimal): %hu\n", numberRepresent);
	printf("16 bits signed int (decimal): %hd\n", numberRepresent);
}

void exercise7() {
	uint16_t num1 = 0x800, num2 = 0x0001, resul = num1 - num2;
	printf("num1 16 bits unsigned int (hexa): %x\n", num1);
	printf("num1 16 bits unsigned int (decimal): %hu\n", num1);
	printf("num1 16 bits signed int (decimal): %hd\n", num1);
	
	printf("num2 16 bits unsigned int (hexa): %x\n", num2);
	printf("num2 16 bits unsigned int (decimal): %hu\n", num2);
	printf("num2 16 bits signed int (decimal): %hd\n", num2);
	
	printf("resul 16 bits unsigned int (hexa): %x\n", resul);
	printf("resul 16 bits unsigned int (decimal): %hu\n", resul);
	printf("resul 16 bits signed int (decimal): %hd\n", resul);

	printf("There is no overflow, and the easiest way to realize this is that it makes sense to perform the operation 248 - 1 = 247. Another reason may be that the range of values of a uint16_t in the result variable is not exceeded\n");

	num1 = 0x7FFF; resul = num1 + num2;
	printf("num1 16 bits unsigned int (hexa): %x\n", num1);
	printf("num1 16 bits unsigned int (decimal): %hu\n", num1);
	printf("num1 16 bits signed int (decimal): %hd\n", num1);

	printf("num2 16 bits unsigned int (hexa): %x\n", num2);
	printf("num2 16 bits unsigned int (decimal): %hu\n", num2);
	printf("num2 16 bits signed int (decimal): %hd\n", num2);

	printf("resul 16 bits unsigned int (hexa): %x\n", resul);
	printf("resul 16 bits unsigned int (decimal): %hu\n", resul);
	printf("resul 16 bits signed int (decimal): %hd\n", resul);

	printf("In this case there was an overflow, and the reason is that it exceeds the limit of a 16 - bit signed integer(2 ^ 15 - 1 < 32767 + 1), so it returns to the lowest possible value (-2 ^ 15)\n");

	num1 = 0xF000; num2 = 0xFF01; resul = num1 + num2;
	printf("num1 16 bits unsigned int (hexa): %x\n", num1);
	printf("num1 16 bits unsigned int (decimal): %hu\n", num1);
	printf("num1 16 bits signed int (decimal): %hd\n", num1);

	printf("num2 16 bits unsigned int (hexa): %x\n", num2);
	printf("num2 16 bits unsigned int (decimal): %hu\n", num2);
	printf("num2 16 bits signed int (decimal): %hd\n", num2);

	printf("resul 16 bits unsigned int (hexa): %x\n", resul);
	printf("resul 16 bits unsigned int (decimal): %hu\n", resul);
	printf("resul 16 bits signed int (decimal): %hd\n", resul);
	
	printf("There was no overflow, since it respects consistency of signs in its result, but doing its sums in binary (1111 0000 0000 0000 0000 + 1111 1111 1111 0000 0000 0001) we arrive at a carry. But, remember that in Complement of a 2 the carry is not taken into account\n");

	num1 = 0x0011; num2 = 0xFF01; resul = num1 + num2;
	printf("num1 16 bits unsigned int (hexa): %x\n", num1);
	printf("num1 16 bits unsigned int (decimal): %hu\n", num1);
	printf("num1 16 bits signed int (decimal): %hd\n", num1);

	printf("num2 16 bits unsigned int (hexa): %x\n", num2);
	printf("num2 16 bits unsigned int (decimal): %hu\n", num2);
	printf("num2 16 bits signed int (decimal): %hd\n", num2);

	printf("resul 16 bits unsigned int (hexa): %x\n", resul);
	printf("resul 16 bits unsigned int (decimal): %hu\n", resul);
	printf("resul 16 bits signed int (decimal): %hd\n", resul);

	printf("There was no overflow, since it respects the coherence of signs in its result, there is no carry or borrow when counting\n");
}

void exercise8() {
	uint16_t uvar16 = 0x80FF;
    printf("uvar 16 bits unsigned int (hexa): %x\n", uvar16);
	printf("uvar 16 bits unsigned int (decimal): %hu\n", uvar16);
	printf("uvar 16 bits signed int (decimal): %hd\n", uvar16);
	
	uint32_t uvar32 = (uint32_t)uvar16;
	printf("uvar 32 bits unsigned int (hexa): %x\n", uvar32);
	printf("uvar 32 bits unsigned int (decimal): %hu\n", uvar32);
	printf("uvar 32 bits signed int (decimal): %hd\n", uvar32);
	
	int16_t var16 = 0x80FF;
	printf("var 16 bits unsigned int (hexa): %x\n", var16);
	printf("var 16 bits unsigned int (decimal): %hu\n", var16);
	printf("var 16 bits signed int (decimal): %hd\n", var16);

	int32_t var32 = (int32_t)var16;
	printf("var 32 bits unsigned int (hexa): %x\n", var32);
	printf("var 32 bits unsigned int (decimal): %hu\n", var32);
	printf("var 32 bits signed int (decimal): %hd\n", var32);

	printf("You are trying to print a variable signed as hexadecimal, when in fact when printing in hexadecimal the variable is printed as unsigned, then it is necessary to autocomplete with so many 1's to the left to indicate that the variable is negative. The shift is done taking into account the source variable, since it completes with 0xFFFF (2^16 - 1) bits to the left. Yes, it does matter if the offset is signed or unsigned, since an unsigned has no problem printing the value 0x80FF, since it is in its range of values (it is less than 2^16)\n");
}

void exercise10() {
	char var = 65;
	printf("var (char): %c\n", var);
	printf("var (int): %d\n", var);
	printf("Yes, it corresponds. You can check it by doing ALT + 65, and you get 'A'\n");
	var = 'a';
	printf("var (char): %c\n", var);
	printf("var (int): %d\n", var);
	printf("Its numerical value (int) is stored. In this case, the 97\n");
	var++;
	printf("var (char): %c\n", var);
	printf("var (int): %d\n", var);
	printf("Yes, you can perform any mathematical or logical operation on the char, since it is considered as an int\n");
}