#ifndef EXCEPTION
#define EXCEPTION
#include <iostream>
using namespace std;
#include <string.h>


#define TAILLE_MATRICE_INVALIDE 1

class CException
{
    private:
        unsigned int uiEXPtype;

    public:
        /**
         * @brief Construct a new CExeption object
         * 
         */
        CException();

        /**
         * @brief Construct a new CExeption object
         * 
         * @param uiType 
         */
        CException(unsigned int uiType);

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