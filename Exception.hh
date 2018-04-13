#ifndef EXCEPTION
#define EXCEPTION
#include <iostream>
using namespace std;
#include <string.h>


#define TAILLE_MATRICE_INVALIDE 1
#define DIVISION_PAR_ZERO 2

class CException
{
    private:
        unsigned int uiEXPtype;
        string sEXPmessage;

    public:
        /**
         * @brief Construit un nouvel objet CException sans paramettre
         * 
         */
        CException();

        /**
         * @brief Construit un nouvel object CException a partir d'un int
         * 
         * @param uiType un int
         */
        CException(unsigned int uiType);

        /**
         * @brief Construit un nouvel object CException a partir d'un string
         * 
         * @param sTxt Message de l'exception
         */
        CException(string sTxt);

        /**
         * @brief uiEXPtype's getter
         * 
         * @return unsigned int 
         */
        unsigned int uiEXPgetType();

        /**
         * @brief retourne un petit texte donnant le type d'exeption levé
         * 
         * @return char* 
         */
        void sEXPmessageException();
};



#endif