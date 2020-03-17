#ifndef LISTPARENT_H_INCLUDED
#define LISTPARENT_H_INCLUDED
#include<iostream>
using namespace std;
#define next(P) P->next
#define info(P) P->info
#define first(L) L.first
#define last(L) L.last

struct infotype_parent{
    string NIM;
    string fakultas;
    string jurusan;
};

typedef struct elmlist_parent *address_parent;

struct elmlist_parent{
    infotype_parent info;
    address_parent next;
    address_parent prev;
};

struct List_parent{
    address_parent first;
    address_parent last;
};

void createList(List_parent &L);
address_parent createElmParent(string NIM, string fakultas, string jurusan);
bool isEmpty(List_parent L);
void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLast(List_parent &L, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);
void printInfoParent(List_parent L);
address_parent findElmParent(List_parent &L, string newNIM);


#endif // LISTPARENT_H_INCLUDED
