#include "ADT.h"
address createNode(string x){
    address Node = new Stack;
    Node->data = x;
    Node->next = nullptr;
    return Node;
}

void createList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

void insertLast(List &L, address p){
        if (L.first == nullptr) {
        L.first = p;
        L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}
void insertFirst(List &L, address p){
    if (L.first == nullptr) {
        L.first = p;
        L.last = p;
        std::cout << "Node pertama berhasil ditambahkan.\n";
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
        std::cout << "Node berhasil ditambahkan di awal.\n";
    }
}
void insertAfter(List &L, address p, string prec){
    address temp = L.first;

    while (temp != nullptr && temp->data != prec) {
        temp = temp->next;
    }

    if (temp != nullptr) {
        p->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = p;
        }
        temp->next = p;
        p->prev = temp;

        if (temp == L.last) {
            L.last = p;
        }
    } else {
        cout << "Teks '" << prec << "' tidak ditemukan.\n";
    }
}
void deleteLast(List &L, address &p) {
    if (L.first->next == nullptr && L.last->prev == nullptr) {
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    }else {
        p = L.last;
        L.last = p->prev;
        L.last->next = nullptr;
        p->prev = nullptr;
    }
}

void deleteFirst(List &L, address &p) {
    if (L.first->next == nullptr && L.last->prev == nullptr) {
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    }else {
        p = L.first;
        L.first = p->next;
        L.first->prev = nullptr;
        p->next = nullptr;
    }
}

void deleteAfter(List &L, address &p, string prec) {
    address a;
    a = L.first;
    p = a->next;
    while (a->data != prec) {
        a = a->next;
        p = p->next;
    }
    a->next = p->next;
    (p->next)->prev = a;
    p->prev = nullptr;
    p->next = nullptr;


}

void copyPaste(List &L, const std::string &pSub, const std::string &qSub) {
    address pNode = nullptr;
    address qNode = nullptr;

    // Gunakan searching untuk menemukan node sumber dan tujuan
    searching(L, pNode, pSub);
    if (pNode == nullptr) {
        std::cout << "Substring sumber '" << pSub << "' tidak ditemukan.\n";
        return;
    }

    searching(L, qNode, qSub);
    if (qNode == nullptr) {
        std::cout << "Substring tujuan '" << qSub << "' tidak ditemukan.\n";
        return;
    }

    // Buat node baru dengan data dari node sumber
    address newNode = createNode(pNode->data);

    // Sisipkan node baru setelah node tujuan
    if (qNode->next == nullptr) {
        insertLast(L, newNode); // Jika tujuan adalah node terakhir
    } else {
        newNode->next = qNode->next;
        newNode->prev = qNode;
        qNode->next->prev = newNode;
        qNode->next = newNode;
    }

    std::cout << "Data '" << pNode->data << "' berhasil disalin setelah '" << qNode->data << "'.\n";
}


void undoRedo (List &L, List &V);
void wordCounter(List L) {
    address temp = L.first;
    while (temp != nullptr) {
        std::string text = temp->data;
        std::istringstream iss(text);
        std::string word;
        int wordCount = 0;

        while (iss >> word) {
            ++wordCount;
        }

        std::cout << "Jumlah kata: " << wordCount << "\n";

        temp = temp->next;
    }
}

void printInfo(List L) {
    if (L.first == nullptr) {
        std::cout << "List kosong.\n";
        return;
    }
    address temp = L.first;
    while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}


void searching(List L, address &p, const std::string &cari) {
    address temp = L.first;
    p = nullptr;

    while (temp != nullptr) {
        std::string text = temp->data;

        auto it = std::search(
            text.begin(), text.end(),
            cari.begin(), cari.end(),
            [](char a, char b) { return std::tolower(a) == std::tolower(b); }
        );

        if (it != text.end()) {
            std::cout << "Kata '" << cari << "' ditemukan di dalam teks: " << text << "\n";
            p = temp;
            return;
        }

        temp = temp->next;
    }

    std::cout << "Kata '" << cari << "' tidak ditemukan di dalam list.\n";
}
