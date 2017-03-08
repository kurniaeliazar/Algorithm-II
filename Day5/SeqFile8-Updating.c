#include <stdio.h>
#include <string.h>

int main() {

	struct {
		char prodi[3];
		char nama[100];
		char nilai[3];
	}rekaman;

	FILE *arsipMatkul;
	FILE *arsipMatkulUpdate;

	arsipMatkul = fopen("ArsipMatKulA.dat", "r");
	arsipMatkulUpdate = fopen("ArsipMatKulUpdate.dat", "w");

	// baca data pertama
	fscanf(arsipMatkul, "%s %s %s\n", &rekaman.prodi, 
		&rekaman.nama, &rekaman.nilai);

	// baca data 
	do{

	  //core logic 
	  //jika prodi if dan nama = "ccc"
	  if((strcmp(rekaman.prodi,"IF") == 0) && (strcmp(rekaman.nama,"ccc") == 0)){
	  	//ganti nilai jadi 80 
	  	strcpy(rekaman.nilai, "80");
	  }

	  //printf("%s %s %s\n", &rekaman.prodi, &rekaman.nama, &rekaman.nilai);

	  fprintf(arsipMatkulUpdate, "%s %s %s\n", rekaman.prodi, rekaman.nama, 
	  	rekaman.nilai);

	  	//baca data berikutnya
	  fscanf(arsipMatkul, "%s %s %s\n", &rekaman.prodi, 
		&rekaman.nama, &rekaman.nilai);
	  
	}while(!feof(arsipMatkul));

	fclose(arsipMatkul);
	fclose(arsipMatkulUpdate);
	     
	return 0;
}