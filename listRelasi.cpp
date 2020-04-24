//double
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "listRelasi.h"

using namespace std;

void createListRelasi(List_Relasi &L)
{
    first_relasi(L) = NULL;
    last_relasi(L) = NULL;
}

address_relasi createElmRelasi(address_parent Q, address_child R)
{
    address_relasi P;
    P = new elmList_relasi;
    mahasiswa(P) = Q;
    buku(P) = R;
    next_Relasi(P) = NULL;
    prev_Relasi(P) = NULL;

    return P;
}

void insertRelasi(List_Relasi &L, address_relasi R)
{
    if(first_relasi(L) == NULL)
    {
        first_relasi(L) = R;
        last_relasi(L) = R;
    }
    else
    {
        next_Relasi(R) = first_relasi(L);
        prev_Relasi(first_relasi(L)) = R;
        first_relasi(L) = R;
    }
}

void deleteFirstRelasi(List_Relasi &L, address_relasi P)
{
    P = first_relasi(L);
    mahasiswa(P) = NULL;
    buku(P) = NULL;
    if(first_relasi(L) == last_relasi(L))
    {
        first_relasi(L) = NULL;
        last_relasi(L) = NULL;
    }
    else
    {
        first_relasi(L) = next_Relasi(P);
        prev_Relasi(first_relasi(L)) = NULL;
        next_Relasi(P) = NULL;
    }
    delete P;
}

void deleteLastRelasi(List_Relasi &L, address_relasi P)
{
    P = last_relasi(L);
    mahasiswa(P) = NULL;
    buku(P) = NULL;
    if(first_relasi(L) == last_relasi(L))
    {
        first_relasi(L) = NULL;
        last_relasi(L) = NULL;
    }
    else
    {
        last_relasi(L) = prev_Relasi(P);
        next_Relasi(last_relasi(L)) = NULL;
        prev_Relasi(P) = NULL;
    }
}

void deleteAfterRelasi(List_Relasi &L, address_relasi Prec, address_relasi P)
{
    P = next_Relasi(Prec);
    mahasiswa(P) = NULL;
    buku(P) = NULL;
    if(P == last_relasi(L))
    {
        deleteLastRelasi(L, P);
    }
    else
    {
        next_Relasi(Prec) = next_Relasi(P);
        prev_Relasi(next_Relasi(P)) = Prec;
        prev_Relasi(P) = NULL;
        next_Relasi(P) = NULL;
    }
    delete P;
}

void printInfoRelasi(List_Relasi L)
{
    address_relasi P = first_relasi(L);
    if(first_relasi(L)==NULL)
    {
        cout<<"List Kosong"<<endl;
    }
    else
    {
        cout<<"=========================================================================================================================="<<endl;
        cout<<"||                                                         DATA PEMINJAMAN                                              ||"<<endl;
        cout<<"=========================================================================================================================="<<endl;
        cout<<"||     NIM       ||"<<"          Jurusan          ||"<<"Angkatan||"<<"  ID Buku  ||"<<"             Judul Buku            ||"<<"Tahun Terbit||"<<endl;
        cout<<"==========================================================================================================================\n";
        while(P != NULL)
        {
            cout<<"||"<<setiosflags(ios::left)<<setw(15)<<info_Parent(mahasiswa(P)).NIM<<"||"
                <<setiosflags(ios::left)<<setw(27)<<info_Parent(mahasiswa(P)).jurusan<<"||"
                <<setiosflags(ios::left)<<setw(8)<<info_Parent(mahasiswa(P)).angkatan<<"||"
                <<setiosflags(ios::left)<<setw(11)<<info_Child(buku(P)).idBuku<<"||"
                <<setiosflags(ios::left)<<setw(35)<<info_Child(buku(P)).judulBuku<<"||"
                <<setiosflags(ios::left)<<setw(12)<<info_Child(buku(P)).tahun<<"||"<<endl;

            P = next_Relasi(P);
        }
    cout<<"=========================================================================================================================="<<endl;
    }
}


address_relasi findElmRelasi(List_Relasi L, int nim, int idBuku)
{
    address_relasi P = first_relasi(L);
    while(P != NULL && (info_Parent(mahasiswa(P)).NIM != nim || info_Child(buku(P)).idBuku != idBuku))
    {
        P = next_Relasi(P);
    }
    return P;
}

address_relasi findElmRelasiParent(List_Relasi L,address_parent P)
{
    address_relasi Q = first_relasi(L);
    while(Q != NULL && mahasiswa(Q) != P)
    {
        Q = next_Relasi(Q);
    }
    return Q;
}

address_relasi findElmRelasiChild(List_Relasi L,address_child P)
{
    address_relasi Q = first_relasi(L);
    while(Q != NULL && buku(Q) != P)
    {
        Q = next_Relasi(Q);
    }
    return Q;
}


int totalPeminjaman(List_Relasi L)
{
    address_relasi P = first_relasi(L);
    int i = 0;
    while(P != NULL)
    {
        i = i + 1;
        P = next_Relasi(P);
    }
    return i;
}

