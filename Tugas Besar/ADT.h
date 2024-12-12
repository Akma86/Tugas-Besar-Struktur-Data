#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

// Alias untuk pointer pada node Stack
typedef struct Stack *address;

typedef struct MLL *addressmll;

// Struktur data untuk Stack node
struct Stack {
    string data;      // Data yang disimpan pada node
    address next;     // Pointer ke node berikutnya
    address prev;     // Pointer ke node sebelumnya
};

// Struktur untuk Double Linked List
struct List {
    address first;    // Pointer ke node pertama dalam list
    address last;     // Pointer ke node terakhir dalam list
};

struct MLL {
    addressmll next;
    addressmll prev;
    address history;
};

struct riwayat {
    addressmll first;
    addressmll last;
    int undocount;
};


// Membuat sebuah node baru dengan data 'x'
address createNode(string x);

// Mengambil node berdasarkan index (for target)
address getNodeByIndex(List &L, int index);

// Menginisialisasi list kosong dengan pointer pertama dan terakhir bernilai nullptr
void createList(List &L);

// Menambahkan node baru di akhir list
void insertLast(List &L, address p);

// Menambahkan node baru di awal list
void insertFirst(List &L, address p);

// Menyisipkan node baru setelah node dengan data 'prec'
void insertAfter(List &L, address p, string prec);

// Menghapus node terakhir dalam list dan menyimpan pointer node yang dihapus
void deleteLast(List &L, address &p);

// Menghapus node pertama dalam list dan menyimpan pointer node yang dihapus
void deleteFirst(List &L, address &p);

// Menghapus node setelah node dengan data 'prec' dan menyimpan pointer node yang dihapus
void deleteAfter(List &L, address &p, string prec);

// Menyalin data dari node yang mengandung substring 'pSub' ke node setelah substring 'qSub'
void copyPaste(List &L, const std::string &pSub, const std::string &qSub);

// Fitur undo dan redo yang terkait dengan operasi pada list
void undoRedo(List &L, List &V);

// Menghitung jumlah kata dalam setiap node dalam list
void wordCounter(List L);

// Mencetak seluruh informasi data dalam list
void printInfo(List L);

// Mencari substring 'cari' dalam list dan mengembalikan pointer ke node yang relevan
void searching(List L, address &p, const std::string &cari);

void createRiwayat(riwayat &r);
addressmll createMll(address x);
void addHistory(riwayat &r, List L);
void undo(riwayat &r, List &L);
void redo(riwayat &r, List &L);

#endif // ADT_H_INCLUDED
