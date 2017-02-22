#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){

 struct {
 	char maskapai[10]; 
 	int jumlah_penerbangan; 
 	char tujuan [50];
 }flight;

 FILE *Penerbangan;

 int sum, sum_all;
 char Separator[10] = "00";
 char current [10];
 Penerbangan = fopen("flight data separator.txt","rt");

 sum_all = 0;
 if (feof(Penerbangan)){
  	printf("File Kosong,proses konsolidasi dibatalkan...!!!\n");
 } else {
  	fscanf (Penerbangan, "%s %d %s", flight.maskapai, &flight.jumlah_penerbangan, flight.tujuan);
  	
  	do {
   		while(!feof(Penerbangan) && strcmp(flight.maskapai,Separator)==0) {
     		fscanf (Penerbangan, "%s %d %s", flight.maskapai, &flight.jumlah_penerbangan, flight.tujuan);
    	}

   		sum = 0;
   		strcpy(current, flight.maskapai);

   		while(!feof(Penerbangan) && strcmp(flight.maskapai,Separator)!=0) {
     		sum = sum + flight.jumlah_penerbangan;
     		fscanf (Penerbangan, "%s %d %s", flight.maskapai, &flight.jumlah_penerbangan, flight.tujuan);
    	}

   		printf("jumlah penerbangan maskapai %s: %d\n", current, sum);
   		sum_all = sum_all + sum;

    }while(!feof(Penerbangan));

    printf("Jumlah Seluruh Penerbangan : %d", sum_all);

 }
 
 fclose(Penerbangan);
 return 0;
}