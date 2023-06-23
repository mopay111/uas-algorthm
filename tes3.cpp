#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Produk {
    string nama;
    int harga;
    string kode;
};

void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void tambahProduk(Produk dataProduk[], int& jumlahProduk) {
    int jumlahBarang;
    cout << "Masukkan jumlah barang yang ingin ditambahkan: ";
    cin >> jumlahBarang;
    cin.ignore();

    for (int i = 0; i < jumlahBarang; i++) {
        Produk barang;

        cout << "Masukkan nama produk: ";
        getline(cin, barang.nama);

        cout << "Masukkan harga produk: ";
        cin >> barang.harga;

        cin.ignore(); // Membersihkan karakter newline sebelum mengambil input kode barang

        cout << "Masukkan kode barang baru: ";
        getline(cin, barang.kode);

        dataProduk[jumlahProduk] = barang;
        jumlahProduk++;
    }

    setColor(10); // Mengatur warna teks menjadi hijau
    cout << "Produk baru berhasil ditambahkan!" << endl;
    setColor(7); // Mengembalikan warna teks ke warna default
}

void tampilkanProduk(Produk dataProduk[], int jumlahProduk) {
    cout << "Daftar Produk: " << endl;

    // Kolom headers
    gotoXY(0, 2);
    setColor(11); // Mengatur warna teks menjadi biru
    cout << "No";
    gotoXY(10, 2);
    cout << "Nama";
    gotoXY(30, 2);
    cout << "Harga";
    setColor(7); // Mengembalikan warna teks ke warna default

    // Kolom data produk
    for (int i = 0; i < jumlahProduk; i++) {
        gotoXY(0, i + 4);
        cout << i + 1; // Nomor urut
        gotoXY(10, i + 4);
        cout << dataProduk[i].nama;
        gotoXY(30, i + 4);
        cout << dataProduk[i].harga;
    }
}

bool compareProduk(const Produk& a, const Produk& b) {
    return a.harga < b.harga;
}

void sortProduk(Produk dataProduk[], int jumlahProduk) {
    sort(dataProduk, dataProduk + jumlahProduk, compareProduk);

    setColor(10); // Mengatur warna teks menjadi hijau
    cout << "Produk baru berhasil diurutkan berdasarkan harga!" << endl;
    setColor(7); // Mengembalikan warna teks ke warna default
}

int main() {
    const int MAX_PRODUK = 100;
    Produk dataProduk[MAX_PRODUK];
    int jumlahProduk = 0;
    int pilihan;
    string nama_barang;
    string kode_barang;
    int harga_barang;
    string nama, kelas;
    int nim;

    cout << "Masukkan NIM\t: ";
    cin >> nim;
    cin.ignore();
    cout << "Masukkan Nama\t: ";
    getline(cin, nama);
    cout << "Masukkan Kelas\t: ";
    getline(cin, kelas);

    system("cls"); // Membersihkan layar
    setColor(14); // Mengatur warna teks menjadi kuning
    cout << "=======================[ PROGRAM KASIR SWALAYAN ]======================\n";
    setColor(15); // Mengembalikan warna teks ke warna default
    cout << "|          NIM        |          NAMA            |        KELAS      |\n";
    cout << "=======================================================================\n";
    setColor(12); // Mengatur warna teks menjadi merah
    cout << "|      " << nim << "     |         " << nama << "   |      " << kelas << "  |\n";
    cout << "=======================================================================\n\n";
    setColor(7); // Mengembalikan warna teks ke warna default

    do {
        setColor(9); // Mengatur warna teks menjadi biru muda
        cout << "=== Program Kasir Swalayan ===" << endl;
        setColor(7); // Mengembalikan warna teks ke warna default
        cout << "1. Tambah Produk Baru" << endl;
        cout << "2. Tampilkan Produk Baru" << endl;
        cout << "3. Urutkan Produk Baru Berdasarkan Harga" << endl;
        cout << "4. Keluar Program" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahProduk(dataProduk, jumlahProduk);
            break;
        case 2:
            system("cls"); // Membersihkan layar
            tampilkanProduk(dataProduk, jumlahProduk);
            break;
        case 3:
            sortProduk(dataProduk, jumlahProduk);
            system("cls"); // Membersihkan layar
            setColor(10); // Mengatur warna teks menjadi hijau
            cout << "Produk Baru berhasil diurutkan berdasarkan harga!" << endl;
            setColor(7); // Mengembalikan warna teks ke warna default
            tampilkanProduk(dataProduk, jumlahProduk); // Tampilkan daftar produk setelah diurutkan
            break;
        case 4:
            setColor(14); // Mengatur warna teks menjadi kuning
            cout << "Terima kasih telah menggunakan program ini :)" << endl;
            setColor(7); // Mengembalikan warna teks ke warna default
            break;
        default:
            setColor(12); // Mengatur warna teks menjadi merah
            cout << "Pilihan tidak valid!" << endl;
            setColor(7); // Mengembalikan warna teks ke warna default
            break;
        }

        cout << endl;
    } while (pilihan != 4);

    return 0;
}

