#include "ADT.h"

// Membuat node baru dengan data teks tertentu
address createNode(string x) {
    address newNode = new Node;  // Alokasi memori untuk node baru
    newNode->data = x;           // Menyimpan data teks pada node
    newNode->next = nullptr;     // Inisialisasi pointer next menjadi null
    return newNode;              // Mengembalikan alamat node yang dibuat
}

// Menginisialisasi list kosong
void createList(List &L) {
    L.first = nullptr;  // List awal kosong, tidak ada elemen pertama
    L.last = nullptr;   // List awal kosong, tidak ada elemen terakhir
}

address getNodeByIndex(List &L, int index) {
    address current = L.first;
    int count = 0;

    while (current != nullptr) {
        if (count == index) {
            return current;
        }
        current = current->next;
        count++;
    }
    return nullptr; // Jika indeks tidak valid
}


// Menambahkan elemen di akhir list
void insertLast(List &L, address p) {
    if (L.first == nullptr) {  // Jika list kosong
        L.first = p;           // Elemen pertama adalah elemen yang ditambahkan
        L.last = p;            // Elemen terakhir juga sama
    } else {                   // Jika list tidak kosong
        L.last->next = p;      // Node terakhir saat ini menunjuk ke node baru
        p->prev = L.last;      // Node baru menunjuk kembali ke node terakhir
        L.last = p;            // Perbarui node terakhir menjadi node baru
    }
}

// Menambahkan elemen di awal list
void insertFirst(List &L, address p) {
    if (L.first == nullptr) {  // Jika list kosong
        L.first = p;           // Elemen pertama adalah elemen yang ditambahkan
        L.last = p;            // Elemen terakhir juga sama
        std::cout << "Node pertama berhasil ditambahkan.\n";
    } else {                   // Jika list tidak kosong
        p->next = L.first;     // Node baru menunjuk ke elemen pertama saat ini
        L.first->prev = p;     // Elemen pertama saat ini menunjuk kembali ke node baru
        L.first = p;           // Perbarui elemen pertama menjadi node baru
        std::cout << "Node berhasil ditambahkan di awal.\n";
    }
}

// Menyisipkan elemen setelah node tertentu
void insertAfter(List &L, address p, string prec) {
    address temp = L.first;  // Mulai pencarian dari elemen pertama

    while (temp != nullptr && temp->data != prec) {  // Cari node dengan data prec
        temp = temp->next;
    }

    if (temp != nullptr) {  // Jika ditemukan
        p->next = temp->next;            // Node baru menunjuk ke node setelah node prec
        if (temp->next != nullptr) {     // Jika node setelahnya ada
            temp->next->prev = p;        // Update prev node setelahnya
        }
        temp->next = p;                  // Update next node prec ke node baru
        p->prev = temp;                  // Update prev node baru ke node prec

        if (temp == L.last) {            // Jika node prec adalah node terakhir
            L.last = p;                  // Perbarui node terakhir
        }
    } else {                             // Jika tidak ditemukan
        cout << "Teks '" << prec << "' tidak ditemukan.\n";
    }
}

// Menghapus elemen terakhir
void deleteLast(List &L, address &p) {
    if (L.first->next == nullptr && L.last->prev == nullptr) {  // Jika hanya ada satu elemen
        p = L.first;              // Ambil elemen tersebut
        L.first = nullptr;        // Kosongkan list
        L.last = nullptr;
    } else {                      // Jika lebih dari satu elemen
        p = L.last;               // Ambil elemen terakhir
        L.last = p->prev;         // Perbarui elemen terakhir menjadi elemen sebelumnya
        L.last->next = nullptr;   // Putuskan hubungan dengan elemen terakhir
        p->prev = nullptr;        // Putuskan hubungan elemen yang dihapus
    }
}

// Menghapus elemen pertama
void deleteFirst(List &L, address &p) {
    if (L.first->next == nullptr && L.last->prev == nullptr) {  // Jika hanya ada satu elemen
        p = L.first;              // Ambil elemen tersebut
        L.first = nullptr;        // Kosongkan list
        L.last = nullptr;
    } else {                      // Jika lebih dari satu elemen
        p = L.first;              // Ambil elemen pertama
        L.first = p->next;        // Perbarui elemen pertama menjadi elemen berikutnya
        L.first->prev = nullptr;  // Putuskan hubungan elemen sebelumnya
        p->next = nullptr;        // Putuskan hubungan elemen yang dihapus
    }
}


void deleteAt(List &L, int posisi, address &P) {
    if (posisi == 1) {
        deleteFirst(L, P);
    } else if (posisi == countElements(L)) {
        deleteLast(L, P);
    } else {
        int count = 1;
        address current = L.first;
        while (current != nullptr && count != posisi) {
            current = current->next;
            count++;
        }
        if (current != nullptr) {
            P = current;
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            P->next = nullptr;
            P->prev = nullptr;
        } else {
            cout << "Posisi tidak valid.\n";
        }
    }
}


int countElements(List L) {
    int count = 0;
    address P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

void deallocate(address &P) {
    delete P; // Membebaskan memori elemen P
    P = nullptr; // Menghindari dangling pointer
}


// Menghapus elemen setelah node tertentu
void deleteAfter(List &L, address &p, string prec) {
    address a = L.first;   // Mulai pencarian dari elemen pertama
    while (a->data != prec) {  // Cari node dengan data prec
        a = a->next;
    }
    p = a->next;           // Elemen yang akan dihapus adalah setelah node prec
    a->next = p->next;     // Node prec menunjuk ke elemen setelah node yang dihapus
    if (p->next != nullptr) {
        p->next->prev = a;  // Update prev elemen setelah node yang dihapus
    }
    p->prev = nullptr;     // Putuskan hubungan node yang dihapus
    p->next = nullptr;
}

// Menyalin data dari satu node ke node lain
void copyPaste(List &L, const std::string &pSub, const std::string &qSub) {
    address pNode = nullptr;
    address qNode = nullptr;

    // Cari node sumber dan tujuan
    searching(L, pNode, pSub);
    if (pNode == nullptr) {  // Jika node sumber tidak ditemukan
        std::cout << "Substring sumber '" << pSub << "' tidak ditemukan.\n";
        return;
    }

    searching(L, qNode, qSub);
    if (qNode == nullptr) {  // Jika node tujuan tidak ditemukan
        std::cout << "Substring tujuan '" << qSub << "' tidak ditemukan.\n";
        return;
    }

    // Gabungkan semua kata dari node sumber hingga akhir list menjadi satu kalimat
    std::string fullSentence;
    address temp = pNode;
    while (temp != nullptr) {
        if (!fullSentence.empty()) {
            fullSentence += " "; // Tambahkan spasi antar kata
        }
        fullSentence += temp->data;
        temp = temp->next;
    }

    // Buat node baru dengan data berupa kalimat lengkap
    address newNode = createNode(fullSentence);

    // Sisipkan node baru setelah node tujuan
    if (qNode->next == nullptr) {   // Jika tujuan adalah node terakhir
        insertLast(L, newNode);
    } else {
        newNode->next = qNode->next;
        newNode->prev = qNode;
        qNode->next->prev = newNode;
        qNode->next = newNode;
    }

    std::cout << "Kalimat '" << fullSentence << "' berhasil disalin setelah '" << qNode->data << "'.\n";
}

// Menghitung jumlah kata dalam teks pada setiap node
void wordCounter(List L) {
    address temp = L.first;
    while (temp != nullptr) {
        std::string text = temp->data;
        std::istringstream iss(text);
        std::string word;
        int wordCount = 0;

        while (iss >> word) {  // Hitung jumlah kata
            ++wordCount;
        }

        std::cout << "Jumlah kata: " << wordCount << "\n";
        temp = temp->next;  // Lanjutkan ke node berikutnya
    }
}

// Mencetak semua data dalam list
void printInfo(List L) {
    if (L.first == nullptr) {  // Jika list kosong
        std::cout << "List kosong.\n";
        return;
    }
    address temp = L.first;
    while (temp != nullptr) {  // Tampilkan semua data
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

// Mencari substring dalam list
void searching(List L, address &p, const std::string &cari) {
    address temp = L.first;
    p = nullptr;
    bool found = false;

    while (temp != nullptr) {
        std::string text = temp->data;

        auto it = std::search(
            text.begin(), text.end(),
            cari.begin(), cari.end(),
            [](char a, char b) { return std::tolower(a) == std::tolower(b); }
        );

        if (it != text.end()) {  // Jika ditemukan
            std::cout << "Kata '" << cari << "' ditemukan di dalam teks: " << text << "\n";
            if (p == nullptr){
                p = temp;
            }
            found = true;
        }
        temp = temp->next;  // Lanjutkan ke node berikutnya
    }
    if (!found){
        std::cout << "Kata '" << cari << "' tidak ditemukan di dalam list.\n";
    }
}


void createRiwayat(riwayat &r) {
    r.first = nullptr;
    r.last = nullptr;
    r.undocount = 0;
}

addressmll createMll(address x) {
    addressmll elementbaru = new MLL;
    elementbaru->next = nullptr;
    elementbaru->prev = nullptr;
    elementbaru->history = x;
    return elementbaru;
}


void addHistory(riwayat &r, List L) {
    List newlist;
    address newElement;
    address p = L.first;
    addressmll k;
    addressmll newMLL;

    createList(newlist);
    while (p != nullptr) {
        newElement = createNode(p->data);
        insertLast(newlist, newElement);
        p = p->next;
    }

    newMLL = createMll(newlist.first);
    if (r.undocount == 0) {
        if (r.first == nullptr) {
            r.first = newMLL;
            r.last = newMLL;
        } else {
            r.last->next = newMLL;
            newMLL->prev = r.last;
            r.last = newMLL;
        }
    } else {
        k = r.last;
        for (int i = 0; i < r.undocount; i++) {
            k = k->prev;
        }
        k->next = newMLL;
        newMLL->prev = k;
        r.last = newMLL;
    }
    r.undocount = 0;

}

void undo(riwayat &r, List &L) {
    L.first = nullptr;
    L.last = nullptr;
    addressmll p = r.last;
    address k;
    address newElementList;
    for (int i = 0; i < r.undocount; i++) {
        p = p->prev;
    }
    p = p->prev;
    k = p->history;
    while (k != nullptr) {
        newElementList = createNode(k->data);
        insertLast(L, newElementList);
        k = k->next;
    }
    r.undocount = r.undocount + 1;
}

void redo(riwayat &r, List &L) {
    // Pastikan bahwa operasi redo hanya dapat dilakukan jika undocount lebih besar dari 0
    if (r.undocount > 0) {
        // Reset list L ke keadaan yang akan di-"redo"
        L.first = nullptr;
        L.last = nullptr;

        addressmll p = r.last;
        address k;
        address newElementList;

        // Navigasi ke node yang sesuai dengan undocount
        for (int i = 0; i < r.undocount; i++) {
            p = p->prev;
        }
        p = p->next; // Bergerak maju untuk "redo"

        // Ambil history yang akan di-"redo"
        k = p->history;

        // Salin data dari node history ke list L
        while (k != nullptr) {
            newElementList = createNode(k->data);
            insertLast(L, newElementList);
            k = k->next;
        }

        // Kurangi undocount karena kita maju satu langkah dalam riwayat
        r.undocount = r.undocount - 1;
    } else {
        cout << "Tidak ada operasi yang dapat di-redo." << endl;
    }
}

