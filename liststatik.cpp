#include <stdio.h>
#include <string.h>

struct nilaiMatkul{
    char nim[10];
    char nama[50];
    char nilai[2];
};

struct elemen{
    nilaiMatkul elmt;
    int next;
};

struct list{
    int first;
    elemen data[10];
};

void createList(list *L){
    (*L).first = -1;
    int i;
    for(i=0;i<=10;i++){
        (*L).data[i].next = -2;
    }
}

int countElement(list L){
    int hasil = 0;
    if(L.first != -1){
        int elmt;
        elmt = L.first;
        
        while(elmt != -1){
            hasil = hasil + 1;
            elmt = L.data[elmt].next;
        }
    }
    return hasil;
}

int emptyElement(list L){
    int hasil = -1;
    if(countElement(L) < 10){
        bool ketemu = false;
        int i = 0;
        while((ketemu == false) && i<=10){
            if(L.data[i].next == -2){
                hasil = i;
                ketemu = true;
            }else{
                i = i + 1;
            }
        }
    }
    return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L){
    if(countElement(*L) < 10){
        int indeks = emptyElement(*L);
        strcpy((*L).data[indeks].elmt.nim, nim);
        strcpy((*L).data[indeks].elmt.nama, nama);
        strcpy((*L).data[indeks].elmt.nilai, nilai);
        
        if((*L).first == -1){
            (*L).data[indeks].next = -1;
        }else{
            (*L).data[indeks].next = (*L).data[(*L).first].next;
        }
        (*L).first = indeks;
    }else{
        printf("sudah tidak dapat ditambah");
    }
}

void addAfter(int prec, char nim[], char nama[], char nilai[], list *L){
    if(countElement(*L) < 10){
        int indeks = emptyElement(*L);
        strcpy((*L).data[indeks].elmt.nim, nim);
        strcpy((*L).data[indeks].elmt.nama, nama);
        strcpy((*L).data[indeks].elmt.nilai, nilai);
        (*L).data[indeks].next = (*L).data[prec].next;
        (*L).data[indeks].next = indeks;
    }else{
        printf("sudah tidak dapat ditambah");
    }
}

void addLast(char nim[], char nama[], char nilai[], list *L){
    if((*L).first == -1){
        int indeks = 0;
        strcpy((*L).data[indeks].elmt.nim, nim);
        strcpy((*L).data[indeks].elmt.nama, nama);
        strcpy((*L).data[indeks].elmt.nilai, nilai);
        (*L).data[indeks].next = -1;
        (*L).data[indeks].next = indeks;
    }else{
        if(countElement(*L) < 10){
            int indeks = emptyElement(*L);
            strcpy((*L).data[indeks].elmt.nim, nim);
            strcpy((*L).data[indeks].elmt.nama, nama);
            strcpy((*L).data[indeks].elmt.nilai, nilai);
            (*L).data[indeks].next = -1;
            int last = (*L).first;
            while((*L).data[last].next != -1){
                last = (*L).data[last].next;
            }
            (*L).data[last].next = indeks;
        }else{
            printf("sudah tidak dapat ditambah");
        }
    }    
}

void delFirst(list *L){
    if((*L).first != -1){
        int elmt = (*L).first;
        (*L).first = (*L).data[(*L).first].next;
        (*L).data[elmt].next = -2;
    }else{
        printf("list kosong\n");
    }
}

void delAfter(int prec, list *L){
    int elmt = (*L).data[prec].next;
    (*L).data[prec].next = (*L).data[elmt].next;
    (*L).data[elmt].next = -2;
}


void delLast(list *L){
    if((*L).first != -1){
        if(countElement(*L) == 1){
            delFirst(L);
        }else{
            int last = (*L).first;
            int beforeLast;
            while((*L).data[last].next != -1){
                beforeLast = last;
                last = (*L).data[last].next;
            }
            (*L).data[beforeLast].next = -1;
            (*L).data[last].next = -2;
        }
    }else{
        printf("list kosong\n");
    }
}

void printElement(list L){
    if(L.first != -1){
        int elmt = L.first;
        int i = 1;

        while(elmt != -1){
            printf("elemen ke : %d\n", elmt);
            printf("nim : %s\n", L.data[elmt].elmt.nim);
            printf("nama : %s\n", L.data[elmt].elmt.nama);
            printf("nilai : %s\n", L.data[elmt].elmt.nilai);
            printf("next : %d\n", L.data[elmt].next);
            printf("------------- \n");
            elmt = L.data[elmt].next;
            i = i + 1;
        }
    }else{
        printf("list kosong\n");
    }
}

void delAll(list *L){
    int i;
    for(i = countElement(*L);i>=1;i--){
        delLast(L);
    }
}

int main()
{
    struct list L;
    //emptyElement(L);
    createList(&L);
    printElement(L);
    printf("===================\n");
    addFirst("13501019","Andik","A", &L);
    addAfter(L.first, "13401020","Asep", "B", &L);
    addLast("13501020","Desi","A", &L);
    printElement(L);
    printf("=====================\n");
    // delLast(&L);
    // delAfter(L.first, &L);
    // delFirst(&L);
    // printElement(L);
    // printf("=====================\n");
    return 0;
}
