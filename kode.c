#include"header.h"

int isKodeUnik(char kode[]) {
    Paket* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->kode, kode) == 0) {
            return 0; // Kode sudah ada
        }
        curr = curr->next;
    }
    return 1; // Kode unik
}

char* buatKodePelacakan(int asal, int tujuan) {
    static char kode[10]; // 9 karakter + null terminator
    int randomNum;
    srand(time(NULL));
    do {
        randomNum = rand() % 100000; // Angka acak 0-99999
        sprintf(kode, "%s%s%05d", kodeProvinsi[asal], kodeProvinsi[tujuan], randomNum);
    } while (!isKodeUnik(kode)); // Ulangi sampai kode unik
    return kode;
}
