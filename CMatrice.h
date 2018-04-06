#ifndef CMatrice_h
#define CMatrice_h

#include "CMatrice.h"


class CMatrice {

 public:

    virtual CMatrice operator+(CMatrice MATmat);

    virtual CMatrice operator*(void  dVal, void  MATmat);

    virtual CMatrice operator-(CMatrice MATmat);

    virtual CMatrice operator/(CMatrice MATmat);

    virtual CMatrice operator*(CMatrice MATmat);

    virtual CMatrice operator/(void  dVal);

    virtual void MATafficherMatrice();

    virtual CMatrice MATtransposee();

 private:

    virtual CMatrice operator*(void  dVal);

 public:
    Integer **pMATmatrice;

 private:
    Integer uiMATnbColonne;
    Integer uiMATnbLigne;

};

#endif // CMatrice_h
