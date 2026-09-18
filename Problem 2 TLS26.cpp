#include <iostream>

// Fungsi untuk menghitung panjang string
int PanjangString(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char pesan[1000];
    
    // Untuk menerima input pesan pengguna
    std::cout << "Masukkan pesan asli (Huruf KAPITAL): ";
    std::cin >> pesan;

    int len = PanjangString(pesan);
    int prev_shift = 0;

    std::cout << "Pesan ter-sandi: ";
    for (int i = 0; i < len; i++) {
        char current_char = pesan[i];
        
        // Memastikan hurufnya adalah huruf kapital dari A-Z
        if (current_char >= 'A' && current_char <= 'Z') {
            // Menentukan nilai huruf (A=1, B=2, ..., Z=26)
            int val = current_char - 'A' + 1;
            
            // Penghitungan 
            int new_val = (val - 1 + prev_shift) % 26 + 1;
            
            // Menukar nilai angka kembali ke aksara huruf
            char new_char = (char)('A' + new_val - 1);
            
            std::cout << new_char;
            
            // Simpan nilai huruf ASAL sebagai penanda anjakan huruf seterusnya
            prev_shift = val;
        } else {
            // Jika bukan A-Z (cth: simbol/nombor), cetak tanpa perubahan
            std::cout << current_char;
        }
    }
    std::cout << std::endl;

    return 0;
}
