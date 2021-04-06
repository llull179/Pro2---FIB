/** @file Sessio.hh
    @brief Especificació de la classe Sessió.
*/

#ifndef _Sessio_hh
#define _Sessio_hh

#ifndef NO_DIAGRAM
#include "CjtProblemes.hh"
#include "BinTree.hh"
#include <list>
#endif


/** @class Sessio.hh
    @brief Representa una Sessió. 

*/
class Sessio
{
    
private:    

    list <int> problemes;

public:
    
    //Constructora
    
    /** @brief Creadora por defecte.
        \pre <em>cert</em>
        \post El resultat és un nou Problema.
    */

    Sessio();
    
    //Consultors

    
    //Modificadors
    
    
    //Escriure

    /** @brief Retorna les estadístiques d'una sessió.
        \pre <em>cert</em>
        \post Si s no existeix s'imprimeix un miisatge d'error. S'imprimeix el nombre de problemes que formen
        la sessió i els seus identificadors, seguit de l'estructura de prequisits en preordre.
    */

    void escriure_sessio () const;
};
#endif
