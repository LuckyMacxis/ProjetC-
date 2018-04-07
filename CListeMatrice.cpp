#include "CListeMatrice.h"


CListeMatrice::CListeMatrice()
{
}


CListeMatrice::~CListeMatrice()
{
}
/*void CListeMatrice::LISajouter(CMatrice MATmat)
{
}*/

void CListeMatrice::LISsupprimer(unsigned int uiPosition)
{
}

void CListeMatrice::LISviderListe()
{
}

void CListeMatrice::LISajouter(string  sChemin)
{
	ifstream monFlux(sChemin);  //Ouverture du fichier en lecture
	if (monFlux)
	{
		string ligne;
		getline(monFlux, ligne);
		ligne.substr(12, 10);

		while (getline(monFlux, ligne))
		{
			cout << ligne << "\n";
		}
		cout << "okligne";
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
}