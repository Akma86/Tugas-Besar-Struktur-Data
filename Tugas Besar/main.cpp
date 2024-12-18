#include <iostream>
#include "ADT.h"
using namespace std;

int main()
{
    List myList ;
    List secondList;
    createList(myList);
    createList(secondList);
    int pilihan;
    string input, cari;
    address p;
    bool kondisi = true;
    riwayat history;
    createRiwayat(history);
    while (kondisi){
        cout << "\n=====================================\n";
        cout << "               MENU                  \n";
        cout << "=====================================\n";
        cout << "  1. Penyisipan teks                \n";
        cout << "  2. Copy-paste                     \n";
        cout << "  3. Undo                           \n";
        cout << "  4. Redo                           \n";
        cout << "  5. Hapus teks                     \n";
        cout << "  6. Penghitung kata (Word Counter) \n";
        cout << "  7. Cetak teks                     \n";
        cout << "  8. Pencarian (Searching)          \n";
        cout << "  9. Keluar                         \n";
        cout << "=====================================\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;
        cin.ignore(); // Menghapus newline dari buffer

        if (pilihan == 1){
            string inputText;
            int posisi;
            cout << "Masukkan teks yang ingin disisipkan: ";
            getline(cin, inputText);
            cout << "Pilih posisi:\n1. Awal\n2. Akhir\nPilihan: ";
            cin >> posisi;
            cin.ignore(); // Clean buffer dari input

            address newNode = createNode(inputText);

            if (posisi == 1) {
                insertFirst(myList, newNode);
                cout << "Teks disisipkan di awal.\n";
            } else if (posisi == 2) {
                insertLast(myList, newNode);
                cout << "Teks disisipkan di akhir.\n";
            } else {
            cout << "Pilihan posisi invalid.\n";
                delete newNode; // Hapus node jika pilihan invalid
            }
            // Print data list setelah penyisipan
            cout << "Data dalam List setelah penyisipan:\n";
            printInfo(myList);
            addHistory(history, myList);

        }else if (pilihan == 2){
            int sumberIndex, tujuanIndex;
            cout << "Masukkan indeks node sumber untuk disalin: ";
            cin >> sumberIndex;
            cin.ignore();
            cout << "Masukkan indeks node tujuan untuk menyisipkan teks: ";
            cin >> tujuanIndex;
            cin.ignore();

            // Validasi indeks sumber dan tujuan
            address pSource = getNodeByIndex(myList, sumberIndex);
            address pTarget = getNodeByIndex(myList, tujuanIndex);

            if (pSource == nullptr) {
                cout << "Node sumber dengan indeks " << sumberIndex << " tidak ditemukan.\n";
            } else if (pTarget == nullptr) {
                cout << "Node tujuan dengan indeks " << tujuanIndex << " tidak ditemukan.\n";
            } else {
                // Panggil fungsi copyPaste
                copyPaste(myList, pSource->data, pTarget->data);
                addHistory(history, myList);
            }
        }else if (pilihan == 3){
            undo(history, myList);
            cout << "Berhasil undo!" << endl;
            cout << "Data list:\n";
            printInfo(myList);
        }else if (pilihan == 4){
            redo(history, myList);
            cout << "Berhasil redo!" << endl;
            cout << "Data list:\n";
            printInfo(myList);
        }else if (pilihan == 5){
            int posisi;
            address hapus;
            cout << "Masukkan posisi elemen yang ingin dihapus (mulai dari 1): ";
            cin >> posisi;
            if (posisi == 1) { // Jika posisi adalah elemen pertama
                deleteFirst(myList, hapus);
            } else if (posisi == countElements(myList)) { // Jika posisi adalah elemen terakhir
                deleteLast(myList, hapus);
            } else {
                deleteAt(myList,posisi,hapus);
                cout << "Input harus berupa angka. Silakan coba lagi.\n";
                deallocate(hapus);
                cin.clear(); // Res
            }
            addHistory(history, myList);
        }else if (pilihan == 6){
            wordCounter(myList);
        }else if (pilihan == 7){
            printInfo(myList);
        }else if (pilihan == 8){
            cout << "Masukan kata yang di cari : ";
            cin >> cari;
            searching(myList, p, cari);
        } else if (pilihan == 9){
            kondisi = false;
        } else {
            cout << "Pilihan tidak valid. Silakan pilih opsi yang tersedia.\n";
        }
    }
    return 0;
}
