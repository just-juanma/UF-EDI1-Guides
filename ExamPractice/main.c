#include "mde.h"

int main() {
	eEstado maquina1 = RESET;
	eEstado maquina2 = RESET;
	while (1)
	{
		mdeTanque(maquina1);
		mdeTanque(maquina2);
	}
	return 0;
}