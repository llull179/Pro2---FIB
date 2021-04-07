/** @file CjtProblemes.hh
    @brief Especificació de la clase CjtProblema.
*/

#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

#include "Problema.hh"
#ifndef NO_DIAGRAM
#include <set>
#endif


/** @class CjtProblemes
    @brief Representa un conjunt de problemes. 

*/
class CjtProblemes
{
    
private:    
    set <Problema> problemes;

public:
    
    //Constructora
    
    /** @brief Creadora por defecte.
        \pre <em>cert</em>
        \post El resultat és un nou Conjunt de Problemes.
    */

    CjtProblemes();
    
    //Consultors
    
    /** @brief Consultora de problemes.
        \pre <em>cert</em>
        \post El resultat indica si el parametre implícit conté el problema
    */

    bool existeix_problema (const string & p ) const;

    
    /** @brief Accedeix a al Problema <em>p</em>
        \pre El Problema p existeix.
        \post Retorna el Problema p.

    */

    Problema& accedir_problema (const string& p);
    
    //Modificadores
    
    /** @brief Afageix un problema
        \pre <em>p</em> p no existeix.
        \post S'ha afegit el problema al paràmetre implícit. Imprimeix el numero de problemes després d'afegir-lo.

    */

    void nou_problema (const string & p);

    //Llegir

    /** @brief Llegeix els problemes inicials
        \pre cert
        \post Guarda la colecció inicial de problemes.

    */

    void llegir_problemes_inicials ();

    //Escriure

    /** @brief Llistat de problemes.
        \pre <em>cert</em>
        \post Es llisten tots els problemes de la colecció inicant el nombre d'enviaments per cada problema,
        també s'indiquen els enviaments amb éxit i el ratio (t+1)/(e+1), es llisten en ordre creixent per ratio.
    */

    void llistat_problemes () const;
    
};
#endif
