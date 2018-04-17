#ifndef CMatrice_h
#define CMatrice_h

#include <iostream>
#include <fstream>
#include <string>
#include "CMatrice.hh"
#include "Exception.hh"
using namespace std;



template <class Mtype> class CMatrice{

    private:
    Mtype **pMATmatrice;
    unsigned int uiMATnbColonne;
    unsigned int uiMATnbLigne;

    public:

    /**
     * @brief Construit un nouvel object CMatrice<Mtype> sans parrametre
     * le nombre de ligne et de colonne sont mis à 0, et le tableau à null.
     */
    CMatrice<Mtype>(){
        uiMATnbColonne = 0;
        uiMATnbLigne = 0;
        pMATmatrice = NULL;
    }

    /**
     * @brief Construit un nouvel object CMatrice<Mtype> avec tous les parametres possibles
     * 
     * @param pMatrice un tableau de pointeur de Mtype qui represente les valeurs de la matrice.
     * @param uiNbLigne le nombre de ligne de la matrice
     * @param uiNbColonne le nombre de colonne de la matrice
     * @throw CException si le tableau de pointeur est null.
     */
    CMatrice<Mtype>(Mtype **pMatrice, unsigned int uiNbLigne, unsigned int uiNbColonne){

        if (!**pMatrice)
            throw CException("Argument null");
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

    /**
     * @brief Constructeur de copy
     * 
     * @param MATmatrice un Object CMatrice<Mtype> à partir duquel creer un nouvel object CMatrice<Mtype>
     */
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

    /**
     * @brief affiche une matrice dans le terminal
     * 
     */
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

        /**
         * @brief operateur d'affectation
         * si la matrice a gauche était deja alloue, alors elle sera tout d'abord desaloue
         * @param MATmatrice un Object CMatrice
         * @return CMatrice<Mtype>& un nouvel object CMatrice deja alloue.
         */
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

    
    /**
     * @brief operateur d'addition
     * Cette operateur ne modifie pas les valeurs des deux operandes
     * @param MATmat une CMatrice
     * @return CMatrice<Mtype>& un nouvel object CMatrice deja alloue
     * @throw CException si les deux matrices ne sont pas de la même taille
     */
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

    
    /**
     * @brief operateur de soustraction
     * Cette operateur ne modifie pas les valeurs des deux operandes
     * @param MATmat une CMatrice
     * @return CMatrice<Mtype>& un nouvel object CMatrice deja alloue
     * @throw CException si les deux matrices ne sont pas de la même taille
     */
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

    /**
     * @brief operateur de multiplication entre un CMatrice et un double
     * Cette operateur de modifie pas les valeurs des deux operandes
     * @param dVal un double
     * @return CMatrice<Mtype>& un nouvel object CMatrice deja alloue
     */
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

    /**
     * @brief operateur de multiplication entre deux CMatrices
     * Cette operateur ne modifie pas les valeurs des deux operandes
     * @param MATmat un CMatrice
     * @return CMatrice<Mtype>& Un nouvel object CMatrice deja alloue
     * @throw CException si les deux matrices n'ont pas les bonnes tailles pour être multiplie
     */
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

    /**
     * @brief operateur de multiplication entre un double et un CMatrice
     * Cette operateur de modifie pas les valeurs des deux operandes
     * @param dVal un double
     * @param MATmat un CMatrice correctement alloue et initialise
     * @return CMatrice<Mtype>& un nouvel object CMatrice deja alloue
     * @throw CException si le CMatrice est null
     */
    friend CMatrice<Mtype> & operator*(double  dVal, CMatrice<Mtype> & MATmat){
        if (MATmat == NULL)
            throw CException("Aguments à null");
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

    /**
     * @brief faire la transposé d'une matrice
     * Le CMatrice d'origine n'est pas modifie
     * @return CMatrice<Mtype>& un nouvel object CMatrice deja alloue
     */
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



    static CMatrice<double> MATlireFichier(string  sChemin)
    {
        ifstream monFlux(sChemin);  //Ouverture du fichier en lecture
        if (monFlux)
        {
            string stype;
            unsigned int iNbLignes, iNbColonnes;
            string sligne;

            getline(monFlux, sligne);
            stype=sligne.substr(14,15);
            /*if (stype.compare("double")!=0)
                //throw CException("Type de la matrice different de double");*/
            getline(monFlux, sligne);
            sligne=sligne.substr(9, 10);
            iNbLignes = stoi(sligne, nullptr,10);
            
            getline(monFlux, sligne);
            sligne = sligne.substr(11, 10);
            iNbColonnes = stoi(sligne, nullptr, 10);
            getline(monFlux, sligne);
            double **Matrice = new double*[iNbLignes];
            for (int i = 0; i < iNbLignes; i++)
                Matrice[i] = new double[iNbColonnes];
            int indicateur=0;
            int indexMat;
            while (indicateur != iNbLignes)
            {
                getline(monFlux, sligne);
                int i;
                indexMat = 0;
                i = 0;
                int indextemp;
                char temp0[50];
                    while (sligne[i] != '\0')
                    {
                        indextemp = 0;
                        while (sligne[i] == ' ' && sligne[i] != '\0')
                        {
                            i++;
                        }
                        while (sligne[i] != ' ' && sligne[i] != '\0')
                        {
                            temp0[indextemp] = sligne[i];
                            indextemp++;
                            i++;
                        }
                        string temp(temp0);
                        Matrice[indicateur][indexMat] = stod(temp0);
                        indexMat++;
                        for (int j = 0; j < 50; j++)
                            temp0[j] = ' ';
                        }
                        indicateur++;
            }
            CMatrice<double>* Mat = new CMatrice<double>(Matrice, iNbLignes, iNbColonnes);
            for (int i = 0; i < iNbLignes; i++)
                delete[] Matrice[i];
            delete[] Matrice;
            return Mat;
        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        }
    }

};

#endif // CMatrice_h
