//Pembuatan header untuk listChild dikerjakan oleh MAYANG SARI(1301194227)

#ifndef LISTCHILD_H_INCLUDED
#define LISTCHILD_H_INCLUDED
#include<iostream>
#define next_Child(P) P->next_Child
#define prev_Child(P) P->prev_Child
#define info_Child(P) P->info_Child
#define buku(P) P->buku
#define first_child(L) L.first_child

using namespace std;

struct infotype_child{
    int idBuku;
    string judulBuku;
    int tahun;
};

typedef struct elmlist_child *address_child;

struct elmlist_child {
    infotype_child info_Child;
    address_child next_Child;
    address_child prev_Child;
};
struct List_child{
    address_child first_child;
};

void createListChild(List_child &L);
address_child createElmChild(int idBuku, string judulBuku, int tahun);
void insertFirstChild(List_child &L, address_child P);
void insertLastChild(List_child &L, address_child P);
void insertAfterChild(List_child &L, address_child Prec, address_child P);
void insertSortChild(List_child &L, address_child P);
void deleteFirstChild(List_child &L, address_child &P);
void deleteLastChild(List_child &L, address_child &P);
void deleteAfterChild(List_child &L, address_child Prec, address_child &P);
void deleteChild(List_child &L, address_child P);
void printInfoChild(List_child L);
address_child findElmChild(List_child &L, int id);
int totalBuku(List_child L);

#endif // LISTCHILD_H_INCLUDED
