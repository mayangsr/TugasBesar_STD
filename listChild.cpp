//double circular
#include "listChild.h"
#include <stdio.h>
#include <iomanip>

void createListChild(List_child &L){
    first_child(L)=NULL;
}

address_child createElmChild(int idBuku, string judulBuku, int tahun){
    address_child P;
    P = new elmlist_child;
    info_Child(P).idBuku = idBuku;
    info_Child(P).judulBuku = judulBuku;
    info_Child(P).tahun = tahun;
    next_Child(P) = NULL;
    prev_Child(P) = NULL;
    return P;
}

void insertFirstChild(List_child &L, address_child P){
    if (first_child(L)==NULL){
        first_child(L)=P;
        next_Child(first_child(L))=P;
        prev_Child(first_child(L))=P;
    }else{
        next_Child(P)=first_child(L);
        prev_Child(P)=prev_Child(first_child(L));
        next_Child(prev_Child(first_child(L)))=P;
        prev_Child(first_child(L))=P;
        first_child(L)=P;
    }
}

void insertLastChild(List_child &L, address_child P){
        next_Child(prev_Child(first_child(L)))=P;
        prev_Child(P)=prev_Child(first_child(L));
        next_Child(P)=first_child(L);
        prev_Child(first_child(L))=P;

}

void insertAfterChild(List_child &L, address_child Prec, address_child P){
        next_Child(P)=next_Child(Prec);
        prev_Child(P)=Prec;
        next_Child(Prec)=P;
        prev_Child(next_Child(P))=P;
}

void insertSortChild(List_child &L, address_child P){
    if(first_child(L) == NULL || info_Child(P).idBuku <= info_Child(first_child(L)).idBuku){
        insertFirstChild(L, P);
    }else if(info_Child(P).idBuku  >= info_Child(prev_Child(first_child(L))).idBuku ){
        insertLastChild(L, P);
    }else{
        address_child Q = first_child(L);
        while(info_Child(next_Child(Q)).idBuku  < info_Child(P).idBuku ){
            Q = next_Child(Q);
        }
        insertAfterChild(L, Q, P);
    }
}

void deleteFirstChild(List_child &L, address_child &P){
    P = first_child(L);
    if(first_child(L) == NULL){
        cout<<"List is empty"<<endl;
    }else if (next_Child(P)==first_child(L)){
        next_Child(P) = NULL;
        prev_Child(P) = NULL;
        first_child(L) = NULL;
    }else{
        first_child(L)=next_Child(P);
        next_Child(prev_Child(P))=first_child(L);
        prev_Child(first_child(L))=prev_Child(P);
        next_Child(P)=NULL;
        prev_Child(P)=NULL;
    }
}

void deleteLastChild(List_child &L, address_child &P){
    P = prev_Child(first_child(L));
        next_Child(prev_Child(P))=first_child(L);
        prev_Child(first_child(L))=prev_Child(P);
        next_Child(P)=NULL;
        prev_Child(P)=NULL;

}

void deleteAfterChild(List_child &L, address_child Prec, address_child &P){
    P=next_Child(Prec);
        next_Child(Prec)=next_Child(P);
        prev_Child(next_Child(P))=Prec;
        next_Child(P)=NULL;
        prev_Child(P)=NULL;

}

void deleteChild(List_child &L, address_child P){
    if(first_child(L) == NULL){
        cout<<"List is empty"<<endl;
    }else if(P == first_child(L)){
        deleteFirstChild(L, P);
    }else if(P == prev_Child(first_child(L))){
        deleteLastChild(L, P);
    }else{
        deleteAfterChild(L, prev_Child(P), P);
    }
    delete P;
}

void printInfoChild(List_child L){
    address_child P = first_child(L);
    if (P == NULL){
        cout<<"List Kosong \n";
    }else{
        cout<<"=================================================================="<<endl;
        cout<<"||                              DATA BUKU                       ||"<<endl;
        cout<<"=================================================================="<<endl;
        cout<<"||  ID Buku  ||"<<"             Judul Buku            ||"<<"Tahun Terbit||"<<endl;
        cout<<"==================================================================\n";
        do
        {
            cout<<"||"<<setiosflags(ios::left)<<setw(11)<<info_Child(P).idBuku<<"||"
                <<setiosflags(ios::left)<<setw(35)<<info_Child(P).judulBuku<<"||"
                <<setiosflags(ios::left)<<setw(12)<<info_Child(P).tahun<<"||"<<endl;

            P = next_Child(P);
        }while(P != first_child(L));
    }
        cout<<"=================================================================="<<endl;
}

address_child findElmChild(List_child &L, int id){
    address_child P = first_child(L);
    if(P != NULL){
        do{
            if (info_Child(P).idBuku == id){
                return P;
            }
            P=next_Child(P);
        }while (P!=first_child(L));
        return NULL;
    }else{
        return NULL;
    }
}

int totalBuku(List_child L){
    int i = 0;
    address_child P = first_child(L);
    if (P!=NULL){
        do{
            i++;
            P = next_Child(P);
        }while (P != first_child(L));
    }
    return i;
}
