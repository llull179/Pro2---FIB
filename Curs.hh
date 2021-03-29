/** @file CjtCursos.hh
    @brief Especificació de la clase CjtCursos.
*/

#ifndef _CjtCursos_hh_
#define _CjtCursos_hh_

#ifndef NO_DIAGRAM
#include "CjtSessions.hh"
#endif


/** @class CjtCursos
    @brief Representa un conjunt de cursos. 

*/
class CjtCUrsos
{
    
private:    

    //asdasd

public:
    
    //Constructora
    
    /** @brief Creadora por defecte.
        \pre <em>cert</em>
        \post El resultat és un nou conjunt de cursos.
    */

    CjtPCursos();
    
    //Consultora
    
    /** @brief Consultora de cursos.
        \pre <em>cert</em>
        \post El resultat indica si el curs c existeix.
    */

    bool existeix_curs (const int c ) const;
    
    //Modificadores
    
    /** @brief Afageix un nou curs
        \pre Es llegeix el numero de sessions S, i despres una seqüència de S sessions.
        \post Se ha afegit el curs amb identificadpr N+1 al paràmetre implícit, si no hi ha
        intersecció de problemes en les sessions, s'afageix el curs i s'imprimeix el seu identificador.
        En cas contrari s'imprimeix un missatge d'error

    */

    void nou_curs ();

    //Llegir i escriure

    /** @brief Llegeix els cursos inicials
        \pre cert
        \post Guarda el conjunt inicial de cursos.

    */

    void llegir_cursos_inicials (Sessio& s);
    
};
#endif
