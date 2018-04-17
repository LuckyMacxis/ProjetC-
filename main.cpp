#include "CMatrice.hh"
#include "CListeMatrice.h"


int main(){

    try{
        CListeMatrice *lis = new CListeMatrice();
    string chemin = "Test.txt";
    lis->LISajouter(chemin);
    }catch(CException e){
        e.sEXPmessageException();
    }
}