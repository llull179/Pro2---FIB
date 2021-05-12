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
    //firs:problema, second:sessio a la que pertany
    map<string, string> problemes;
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

    /** @brief Comprova si el curs es pot crear.
        \pre <em>cert</em>
        \post Recorr les sesions del curs per comprovar que no hi hagui interessecció entre problemes,
        a més crea un map amb tots els problemes del curs i un vectir amb totes les sessions
    */

    bool curs_pot_crear(CjtSessions cjtses);



    /** @brief Retorna una string amb la sessio a la qual pertany el problema <em>p</em>
        \pre <em>cert</em>
        \post Retorna una string amb la sessio a la qual pertany el problema <em>p</em>
    */
    string retorna_sessio(const string& p);

    //Modificadors

   /** @brief Actualitza el curs després de ser completat per un usuari
        \pre cert.
        \post Suma 1 als usuaris completats i resta 1 als usuaris inscrits.
    */
   void actualitzar_completat();


    /*void lletgir_sessions ();*/

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
