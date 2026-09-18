#include <iostream>

// Fungsi buatan sendiri untuk menghitung panjang array/kondisi
int main() {
    int n, k;
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> n;
    std::cout << "Masukkan nilai K awal: ";
    std::cin >> k;

    int astronot[1000];
    for (int i = 0; i < n; i++) {
        astronot[i] = i + 1;
    }

    int current_size = n;
    int pos = 0;

    std::cout << "Urutan Eliminasi:";
    while (current_size > 1) {
        // Menentukan posisi yang dieliminasi
        pos = (pos + k - 1) % current_size;
        int eliminasi = astronot[pos];

        std::cout << "Astronot " << eliminasi << " tereliminasi.";

        // Perbarui daftar astronot (geser elemen ke kiri)
        for (int i = pos; i < current_size - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        current_size--;

        // Update nilai K sesuai aturan
        if (eliminasi % 2 == 0) {
            k += 2;
        } else {
            k -= 1;
        }

        if (k < 2) {
            k = 2;
        }
    }

    std::cout << "Astronot terakhir yang bertahan: " << astronot[0] << std::endl;

    return 0;
}
