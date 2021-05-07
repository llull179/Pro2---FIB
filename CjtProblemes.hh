/** @file CjtProblemes.hh
    @brief Especificació de la clase CjtProblemes.
*/

#ifndef _CJTPROBLEMES_HH_
#define _CJTPROBLEMES_HH_

#include "Problema.hh"
#ifndef NO_DIAGRAM
#include <map>
#include <vector>
#include <algorithm>
#endif


/** @class CjtProblemes
    @brief Representa un conjunt de problemes (Problema).

*/
class CjtProblemes
{

private:
    vector<pair<string,Problema>> prob_ord;
    map<string,Problema> problemes;
    Problema nulo;
    static bool cmp (const pair<string,Problema>& a, const pair<string,Problema>& b);
public:

    //Constructora

    /** @brief Creadora por defecte.
        \pre <em>cert</em>.
        \post El resultat és un nou Conjunt de Problemes.
    */

    CjtProblemes();

    //Consultors
    
    
    /** @brief Consultora de problemes.
        \pre <em>cert</em>.
        \post El resultat indica si el parametre implícit conté el problema
    */

    bool existeix_problema (const string& p ) const;


    /** @brief Accedeix a al Problema <em>p</em>
        \pre El Problema p existeix.
        \post Retorna el Problema p.

    */

    Problema& accedir_problema (const string& p, bool& found);

    //Modificadores

    /** @brief Afageix un problema
        \pre El problema <em>p</em> p existeix.
        \post S'ha afegit el problema al paràmetre implícit. Imprimeix el numero de problemes després d'afegir-lo.

    */

    void nou_problema (const string & p);

    //Llegir

    /** @brief Llegeix els problemes inicials
        \pre <em>cert</em>.
        \post Guarda la colecció inicial de problemes.

    */

    void llegir_problemes_inicials ();

    //Escriure

    /** @brief Llistat de problemes.
        \pre <em>cert</em>.
        \post Es llisten tots els problemes de la colecció inicant el nombre d'enviaments per cada problema,
        també s'indiquen els enviaments amb éxit i el ratio (t+1)/(e+1), es llisten en ordre creixent per ratio.
    */

    void llistat_problemes ();

    /** @brief Ordenar problemes.
        \pre <em>cert</em>.
        \post Guarda els problemes del map al vector de manera ordenada
    */

    void ordenar_problemes ();

};
#endif
