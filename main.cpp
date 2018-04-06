#include "CMatrice.h"


int main(){

    int a[2][2] = {1,2,3,4};

    CMatrice<int> * matrice = new CMatrice<int>(a,2,2);

    return 0;
}