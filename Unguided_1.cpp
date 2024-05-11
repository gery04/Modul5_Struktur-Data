#include <iostream>
#include <list>

using namespace std;

// Struktur data untuk mahasiswa
struct Mahasiswa {
    int nim;
    int nilai;
};

// Ukuran tabel hash
const int TABLE_SIZE = 10;

// Class HashTable untuk tabel hash
class HashTable {
private:
    list<Mahasiswa> table[TABLE_SIZE]; // Array dari list untuk chaining

    // Fungsi hash sederhana
    int hashFunction(int nim) {
        return nim % TABLE_SIZE;
    }

public:
    // Menambahkan data mahasiswa ke tabel hash
    void insertData(int nim, int nilai) {
        int index = hashFunction(nim);
        Mahasiswa mhs = {nim, nilai};
        table[index].push_back(mhs);
    }

    // Menghapus data mahasiswa dari tabel hash berdasarkan NIM
    void deleteData(int nim) {
        int index = hashFunction(nim);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->nim == nim) {
                table[index].erase(it);
                cout << "Data mahasiswa dengan NIM " << nim << " telah dihapus.\n";
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
    }

    // Mencari data mahasiswa berdasarkan NIM
    void searchDataByNIM(int nim) {
        int index = hashFunction(nim);
        for (const auto& mhs : table[index]) {
            if (mhs.nim == nim) {
                cout << "Data mahasiswa dengan NIM " << nim << " ditemukan. Nilai: " << mhs.nilai << "\n";
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
    }

    // Mencari dan menampilkan data mahasiswa berdasarkan rentang nilai (80-90)
    void searchByScoreRange(int minScore, int maxScore) {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (const auto& mhs : table[i]) {
                if (mhs.nilai >= minScore && mhs.nilai <= maxScore) {
                    cout << "NIM: " << mhs.nim << ", Nilai: " << mhs.nilai << "\n";
                }
            }
        }
    }
};

// Fungsi main untuk penggunaan hash table
int main() {
    HashTable hashTable;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Cari Data Mahasiswa berdasarkan NIM\n";
        cout << "4. Cari Data Mahasiswa berdasarkan Rentang Nilai (80-90)\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int nim, nilai;
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                cout << "Masukkan Nilai Mahasiswa: ";
                cin >> nilai;
                hashTable.insertData(nim, nilai);
                break;
            }
            case 2: {
                int nim;
                cout << "Masukkan NIM Mahasiswa yang akan dihapus: ";
                cin >> nim;
                hashTable.deleteData(nim);
                break;
            }
            case 3: {
                int nim;
                cout << "Masukkan NIM Mahasiswa yang ingin dicari: ";
                cin >> nim;
                hashTable.searchDataByNIM(nim);
                break;
            }
            case 4: {
                cout << "Mahasiswa dengan nilai antara 80 dan 90:\n";
                hashTable.searchByScoreRange(80, 90);
                break;
            }
            case 0:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 0);

    return 0;
}
