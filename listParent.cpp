#include "listParent.h"

void createList(List_parent &L){
    first(L)=NULL;
    last(L)=NULL;
}
address_parent createElmParent(string NIM, string fakultas, string jurusan){
    address_parent P;
    P = new elmlist_parent;
    info(P).NIM = NIM;
    info(P).fakultas = fakultas;
    info(P).jurusan = jurusan;
    next(P)=NULL;
    return P;
}
bool isEmpty(List_parent L){
    return first(L)==NULL;
}
void insertFirst(List_parent &L, address_parent P){
    if (isEmpty(L)){
        first(L)=P;
        last(L)=P;
    }else{
        next(P)=first(L);
        first(L)=P;
    }
}
void insertAfter(List_parent &L, address_parent Prec, address_parent P){
    P=first(L);
    if (isEmpty(L) || first(L)==last(L)){
        insertLast(L, P);
    }else {
        next(P)=next(Prec);
        next(Prec)=P;
    }
}
void insertLast(List_parent &L, address_parent P){
    if (isEmpty(L)){
        first(L)=NULL;
        last(L)=NULL;
    }else{
        next(last(L))=P;
        last(L)=P;
    }
}
void deleteFirst(List_parent &L, address_parent &P){
    P=first(L);
    if (first(L)==last(L)){
        first(L)=NULL;
        last(L)=NULL;
    }else{
        first(L)=next(P);
        next(P)=NULL;
    }
}
void deleteLast(List_parent &L, address_parent &P){
    P=last(L);
    if (first(L)==last(L)){
        first(L)=NULL;
        last(L)=NULL;
    }else{
        address_parent Q = first(L);
        while (next(Q)!=last(L)){
            Q=next(Q);
        }
        last(L)=Q;
        next(Q)=NULL;
    }
}
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P){
    if (P==first(L) || first(L)==last(L)){
        deleteFirst(L, P);
    }else {
        P=next(Prec);
        next(Prec)=next(P);
        next(P)=NULL;
    }
}
void printInfoParent(List_parent L){
    address_parent P = first(L);
    while (P!=last(L)){
        cout<<info(P).NIM<<" "<<info(P).fakultas<<" "<<info(P).jurusan<<endl;
        P=next(P);
    }
}
address_parent findElmParent(List_parent &L, string newNIM){
    address_parent P = first(L);
    while (P!=last(L) && info(P).NIM!=newNIM){
        P=next(P);
    }
    return P;
}
