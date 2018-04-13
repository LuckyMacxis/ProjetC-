#ifndef CListeMatrice_h
#define CListeMatrice_h

#include <vector>

#include <iostream>

#include <fstream>

#include "CMatrice.hh"

#include <string>

using namespace std;

class CListeMatrice {

public:
	CListeMatrice();
	~CListeMatrice();
	//virtual void LISajouter(CMatrice MATmat);
	virtual void LISsupprimer(unsigned int uiPosition);

	virtual void LISviderListe();

	virtual void LISajouter(string  sChemin);


private:
	unsigned int uiLIStaille;

	/**
	 * @element-type CMatrice
	 */
	 // std::vector< CMatrice* > myCMatrice;
};

#endif // CListeMatrice_h

