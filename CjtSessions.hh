/** @file CjtSessions.hh
    @brief Especificació de la classe CjtSessions.
*/

#ifndef _CJTSESSIONS_HH_
#define _CJTSESSIONS_HH_


#include "Sessio.hh"
#ifndef NO_DIAGRAM
#include <map>
#endif


/** @class CjtSessions
    @brief Representa un Conjunt de sessions (Sessio). 

*/
class CjtSessions
{
    
private:    

    map <string, Sessio> sessions;

public:
    
    //Constructora
    
    /** @brief Creadora por defecte.
        \pre <em>cert</em>.
        \post El resultat és un nou conjunt de Sessions.
    */

    CjtSessions();
    
    //Consultors

    /** @brief Consulta si la Sessió s existeix  <em>s</em>.
        \pre <em>cert</em>.
        \post Retorna si existeix.

    */

    bool existeix_sessio (const string& s) const;

    /** @brief Accedeix a la Sessió <em>s</em>.
        \pre La Sessió s existeix.
        \post Retorna la Sessió s.

    */

    Sessio accedir_sessio (const string& s);

    //Modificadorss
    
    /** @brief Afageix un sessio.
        \pre Els problemes existeixen i no estan repetits.
        \post Se ha creat la sessió. Imprimeix el numero de sessions Q després de crear-la.

    */

    void nova_sessio (const string & s);

    //Llegir

    /** @brief Llegeix les sessions inicials
        \pre <em>cert</em>.
        \post Guarda el repositrori inicial de sessions.

    */

    void llegir_sessions_inicials ();
    
    //Escriure

    /** @brief Llistat de Sessions.
        \pre <em>cert</em>.
        \post Es llisten totes les sessions en ordre creixent per l'identificador, mostrant el nombre de problemes
        que les formen i els seus identificadors, seguit de l'estructura de prequisits en preordre.
    */

    void llistat_sessions ();


};
#endif
