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
    @brief Representa una Sessio. 

*/
class Sessio
{
    
private:    
    string ident;
    BinTree <string> prerequisits;
    map<string, pair<string,string>> copia_pre;
public:
    
    //Constructora
    
    /** @brief Creadora por defecte.
        \pre <em>cert</em>.
        \post El resultat és una nova Sessió.
    */

    Sessio();
    

    //Consultors

     /** @brief Retorna la cantidad de problemes de la Sessió.
        \pre <em>cert</em>.
        \post Retorna la cantidad de problemes de la Sessió.
    */

    int get_size();
    
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


    /** @brief  Retorna l'string de la posició x del map de tots els problemes del p.i.
        \pre <em>cert</em>.
        \post Retorna l'string de la posició x del map de tots els problemes del p.i.
    */
    string agafa_iessim(int x);
    /** @brief  Retorna l'string de la posició x del map de tots els problemes del p.i.
        \pre <em>cert</em>.
        \post Retorna l'string de la posició x del map de tots els problemes del p.i.
    */
    string obtenir_arrel();
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


    pair<string,string> retorna_fills(const string& p);
    
};
#endif