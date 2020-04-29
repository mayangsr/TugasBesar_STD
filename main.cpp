#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "listChild.h"
#include "listParent.h"
#include "listRelasi.h"

using namespace std;

int main()
{
    //AZIZAH CAHYA KEMILA(1301194103)
    int pilih;
    List_parent L1;
    createListParent(L1);
    List_child L2;
    createListChild(L2);
    List_Relasi L3;
    createListRelasi(L3);
    while(pilih != 0)
    {
        cout<<"=======================MENU========================="<<endl
            <<"|| 1.  Masukkan Data Mahasiswa                    ||"<<endl
            <<"|| 2.  Masukkan Data Buku                         ||"<<endl
            <<"|| 3.  Tampilkan List Mahasiswa                   ||"<<endl
            <<"|| 4.  Tampilkan List Buku                        ||"<<endl
            <<"|| 5.  Peminjaman                                 ||"<<endl
            <<"|| 6.  Pengembalian                               ||"<<endl
            <<"|| 7.  Tampilkan Semua Peminjaman                 ||"<<endl
            <<"|| 8.  Cari Data Peminjam dengan ID mahasiswa/buku||"<<endl
            <<"|| 9.  Hapus Data Mahasiswa                       ||"<<endl
            <<"|| 10. Hapus Data Buku                            ||"<<endl
            <<"|| 11. Total buku                                 ||"<<endl
            <<"|| 12. Total Mahasiswa                            ||"<<endl
            <<"|| 13. Total Peminjaman                           ||"<<endl
            <<"|| 0. exit                                        ||"<<endl
            <<"===================================================="<<endl;
        cout<<"Choose Menu : ";
        cin>>pilih;
        switch(pilih)
        {
            case 1:
            {
                int id, year;
                string jurusan;
                cout<<"=================INPUT DATA MAHASISWA==============="<<endl;
                cout<<" NIM      : ";
                cin>>id;
                address_parent Q = findElmParent(L1, id);
                while(Q != NULL)
                {
                    cout<<" NIM telah digunakan"<<endl;
                    cout<<" NIM      : ";
                    cin>>id;
                    Q = findElmParent(L1, id);
                }
                cout<<" Jurusan  : ";
                cin.get();
                getline(cin, jurusan);
                cout<<" Angkatan : ";
                cin>>year;
                address_parent P = createElmParent(id, jurusan, year);
                insertSortParent(L1, P);
                cout<<"============DATA MAHASISWA TELAH DIINPUT============"<<endl;
                break;
            }
            case 2:
            {
                int idBuku, tahunBuku;
                string judul;
                cout<<"=================INPUT DATA BUKU===================="<<endl;
                cout<<" ID Buku      : ";
                cin>>idBuku;
                address_child Q = findElmChild(L2, idBuku);
                while(Q != NULL)
                {
                    cout<<" ID telah digunakan"<<endl;
                    cout<<" ID Buku      : ";
                    cin>>idBuku;
                    Q = findElmChild(L2, idBuku);
                }
                cout<<" Judul Buku   : ";
                cin.get();
                getline(cin,judul);
                cout<<" Tahun Terbit : ";
                cin>>tahunBuku;
                address_child P = createElmChild(idBuku, judul, tahunBuku);
                insertSortChild(L2, P);
                cout<<"=============DATA BUKU TELAH DIINPUT================"<<endl;
                break;
            }
            case 3 :
            {
                printInfoParent(L1);
                break;
            }
            case 4 :
            {
                printInfoChild(L2);
                break;
            }
            case 5 :
            {
                if(first_child(L2)==NULL && first_parent(L1)==NULL){
                    cout<<" List Mahasiswa dan Buku Kosong";
                }else if(first_parent(L1)==NULL){
                    cout<<" List Mahasiswa Kosong";
                }else if (first_child(L2)==NULL )
                {
                    cout<<"List Buku Buku Kosong";
                }
                else
                {
                    int ID, idBuku;
                    cout<<"=================PEMINJAMAN BUKU===================="<<endl;
                    cout<<endl;
                    cout<<" Masukkan NIM         : ";
                    cin>>ID;
                    address_parent Q = findElmParent(L1, ID);
                    if(Q==NULL)
                    {
                        cout<<" NIM tidak ditemukan \n";
                        cout<<" !!!!!!!TIDAK DAPAT MEMINJAM BUKU!!!!!!!"<<endl;
                    }else{
                        cout<<" Masukkan ID Buku     : ";
                        cin>>idBuku;
                        address_child R = findElmChild(L2, idBuku);
                        if (R == NULL)
                        {
                            cout<<" ID buku tidak ditemukan\n";
                            cout<<" !!!!!!!TIDAK DAPAT MEMINJAM BUKU!!!!!!!"<<endl;
                        }
                        address_relasi S = findElmRelasi(L3, ID, idBuku);

                        if(S!=NULL)
                        {
                            cout<<" Tidak boleh meminjam buku yang sama";
                        }
                        else if(R != NULL&&Q!=NULL)
                        {
                            address_relasi P = createElmRelasi(Q, R);
                            insertRelasi(L3, P);
                            cout<<endl;
                            cout<<"==============BUKU BERHASIL DIPINJAM================"<<endl;
                        }
                    }
                }
                break;
            }
            case 6 :
            {
                if(first_relasi(L3)==NULL)
                {
                    cout<<"List Kosong"<<endl;
                }
                else
                {
                    int ID, idBuku;
                    cout<<"==============PENGEMBALIAN BUKU====================="<<endl;
                    cout<<endl;
                    cout<<" Masukkan NIM              : ";
                    cin>>ID;
                    address_parent Q = findElmParent(L1, ID);
                    if (Q==NULL)
                    {
                        cout<<" NIM tidak ditemukan\n";
                    }else{
                        cout<<" Masukkan ID Buku          : ";
                        cin>>idBuku;
                        address_child R = findElmChild(L2, idBuku);
                        address_relasi P = findElmRelasi(L3, ID, idBuku);
                        if (R == NULL)
                        {
                            cout<<" ID buku tidak ditemukan\n";
                        }
                        else if(P == NULL)
                        {
                            cout<<" Data tidak ditemukan dalam data peminjaman"<<endl;
                        }else{
                            if(P == first_relasi(L3))
                            {
                                deleteFirstRelasi(L3, P);
                            }
                            else if(P == last_relasi(L3))
                            {
                                deleteLastRelasi(L3, P);
                            }
                            else
                            {
                                deleteAfterRelasi(L3, prev_Relasi(P), P);
                            }
                        }
                    }
                    cout<<endl;
                    cout<<"==============BUKU TELAH DIKEMBALIKAN==============="<<endl;
                }
                break;
            }
            case 7 :
            {
                printInfoRelasi(L3);
                break;
            }
            case 8 :
            {
                if(first_relasi(L3)==NULL){
                    cout<<" List Peminjaman Kosong \n";
                }else{
                    int pilih;
                    cout<<" Untuk melihat buku yang dipinjam mahasiswa tertentu silahkan pilih 1,\n"
                        <<" Untuk mellihat daftar peminjam buku tertentu silahkan pilih 2\n"<<"\n";
                    cout<<" 1. Cari dengan NIM"<<endl;
                    cout<<" 2. Cari dengan ID Buku"<<endl;
                    cout<<" Choose Menu : ";
                    cin>>pilih;
                    if(pilih == 1){
                        int nim;
                        cout<<" Masukkan NIM : ";
                        cin>>nim;
                        address_parent P = findElmParent(L1, nim);
                        address_relasi Q = findElmRelasiParent(L3, P);
                        if(Q != NULL){
                            cout<<"=================================================================="<<endl;
                            cout<<"||                              DATA BUKU                       ||"<<endl;
                            cout<<"=================================================================="<<endl;
                            cout<<"||  ID Buku  ||"<<"             Judul Buku            ||"<<"Tahun Terbit||"<<endl;
                            cout<<"==================================================================\n";
                            Q = first_relasi(L3);
                            while(Q != NULL)
                            {
                                if(info_Parent(mahasiswa(Q)).NIM == nim){
                                    cout<<"||"<<setiosflags(ios::left)<<setw(11)<<info_Child(buku(Q)).idBuku<<"||"
                                    <<setiosflags(ios::left)<<setw(35)<<info_Child(buku(Q)).judulBuku<<"||"
                                    <<setiosflags(ios::left)<<setw(12)<<info_Child(buku(Q)).tahun<<"||"<<endl;
                                }
                                Q = next_Relasi(Q);
                            }
                            cout<<"=================================================================="<<endl;
                        }else{
                            cout<<" Data Peminjaman Tidak Ditemukan"<<endl;
                        }
                    }else if(pilih == 2){
                        int id;
                        cout<<" Masukkan ID Buku: ";
                        cin>>id;
                        address_child R = findElmChild(L2, id);
                        address_relasi Q = findElmRelasiChild(L3, R);
                        if(Q != NULL){
                            cout<<"=========================================================="<<endl;
                            cout<<"||                    DATA MAHASISWA                    ||"<<endl;
                            cout<<"=========================================================="<<endl;
                            cout<<"||     NIM       ||"<<"          Jurusan          ||"<<"Angkatan||"<<endl;
                            cout<<"==========================================================\n";
                            while(Q != NULL)
                            {
                                if(info_Child(buku(Q)).idBuku == id){
                                    cout<<"||"<<setiosflags(ios::left)<<setw(15)<<info_Parent(mahasiswa(Q)).NIM<<"||"
                                        <<setiosflags(ios::left)<<setw(27)<<info_Parent(mahasiswa(Q)).jurusan<<"||"
                                        <<setiosflags(ios::left)<<setw(8)<<info_Parent(mahasiswa(Q)).angkatan<<"||"<<endl;
                                }
                                Q = next_Relasi(Q);
                            }
                            cout<<"=========================================================="<<endl;
                        }else{
                            cout<<" Data Peminjaman Tidak Ditemukan"<<endl;
                        }
                    }
                }
                break;
            }
            case 9 :
            {
                if (first_parent(L1)==NULL)
                {
                    cout<<" List Kosong";
                }
                else
                {
                    int id;
                    cout<<"==========MENGHAPUS DATA MAHASISWA=========="<<endl;
                    cout<<" Masukkan NIM : ";
                    cin>>id;
                    cout<<endl;
                    address_parent P = findElmParent(L1, id);
                    address_relasi Q = findElmRelasiParent(L3, P);
                    if(Q != NULL)
                    {
                        cout<<"===Masih Ada Buku yang Belum Dikembalikan==="<<endl;
                    }else if(P==NULL){
                        cout<<"NIM tidak ditemukan \n";
                    }
                    else
                    {
                        deleteParent(L1, P);
                        cout<<"=============DATA TELAH DIHAPUS============="<<endl;
                    }
                }
                break;
            }
            case 10 :
            {
                if(first_child(L2)==NULL)
                {
                    cout<<"List Kosong";
                }
                else
                {
                    int idBuku;
                    cout<<"==============MENGHAPUS DATA BUKU==============="<<endl;
                    cout<<" Masukkan ID Buku : ";
                    cin>>idBuku;
                    cout<<endl;
                    address_child P = findElmChild(L2, idBuku);
                    address_relasi Q = findElmRelasiChild(L3, P);
                    if(Q != NULL)
                    {
                        cout<<"=====Masih Ada Buku yang Belum Dikembalikan====="<<endl;
                    }else if(P==NULL){
                        cout<<"ID Buku tidak ditemukan \n";
                    }
                    else
                    {
                        deleteChild(L2, P);
                        cout<<"=============DATA BUKU TELAH DIHAPUS============"<<endl;
                    }
                }
                break;
            }
            case 11 :
            {
                int totBuku = totalBuku(L2);
                cout<<"Total Jenis Buku: "<<totBuku;
                break;
            }
            //BATAS MAIN.CPP YANG DIKERJAKAN OLEH AZIZAH CAHYA KEMILA (1301194103)
            //MAYANG SARI (1301194227)
            case 12 :
            {
                int mhsw = totalMahasiswa(L1);
                cout<<"Total Mahasiswa: "<<mhsw;
                break;
            }
            case 13:
            {
                int sum = totalPeminjaman(L3);
                cout<<"Total peminjaman : "<<sum<<endl;
                break;
            }
            //BATAS MAIN.CPP YANG DIKERJAKAN OLEH MAYANG SARI (1301194103)
        }
        //AZIZAH CAHYA KEMILA (1301194103)
        cout<<endl;
        system("PAUSE");
        system("CLS");

    }
    return 0;
}

