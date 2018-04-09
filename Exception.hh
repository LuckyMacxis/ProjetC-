#ifndef EXCEPTION
#define EXCEPTION
#include <iostream>
using namespace std;
#include <string.h>

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
        char * sEXPmessageException();
};



#endif