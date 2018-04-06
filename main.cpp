#include "CMatrice.hh"


int main(){
    int m = 2;

    int **a = new int*[m];

    for(int i = 0; i<m;i++){
        a[i] = new int[2];
        for(int j = 0; j < 2; j++){
            a[i][j] = 2;
        }
    }

    CMatrice<int> matrice(a,2,2);

    matrice.MATafficherMatrice();

    return 0;
}