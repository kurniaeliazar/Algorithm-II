#include <stdio.h>
#include <string.h>

int main() {

	struct {
		char npm[3];
		char nama[100];
		float ipk;
	}rekamanMaster, rekamanTrans ;


	FILE *fileMaster;
	FILE *fileTrans;
    FILE *fileNewMaster;

	fileMaster = fopen("FileMaster.dat", "r");
    fileTrans = fopen("FileTrans.dat", "r");
	fileNewMaster = fopen("FileNewMaster.dat", "w");

	fscanf(fileMaster, "%s %s %f\n", &rekamanMaster.npm, &rekamanMaster.nama, &rekamanMaster.ipk);
    fscanf(fileTrans, "%s %s %f\n", &rekamanTrans.npm, &rekamanTrans.nama, &rekamanTrans.ipk);

    printf("File master \n");
    do {
        printf("%s %s %f\n", rekamanMaster.npm, rekamanMaster.nama, rekamanMaster.ipk);
        printf("File Trans \n");
        do {
            printf("%s - %s - %d\n", rekamanMaster.npm, rekamanTrans.npm, strcmp(rekamanMaster.npm, rekamanTrans.npm));
            if(strcmp(rekamanMaster.npm, rekamanTrans.npm) > 0){
                printf("%s %s %f\n", rekamanTrans.npm, rekamanTrans.nama, rekamanTrans.ipk);
            }
            fscanf(fileTrans, "%s %s %f\n", &rekamanTrans.npm, &rekamanTrans.nama, &rekamanTrans.ipk);
        }while(!feof(fileTrans));
        // printf("%s %s %f\n", rekamanTrans.npm, rekamanTrans.nama, rekamanTrans.ipk);

        fscanf(fileMaster, "%s %s %f\n", &rekamanMaster.npm, &rekamanMaster.nama, &rekamanMaster.ipk);
    }while(!feof(fileMaster));
    //printf("%s %s %f\n", rekamanMaster.npm, rekamanMaster.nama, rekamanMaster.ipk);

    

	// do{
	//   if((strcmp(rekaman.prodi,"IF") == 0) && (strcmp(rekaman.nama,"ccc") == 0)){
	//   	strcpy(rekaman.nilai, "80");
	//   }

	//   fprintf(arsipMatkulUpdate, "%s %s %s\n", rekaman.prodi, rekaman.nama, 
	//   	rekaman.nilai);

	//   fscanf(arsipMatkul, "%s %s %s\n", &rekaman.prodi, 
	// 	&rekaman.nama, &rekaman.nilai);
	  
	// }while(!feof(arsipMatkul));

	fclose(fileMaster);
	fclose(fileTrans);
    fclose(fileNewMaster);
	     
	return 0;
}