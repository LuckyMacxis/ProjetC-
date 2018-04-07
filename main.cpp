<<<<<<< HEAD
#include "CMatrice.hh"


int main(){
    int m = 2;

    int **a = new int*[m];
    int **b = new int*[m];

    for(int i = 0; i<m;i++){
        a[i] = new int[3];
        for(int j = 0; j < 3; j++){
            a[i][j] = 2;
        }
    }

    for(int i = 0; i<m;i++){
        b[i] = new int[3];
        for(int j = 0; j < 3; j++){
            b[i][j] = 1;
        }
    }

    CMatrice<int> matrice(a,2,3);

    CMatrice<int> matrice2(b,2,3);

    matrice.MATafficherMatrice();

    matrice2.MATafficherMatrice();

    matrice2 = matrice;

    cout << " = \n";
    matrice2.MATafficherMatrice();

    return 0;
=======
#include "stdafx.h"
#include "CListeMatrice.h"

int main()
{
	CListeMatrice Lis;
	Lis = new CListeMatrice();
	Lis.LISajouter("C:\Users\ZoD\Documents\GitHub\Test");
	return 0;
>>>>>>> 583d311b88a6062c88226f214b8962dc0e3f16a4
}