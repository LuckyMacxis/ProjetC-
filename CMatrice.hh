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

        CMatrice<Mtype> & operator=(CMatrice<Mtype> MATmatrice){
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
        return *this;
    }

    

    CMatrice<Mtype> & operator+(CMatrice<Mtype> & MATmat){
        unsigned int uiBoucle1, uiBoucle2;
        CMatrice<Mtype> * MATresult = new CMatrice(*this);

        if(MATmat.uiMATnbColonne != uiMATnbColonne || MATmat.uiMATnbLigne != uiMATnbLigne)
            throw CException("Les deux matrices doivent être de la meme taille");
        
        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbLigne; uiBoucle1++){
            for(uiBoucle2 = 0; uiBoucle2 < uiMATnbColonne; uiBoucle2++){
                MATresult->pMATmatrice[uiBoucle1][uiBoucle2] = pMATmatrice[uiBoucle1][uiBoucle2] + MATmat.pMATmatrice[uiBoucle1][uiBoucle2];
            }
        }
        
        return *MATresult;
    }

    

    CMatrice<Mtype> & operator-(CMatrice<Mtype> & MATmat){
        unsigned int uiBoucle1, uiBoucle2;
        CMatrice<Mtype> * MATresult = new CMatrice<Mtype>(*this);

        if(MATmat.uiMATnbColonne != uiMATnbColonne || MATmat.uiMATnbLigne != uiMATnbLigne)
            throw CException("Les deux matrices doivent être de la meme taille");
        
        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbLigne; uiBoucle1++){
            for(uiBoucle2 = 0; uiBoucle2 < uiMATnbColonne; uiBoucle2++){
                MATresult->pMATmatrice[uiBoucle1][uiBoucle2] = pMATmatrice[uiBoucle1][uiBoucle2] - MATmat.pMATmatrice[uiBoucle1][uiBoucle2];
            }
        }
        
        return *MATresult;
    }


    CMatrice<Mtype> & operator*(double  dVal){
        unsigned int uiBoucle1, uiBoucle2;

        CMatrice<Mtype> * MATresult = new CMatrice(*this);

        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbLigne; uiBoucle1++){
            for(uiBoucle2 = 0; uiBoucle2 < uiMATnbColonne; uiBoucle2++){
                MATresult->pMATmatrice[uiBoucle1][uiBoucle2] = dVal * pMATmatrice[uiBoucle1][uiBoucle2];
            }
        }

        return *MATresult;
    }

    CMatrice<Mtype> & operator*(CMatrice<Mtype> & MATmat){
        unsigned int uiBoucle1, uiBoucle2, uiBoucle3;
        unsigned int uiNbColonneResult, uiNbLigneResult;
        Mtype ** pMtab;
        Mtype Mtmp;

        if(uiMATnbColonne != MATmat.uiMATnbLigne
        || uiMATnbLigne != MATmat.uiMATnbColonne){
            throw CException("taille des matrices imcompatibles pour les multiplier");
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

        CMatrice<Mtype> * MATresult = new CMatrice<Mtype>(pMtab,uiNbColonneResult,uiNbLigneResult);

        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbColonne; uiBoucle1++)
            {
                delete []pMtab[uiBoucle1];
            }
            delete []pMtab;

        return *MATresult;
    }

    friend CMatrice<Mtype> & operator*(double  dVal, CMatrice<Mtype> & MATmat){
        unsigned int uiBoucle1, uiBoucle2;

        CMatrice<Mtype> * MATresult = new CMatrice<Mtype>(MATmat);

        for(uiBoucle1 = 0; uiBoucle1 < MATmat.uiMATnbLigne; uiBoucle1++){
            for(uiBoucle2 = 0; uiBoucle2 < MATmat.uiMATnbColonne; uiBoucle2++){
                MATresult->pMATmatrice[uiBoucle1][uiBoucle2] = dVal * MATmat.pMATmatrice[uiBoucle1][uiBoucle2];
            }
        }

        return *MATresult;
    }

    CMatrice<Mtype> & operator/(double  dVal){
        unsigned int uiBoucle1, uiBoucle2;

        if(dVal == 0)
            throw CException("Division par 0");

        CMatrice<Mtype> * MATresult = new CMatrice(*this);

        for(uiBoucle1 = 0; uiBoucle1 < uiMATnbLigne; uiBoucle1++){
            for(uiBoucle2 = 0; uiBoucle2 < uiMATnbColonne; uiBoucle2++){
                MATresult->pMATmatrice[uiBoucle1][uiBoucle2] =pMATmatrice[uiBoucle1][uiBoucle2] / dVal;
            }
        }

        return *MATresult;
    }

    CMatrice<Mtype> & MATtransposee(){
        unsigned int uiBoucle1, uiBoucle2;

        CMatrice<Mtype> * MATresult = new CMatrice();
        MATresult->uiMATnbLigne = uiMATnbColonne;
        MATresult->uiMATnbColonne = uiMATnbLigne;

        MATresult->pMATmatrice = new Mtype*[MATresult->uiMATnbLigne];

        for(uiBoucle1 = 0; uiBoucle1 < MATresult->uiMATnbLigne; uiBoucle1++){
            MATresult->pMATmatrice[uiBoucle1] = new Mtype[MATresult->uiMATnbColonne];
            for(uiBoucle2 = 0; uiBoucle2 < MATresult->uiMATnbColonne; uiBoucle2++){
                MATresult->pMATmatrice[uiBoucle1][uiBoucle2] = pMATmatrice[uiBoucle2][uiBoucle1];
            }
        }

        return *MATresult;
    }

};

#endif // CMatrice_h
