#include <stdio.h>
#include <string.h>

int main(){
	struct {
		char nim[10];
		char nama[100];
		char nilai[2];
	}rekaman;

	FILE *arsipMatkul;

	arsipMatkul = fopen("ArsipMatKul.dat", "w");
	printf("Tuliskan rekaman satu per sat : \n");
	printf("masukan nim : \n ");
	scanf("%s", &rekaman.nim);

	while(strcmp(rekaman.nim, "XXXXXXXX") != 0){
		printf("masukan nama : \n");
		scanf("%s", &rekaman.nama);
		printf("masukan nilai : \n");
		scanf("%s", &rekaman.nilai);
		fprintf(arsipMatkul, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
		
		printf("masukan nim : \n ");
		scanf("%s", &rekaman.nim);
	}

	fprintf(arsipMatkul, "%s %s %s\n", "XXXXXXXX", "XXX", "X");
	fclose(arsipMatkul);
	return 0;
}