#ifndef CMatrice_h
#define CMatrice_h

#include <iostream>
using namespace std;
#include <string.h>
#include "Exception.hh"



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

    CMatrice<Mtype>(Mtype **pMatrice, unsigned int uiNbLigne, unsigned int uiNbColonne){
        unsigned int uiBoucle1;
        unsigned int uiBoucle2;

        uiMATnbColonne = uiNbColonne;
        uiMATnbLigne = uiNbLigne;

        pMATmatrice = new Mtype*[uiMATnbLigne];

        for(uiBoucle1 = 0; uiBoucle1 < uiNbLigne; uiBoucle1++){
            pMATmatrice[uiBoucle1] = new Mtype[uiMATnbColonne];
            
            for(uiBoucle2 = 0; uiBoucle2 < uiNbColonne; uiBoucle2++){
                pMATmatrice[uiBoucle1][uiBoucle2] = pMatrice[uiBoucle1][uiBoucle2];
            }
        }

    }

    CMatrice<Mtype>(CMatrice<Mtype> &MATmatrice){
        unsigned int uiBoucle1;
        unsigned int uiBoucle2;

        uiMATnbColonne = MATmatrice.uiMATnbColonne;
        uiMATnbLigne = MATmatrice.uiMATnbLigne;

        pMATmatrice = new Mtype*[uiMATnbLigne];

        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbLigne; uiBoucle1++){
            pMATmatrice[uiBoucle1] = new Mtype[uiMATnbColonne];
            
            for(uiBoucle2 = 0; uiBoucle2 < uiMATnbColonne; uiBoucle2++){
                pMATmatrice[uiBoucle1][uiBoucle2] = MATmatrice.pMATmatrice[uiBoucle1][uiBoucle2];
            }
        }
    }

    void MATafficherMatrice(){
        unsigned int uiBoucle1;
        unsigned int uiBoucle2;

        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbLigne; uiBoucle1++){
            cout << '\n';
            for(uiBoucle2 = 0; uiBoucle2 < uiMATnbColonne; uiBoucle2++){
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

        pMATmatrice = new Mtype*[uiMATnbLigne];

        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbLigne; uiBoucle1++){
            pMATmatrice[uiBoucle1] = new Mtype[uiMATnbColonne];
            for(uiBoucle2 = 0; uiBoucle2 < uiMATnbColonne; uiBoucle2++){
                pMATmatrice[uiBoucle1][uiBoucle2] = MATmatrice.pMATmatrice[uiBoucle1][uiBoucle2]; 
            }
        }
    }

    CMatrice<Mtype> operator+(CMatrice<Mtype> MATmat){
        unsigned int uiBoucle1, uiBoucle2;
        CMatrice<Mtype> MATresult(*this);

        if(MATmat.uiMATnbColonne != uiMATnbColonne || MATmat.uiMATnbLigne != uiMATnbLigne)
            throw CException(TAILLE_MATRICE_INVALIDE);
        
        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbLigne; uiBoucle1++){
            for(uiBoucle2 = 0; uiBoucle2 < uiMATnbColonne; uiBoucle2++){
                MATresult.pMATmatrice[uiBoucle1][uiBoucle2] = pMATmatrice[uiBoucle1][uiBoucle2] + MATmat.pMATmatrice[uiBoucle1][uiBoucle2];
            }
        }
        
        return MATresult;
    }

    

    CMatrice<Mtype> operator-(CMatrice<Mtype> MATmat){
        unsigned int uiBoucle1, uiBoucle2;
        CMatrice<Mtype> MATresult(*this);

        if(MATmat.uiMATnbColonne != uiMATnbColonne || MATmat.uiMATnbLigne != uiMATnbLigne)
            throw CException(TAILLE_MATRICE_INVALIDE);
        
        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbLigne; uiBoucle1++){
            for(uiBoucle2 = 0; uiBoucle2 < uiMATnbColonne; uiBoucle2++){
                MATresult.pMATmatrice[uiBoucle1][uiBoucle2] = pMATmatrice[uiBoucle1][uiBoucle2] - MATmat.pMATmatrice[uiBoucle1][uiBoucle2];
            }
        }
        
        return MATresult;
    }


    CMatrice operator*(double  dVal){
        unsigned int uiBoucle1, uiBoucle2;

        CMatrice<Mtype> MATresult(*this);

        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbLigne; uiBoucle1++){
            for(uiBoucle2 = 0; uiBoucle2 < uiMATnbColonne; uiBoucle2++){
                MATresult.pMATmatrice[uiBoucle1][uiBoucle2] = dVal * pMATmatrice[uiBoucle1][uiBoucle2];
            }
        }

        return MATresult;
    }

    CMatrice<Mtype> operator*(CMatrice<Mtype> & MATmat){
        unsigned int uiBoucle1, uiBoucle2, uiBoucle3;
        unsigned int uiNbColonneResult, uiNbLigneResult;
        Mtype ** pMtab;
        Mtype Mtmp;

        if(uiMATnbColonne != MATmat.uiMATnbLigne
        || uiMATnbLigne != MATmat.uiMATnbColonne){
            throw CException(TAILLE_MATRICE_INVALIDE);
        }

        uiNbColonneResult = uiMATnbLigne;
        uiNbLigneResult = uiNbColonneResult;

        pMtab = new Mtype*[uiNbLigneResult];

        for(uiBoucle1 = 0; uiBoucle1 < uiNbLigneResult; uiBoucle1++){
            pMtab[uiBoucle1] = new Mtype[uiNbColonneResult];
            for(uiBoucle2 = 0; uiBoucle2 < uiNbLigneResult; uiBoucle2++){
                Mtmp = 0;
                for(uiBoucle3 = 0; uiBoucle3 < uiMATnbColonne; uiBoucle3++){
                    
                    Mtmp = Mtmp + (pMATmatrice[uiBoucle1][uiBoucle3] * MATmat.pMATmatrice[uiBoucle3][uiBoucle2]);
                    
                }
                pMtab[uiBoucle1][uiBoucle2] = Mtmp;
                
            }
        }

        CMatrice<Mtype>  MATresult(pMtab,uiNbColonneResult,uiNbLigneResult);

        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbColonne; uiBoucle1++)
            {
                delete []pMtab[uiBoucle1];
            }
            delete []pMtab;

        return MATresult;
    }

    /*CMatrice operator*(double  dVal, CMatrice * MATmat);

    CMatrice operator/(CMatrice * MATmat);


    CMatrice operator/(double  dVal);

    CMatrice MATtransposee();

    */

};

#endif // CMatrice_h
