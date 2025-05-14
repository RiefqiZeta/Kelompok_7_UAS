#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PROVINSI 38
#define MAX_PAKET 100

typedef struct Paket {
    char kode[10];
    char pengirim[50];
    char telepon_pengirim[15];
    char penerima[50];
    char telepon_penerima[15];
    char provinsi_asal[20];
    char provinsi_tujuan[20];
    char alamat[100];
    char berat[5];
    int status; // 0: diterima, 1: dalam perjalanan, 2: sampai
    struct Paket *next;
} Paket;

typedef struct Queue {
    Paket *paket;
    struct Queue *next;
} Queue;

/* Declare global variables with extern */
extern Paket *head;
extern Queue *updateQueue;
extern char *statusList[];
extern const char* daftarProvinsi[];
extern const char* kodeProvinsi[];

/* Function prototypes */
int isKodeUnik(char kode[]);
char* buatKodePelacakan(int asal, int tujuan);
Paket* buatPaketBaru(char *pengirim, char*telepon_pengirim, char*penerima, char*telepon_penerima, int provinsi_asal, int provinsi_tujuan, char*alamat, char *berat);
void tambahKeLinkedList(Paket *p);
void tambahKeQueue(Paket *p);
Paket* cariPaket(char *kode);
void pesanPaket();
void lacakPaket();
void loginAdmin();
void tampilkanPaketTerurut();
void updateStatus();
void lihatAntrian();
int adminLogin();
void loginAdmin();
void tampilkanDaftarProvinsi();
void menuUtama();

#endif /* HEADER_H */
