# Kelompok_7_UAS
## Sistem Informasi Pelacakan dan Pemesanan Pengiriman Paket

Sistem informasi berbasis Command Line Interface (CLI) untuk pemesanan dan pelacakan paket menggunakan bahasa C. Program ini dikembangkan sebagai bagian dari tugas Praktikum Struktur Data dan Algoritma di Universitas Syiah Kuala.

## Daftar Isi
- Latar Belakang
- Fitur Utama
- Struktur Data dan Algoritma
- Struktur Kode
- Cara Menggunakan
- Kompilasi Program
- Tim Pengembang

## Latar Belakang

Kebutuhan layanan pengiriman paket semakin meningkat seiring berkembangnya teknologi. Tidak semua sistem logistik tersedia dalam bentuk aplikasi sederhana yang dapat dijalankan secara lokal. Sistem ini dikembangkan sebagai prototipe berbasis CLI menggunakan bahasa pemrograman C dan diharapkan mampu menjadi media pembelajaran dalam penerapan struktur data dan algoritma pada proyek nyata.

## Fitur Utama

1. Pemesanan Paket
   - Input data pengirim dan penerima
   - Pemilihan provinsi asal dan tujuan
   - Otomatis menghasilkan kode pelacakan unik

2. Pelacakan Paket
   - Menggunakan kode pelacakan untuk melihat status pengiriman
   - Menampilkan detail paket dan status terkini

3. Panel Admin
   - Login dengan username dan password
   - Memperbarui status pengiriman paket
   - Melihat antrian paket yang perlu diupdate
   - Menampilkan daftar paket dengan berbagai opsi pengurutan

## Struktur Data dan Algoritma
Struktur Data:

1. Array
   - Digunakan untuk menyimpan data statis seperti daftar provinsi dan kode provinsi
   - Implementasi dalam `globals.c` untuk penyimpanan daftar provinsi Indonesia

2. Linked List
   - Digunakan untuk penyimpanan data paket secara dinamis
   - Memudahkan penambahan data paket baru tanpa perlu pengalokasian ulang memori
   - Implementasi dalam struktur `Paket` yang terhubung satu sama lain dengan pointer

3. Queue (Antrian)
   - Digunakan untuk mengelola antrian update status paket oleh admin
   - Implementasi dalam struktur `Queue` yang menampung paket yang perlu diupdate

Algoritma:

1. Linear Search
   - Digunakan dalam fungsi `cariPaket()` untuk mencari paket berdasarkan kode pelacakan
   - Kompleksitas waktu O(n) dimana n adalah jumlah paket

2. Quick Sort
   - Digunakan dalam fungsi `tampilkanPaketTerurut()` untuk mengurutkan paket
   - Implementasi dengan fungsi `qsort()` dari library C
   - Memiliki beberapa fungsi pembanding seperti `bandingkanPengirim()`, `bandingkanPenerima()`, dsb.

3. Random Generator
   - Digunakan dalam fungsi `buatKodePelacakan()` untuk menghasilkan kode pelacakan unik
   - Mengkombinasikan kode provinsi dengan angka acak

## Struktur Kode

Program terbagi menjadi beberapa file untuk memudahkan pengembangan dan pemeliharaan:

1. header.h
   - Berisi deklarasi semua struktur data, variabel global, dan prototype fungsi
   - Dilengkapi dengan header guard untuk mencegah multiple inclusion

2. globals.c
   - Mendefinisikan semua variabel global seperti head, updateQueue, statusList, daftarProvinsi, kodeProvinsi
   - Mencegah duplikasi simbol saat linking

3. main.c
   - Berisi fungsi utama yang menjalankan program
   - Memanggil menuUtama() untuk memulai aplikasi

4. menu.c
   - Menampilkan menu utama program
   - Implementasi fungsi menuUtama() dan tampilkanDaftarProvinsi()

5. admin.c
   - Implementasi fitur-fitur admin
   - Berisi fungsi loginAdmin() dan adminLogin()

6. paket.c
   - Berisi fungsi-fungsi untuk manajemen paket
   - Implementasi pembuatan, pencarian, dan tracking paket

7. kode.c
   - Implementasi pembuatan dan validasi kode pelacakan
   - Berisi fungsi isKodeUnik() dan buatKodePelacakan()

8. sorting.c
   - Berisi implementasi berbagai fungsi pengurutan
   - Termasuk fungsi-fungsi pembanding untuk qsort

## Cara Menggunakan

Menu Utama
Program menyediakan 4 menu utama:
1. Pesan Paket - Untuk melakukan pemesanan pengiriman baru
2. Lacak Paket - Untuk melacak status pengiriman menggunakan kode pelacakan
3. Login Admin - Untuk masuk ke panel admin
4. Keluar - Untuk mengakhiri program

Pemesanan Paket
1. Masukkan informasi pengirim (nama dan nomor telepon)
2. Masukkan informasi penerima (nama dan nomor telepon)
3. Pilih provinsi asal dan tujuan dari daftar yang tersedia
4. Masukkan alamat tujuan dan berat paket
5. Sistem akan menampilkan kode pelacakan yang dibuat secara otomatis

Pelacakan Paket
1. Masukkan kode pelacakan paket
2. Sistem akan menampilkan detail paket dan status pengiriman terkini

Panel Admin
1. Login dengan:
   - Username: admin
   - Password: admin123
2. Setelah berhasil login, admin dapat:
   - Melihat antrian update paket
   - Memperbarui status paket
   - Menampilkan daftar paket dengan berbagai opsi pengurutan

### Kompilasi Program

Program dapat dikompilasi menggunakan GCC dan Makefile yang telah disediakan:

### Kompilasi program
make

### Jalankan program
./sistem_paket

### Membersihkan file objek dan executable
make clean

## Tim Pengembang

Kelompok 7 Praktikum Struktur Data dan Algoritma:
- Abdan Syakura Bin Yasir (2408107010014)
- Dara Ramadhani (2408107010028)
- Muhammad Riyadh (2408107010015)
- Teuku Riefqi Zeta (2408107010071)
