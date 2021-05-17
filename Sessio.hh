/** @file Sessio.hh
    @brief Especificació de la classe Sessio.
*/

#ifndef _Sessio_HH_
#define _Sessio_HH_

#include "CjtProblemes.hh"
#include "GrupProb.hh"
#include "BinTree.hh"
#include "ProbsSessio.hh"
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
    static void iniciar_enviables_recursiu(const BinTree<string>& a, const GrupProb& resolts, GrupProb& env, bool acaba);
    static void recorrer(const BinTree<string>& a, ProbsSessio& probs, const string& s, bool& creable);
    static bool existeix_BinTree_prob(const BinTree<string>& a, const string& p);
public:
    
    //Constructora
    
    /** @brief Creadora por defecte.
        \pre <em>cert</em>.
        \post El resultat és una nova Sessió.
    */

    Sessio();

    Sessio(const string& x);
    

    //Consultors


    /** @brief Comprova si el problema p pertany a la Sessió
        \pre <em>cert</em>.
        \post Comprova si el problema p pertany a la Sessió
    */

    bool existeix_prob(const string& p);


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

    /** @brief Recorr el BinTree de prerequisits i afegeix a la classe ProbsSessio tots els problemes que pertanyen.
        \pre <em>cert</em>.
        \post Recorr el BinTree de prerequisits i afegeix a la classe ProbsSessio tots els problemes que pertanyen. 
        Retorna true si s'han pogut afegir tots els problemes fora intersecció i fals en cas contrari.
    */
    bool recorrer_i_afegir(ProbsSessio& probs);

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

    void escriure_sessio () const;
    
    
   

    
};
#endif