#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;
typedef struct Stack *address;

struct Stack{
    string data;
    address next;
    address prev;
};
struct List{
    address first;
    address last;
};

address createNode(string x);
void insertLast(List &L, address p);
void insertFirst(List &L, address p);
void insertAfter(List &L, address p);
void deleteLast(List &L, address &p);
void deleteFirst(List &L, address &p);
void deleteAfter(List &L, address &p, string prec);
void copyPaste (List &L);
void undoRedo (List &L, List &V);
void wordCounter (List L);
void printInfo (List L);
void searching (List L, address &p);


#endif // ADT_H_INCLUDED
