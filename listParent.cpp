//single
#include "listParent.h"

void createListParent(List_parent &L){
    first_parent(L)=NULL;
    last_parent(L)=NULL;
}

address_parent createElmParent(int id, string jurusan, int year){
    address_parent P;
    P = new elmlist_parent;
    info_Parent(P).NIM = id;
    info_Parent(P).jurusan = jurusan;
    info_Parent(P).angkatan = year;
    next_Parent(P)=NULL;
    return P;
}

bool isEmptyParent(List_parent L){
    return first_parent(L)==NULL;
}

void insertFirstParent(List_parent &L, address_parent P){
    if (isEmptyParent(L)){
        first_parent(L)=P;
        last_parent(L)=P;
    }else{
        next_Parent(P)=first_parent(L);
        first_parent(L)=P;
    }
}

void insertAfterParent(List_parent &L, address_parent Prec, address_parent P){
    P=first_parent(L);
    if (isEmptyParent(L) || Prec == last_parent(L)){
        insertLastParent(L, P);
    }else {
        next_Parent(P)=next_Parent(Prec);
        next_Parent(Prec)=P;
    }
}

void insertSortParent(List_parent &L, address_parent P){
    if(first_parent(L) == NULL || info_Parent(P).NIM <= info_Parent(first_parent(L)).NIM){
        insertFirstParent(L, P);
    }else if(info_Parent(P).NIM >= info_Parent(last_parent(L)).NIM){
        insertLastParent(L, P);
    }else{
        address_parent Q = first_parent(L);
        while(info_Parent(Q).NIM > info_Parent(P).NIM){
            Q = next_Parent(Q);
        }
        insertAfterParent(L, Q, P);
    }
}

void insertLastParent(List_parent &L, address_parent P){
    if (isEmptyParent(L)){
        first_parent(L)=NULL;
        last_parent(L)=NULL;
    }else{
        next_Parent(last_parent(L))=P;
        last_parent(L)=P;
    }
}

void deleteFirstParent(List_parent &L, address_parent &P){
    P=first_parent(L);
    if (first_parent(L)==last_parent(L)){
        first_parent(L)=NULL;
        last_parent(L)=NULL;
    }else{
        first_parent(L)=next_Parent(P);
        next_Parent(P)=NULL;
    }
}

void deleteLastParent(List_parent &L, address_parent &P){
    P=last_parent(L);
        address_parent Q = first_parent(L);
        while (next_Parent(Q)!=last_parent(L)){
            Q=next_Parent(Q);
        }
        last_parent(L)=Q;
        next_Parent(Q)=NULL;

}

void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P){
        P=next_Parent(Prec);
        next_Parent(Prec)=next_Parent(P);
        next_Parent(P)=NULL;
}

void deleteParent(List_parent &L, address_parent P){
    if(P == first_parent(L)){
        deleteFirstParent(L, P);
    }else if(P == last_parent(L)){
        deleteLastParent(L, P);
    }else{
        address_parent Q =first_parent(L);
        while(next_Parent(Q) != P){
            Q = next_Parent(Q);
        }
        deleteAfterParent(L, Q, P);
    }
    delete P;
}

void printInfoParent(List_parent L){
    address_parent P = first_parent(L);
    while (P!=NULL){
        cout<<"NIM : "<<info_Parent(P).NIM<<endl;
        cout<<"Jurusan : "<<info_Parent(P).jurusan<<endl;
        cout<<"Angkatan : "<<info_Parent(P).angkatan<<endl;
        cout<<endl;
        P=next_Parent(P);
    }
    cout<<endl;
}

address_parent findElmParent(List_parent &L, int ID){
    address_parent P = first_parent(L);
    while (P!=NULL && info_Parent(P).NIM!=ID){
        P=next_Parent(P);
    }
    return P;
}
