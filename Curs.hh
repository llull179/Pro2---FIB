/** @file Curs.hh
    @brief Especificació de la clase Curs.
*/

#ifndef _CURS_HH_
#define _CURS_HH_

#include "CjtSessions.hh"



/** @class Curs
    @brief Representa un  Curs. 

*/
class Curs
{
    
private:    

    vector <string> sessions;
    //first: usuaris copletat el curs; second: usuaris inscrits actualment
    pair <int, int> users;

public:
    
    //Constructor
    
    /** @brief Creadora per defecte.
        \pre <em>cert</em>.
        \post El resultat és un nou curs.
    */

    Curs();
    
    //Consultors

    /** @brief Crea un vector amb les sesions que conté el curs c
        \pre <em>cert</em>
        \post Retorna un vector amb les Sesions del p.i.
    */
    vector<string> llista_sesions();

    //Modificadors
    
    /** @brief Afegir la Sessio <em> s </em> al curs del p.i
        \pre La Sessio s existeix.
        \post Retorna el curs amb la Sessió afegida
    */


    void lletgir_sessions ();

    //Llegir i escriure

    /** @brief Retorna les estadístiques d'un curs.
        \pre <em>cert</em>
        \post Mostra el nombre d'usuaris actuals o passats que l'han completat, el nombre d'usuaris inscirts 
        actualment i els seus identificadors, seguit del nombre de sessions que el formen i els seus identificadors.
    */

    void escriure_curs () const;
    
    /** @brief Actualitza el nombre d'usuaris inscrits a un curs.
        \pre <em>cert</em>
        \post Suma als usuaris iscrits al p.i el nombre x.
    */

    void act_inscrits (int x);
    /** @brief Retorna el nombre d'usuaris inscrits.
        \pre <em>cert</em>
        \post Retorna el nombre d'usuaris inscrits.
    */

    int usuaris_inscrits ();
};
#endif
