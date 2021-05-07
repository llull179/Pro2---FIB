/** @file Curs.hh
    @brief Especificació de la clase Curs.
*/

#ifndef _CURS_HH_
#define _CURS_HH_

#include "CjtSessions.hh"



/** @    @brief     @brief Representa un  Curs. 

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

    /** @brief Retorna el nombre de sesions que te el curs
        \pre <em>cert</em>
        \post Retorna la mida del vector sessions del p.i.
    */
    int num_sessions();

    /** @brief Retorna la sessio numero i del curs
        \pre <em>cert</em>
        \post Retorna la sessio numero i del curs
    */
    string get_sessio(int i);

    /** @brief CComprova si el curs compleix les condicions per ser creat
        \pre <em>cert</em>
        \post Retorna true si el curs no te cap interessció de problesmes.
    */

    bool curs_pot_crear() const;

    /** @brief Crea un vector amb les sesions que conté el curs c
        \pre <em>cert</em>
        \post Retorna un vector amb les Sesions del p.i.
    */
    vector<string> llista_sesions();

    /** @brief Retorna una string amb la sessio a la qual pertany el problema <em>p</em>
        \pre <em>cert</em>
        \post Retorna una string amb la sessio a la qual pertany el problema <em>p</em>
    */
    string retorna_sessio(CjtSessions cs,const string& s);

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
