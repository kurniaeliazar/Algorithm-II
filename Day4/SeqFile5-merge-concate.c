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
	FILE *arsipMatkul3;

	arsipMatkul1 = fopen("ArsipMatKul1.dat", "r");
	arsipMatkul2 = fopen("ArsipMatKul2.dat", "r");
	arsipMatkul3 = fopen("ArsipMatKul3.dat", "w");

	printf("mulai proses penggabungan file\n");

	fscanf(arsipMatkul1, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

	while(strcmp(rekaman.nim,"XXXXXXXX") !=0){
		fprintf(arsipMatkul3, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
		fscanf(arsipMatkul1, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
	}

	fscanf(arsipMatkul2, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

	while(strcmp(rekaman.nim,"XXXXXXXX") !=0){
		fprintf(arsipMatkul3, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
		fscanf(arsipMatkul2, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
	}

	fprintf(arsipMatkul3, "%s %s %s\n", "XXXXXXXX", "XXX", "X");
	printf("Proses penggabungan file selesai\n");

	fclose(arsipMatkul1);
	fclose(arsipMatkul2);
	fclose(arsipMatkul3);

}