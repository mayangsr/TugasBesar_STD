#include "listChild.h"

void createList(List_child &L){
    first(L)=NULL;
}

address_child createElmChild(int idBuku, string judulBuku, string kodeBuku, int tahun){
    address_child P;
    P = new elmlist_child;
    info(P).idBuku = idBuku;
    info(P).judulBuku = judulBuku;
    info(P).kodeBuku = kodeBuku;
    info(P).tahun = tahun;
    next(P) = NULL;
    return P;
}
void insertFirst(List_child &L, address_child P){
    if (first(L)==NULL){
        first(L)=P;
        next(first(L))=P;
        prev(first(L))=P;
    }else{
        next(P)=first(L);
        prev(P)=first(L);
        next(prev(first(L)))=P;

        prev(first(L))=P;
        first(L)=P;
    }
}
void insertLast(List_child &L, address_child P){
    if (first(L)==NULL){
        insertFirst(L, P);
    }else{
        next(prev(first(L)))=P;
        prev(P)=prev(first(L));
        next(P)=first(L);
        prev(first(L))=P;
    }
}
void insertAfter(List_child &L, address_child Prec, address_child P){
    if (Prec==prev(first(L))){
        insertLast(L, P);
    }else{
        next(P)=next(Prec);
        prev(P)=Prec;
        next(Prec)=P;
        prev(next(P))=P;
    }
}
void deleteFirst(List_child &L, address_child &P){
    P=first(L);
    if (next(P)==first(L)){
        next(P)=NULL;
        prev(P)=NULL;
/*
    }else if (prev(first(L)==next(first(L)))){
        first(L)=next(P);
        next(first(L))=first(L);
        prev(first(L))=first(L);
        next(P)=NULL;
        prev(P)=NULL;
*/
/** ca itu yg aku matiin cek coba pake ga wwkwk, kalo make itu yg last ikut ke delete **/
    }else{
        first(L)=next(P);
        next(prev(P))=first(L);
        prev(first(L))=prev(P);
        next(P)=NULL;
        prev(P)=NULL;
    }
}
void deleteLast(List_child &L, address_child &P){
    P=prev(first(L));
    if (P==first(L)){
        deleteFirst(L, P);
    }else if (prev(first(L))==next(first(L))){
        next(first(L))=first(L);
        prev(first(L))=first(L);
        next(P)=NULL;
        prev(P)=NULL;
    }else{
        next(prev(P))=first(L);
        prev(first(L))=prev(P);
        next(P)=NULL;
        prev(P)=NULL;
    }
}
/** yg delete after jg pake list kan? **/
void deleteAfter(List_child &L, address_child Prec, address_child &P){
    P=next(Prec);
    if (P==first(L)){
        deleteFirst(L, P);
    }else if (P==prev(first(L))){
        deleteLast(L, P);
    }else{
        next(Prec)=next(P);
        prev(next(P))=Prec;
        next(P)=NULL;
        prev(P)=NULL;
    }
}
void printInfoChild(List_child L){
    address_child P = first(L);
    do{
        cout<<info(P).idBuku<<". "<<info(P).judulBuku<<" "<<info(P).kodeBuku<<" "<<info(P).tahun<<"."<<endl;
        P=next(P);
    }while(P!=first(L));
}
address_child findElmChild(List_child &L, string newKode){
    address_child P = first(L);
    do{
        if (info(P).kodeBuku == newKode){
            return P;
        }else{
            return NULL;
        }
        P=next(P);
    }while (P!=NULL || P!=first(L));
}
