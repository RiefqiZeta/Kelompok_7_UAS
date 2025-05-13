#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PROVINSI 34
#define MAX_PAKET 100

// ===== Struktur Data =====
typedef struct Paket {
    char kode[10];
    char pengirim[50];
    char alamat[100];
    char isi[100];
    int status; // 0: diterima, 1: dalam perjalanan, 2: sampai
    struct Paket *next;
} Paket;

typedef struct Queue {
    Paket *paket;
    struct Queue *next;
} Queue;

Paket *head = NULL;
Queue *updateQueue = NULL;
char *statusList[] = { "Diterima oleh kurir", "Dalam perjalanan", "Sampai di tujuan" };

// ===== Fungsi Utilitas =====
void generateKode(char *kode) {
    sprintf(kode, "PKT%04d", rand() % 10000);
}

Paket* buatPaketBaru(char *pengirim, char *alamat, char *isi) {
    Paket *p = (Paket *)malloc(sizeof(Paket));
    generateKode(p->kode);
    strcpy(p->pengirim, pengirim);
    strcpy(p->alamat, alamat);
    strcpy(p->isi, isi);
    p->status = 0;
    p->next = NULL;
    return p;
}

void tambahKeLinkedList(Paket *p) {
    if (head == NULL) {
        head = p;
    } else {
        Paket *curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = p;
    }
}

void tambahKeQueue(Paket *p) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->paket = p;
    q->next = NULL;

    if (updateQueue == NULL) {
        updateQueue = q;
    } else {
        Queue *temp = updateQueue;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = q;
    }
}

Paket* cariPaket(char *kode) {
    Paket *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->kode, kode) == 0)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

// ===== Menu dan Fungsi Utama =====
void pesanPaket() {
    char pengirim[50], alamat[100], isi[100];
    printf("\n=== PEMESANAN PAKET ===\n");
    printf("Masukkan nama pengirim   : "); gets(pengirim);
    printf("Masukkan alamat tujuan   : "); gets(alamat);
    printf("Masukkan isi paket       : "); gets(isi);

    Paket *paket = buatPaketBaru(pengirim, alamat, isi);
    tambahKeLinkedList(paket);
    tambahKeQueue(paket);

    printf("\nPaket berhasil dipesan!\nKode Pelacakan Anda: %s\n", paket->kode);
}

void lacakPaket() {
    char kode[10];
    printf("\n=== LACAK PAKET ===\n");
    printf("Masukkan Kode Pelacakan: "); gets(kode);
    Paket *p = cariPaket(kode);
    if (p == NULL) {
        printf("Paket tidak ditemukan.\n");
        return;
    }

    printf("\nStatus Paket:\n");
    for (int i = 0; i < 3; i++) {
        printf("[%c] %s\n", i <= p->status ? 0xFB : ' ', statusList[i]);
    }
}

void loginAdmin();

void menuUtama() {
    int pilihan;
    do {
        printf("\n===================================\n");
        printf("       SISTEM PELACAKAN PAKET CLI\n");
        printf("===================================\n");
        printf("Silakan pilih menu:\n");
        printf("1. Pesan Paket\n");
        printf("2. Lacak Paket\n");
        printf("3. Login sebagai Admin\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan Anda: "); scanf("%d", &pilihan); getchar();

        switch(pilihan) {
            case 1: pesanPaket(); break;
            case 2: lacakPaket(); break;
            case 3: loginAdmin(); break;
            case 4: printf("\nTerima kasih telah menggunakan sistem pelacakan paket ini.\nSampai jumpa!\n"); break;
            default: printf("Pilihan tidak valid!\n"); break;
        }
    } while(pilihan != 4);
}

// ===== Admin =====
int adminLogin() {
    char user[20], pass[20];
    printf("\n=== LOGIN ADMIN ===\n");
    printf("Username : "); gets(user);
    printf("Password : "); gets(pass);
    return strcmp(user, "admin") == 0 && strcmp(pass, "admin123") == 0;
}

void updateStatus() {
    char kode[10];
    printf("Masukkan Kode Pelacakan: "); gets(kode);
    Paket *p = cariPaket(kode);
    if (p == NULL) {
        printf("Paket tidak ditemukan.\n");
        return;
    }

    printf("Status saat ini  : %s\n", statusList[p->status]);
    if (p->status < 2) {
        p->status++;
        printf("Update ke status baru : %s\n", statusList[p->status]);
        printf("Status berhasil diperbarui!\n");
    } else {
        printf("Paket sudah sampai di tujuan.\n");
    }
}

void lihatAntrian() {
    printf("\n=== ANTRIAN UPDATE ===\n");
    Queue *curr = updateQueue;
    while (curr != NULL) {
        printf("- %s | %s | Status: %s\n", curr->paket->kode, curr->paket->pengirim, statusList[curr->paket->status]);
        curr = curr->next;
    }
}

void loginAdmin() {
    if (!adminLogin()) {
        printf("Login gagal!\n");
        return;
    }

    printf("Login berhasil!\n");
    int pilihan;
    do {
        printf("\n--- MENU ADMIN ---\n");
        printf("1. Lihat Antrian Update\n");
        printf("2. Update Status Paket\n");
        printf("3. Logout\n");
        printf("Pilih menu: "); scanf("%d", &pilihan); getchar();
        switch(pilihan) {
            case 1: lihatAntrian(); break;
            case 2: updateStatus(); break;
            case 3: printf("Logout berhasil.\n"); break;
            default: printf("Pilihan tidak valid.\n"); break;
        }
    } while (pilihan != 3);
}

// ===== Program Utama =====
int main() {
    srand(time(NULL));
    menuUtama();
    return 0;
}
