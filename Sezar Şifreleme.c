#include<stdio.h>
#include<conio.h> 
int sifrele(char cumle[], int sifrelenicekKarakter);
int sifrecoz(char cumle[], int sifrelenicekKarakter);
int i;
int sifrele(char cumle[], int sifrelenicekKarakter) {
	if ((int)cumle[i] > 64 && (int)cumle[i] < 91) {
		for (i = 0; cumle[i]; i++) {
			if (cumle[i] == ' ')
			{
				cumle[i] == ' ';
			}
			else
			{
				char b;
				b = (char)(((int)cumle[i] - 65 + sifrelenicekKarakter) % 26 + 65);
				cumle[i] = b;
			}


		}

	}
	else if ((int)cumle[i] > 96 && (int)cumle[i] < 123) {
		for (i = 0; cumle[i]; i++) {
			if (cumle[i] == ' ')
			{
				cumle[i] == ' ';
			}
			else {
				char b;
				b = (char)(((int)cumle[i] - 97 + sifrelenicekKarakter) % 26 + 97);
				cumle[i] = b;

			}



		}

	}


}

int sifrecoz(char cumle[], int sifrelenicekKarakter) {


	if ((int)cumle[i] > 64 && (int)cumle[i] < 91) {
		for (i = 0; cumle[i]; i++) {

			if (cumle[i] == ' ')
			{
				cumle[i] = ' ';
			}
			else
			{

				char b;
				b = (char)(((int)cumle[i] - 65 - sifrelenicekKarakter % 26 + 26) % 26) + 65;
				cumle[i] = b;
			}

		}

	}
	else if ((int)cumle[i] > 96 && (int)cumle[i] < 123) {
		for (i = 0; cumle[i]; i++) {

			if (cumle[i] == ' ')
			{
				cumle[i] = ' ';
			}
			else {
				char b;


				b = (char)(((int)cumle[i] - 97 - sifrelenicekKarakter % 26 + 26) % 26) + 97;

				cumle[i] = b;


			}


		}

	}



}

int main(void)
{
	FILE* dosya;
	FILE* dosya2;


	char cumle[250];
	int menuSecim, sifrelenicekKarakter;
	printf("Lutfen islem turunu seciniz:\nSifrelemek icin ->1\nSifre Cozmek icin ->2\t");
	scanf_s("%d", &menuSecim);
	if (menuSecim == 1) {

		int rtn = fopen_s(&dosya, "giris.txt", "r");
		fopen_s(&dosya2, "sifreli.txt", "w");
		if (rtn != 0) {
			return 0;
		}
		printf("Kac karaktere gore sifrelenmesini istersiniz ?\t");
		scanf_s("%d", &sifrelenicekKarakter);
		while (fscanf_s(dosya, "%[^\n]", cumle, 250) != EOF)
		{

			sifrele(cumle, sifrelenicekKarakter);


			fprintf(dosya2, "%s", cumle);

		}
		fclose(dosya);
		fclose(dosya2);


	}
	else if (menuSecim == 2) {
		fopen_s(&dosya2, "sifreli.txt", "r");
		int rtn = fopen_s(&dosya, "cikis.txt", "w");
		if (rtn != 0) {
			return 0;
		}
		while (fscanf_s(dosya2, "%[^\n]", cumle, 250) != EOF)
		{
			printf("Kac karaktere gore cozulmesini istersiniz ? :");
			scanf_s("%d", &sifrelenicekKarakter);
			sifrecoz(cumle, sifrelenicekKarakter);


			fprintf(dosya, "%s", cumle);

		}
		fclose(dosya2);
		fclose(dosya);





	}
	else
	{
		printf("Hatali secim.");
	}

	return 0;
}