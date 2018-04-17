#ifndef CListeMatrice_h
#define CListeMatrice_h

#include <vector>

#include <iostream>

#include <fstream>
#include <string>
#include "CMatrice.hh"
#include "Exception.hh"
using namespace std;

class CListeMatrice {

public:
	CListeMatrice();
	~CListeMatrice();
	//virtual void LISajouter(CMatrice MATmat);
	virtual void LISsupprimer(unsigned int uiPosition);

	virtual void LISviderListe();

	CMatrice<double> LISajouter(string  sChemin);


private:
	unsigned int uiLIStaille;
	CMatrice<double>* MatriceList;
};

#endif // CListeMatrice_h

