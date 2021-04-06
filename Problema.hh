/** @file Problema.hh
    @brief Especificació de la clase Problema.
*/

#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif


/** @class Problema
    @brief Representa un Problema. 

*/
class Problema
{
    
private:    
    string ident;
    map <string, int> estadist;
    estadist['env_total'] = 0;
    estadist['env_exit'] = 0;
    estadist['ratio'] = 0;
    bool operator<(const Problema &d) const;

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

    Problema(const string & p);
    
    //Consultorss
    
    /** @brief Ordena el set dels problemes
        \pre Cert
        \post Set ordenat.

    */
    bool operator<(const Problema &d);

    //Modificadors
    
    /** @brief Actualitza les estadístiques del problema
        \pre El problema p existeix.
        \post S'actualitzen el nombre d'enviaments total, amb éxit i el ratio.

    */

    void actualitzar_problema ();


    //Escriure


    /** @brief Retorna les estadístiques del problema.
        \pre <em>cert</em>
        \post Si p no existeix s'imprimeix un misatge d'error. S'indica el nombre d'enviaments al problema,
        també s'indiquen els enviaments amb éxit i el ratio
    */

    void escriure_problema () const;
    
};
#endif
