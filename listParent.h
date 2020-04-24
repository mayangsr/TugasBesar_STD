#ifndef LISTPARENT_H_INCLUDED
#define LISTPARENT_H_INCLUDED
#include<iostream>
using namespace std;
#define next_Parent(P) P->next_Parent
#define info_Parent(P) P->info_Parent
#define mahasiswa(P) P->mahasiswa
#define first_parent(L) L.first_parent
#define last_parent(L) L.last_parent

struct infotype_parent{
    int NIM;
    string jurusan;
    int angkatan;
};

typedef struct elmlist_parent *address_parent;

struct elmlist_parent{
    infotype_parent info_Parent;
    address_parent next_Parent;
    address_parent prev_parent;
};

struct List_parent{
    address_parent first_parent;
    address_parent last_parent;
};

void createListParent(List_parent &L);
address_parent createElmParent(int id, string jurusan, int year);
void insertFirstParent(List_parent &L, address_parent P);
void insertAfterParent(List_parent &L, address_parent Prec, address_parent P);
void insertLastParent(List_parent &L, address_parent P);
void insertSortParent(List_parent &L, address_parent P);
void deleteFirstParent(List_parent &L, address_parent &P);
void deleteLastParent(List_parent &L, address_parent &P);
void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P);
void deleteParent(List_parent &L, address_parent P);
void printInfoParent(List_parent L);
address_parent findElmParent(List_parent &L, int newID);
int totalMahasiswa(List_parent L);


#endif // LISTPARENT_H_INCLUDED
