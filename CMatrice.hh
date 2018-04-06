#ifndef CMatrice_h
#define CMatrice_h

#include <iostream>
using namespace std;
#include <string.h>


template <class Mtype> class CMatrice{

    private:
    Mtype **pMATmatrice;
    unsigned int uiMATnbColonne;
    unsigned int uiMATnbLigne;

    public:

    //Constructeurs
    CMatrice<Mtype>(){
        uiMATnbColonne = 0;
        uiMATnbLigne = 0;
        pMATmatrice = NULL;
    }

    CMatrice<Mtype>(Mtype **pMatrice, unsigned int uiNbColonne, unsigned int uiNbLigne){
        unsigned int uiBoucle1;
        unsigned int uiBoucle2;

        uiMATnbColonne = uiNbColonne;
        uiMATnbLigne = uiNbLigne;

        pMATmatrice = new Mtype*[uiMATnbColonne];

        for(uiBoucle1 = 0; uiBoucle1 < uiNbColonne; uiBoucle1++){
            pMATmatrice[uiBoucle1] = new Mtype[uiMATnbLigne];
            
            for(uiBoucle2 = 0; uiBoucle2 < uiNbLigne; uiBoucle2++){
                pMATmatrice[uiBoucle1][uiBoucle2] = pMatrice[uiBoucle1][uiBoucle2];
            }
        }

    }

    CMatrice<Mtype>(CMatrice<Mtype> &MATmatrice){
        unsigned int uiBoucle1;
        unsigned int uiBoucle2;

        uiMATnbColonne = MATmatrice.uiMATnbColonne;
        uiMATnbLigne = MATmatrice.uiMATnbLigne;

        pMATmatrice = new Mtype*[uiMATnbColonne];

        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbColonne; uiBoucle1++){
            pMATmatrice[uiBoucle1] = new Mtype[uiMATnbLigne];
            
            for(uiBoucle2 = 0; uiBoucle2 < uiMATnbLigne; uiBoucle2++){
                pMATmatrice[uiBoucle1][uiBoucle2] = MATmatrice.pMATmatrice[uiBoucle1][uiBoucle2];
            }
        }
    }

    void MATafficherMatrice(){
        unsigned int uiBoucle1;
        unsigned int uiBoucle2;

        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbColonne; uiBoucle1++){
            cout << '\n';
            for(uiBoucle2 = 0; uiBoucle2 < uiMATnbLigne; uiBoucle2++){
                cout << pMATmatrice[uiBoucle1][uiBoucle2] << "   ";
            }
        }
        cout << '\n';
    }

    CMatrice<Mtype> operator=(CMatrice<Mtype> &MATmatrice){
        unsigned int uiBoucle1;
        unsigned int uiBoucle2;

        uiMATnbColonne = MATmatrice.uiMATnbColonne;
        uiMATnbLigne = MATmatrice.uiMATnbLigne;

        if(pMATmatrice != NULL){
            for(uiBoucle1 = 0; uiBoucle1 < uiMATnbColonne; uiBoucle1++)
            {
                delete []pMATmatrice[uiBoucle1];
            }
            delete []pMATmatrice;
        }

        pMATmatrice = new Mtype*[uiMATnbColonne];

        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbColonne; uiBoucle1++){
            pMATmatrice[uiBoucle1] = new Mtype[uiMATnbLigne];
            for(uiBoucle2 = 0; uiBoucle2 < uiMATnbLigne; uiBoucle2++){
                pMATmatrice[uiBoucle1][uiBoucle2] = MATmatrice.pMATmatrice[uiBoucle1][uiBoucle2]; 
            }
        }
    }

   /* CMatrice operator+(CMatrice MATmat);

    CMatrice operator*(double  dVal, CMatrice * MATmat);

    CMatrice operator-(CMatrice * MATmat);

    CMatrice operator/(CMatrice * MATmat);

    CMatrice operator*(CMatrice * MATmat);

    CMatrice operator/(double  dVal);

    CMatrice MATtransposee();

    CMatrice operator*(double  dVal);*/

};

#endif // CMatrice_h
