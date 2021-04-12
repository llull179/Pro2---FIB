/** @file Problema.hh
    @brief Especificació de la classe Problema.
*/
#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

#include "Problema.hh"
#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
using namespace std;
#endif


/** @class Problema.hh
    @brief Representa un Problema. 

*/
class Problema
{
    
private:    

    struct{
        string ident;
        int env_totals = 0;
        int env_exit = 0;
        int ratio = 0;
    } stats;

public:
    
    //Constructora
    
    /** @brief Creadora per defecte.
        \pre <em>cert</em>
        \post El resultat és un nou Problema.
    */

    Problema();

    
    /** @brief Creadora amb identificador.
        \pre <em>cert</em>
        \post El resultat és un nou Problema amb un idetificador <em>p</em>.
    */

    Problema(const string& p);
    
    //Consultors

    /** @brief Comprova l'identificador del problema..
        \pre <em>cert</em>
        \post retorna l'identificador (stats.ident) del <em>p.i</em>.
    */

    string consultar_ident() const;

    //Modificadors
    
    /** @brief Actualitza les estadístiques del problema
        \pre El problema p existeix, r és si s'ha completat amb èxit el problema.
        \post Es suma 1 al nombre d'enviaments total,  s'actualitza els enviaments amb éxit i el ratio.

    */

    void actualitzar_stats (bool r);
    
    //Escriure

    /** @brief Retorna les estadístiques del problema.
        \pre <em>cert</em>
        \post Si p no existeix s'imprimeix un misatge d'error. S'indica el nombre d'enviaments al problema,
        també s'indiquen els enviaments amb éxit i el ratio
    */

    void escriure_problema () const;


};
#endif
