/** @file Curs.hh
    @brief Especificació de la clase Curs.
*/

#ifndef _CURS_hh_
#define _CURS_hh_

#include "CjtSessions.hh"


/** @class CjtCurs
    @brief Representa un  cursos. 

*/
class Curs
{
    
private:    

    list <Sessio> sessions;
    pair <int, int> users;

public:
    
    //Constructor
    
    /** @brief Creadora per defecte.
        \pre <em>cert</em>
        \post El resultat és un nou cursos.
    */

    Curs();
    
    //Consultors

    /** @brief Troba la sessió a la qual pertany el problema <em>p</em> al curs.
        \pre El problema p existeix.
        \post Retorna l'identificador de la Sessió a la qual pertany el problema
    */

    string trobar_sessio (const string& p) const;

    //Modificadors
    

    //Llegir i escriure

    /** @brief Retorna les estadístiques d'un curs.
        \pre <em>cert</em>
        \post Mostra el nombre d'usuaris actuals o passats que l'han completat, el nombre d'usuaris inscirts 
        actualment i els seus identificadors, seguit del nombre de sessions que el formen i els seus identificadors.
    */

    void escriure_curs () const;
    
};
#endif
