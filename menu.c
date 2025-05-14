#include"header.h"

void menuUtama() {
    char pilihan[10];
    do {
        printf("\n===================================\n");
        printf("       SISTEM PELACAKAN PAKET CLI\n");
        printf("===================================\n");
        printf("Silakan pilih menu:\n");
        printf("1. Pesan Paket\n");
        printf("2. Lacak Paket\n");
        printf("3. Login sebagai Admin\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        fgets(pilihan, sizeof(pilihan), stdin);
        pilihan[strcspn(pilihan, "\n")] = '\0';

        if (strlen(pilihan) != 1 || pilihan[0] < '1' || pilihan[0] > '4') {
            printf("⚠️  Pilihan tidak valid! Silakan masukkan angka 1 - 4.\n");
            continue;
        }

        switch (pilihan[0]) {
            case '1': pesanPaket(); break;
            case '2': lacakPaket(); break;
            case '3': loginAdmin(); break;
            case '4':
                printf("\nTerima kasih telah menggunakan sistem pelacakan paket ini.\nSampai jumpa!\n");
                break;
        }
    } while (pilihan[0] != '4');
}

void tampilkanDaftarProvinsi() {
    printf("\n== Daftar Provinsi ==\n");
    for (int i = 0; i < MAX_PROVINSI; i++) {
        printf("%d. %s\n", i + 1, daftarProvinsi[i]);
    }
}
