#include <stdio.h>
#include <stdlib.h>


void konwersja(int liczba) 
{
	if(liczba > 0)
	{
		konwersja(liczba / 2);
		printf("%d", liczba % 2);
	}
}


int main() {
	int liczba;
	printf("Podaj liczbe: ");
	scanf("%d", &liczba);

	printf("Podana liczba w postaci dziesietnej: %d \nWynik: ", liczba);
  konwersja(liczba);
  printf("\n");

	return 0;
}



