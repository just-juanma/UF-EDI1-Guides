#include "gbl.h"

int main(void) { // uncomment on the exercise you want to try, and comment on the others (I recommend using breakpoints)
 //	exercise1();
 //	exercise2();
 // exercise3();
 //	exercise4();
 //	exercise5();
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