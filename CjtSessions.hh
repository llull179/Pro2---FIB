/** @file Sessio.hh
    @brief Especificació de la clase Sessio.
*/

#ifndef _Sessio_hh
#define _Sessio_hh

#ifndef NO_DIAGRAM
#include "CjtProblemes.hh"
#endif


/** @class Sessio.hh
    @brief Representa una SessioS. 

*/
class Sessio
{
    
private:    

    //list <string> problemes

public:
    
    //Constructora
    
    /** @brief Creadora por defecte.
        \pre <em>cert</em>
        \post El resultat és un nou Problema.
    */

    Sessio();
    
    //Consultora
    
    /** @brief Consultora de problemes.
        \pre <em>cert</em>
        \post El resultat indica si el parametre implícit conté el problema
    */

    bool consultar_problema (const string & p  ) const;
    
    //Modificadores
    
    /** @brief Afageix un sessio
        \pre Els problemes existeixen i no estan repetits
        \post Se ha creat la sessió, si ja existia imprimeix un 
        missatge d'error. Imprimeix el numero de sessions Q després de crear-la.

    */

    void nueva_session (const string & s);

    //Llegir i escriure

    /** @brief Llegeix les sessions inicials
        \pre cert
        \post Guarda el repositrori inicial de sessions.

    */

    void llegir_sessions_inicials (Sessio& s);
    
};
#endif
