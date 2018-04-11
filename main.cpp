#include "CMatrice.hh"


int main(){

    int **a = new int*[2];
    int **b = new int*[3];

    for(int i = 0; i<3;i++){
        a[i] = new int[2];
    }

    a[0][0]=0;
    a[0][1] = 1;
    a[1][1] = 3;
    a[1][0] = 2;
    a[1][2] = 2;
    a[0][2] = 2;

    CMatrice<int> matrice(a,2,3);

   /* CMatrice<int> matrice2;

    matrice2 = matrice;

    matrice.MATafficherMatrice();

    matrice2.MATafficherMatrice();*/



    for(int i = 0; i<3;i++){
        b[i] = new int[3];
        for(int j = 0; j < 2; j++){
            b[i][j] = i+j;
        }
    }

    CMatrice<int> matrice2(b,3,2);

    cout << "Matrice A \n";

    matrice.MATafficherMatrice();

    (matrice.MATtransposee()).MATafficherMatrice();

    

    return 0;
}
    /*
#include "stdafx.h"
#include "CListeMatrice.h"

int main()
{
	CListeMatrice Lis;
	Lis = new CListeMatrice();
	Lis.LISajouter("C:\Users\ZoD\Documents\GitHub\Test");
	return 0;
}*/