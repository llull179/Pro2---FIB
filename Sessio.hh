/** @file Sessio.hh
    @brief Especificació de la classe Sessio.
*/

#ifndef _Sessio_HH_
#define _Sessio_HH_

#include "CjtProblemes.hh"
#include "BinTree.hh"
#ifndef NO_DIAGRAM
#endif


/** @class Sessio
    @brief Representa una Sessió. 

*/
class Sessio
{
    
private:    
    string ident;
    BinTree <string> prerequisits;
public:
    
    //Constructora
    
    /** @brief Creadora por defecte.
        \pre <em>cert</em>.
        \post El resultat és una nova Sessió.
    */

    Sessio();
    
    /** @brief Creadora amb BinTree.
        \pre <em>cert</em>.
        \post El resultat és una nova Sessió amb els prerequisits dels problemes.
    */

    Sessio(BinTree<string> a);

    //Consultors

     /** @brief Comprova la grandaria del BinTree.
        \pre <em>cert</em>.
        \post Retorna el nombre de problemes que conté el BinTree.
    */

    int BinTree_size(const BinTree<string>& a);
    
    /** @brief Comprova si el problema pertany al p.i.
        \pre <em>cert</em>.
        \post Retorna true si pertany i false en cas contrari.
    */ 

    bool trobar_problema(const string& p) ;

    /** @brief Comprova si el valor <em>p</em> pertany al p.i.
        \pre <em>cert</em>.
        \post Retorna true si pertany i false en cas contrari.
    */

    bool trobar_valor_BinTree(const BinTree<string>& a, const string& p);
    //Modificadors
    
    /** @brief Lletgeix els problemes de la sessió en preordre dels prerequisits.
        \pre <em>cert</em>.
        \post <em> a</em> es un BinTree amb tots els prerequisits dels problemes. L'arbre a tambées guarda als 
        prerequisits del p.i.
    */

    void lletgir_BinTree(BinTree<string>& a);


    //Escriure

    /** @brief Retorna les estadístiques d'una sessió.
        \pre <em>cert</em>.
        \post S'imprimeix el nombre de problemes que formen la sessió i els seus identificadors,
         seguit de l'estructura de prequisits en preordre.
    */

    void escriure_sessio () ;

    /** @brief Escriu els problemes de la sessió en preordre dels prerequisits.
        \pre <em>cert</em>.
        \post Escriu una llista de problemes seguint l'ordre dels prerequisits 
    */

    void escriure_BinTree (const BinTree<string> & a) const;
};
#endif
