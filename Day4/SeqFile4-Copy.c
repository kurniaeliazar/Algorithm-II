#include <stdio.h>
#include <string.h>

int main(){

	struct {
		char nim[10];
		char nama[100];
		char nilai[2];

	}rekaman;

	FILE *arsipMatkul1;
	FILE *arsipMatkul2;

	arsipMatkul1 = fopen("ArsipMatKul.dat", "r");
	arsipMatkul2 = fopen("ArsipMatKul-Copy.dat", "w");

	printf("Mulai proses menyalin file\n");
	fscanf(arsipMatkul1, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

	if(strcmp(rekaman.nim, "XXXXXXXX") == 0){
		fprintf(arsipMatkul2, "%s %s %s\n", "XXXXXXXX", "XXX", "X");
	}else{
		while(strcmp(rekaman.nim,"XXXXXXXX") !=0){
			fprintf(arsipMatkul2, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
			fscanf(arsipMatkul1, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
		}
		fprintf(arsipMatkul2, "%s %s %s\n", "XXXXXXXX", "XXX", "X");
	}

	printf("Proses menyalin selesai\n");
	fclose(arsipMatkul1);
	fclose(arsipMatkul2);

	return 0;
}