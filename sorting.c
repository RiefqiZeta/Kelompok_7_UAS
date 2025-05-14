#include"header.h"

int bandingkanPengirim(const void *a, const void *b) {
    Paket *p1 = *(Paket **)a;
    Paket *p2 = *(Paket **)b;
    return strcmp(p1->pengirim, p2->pengirim);
}

int bandingkanPenerima(const void *a, const void *b) {
    Paket *p1 = *(Paket **)a;
    Paket *p2 = *(Paket **)b;
    return strcmp(p1->penerima, p2->penerima);
}

int bandingkanKode(const void *a, const void *b) {
    Paket *p1 = *(Paket **)a;
    Paket *p2 = *(Paket **)b;
    return strcmp(p1->kode, p2->kode);
}

int bandingkanAsal(const void *a, const void *b) {
    Paket *p1 = *(Paket **)a;
    Paket *p2 = *(Paket **)b;
    return strcmp(p1->provinsi_asal, p2->provinsi_asal);
}

int bandingkanTujuan(const void *a, const void *b) {
    Paket *p1 = *(Paket **)a;
    Paket *p2 = *(Paket **)b;
    return strcmp(p1->provinsi_tujuan, p2->provinsi_tujuan);
}

int bandingkanStatus(const void *a, const void *b) {
    Paket *p1 = *(Paket **)a;
    Paket *p2 = *(Paket **)b;
    return p1->status - p2->status;
}

void tampilkanPaketTerurut() {
    int count = 0;
    Paket *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    if (count == 0) {
        printf("Belum ada paket.\n");
        return;
    }

    Paket **array = malloc(sizeof(Paket *) * count);
    curr = head;
    for (int i = 0; i < count; i++) {
        array[i] = curr;
        curr = curr->next;
    }

    char pilihan[10];
    printf("\n== URUTKAN BERDASARKAN ==\n");
    printf("1. Nama Pengirim\n2. Nama Penerima\n3. Kode Pelacakan\n4. Provinsi Asal\n");
    printf("5. Provinsi Tujuan\n6. Status Pengiriman\nPilihan Anda: ");
    fgets(pilihan, sizeof(pilihan), stdin);
    pilihan[strcspn(pilihan, "\n")] = '\0';

    if (strlen(pilihan) != 1 || pilihan[0] < '1' || pilihan[0] > '6') {
        printf("⚠️  Pilihan tidak valid!\n");
        free(array);
        return;
    }

    switch (pilihan[0]) {
        case '1': qsort(array, count, sizeof(Paket *), bandingkanPengirim); break;
        case '2': qsort(array, count, sizeof(Paket *), bandingkanPenerima); break;
        case '3': qsort(array, count, sizeof(Paket *), bandingkanKode); break;
        case '4': qsort(array, count, sizeof(Paket *), bandingkanAsal); break;
        case '5': qsort(array, count, sizeof(Paket *), bandingkanTujuan); break;
        case '6': qsort(array, count, sizeof(Paket *), bandingkanStatus); break;
    }

    printf("\n=== DAFTAR PAKET TERURUT ===\n");
    for (int i = 0; i < count; i++) {
        Paket *p = array[i];
        printf("%s | %s -> %s | Status: %s\n",
               p->kode, p->provinsi_asal, p->provinsi_tujuan,
               p->status == -1 ? "Belum dikirim" : statusList[p->status]);
    }
    free(array);
}
