#include"header.h"

Paket* buatPaketBaru(char *pengirim, char*telepon_pengirim, char*penerima,
    char*telepon_penerima, int provinsi_asal, int provinsi_tujuan, char*alamat, char *berat) {
    Paket *p = (Paket *)malloc(sizeof(Paket));
    char* kode = buatKodePelacakan(provinsi_asal - 1, provinsi_tujuan - 1);
    strcpy(p->kode, kode);
    strcpy(p->pengirim, pengirim);
    strcpy(p->telepon_pengirim, telepon_pengirim);
    strcpy(p->penerima, penerima);
    strcpy(p->telepon_penerima, telepon_penerima);
    strcpy(p->provinsi_asal, daftarProvinsi[provinsi_asal - 1]);
    strcpy(p->provinsi_tujuan, daftarProvinsi[provinsi_tujuan - 1]);
    strcpy(p->alamat, alamat);
    strcpy(p->berat, berat);
    p->status = -1;
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

void pesanPaket() {
    char pengirim[50], telepon_pengirim[15], penerima[50], telepon_penerima[15], alamat[100], berat[5];
    int provinsi_asal, provinsi_tujuan;

    printf("\n=== PEMESANAN PAKET ===\n");
    tampilkanDaftarProvinsi();

    printf("Masukkan nama pengirim                      : ");
    fgets(pengirim, sizeof(pengirim), stdin);
    pengirim[strcspn(pengirim, "\n")] = '\0';
    if (strlen(pengirim) == 0) {
        printf("Nama pengirim tidak boleh kosong.\n");
        return;
    }

    printf("Masukkan nomor telepon pengirim             : ");
    fgets(telepon_pengirim, sizeof(telepon_pengirim), stdin);
    telepon_pengirim[strcspn(telepon_pengirim, "\n")] = '\0';
    if (strlen(telepon_pengirim) == 0) {
        printf("Nomor telepon pengirim tidak boleh kosong.\n");
        return;
    }

    printf("Masukkan nama penerima                      : ");
    fgets(penerima, sizeof(penerima), stdin);
    penerima[strcspn(penerima, "\n")] = '\0';
    if (strlen(penerima) == 0) {
        printf("Nama penerima tidak boleh kosong.\n");
        return;
    }

    printf("Masukkan nomor telepon penerima             : ");
    fgets(telepon_penerima, sizeof(telepon_penerima), stdin);
    telepon_penerima[strcspn(telepon_penerima, "\n")] = '\0';
    if (strlen(telepon_penerima) == 0) {
        printf("Nomor telepon penerima tidak boleh kosong.\n");
        return;
    }

    printf("Masukkan provinsi pengirim (kode provinsi)  : ");
    if (scanf("%d", &provinsi_asal) != 1 || provinsi_asal < 1 || provinsi_asal > MAX_PROVINSI) {
        printf("Kode provinsi pengirim tidak valid.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Masukkan provinsi penerima (kode provinsi)  : ");
    if (scanf("%d", &provinsi_tujuan) != 1 || provinsi_tujuan < 1 || provinsi_tujuan > MAX_PROVINSI) {
        printf("Kode provinsi penerima tidak valid.\n");
        while (getchar() != '\n');
        return;
    }

    getchar(); // Clear newline

    printf("Masukkan alamat tujuan                      : ");
    fgets(alamat, sizeof(alamat), stdin);
    alamat[strcspn(alamat, "\n")] = '\0';
    if (strlen(alamat) == 0) {
        printf("Alamat tujuan tidak boleh kosong.\n");
        return;
    }

    printf("Masukkan berat(Kg) paket                    : ");
    fgets(berat, sizeof(berat), stdin);
    berat[strcspn(berat, "\n")] = '\0';
    if (strlen(berat) == 0 || atof(berat) <= 0) {
        printf("Berat paket harus angka dan lebih dari 0.\n");
        return;
    }

    Paket *paket = buatPaketBaru(pengirim, telepon_pengirim, penerima, telepon_penerima,
        provinsi_asal, provinsi_tujuan, alamat, berat);
    tambahKeLinkedList(paket);
    tambahKeQueue(paket);

    printf("\nPaket berhasil dipesan!\nKode Pelacakan Anda: %s\n", paket->kode);
}

void lacakPaket() {
    char kode[20];
    printf("\n=== LACAK PAKET ===\n");
    printf("Masukkan Kode Pelacakan: ");
    fgets(kode, sizeof(kode), stdin);
    kode[strcspn(kode, "\n")] = '\0';
    if (strlen(kode) == 0) {
        printf("Kode pelacakan tidak boleh kosong.\n");
        return;
    }

    Paket *p = cariPaket(kode);
    if (p == NULL) {
        printf("Paket dengan kode '%s' tidak ditemukan.\n", kode);
        return;
    }

    printf("\n--- INFORMASI PAKET ---\n");
    printf("Kode Pelacakan    : %s\n", p->kode);
    printf("Pengirim          : %s\n", p->pengirim);
    printf("Telepon Pengirim  : %s\n", p->telepon_pengirim);
    printf("Penerima          : %s\n", p->penerima);
    printf("Telepon Penerima  : %s\n", p->telepon_penerima);
    printf("Asal              : %s\n", p->provinsi_asal);
    printf("Tujuan            : %s\n", p->provinsi_tujuan);
    printf("Alamat Tujuan     : %s\n", p->alamat);
    printf("Berat Paket       : %s Kg\n", p->berat);

    printf("\nStatus Paket:\n");
    if (p->status == -1) {
        printf("[ ] Belum dikirim oleh kurir\n");
    }
    for (int i = 0; i < 3; i++) {
        if (p->status >= i) {
            printf("[✅] %s\n", statusList[i]);
        } else {
            printf("[ ] %s\n", statusList[i]);
        }
    }
}

void updateStatus() {
    char kode[10];
    printf("Masukkan Kode Pelacakan: ");
    fgets(kode, sizeof(kode), stdin);
    
    // Hapus newline jika ada
    kode[strcspn(kode, "\n")] = '\0';

    // Bersihkan buffer jika input terpotong (melebihi 9 karakter)
    int len = strlen(kode);
    if (len == sizeof(kode) - 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

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
    if (!curr) {
        printf("Antrian kosong.\n");
        return;
    }
    while (curr != NULL) {
        Paket *p = curr->paket;
        printf("- %s | %s | %s ➝ %s | Status: ",
            p->kode, p->pengirim, p->provinsi_asal, p->provinsi_tujuan);
        if (p->status == -1)
            printf("Belum dikirim\n");
        else
            printf("%s\n", statusList[p->status]);
        curr = curr->next;
    }
}
