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
        cout << "\nMenu:\n";
        cout << "1. Penyisipan teks\n";
        cout << "2. Copy-paste\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Delete teks\n";
        cout << "6. Word counter\n";
        cout << "7. Print teks\n";
        cout << "8. Searching\n";
        cout << "9. Selesai\n";
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
            string pSub, qSub;
            cout << "Masukkan teks yang ingin disalin: ";
            getline(cin, pSub);
            cout << "Masukkan teks tujuan: ";
            getline(cin, qSub);

            // Panggil fungsi copyPaste
            copyPaste(myList, pSub, qSub);
            addHistory(history, myList);
        }else if (pilihan == 3){
            undo(history, myList);
            cout << "Berhasil redo!" << endl;
            cout << "Data list:\n";
            printInfo(myList);
        }else if (pilihan == 4){

        }else if (pilihan == 5){

        }else if (pilihan == 6){

        }else if (pilihan == 7){
            printInfo(myList);
        }else if (pilihan == 8){

        } else if (pilihan == 9){
            kondisi = false;
        } else {
            cout << "Pilihan tidak valid. Silakan pilih opsi yang tersedia.\n";
        }
    }
    return 0;
}
