#include "CMatrice.hh"
#include "CListeMatrice.h"


int main(){

    try{
        string chemin = "Test.txt";
        CMatrice<double> *Matrice;
        Matrice->MATafficherMatrice();
    
    }catch(CException e){
        e.sEXPmessageException();
    }
}