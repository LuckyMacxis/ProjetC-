#include "Exception.hh"

/**
 * @brief Construit un nouvel objet CException sans paramettre
 * 
 */
CException::CException()
{
    sEXPmessage = "";
    uiEXPtype = 0;
}

/**
 * @brief Construit un nouvel object CException a partir d'un string
 * 
 * @param sTxt Message de l'exception
 */
CException::CException(string sTxt){
    sEXPmessage = sTxt;
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
void CException::sEXPmessageException()
{
    if (sEXPmessage == "" ){
        cout << "\nUne Exception a était levée. Exception du type : " << uiEXPtype << "\n";
    }else{
        cout << sEXPmessage;
    }
        
}
