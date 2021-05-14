/** @file GrupProb.hh
    @brief Especificació de la classe GrupProb.
*/

#ifndef _GRUPPROB_HH_
#define _GRUPPROB_HH_

#include "CjtProblemes.hh"
#include "BinTree.hh"
#ifndef NO_DIAGRAM
#endif


/** @class GrupProb
    @brief Representa un Grup d'un problema. 

*/
class GrupProb
{
    
private:    
 //string = identificador problema,int = enviaments al problema
    map<string, int> probs;
public:
    
    //Constructora
    
    /** @brief Creadora por defecte.
        \pre <em>cert</em>.
        \post El resultat és un nou Grup de Problemes.
    */

    GrupProb();
    

    //Consultors
    /** @brief Retorna quants d'elements pertanyen al grup.
        \pre <em>cert</em>.
        \post Retorna quants d'elements pertanyen al grup.
    */

    int get_size();

    /** @brief Retorna el numero d'intents que s'han realitzat a aquest problema.
        \pre <em>cert</em>.
        \post Retorna el numero d'intents que s'han realitzat a aquest problema..
    */

    int get_intents(const string& p);

    /** @brief Comrpova si el problema p pertany al p.i.
        \pre <em>cert</em>.
        \post Retorna true si el problema pertany al grup.
    */

    bool pertany(const string& p) const;
    //Modificadors
    /** @brief Afegeix l'elemetn p al grup de problemes.
        \pre <em>cert</em>.
        \post Afegeix l'element p al grup de problemes amb x entregues.
    */

    void afegeix(const string& p, int x);

    /** @brief Suma 1 intent al problema.
        \pre <em>cert</em>.
        \post Suma 1 intent al problema.
    */

    void suma_int(const string& p);

    /** @brief Elimina l'elemetn p del grup de problemes.
        \pre <em>cert</em>.
        \post Elimina l'element p del grup de problemes.
    */

    void elimina(const string& p);

    //Escriure
     /** @brief Escriu tots els problemes que pertanyen al grup de problemes i el nombre d'enviaments realitzats al problema.
        \pre <em>cert</em>.
        \post Escriu tots els problemes que pertanyen al grup de problemes i el nombre d'enviaments realitzats al problema.
    */

    void mostrar_problemes();


};
#endif