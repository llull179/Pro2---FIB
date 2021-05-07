/** @file Problema.hh
    @brief Especificació de la classe Problema.
*/
#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
using namespace std;
#endif


/** @class Problema
    @brief Representa un Problema.

*/
class Problema
{

private:

    struct{
        double env_totals = 0;
        double env_exit = 0;
        double ratio = 1;
    } stats;

public:

    //Constructora

    /** @brief Creadora per defecte.
        \pre <em>cert</em>
        \post El resultat és un nou Problema.
    */

    Problema();


    //Consultors

    /** @brief Retorna el ratio del problema.
        \pre <em>cert</em>.
        \post Retrona el ratio del problema
    */

    void escriure_problema () const;

    /** @brief Retorna el ratio del problema.
        \pre <em>cert</em>.
        \post Retorna el ratio del problema.
    */

    int get_ratio () const;

    //Modificadors

    /** @brief Actualitza les estadístiques del problema
        \pre El problema p existeix, r és si s'ha completat amb èxit el problema.
        \post Es suma 1 al nombre d'enviaments total,  s'actualitza els enviaments amb èxit i el ratio.

    */

    void actualitzar_stats (bool r);

    //Escriure

    /** @brief Retorna les estadístiques del problema.
        \pre <em>cert</em>.
        \post Si p no existeix s'imprimeix un misatge d'error. S'indica el nombre d'enviaments al problema,
        també s'indiquen els enviaments amb èxit i el ratio
    */

    void escriure_problema ();


};
#endif
