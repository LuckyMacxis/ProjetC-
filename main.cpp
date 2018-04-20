#include "CMatrice.hh"

int main(int argc, char* argv[]){
    try{
        unsigned int uiBoucle;
        int iValeur;
        CMatrice<double> * pMATtab[argc];
        CMatrice<double> * pMATmatAddition;

        //lecture des fichier et creation des matrices
        for(uiBoucle = 1; uiBoucle < argc; uiBoucle++){
            pMATtab[uiBoucle] = CMatrice<double>::MATlireFichier(argv[uiBoucle]);
        }

        cout << "entrez une valeur \n";
        cin >> iValeur;

        try{
            for(uiBoucle = 1; uiBoucle < argc; uiBoucle++){
                cout << "\nMatrice " << uiBoucle << " * " << iValeur << endl;
                (*pMATtab[uiBoucle] * iValeur).MATafficherMatrice();
            }
        }catch(CException e){
            e.sEXPmessageException();
        }

        try{
            for(uiBoucle = 1; uiBoucle < argc; uiBoucle++){
                cout << "\nMatrice " << uiBoucle << "/ " << iValeur << endl;
                (*pMATtab[uiBoucle] / iValeur).MATafficherMatrice();
            }
        }catch(CException e){
            e.sEXPmessageException();
        }

        try{
            for(uiBoucle = 1; uiBoucle < argc; uiBoucle++){
                if (uiBoucle == 1){
                    pMATmatAddition = new CMatrice<double>(*pMATtab[uiBoucle]);
                }else{
                    *pMATmatAddition = *pMATmatAddition + *pMATtab[uiBoucle];
                }
            }
            cout << "\n Addition de toutes les matrices\n";
            pMATmatAddition->MATafficherMatrice();
        }catch(CException e){
            e.sEXPmessageException();
        }

        delete pMATmatAddition;

        try{
            for(uiBoucle = 1; uiBoucle < argc; uiBoucle++){
                if (uiBoucle == 1){
                    pMATmatAddition = new CMatrice<double>(*pMATtab[uiBoucle]);
                }else{
                    if (uiBoucle % 2 == 0){
                        *pMATmatAddition = *pMATmatAddition - *pMATtab[uiBoucle];
                    }else{
                        *pMATmatAddition = *pMATmatAddition + *pMATtab[uiBoucle];
                    }
                }
            }
            cout << "\n M1 - M2 + M3 - ....\n";
            pMATmatAddition->MATafficherMatrice();
        }catch(CException e){
            e.sEXPmessageException();
        }

        delete pMATmatAddition;

        try{
            for(uiBoucle = 1; uiBoucle < argc; uiBoucle++){
                if (uiBoucle == 1){
                    pMATmatAddition = new CMatrice<double>(*pMATtab[uiBoucle]);
                }else{
                    *pMATmatAddition = *pMATmatAddition * *pMATtab[uiBoucle];
                }
            }

            cout << "\n Multiplication des matrices\n";
            pMATmatAddition->MATafficherMatrice();
        }catch(CException e){
            e.sEXPmessageException();
        }

    
    }catch(CException e){
        e.sEXPmessageException();
    }
}