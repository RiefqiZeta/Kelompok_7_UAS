#include "header.h"

/* Define global variables */
Paket *head = NULL;
Queue *updateQueue = NULL;
char *statusList[] = { "Diterima oleh kurir", "Dalam perjalanan", "Sampai di tujuan" };

const char* daftarProvinsi[MAX_PROVINSI] = {
    "Aceh", "Sumatera Utara", "Sumatera Barat", "Riau", "Kepulauan Riau",
    "Jambi", "Sumatera Selatan", "Bengkulu", "Lampung", "Kepulauan Bangka Belitung",
    "Banten", "DKI Jakarta", "Jawa Barat", "Jawa Tengah", "DI Yogyakarta",
    "Jawa Timur", "Bali", "Nusa Tenggara Barat", "Nusa Tenggara Timur",
    "Kalimantan Barat", "Kalimantan Tengah", "Kalimantan Selatan",
    "Kalimantan Timur", "Kalimantan Utara", "Sulawesi Utara", "Sulawesi Tengah",
    "Sulawesi Selatan", "Sulawesi Tenggara", "Gorontalo", "Sulawesi Barat",
    "Maluku", "Maluku Utara", "Papua Barat", "Papua Barat Daya", "Papua",
    "Papua Selatan", "Papua Tengah", "Papua Pegunungan"
};

const char* kodeProvinsi[MAX_PROVINSI] = {
    "AC", "SU", "SB", "RI", "KR", "JA", "SS", "BE", "LA", "BB",
    "BT", "JK", "JB", "JT", "DY", "JI", "BA", "NB", "NT",
    "KB", "KT", "KS", "KI", "KU", "SN", "ST", "SL", "SG",
    "GO", "SW", "MA", "MU", "PB", "PD", "PA", "PS", "PT", "PP"
};
