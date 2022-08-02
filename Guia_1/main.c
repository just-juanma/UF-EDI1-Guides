#include "gbl.h"

int main(void) { // descomentar el ejercicio que queres probar, comentar los demas (recomiendo usar breakpoints)
 //	ejercicio1();
 //	ejercicio2();
 // ejercicio3();
 //	ejercicio4();
 //	ejercicio5();
	return 0;
}

void ejercicio1() {
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

	printf("Variables en bytes, mediante sizeof():\n");
	printf("Char: %d (decimal), %x (hexadecimal), %o (octal)\n", tamChar, tamChar, tamChar);
	printf("Short: %d (decimal), %x (hexadecimal), %o (octal)\n", tamShort, tamShort, tamShort);
	printf("Int: %d (decimal), %x (hexadecimal), %o (octal)\n", tamInt, tamInt, tamInt);
	printf("Long: %d (decimal), %x (hexadecimal), %o (octal)\n", tamLong, tamLong, tamLong);
	printf("Long Long: %d (decimal), %x (hexadecimal), %o (octal)\n", tamLongLong, tamLongLong, tamLongLong);
	printf("Float: %d (decimal), %x (hexadecimal), %o (octal)\n", tamFloat, tamFloat, tamFloat);
	printf("Double: %d (decimal), %x (hexadecimal), %o (octal)\n", tamDouble, tamDouble, tamDouble);
	printf("No cambia el tamaño si la variable es unsigned\n");
}

void ejercicio2() {
    int8_t var8 = 0;
    int16_t var16 = 0;
    int32_t var32 = 0;
    int64_t var64 = 0;

    short int tamVar8 = sizeof(var8);
    short int tamVar16 = sizeof(var16);
    short int tamVar32 = sizeof(var32);
    short int tamVar64 = sizeof(var64);

    printf("Variables en bytes, mediante sizeof():\n");
    printf("Int de 8: %d (decimal), %x (hexadecimal), %o (octal)\n", tamVar8, tamVar8, tamVar8);
    printf("Int de 16: %d (decimal), %x (hexadecimal), %o (octal)\n", tamVar16, tamVar16, tamVar16);
    printf("Int de 32: %d (decimal), %x (hexadecimal), %o (octal)\n", tamVar32, tamVar32, tamVar32);
    printf("Int de 64: %d (decimal), %x (hexadecimal), %o (octal)\n", tamVar64, tamVar64, tamVar64);
}

void ejercicio3() {
	int n1, n2, i, * num = NULL;
	printf("Ingrese 2 numeros enteros:\n");
	(void)scanf("%d %d", &n1, &n2);
	if (n1 > n2) {
		num = calloc(n1, sizeof(int));
		if (!num) return;
		for (i = 0; i < n1 - n2 + 1; i++) {
			num[i] = n2 + i;
			printf("Numero [%d]: %d (decimal), %x (hexadecimal), %o (octal)\n", i, num[i], num[i], num[i]);
		}
		free(num);
	}
	else if (n2 > n1) {
		num = calloc(n2, sizeof(int));
		if (!num) return;
		for (i = 0; i < n2 - n1 + 1; i++) {
			num[i] = n2 + i;
			printf("Numero[%d]: %d (decimal), %x (hexadecimal), %o (octal)\n", i, num[i], num[i], num[i]);
		}
		free(num);
	}
	else {
		printf("Dos numeros iguales no son validos\n");
	}
}

void ejercicio4() { ejercicio3Modificado(); }

void ejercicio3Modificado() {
	int n1, n2, i, * num = NULL;
	printf("Ingrese 2 numeros enteros:\n");
	(void)scanf("%d %d", &n1, &n2);
	if (n1 > n2) {
		num = calloc(n1, sizeof(int));
		if (!num) return;
		for (i = 0; i < n1 - n2 + 1; i++) {
			num[i] = n2 + i;
			printf("Numero [%d]: %d (decimal), %x (hexadecimal), %o (octal)", i, num[i], num[i], num[i]);
			imprimirBin8(num[i]);
		}
		free(num);
	}
	else if (n2 > n1) {
		num = calloc(n2, sizeof(int));
		if (!num) return;
		for (i = 0; i < n2 - n1 + 1; i++) {
			num[i] = n1 + i;
			printf("Numero[%d]: %d (decimal), %x (hexadecimal), %o (octal)", i, num[i], num[i], num[i]);
			imprimirBin8(num[i]);
		}
		free(num);
	}
	else {
		printf("Dos numeros iguales no son validos\n");
	}
}

void imprimirBin8(int8_t num) {
	int resto = 0, resultado = num, i = 0, size = 0, temp = 0, * arr = calloc(size, sizeof(int));
	if (!arr) return;
	while (resultado) {
		resto = resultado % 2;
		arr = (int*)realloc(arr, sizeof(int) * ++size);
		if (!arr) return;
		arr[i++] = resto;
		resultado /= 2;
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
	printf(" (binario de 8 bits / 1 byte)\n");
	free(arr);
}

void imprimirBin16(int16_t num) {
	int resto = 0, resultado = num, i = 0, size = 0, temp = 0, * arr = calloc(size, sizeof(int));
	if (!arr) return;
	while (resultado) {
		resto = resultado % 2;
		arr = (int*)realloc(arr, sizeof(int) * ++size);
		if (!arr) return;
		arr[i++] = resto;
		resultado /= 2;
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
	printf(" (binario de 16 bits / 2 bytes)\n");
	free(arr);
}

void imprimirBin32(int32_t num) {
	int resto = 0, resultado = num, i = 0, size = 0, temp = 0, * arr = calloc(size, sizeof(int));
	if (!arr) return;
	while (resultado) {
		resto = resultado % 2;
		arr = (int*)realloc(arr, sizeof(int) * ++size);
		if (!arr) return;
		arr[i++] = resto;
		resultado /= 2;
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
	printf(" (binario de 32 bits / 4 bytes)\n");
	free(arr);
}

void ejercicio5() { // para imprimir el numero en binario uso parte del ejercicio 4
	char bin32[32] = { 0 };
	int32_t decimal;
	printf("Ingrese un numero binario:\n");
	(void)scanf("%s", &bin32);
	decimal = binarioDecimal(bin32);
	printf("%d (decimal), %o (octal)", decimal, decimal); imprimirBin32(decimal); 
}

int32_t binarioDecimal(char* cadena_numero) {
	int i, digito = 0, exponente = strlen(cadena_numero) - 1, decimal = 0;
	for (i = 0; i < strlen(cadena_numero); i++) {
		digito = cadena_numero[i] - '0'; // gracias adri por la idea <3
		decimal += digito * pow(2, exponente--);
	}
	return decimal;
}