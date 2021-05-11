/** @file CjtCursos.hh
    @brief Especificació de la clase CjtCursos.
*/

#ifndef _CJTCURSOS_HH_
#define _CJTCURSOS_HH_

#ifndef NO_DIAGRAM
#include <vector>
#endif
#include "Curs.hh"


/** @class CjtCursos
    @brief Representa un conjunt de cursos (Curs).

*/
class CjtCursos
{

private:

    vector <Curs> cursos;

public:

    //Constructor

    /** @brief Creadora per defecte.
        \pre <em>cert</em>.
        \post El resultat és un nou conjunt de cursos.
    */

    CjtCursos();

    //Consultors

    /** @brief Consultora de cursos.
        \pre <em>cert</em>.
        \post El resultat indica si el curs c existeix.
    */

    bool existeix_curs ( int c ) const;

    /** @brief Accedeix al Curs <em>c</em>
        \pre El Curs c existeix.
        \post Retorna el Curs c.

    */

    Curs& accedir_curs ( int c );

    /** @brief Llistat de cursos.
        \pre <em>cert</em>.
        \post Es llisten tots els cursos en ordre creixent per l'identificador, mostrant el nombre d'usuaris actuals
        o passats que l'han completat, el nombre d'usuaris inscrits actualment i els seus identificadors,
        seguit del nombre de sessions que el formen i els seus identificadors.
    */

    void llistat_cursos () const;



    //Modificadors

    /** @brief Afageix un nou curs
        \pre El curs compleix les condicions per ser creat
        \post Se ha afegit el curs amb identificador N+1 al paràmetre implícit,
        i s'imprimeix el seu identificador.
        En cas contrari s'imprimeix un missatge d'error.

    */

    void nou_curs (const Curs& c);

    //Llegir i escriure

    /** @brief Llegeix els cursos inicials
        \pre cert
        \post Guarda el conjunt inicial de cursos.

    */

    void llegir_cursos_inicials (CjtSessions cjtses);

};
#endif
