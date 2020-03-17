#include <iostream>
#include "listChild.h"
#include "listParent.h"

using namespace std;

int main()
{
    /** INI BUAT NGECEK BENER GA FUNGSINYA CA, NTAR UBAH AJA WWKKW **/
    List_child L;
    List_parent L2;
    address_child P, Q, R;
    address_parent Z;

    createList(L);

    P = createElmChild(1, "Mawar Jingga", "A103", 2001);
    insertFirst(L, P);
    Q = createElmChild(2, "ASHIAPP", "L632", 1999);
    insertAfter(L, P, Q);
    R = createElmChild(3, "Mawar Merah", "A301", 2009);
    insertLast(L, R);
    printInfoChild(L);
    cout<<"hasil delete"<<endl;
    deleteLast(L, P);
    printInfoChild(L);
    cout<<"hasil delete after"<<endl;
    deleteAfter(L, Q, P);
    printInfoChild(L);

    createList(L2);
    Z = createElmParent("1111", "FIF", "IF");
    insertFirst(L2, Z);
    printInfoParent(L2);
    return 0;
}
