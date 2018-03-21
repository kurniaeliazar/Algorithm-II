#include <stdio.h>
#include <string.h>

int main() {

	struct {
		char npm[3];
		char nama[100];
		float ipk;
	}rekamanMaster, rekamanTrans;

    FILE *fileMaster;
    FILE *fileTrans;
    FILE *fileNewMaster;

    fileMaster = fopen("FileMaster.dat", "r");
    fileNewMaster = fopen("FileNewMaster.dat", "w");

    while(!feof(fileMaster)) {
        printf("File master \n");
        fscanf(fileMaster, "%s %s %f\n", &rekamanMaster.npm, &rekamanMaster.nama, &rekamanMaster.ipk);
        printf("%s %s %f\n", rekamanMaster.npm, rekamanMaster.nama, rekamanMaster.ipk);

        printf("File Trans \n");
        fileTrans = fopen("FileTrans.dat", "r");
        while(!feof(fileTrans)) {
            fscanf(fileTrans, "%s %s %f\n", &rekamanTrans.npm, &rekamanTrans.nama, &rekamanTrans.ipk);
            printf("%s %s %f\n", rekamanTrans.npm, rekamanTrans.nama, rekamanTrans.ipk);
            
            // put the logic to update ipk value here
            //
            //
            //
            //
            //
            //

        }

        fprintf(fileNewMaster, "%s %s %f\n", rekamanMaster.npm, rekamanMaster.nama, rekamanMaster.ipk);
        fclose(fileTrans);
    }

    fclose(fileMaster);
    fclose(fileNewMaster);
	     
	return 0;
}