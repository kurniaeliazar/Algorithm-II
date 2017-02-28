#include <stdio.h>
#include <string.h>

int main(){
    
	struct {
		char prodi[3];
		char nama[100];
		char nilai[3];
	}rekaman;

	FILE *arsipMatkul;
	FILE *arsipMatkulIF;
	FILE *arsipMatkulSI;

	arsipMatkul = fopen("ArsipMatKulA.dat", "r");
	arsipMatkulIF = fopen("ArsipMatKulIF.dat", "w");
	arsipMatkulSI = fopen("ArsipMatKulSI.dat", "w");

	printf("mulai proses pemisahan file\n");
	fscanf(arsipMatkul, "%s %s %s\n", &rekaman.prodi, &rekaman.nama, &rekaman.nilai);

	do{
		if(strcmp(rekaman.prodi,"IF") == 0){
		    fprintf(arsipMatkulIF, "%s %s %s\n", rekaman.prodi, rekaman.nama, rekaman.nilai);    
		}else{
		    fprintf(arsipMatkulSI, "%s %s %s\n", rekaman.prodi, rekaman.nama, rekaman.nilai);
		}
		fscanf(arsipMatkul, "%s %s %s\n", &rekaman.prodi, &rekaman.nama, &rekaman.nilai);
	}while(!feof(arsipMatkul));

	printf("Proses pemisahan file selesai\n");

	fclose(arsipMatkul);
	fclose(arsipMatkulIF);
	fclose(arsipMatkulSI);

    return 0;
}