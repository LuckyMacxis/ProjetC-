#ifndef CListeMatrice_h
#define CListeMatrice_h

#include <vector>

#include "CMatrice.h"


class CListeMatrice {

 public:

    virtual void LISajouter(CMatrice MATmat);

    virtual void LISsupprimer(Integer uiPosition);

    virtual void LISviderListe();

    virtual void LISajouter(void  sChemin);


 private:
    Integer uiLIStaille;

 public:

    /**
     * @element-type CMatrice
     */
    std::vector< CMatrice* > myCMatrice;
};

#endif // CListeMatrice_h
