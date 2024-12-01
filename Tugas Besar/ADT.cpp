#include "ADT.h"
address createNode(string x){
    address Node = new Stack;
    Node->data = x;
    Node->next = nullptr;
    return Node;
}
void insertLast(List &L, address p){

}
void insertFirst(List &L, address p);
void insertAfter(List &L, address p);
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
};
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
};
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


};
void copyPaste (List &L);
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
    address temp = L.first;
    while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

void searching(List L, address &p, std::string cari) {
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
