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

    bool econsultar_problema (const string & p ) const;

    
    /** @brief Llistat de problemes.
        \pre <em>cert</em>
        \post Es llisten tots els problemes de la colecció inicant el nombre d'enviaments per cada problema,
        també s'indiquen els enviaments amb éxit i el ratio (t+1)/(e+1), es llisten en ordre creixent per ratio.
    */

    void llistat_problemes () const;

    /** @brief Retorna les estadístiques del problema.
        \pre <em>cert</em>
        \post Si p no existeix s'imprimeix un miisatge d'error. S'indica el nombre d'enviaments al problema,
        també s'indiquen els enviaments amb éxit i el ratio
    */

    void escriure_problema (const string p) const;
    
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
