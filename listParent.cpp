#include "listParent.h"
#include <stdio.h>
#include <iomanip>

void createListParent(List_parent &L){
//MAYANG SARI(1301194227)
    first_parent(L)=NULL;
    last_parent(L)=NULL;
}

address_parent createElmParent(int id, string jurusan, int year){
//MAYANG SARI (1301194227)
    address_parent P;
    P = new elmlist_parent;
    info_Parent(P).NIM = id;
    info_Parent(P).jurusan = jurusan;
    info_Parent(P).angkatan = year;
    next_Parent(P)=NULL;
    return P;
}

void insertFirstParent(List_parent &L, address_parent P){
//MAYANG SARI (1301194227)
    if(first_parent(L) == NULL){
        first_parent(L) = P;
        last_parent(L) = P;
    }else{
        next_Parent(P)=first_parent(L);
        first_parent(L)=P;
    }
 }

void insertAfterParent(List_parent &L, address_parent Prec, address_parent P){
//MAYANG SARI (1301194227)
    next_Parent(P)=next_Parent(Prec);
    next_Parent(Prec)=P;
}

void insertSortParent(List_parent &L, address_parent P){
//AZIZAH CAHYA KEMILA (1301194103)
    if(first_parent(L) == NULL || info_Parent(P).NIM <= info_Parent(first_parent(L)).NIM){
        insertFirstParent(L, P);
    }else if(info_Parent(P).NIM > info_Parent(last_parent(L)).NIM){
        insertLastParent(L, P);
    }else{
        address_parent Q = first_parent(L);
        while(info_Parent(next_Parent(Q)).NIM < info_Parent(P).NIM){
            Q = next_Parent(Q);
        }
        insertAfterParent(L, Q, P);
    }
}

void insertLastParent(List_parent &L, address_parent P){
//MAYANG SARI (1301194227)
        next_Parent(last_parent(L))=P;
        last_parent(L)=P;

}

void deleteFirstParent(List_parent &L, address_parent &P){
//MAYANG SARI (1301194227)
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
//MAYANG SARI (1301194227)
    P=last_parent(L);
        address_parent Q = first_parent(L);
        while (next_Parent(Q)!=last_parent(L)){
            Q=next_Parent(Q);
        }
        last_parent(L)=Q;
        next_Parent(Q)=NULL;

}

void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P){
//MAYANG SARI (1301194227)
        P=next_Parent(Prec);
        next_Parent(Prec)=next_Parent(P);
        next_Parent(P)=NULL;
}

void deleteParent(List_parent &L, address_parent P){
//MAYANG SARI (1301194227)
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
//AZIZAH CAHYA KEMILA (1301194103)
    address_parent P = first_parent(L);
    if (P==NULL){
        cout<<"List Kosong\n";
    }else{
        cout<<"=========================================================="<<endl;
        cout<<"||                    DATA MAHASISWA                    ||"<<endl;
        cout<<"=========================================================="<<endl;
        cout<<"||     NIM       ||"<<"          Jurusan          ||"<<"Angkatan||"<<endl;
        cout<<"==========================================================\n";
        while(P != NULL)
        {
            cout<<"||"<<setiosflags(ios::left)<<setw(15)<<info_Parent(P).NIM<<"||"
                <<setiosflags(ios::left)<<setw(27)<<info_Parent(P).jurusan<<"||"
                <<setiosflags(ios::left)<<setw(8)<<info_Parent(P).angkatan<<"||"<<endl;
            P = next_Parent(P);
        }
    }
        cout<<"=========================================================="<<endl;
}

address_parent findElmParent(List_parent &L, int ID){
//MAYANG SARI (1301194227)
    address_parent P = first_parent(L);
    while (P!=NULL && info_Parent(P).NIM!=ID){
        P=next_Parent(P);
    }
    return P;
}

int totalMahasiswa(List_parent L){
//MAYANG SARI (1301194227)
    address_parent P = first_parent(L);
    int i = 0;
    while (P!=NULL){
        i++;
        P = next_Parent(P);
    }
    return i;
}
