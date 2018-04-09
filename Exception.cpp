#include "Exception.hh"

/**
 * @brief Construct a new CExeption::CExeption object
 * 
 */
CException::CException()
{
    uiEXPtype = 0;
}
/**
 * @brief Construct a new CExeption::CExeption object
 * 
 * @param uiType
 */
CException::CException(unsigned int uiType)
{
    uiEXPtype = uiType;
}

/**
 * @brief uiEXPtype's getter
 * 
 * @return unsigned int 
 */
unsigned int CException::uiEXPgetType() 
{
    return uiEXPtype;
}

/**
 * @brief retourne un petit texte donnant le type d'exeption levée
 * 
 * @return char* 
 */
char * CException::sEXPmessageException()
{
    cout << "\nUne Exception a était levée : " << uiEXPtype << "\n";
}
