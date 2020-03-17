#ifndef LISTCHILD_H_INCLUDED
#define LISTCHILD_H_INCLUDED
#include<iostream>
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define first(L) L.first

using namespace std;

struct infotype_child{
    int idBuku;
    string judulBuku;
    string kodeBuku;
    int tahun;
};

typedef struct elmlist_child *address_child;

struct elmlist_child {
    infotype_child info;
    address_child next;
    address_child prev;
};
struct List_child{
    address_child first;
};

void createList(List_child &L);
address_child createElmChild(int idBuku, string judulBuku, string kodeBuku, int tahun);
void insertFirst(List_child &L, address_child P);
void insertLast(List_child &L, address_child P);
void insertAfter(List_child &L, address_child Prec, address_child P);
void deleteFirst(List_child &L, address_child &P);
void deleteLast(List_child &L, address_child &P);
void deleteAfter(List_child &L, address_child Prec, address_child &P);
void printInfoChild(List_child L);
address_child findElmChild(List_child &L, string newJudul);

#endif // LISTCHILD_H_INCLUDED
