/** @file Sessio.hh
    @brief Especificació de la classe Sessio.
*/

#ifndef _Sessio_HH_
#define _Sessio_HH_

#include "CjtProblemes.hh"
#include "GrupProb.hh"
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
    static void escriure_BinTree (const BinTree<string> & a);
    static void iniciar_enviables_recursiu(const BinTree<string>& a, const GrupProb& resolts, GrupProb& env);
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

    /** @brief  Retorna l'string de la posició x del map de tots els problemes del p.i.
        \pre <em>cert</em>.
        \post Retorna l'string de la posició x del map de tots els problemes del p.i.
    */
    string agafa_iessim(int x);

    /** @brief  Retorna l'arbre a partir del qual s'ha de recorrer perque els problemes anteriors ja s'han completat.
        \pre <em>cert</em>.
        \post Retorna l'arbre a partir del qual s'ha de recorrer perque els problemes anteriors ja s'han completat.
    */

     BinTree<string> cerca_subarbre(const BinTree<string>& a, const string& problema);
    //Modificadors
    
    /** @brief Actualitza tots els problemes enviables.
        \pre <em>cert</em>.
        \post Actualitza tots els problemes enviables
    */
    void actualitza_env(const GrupProb& resolts, GrupProb& env, const string& p );

    /** @brief Lletgeix els problemes de la sessió en preordre dels prerequisits.
        \pre <em>cert</em>.
        \post <em> a</em> es un BinTree amb tots els prerequisits dels problemes. L'arbre a tambées guarda als 
        prerequisits del p.i.
    */

    void lletgir_BinTree(BinTree<string>& a);

    /** @brief Inicialitza els problemes enviables quan un usuari s'inscriu a un curs
        \pre <em>cert</em>.
        \post Inicialitza els problemes enviables quan un usuari s'inscriu a un curs.
    */
    void iniciar_enviables(const GrupProb& resolts, GrupProb& env);

    

    //Escriure

    /** @brief Retorna les estadístiques d'una sessió.
        \pre <em>cert</em>.
        \post S'imprimeix el nombre de problemes que formen la sessió i els seus identificadors,
         seguit de l'estructura de prequisits en preordre.
    */

    void escriure_sessio () ;
    
    
   

    
};
#endif