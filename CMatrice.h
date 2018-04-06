#ifndef CMatrice_h
#define CMatrice_h

#include "CMatrice.h"


class CMatrice {

 public:

    CMatrice operator+(CMatrice MATmat);

    CMatrice operator*(double  dVal, CMatrice * MATmat);

    CMatrice operator-(CMatrice * MATmat);

    CMatrice operator/(CMatrice * MATmat);

    CMatrice operator*(CMatrice * MATmat);

    CMatrice operator/(double  dVal);

    void MATafficherMatrice();

    CMatrice MATtransposee();

    CMatrice operator*(double  dVal);

 private:
    Integer **pMATmatrice;
    Integer uiMATnbColonne;
    Integer uiMATnbLigne;

};

#endif // CMatrice_h
