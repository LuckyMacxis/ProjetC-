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

CMatrice<double> CListeMatrice::LISajouter(string  sChemin)
{
	ifstream monFlux(sChemin);  //Ouverture du fichier en lecture
	if (monFlux)
	{
		string stype;
		unsigned int iNbLignes, iNbColonnes;
		string sligne;

		getline(monFlux, sligne);
		stype=sligne.substr(14,15);
		if (stype.compare("double")!=0)
			throw CException("Type de la matrice différent de double");
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
		uiLIStaille++;
		CMatrice<double>* Mat = new CMatrice<double>(Matrice, iNbLignes, iNbColonnes);
		Mat->MATafficherMatrice();
		for (int i = 0; i < iNbLignes; i++)
			delete[] Matrice[i];
		delete[] Matrice;
		return *Mat;
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
}




















/*unsigned int i; int j = 0;
for (i = 0; i <= iNbColonnes; i=i+2)
{
Matrice[indicateur][j] = stod(sligne);
sligne = sligne.substr(2, iNbColonnes*2);
sligne.erase()
j++;
}
Matrice[indicateur][j] = stod(sligne);
indicateur++;
}*/