#include <stdio.h>
#include <string.h>

int main(){
	struct {
		char nim[10];
		char nama[100];
		char nilai[2];

	}rekaman;

	FILE *arsipMatkul = fopen("ArsipMatKul.dat", "r");
	printf("isi arsip beruntun adalah : \n");

	fscanf(arsipMatkul, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

	if(strcmp(rekaman.nim, "XXXXXXXX") == 0) printf("arsip kosong");
	else{
		do{
			printf("nim : %s\n", rekaman.nim);
			printf("nama : %s\n", rekaman.nama);
			printf("nilai : %s\n", rekaman.nilai);
			printf("---------------------\n");
			fscanf(arsipMatkul, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
		}while(strcmp(rekaman.nim,"XXXXXXXX") !=0);
	}

	fclose(arsipMatkul);
	return 0;
}