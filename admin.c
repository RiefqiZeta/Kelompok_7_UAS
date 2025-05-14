#include"header.h"

int adminLogin() {
    char user[20], pass[20];
    printf("\n=== LOGIN ADMIN ===\n");
    printf("Username : ");
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = '\0';

    printf("Password : ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0';

    return strcmp(user, "admin") == 0 && strcmp(pass, "admin123") == 0;
}

void loginAdmin() {
    if (!adminLogin()) {
        printf("⚠️  Login gagal!\n");
        return;
    }
    printf("✅ Login berhasil!\n");

    char pilihan[10]; // Buffer input aman
    do {
        printf("\n--- MENU ADMIN ---\n");
        printf("1. Lihat Antrian Update\n");
        printf("2. Update Status Paket\n");
        printf("3. Tampilkan Daftar Paket (Urutkan)\n");
        printf("4. Logout\n");
        printf("Pilih menu: ");
        
        fgets(pilihan, sizeof(pilihan), stdin);       // Baca input dengan aman
        pilihan[strcspn(pilihan, "\n")] = '\0';       // Hapus newline

        if (strlen(pilihan) != 1 || pilihan[0] < '1' || pilihan[0] > '4') {
            printf("⚠️  Pilihan tidak valid! Masukkan angka 1 - 4.\n");
            continue;
        }

        switch (pilihan[0]) {
            case '1': lihatAntrian(); break;
            case '2': updateStatus(); break;
            case '3': tampilkanPaketTerurut(); break;
            case '4': printf("Logout berhasil.\n"); break;
        }
    } while (pilihan[0] != '4');
}
