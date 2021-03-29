/** @file CjtProblemes.hh
    @brief Especificació de la clase CjtProblema.
*/

#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

#ifndef NO_DIAGRAM
#include <string>
#include <list>
#endif


/** @class CjtProblemes
    @brief Representa un conjunt de problemes. 

*/
class CjtProblemes
{
    
private:    

    list <string> problemes;

public:
    
    //Constructora
    
    /** @brief Creadora por defecte.
        \pre <em>cert</em>
        \post El resultat és un nou Conjunt de Problemes.
    */

    CjtProblemes();
    
    //Consultora
    
    /** @brief Consultora de problemes.
        \pre <em>cert</em>
        \post El resultat indica si el parametre implícit conté el problema
    */

    bool consultar_problema (const string & p  ) const;
    
    //Modificadores
    
    /** @brief Afageix un problema
        \pre <em>cert</em>
        \post Se ha afegit el problema al paràmetre implícit, si ja existia imprimeix un 
        missatge d'error. Imprimeix el numero de problemes després d'afegir-lo.

    */

    void nuevo_problema (const string & p);

    //Llegir i escriure

    /** @brief Llegeix els problemes inicials
        \pre cert
        \post Guarda la colecció inicial de problemes.

    */

    void llegir_problemes_inicials (Sessio& s);
    
};
#endif
