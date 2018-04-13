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
		string stype;
		unsigned int iNbLignes, iNbColonnes;
		string sligne;

		getline(monFlux, sligne);
		stype=sligne.substr(14,10);

		getline(monFlux, sligne);
		sligne=sligne.substr(9, 10);
		iNbLignes = stoi(sligne, nullptr,5);

		getline(monFlux, sligne);
		sligne = sligne.substr(11, 10);
		iNbColonnes = stoi(sligne, nullptr, 10);

		getline(monFlux, sligne);

		double **Matrice = new double*[iNbLignes];
		for (int i = 0; i < iNbLignes; i++)
			Matrice[i] = new double[iNbColonnes];
		int indicateur=0;
		while (indicateur!=iNbLignes)
		{
			getline(monFlux, sligne);
			unsigned int i; int j = 0;
			for (i = 0; i <= iNbColonnes; i=i+2)
			{
				Matrice[indicateur][j] = stod(sligne);
				sligne = sligne.substr(2, iNbColonnes*2);
				j++;
			}
			Matrice[indicateur][j] = stod(sligne);
			indicateur++;
		}
		uiLIStaille++;
		CMatrice<double> Mat(Matrice,iNbLignes,iNbColonnes);
		Mat.MATafficherMatrice();
		for (int i = 0; i < iNbLignes; i++)
			delete[] Matrice[i];
		delete[] Matrice;
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
}