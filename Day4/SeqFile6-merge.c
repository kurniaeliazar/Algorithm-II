#include <stdio.h>
#include <string.h>

int main(){

	struct {
		char nim[10];
		char nama[100];
		char nilai[2];

	}rekaman1, rekaman2;

	FILE *arsipMatkul1;
	FILE *arsipMatkul2;
	FILE *arsipMatkul3;

	arsipMatkul1 = fopen("ArsipMatKul1.dat", "r");
	arsipMatkul2 = fopen("ArsipMatKul2.dat", "r");
	arsipMatkul3 = fopen("ArsipMatKul3-Terurut.dat", "w");

	printf("mulai proses penggabungan file\n");
	fscanf(arsipMatkul1, "%s %s %s\n", &rekaman1.nim, &rekaman1.nama, &rekaman1.nilai);
	fscanf(arsipMatkul2, "%s %s %s\n", &rekaman2.nim, &rekaman2.nama, &rekaman2.nilai);

	while((strcmp(rekaman1.nim,"XXXXXXXX") !=0) && (strcmp(rekaman2.nim,"XXXXXXXX") !=0)) {
		if(strcmp(rekaman1.nim,rekaman2.nim) < 1){
			fprintf(arsipMatkul3, "%s %s %s\n", rekaman1.nim, rekaman1.nama, rekaman1.nilai);
			fscanf(arsipMatkul1, "%s %s %s\n", &rekaman1.nim, &rekaman1.nama, &rekaman1.nilai);
		}else{
			fprintf(arsipMatkul3, "%s %s %s\n", rekaman2.nim, rekaman2.nama, rekaman2.nilai);
			fscanf(arsipMatkul2, "%s %s %s\n", &rekaman2.nim, &rekaman2.nama, &rekaman2.nilai);
		}
	}

	while(strcmp(rekaman1.nim,"XXXXXXXX") !=0){
		fprintf(arsipMatkul3, "%s %s %s\n", rekaman1.nim, rekaman1.nama, rekaman1.nilai);
		fscanf(arsipMatkul1, "%s %s %s\n", &rekaman1.nim, &rekaman1.nama, &rekaman1.nilai);
	}

	while(strcmp(rekaman2.nim,"XXXXXXXX") !=0){
		fprintf(arsipMatkul3, "%s %s %s\n", rekaman2.nim, rekaman2.nama, rekaman2.nilai);
		fscanf(arsipMatkul2, "%s %s %s\n", &rekaman2.nim, &rekaman2.nama, &rekaman2.nilai);
	}

	fprintf(arsipMatkul3, "%s %s %s\n", "XXXXXXXX", "XXX", "X");
	printf("Proses penggabungan file selesai\n");

	fclose(arsipMatkul1);
	fclose(arsipMatkul2);
	fclose(arsipMatkul3);

  	return 0;
}