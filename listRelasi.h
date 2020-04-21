#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED
#include <iostream>
#include "listChild.h"
#include "listParent.h"
#define next_Relasi(P) P->next_Relasi
#define prev_Relasi(P) P->prev_Relasi
#define first_relasi(L) L.first_relasi
#define last_relasi(L) L.last_relasi


using namespace std;
typedef struct elmList_relasi *address_relasi;
struct elmList_relasi{
    address_parent mahasiswa;
    address_child buku;
    address_relasi next_Relasi;
    address_relasi prev_Relasi;
};

struct List_Relasi{
    address_relasi first_relasi;
    address_relasi last_relasi;
};

void createListRelasi(List_Relasi &L);
address_relasi createElmRelasi(address_parent Q, address_child R);
void insertRelasi(List_Relasi &L, address_relasi R);
void deleteFirstRelasi(List_Relasi &L, address_relasi P);
void deleteLastRelasi(List_Relasi &L, address_relasi P);
void deleteAfterRelasi(List_Relasi &L, address_relasi Prec, address_relasi P);
void printInfoRelasi(List_Relasi L);
address_relasi findElmRelasi(List_Relasi L, int nim, int idBuku);
address_relasi findElmRelasiParent(List_Relasi ,address_parent P);
address_relasi findElmRelasiChild(List_Relasi L ,address_child P);
int totalPeminjaman(List_Relasi L);



#endif // LISTRELASI_H_INCLUDED
