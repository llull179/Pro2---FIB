/** @file Curs.hh
    @brief Especificació de la clase Curs.
*/

#ifndef _CURS_HH_
#define _CURS_HH_

#include "CjtSessions.hh"
#ifndef NO_DIAGRAM

#endif


/** @class Curs
    @brief Representa un  Curs. 

*/
class Curs
{
    
private:    

    vector <string> sessions;
    pair <int, int> users;

public:
    
    //Constructor
    
    /** @brief Creadora per defecte.
        \pre <em>cert</em>.
        \post El resultat és un nou curs.
    */

    Curs();
    
    //Consultors

    /** @brief Ret
        \pre El problema p existeix.
        \post Retorna l'identificador de la Sessió a la qual pertany el problema.
    */

    string trobar_sessio (int x);

    //Modificadors
    
    /** @brief Afegir la Sessio <em> s </em> al curs del p.i
        \pre La Sessio s existeix.
        \post Retonra el curs amb la Sessió afegida
    */


    void lletgir_sessions ();

    //Llegir i escriure

    /** @brief Retorna les estadístiques d'un curs.
        \pre <em>cert</em>
        \post Mostra el nombre d'usuaris actuals o passats que l'han completat, el nombre d'usuaris inscirts 
        actualment i els seus identificadors, seguit del nombre de sessions que el formen i els seus identificadors.
    */

    void escriure_curs () const;
    
};
#endif
