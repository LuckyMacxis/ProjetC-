#include "CMatrice.hh"


int main(){
    int m = 2;

    int **a = new int*[m];

    for(int i = 0; i<m;i++){
        a[i] = new int[3];
        for(int j = 0; j < 3; j++){
            a[i][j] = 2;
        }
    }

    CMatrice<int> matrice(a,2,3);

    matrice.MATafficherMatrice();

    CMatrice<int> copy(matrice);

    cout << "\n\n";

    copy.MATafficherMatrice();

    return 0;
}