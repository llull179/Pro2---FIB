/** @file Sessio.hh
    @brief Especificació de la classe Sessió.
*/

#ifndef _Sessio_hh
#define _Sessio_hh

#ifndef NO_DIAGRAM
#include "CjtProblemes.hh"
#include "BinTree.hh"
#endif


/** @class Sessio.hh
    @brief Representa una Sessió. 

*/
class Sessio
{
    
private:    

    //list <string> problemes

public:
    
    //Constructora
    
    /** @brief Creadora por defecte.
        \pre <em>cert</em>
        \post El resultat és un nou Problema.
    */

    Sessio();
    
    //Consultora
    
    /** @brief Consultora de problemes.
        \pre <em>cert</em>
        \post El resultat indica si el parametre implícit conté el problema
    */

    bool consultar_problema (const string & p  ) const;

    
    
    //Modificadores
    
    /** @brief Afageix un sessio
        \pre Els problemes existeixen i no estan repetits
        \post Se ha creat la sessió, si ja existia imprimeix un 
        missatge d'error. Imprimeix el numero de sessions Q després de crear-la.

    */

    void nova_sessio (const string & s);

    //Llegir

    /** @brief Llegeix les sessions inicials
        \pre cert
        \post Guarda el repositrori inicial de sessions.

    */

    void llegir_sessions_inicials (Sessio& s);
    
    //Escriure

    /** @brief Llistat de Sessions.
        \pre <em>cert</em>
        \post Es llisten totes les sessions en ordre creixent per l'identificador, mostrant el nombre de problemes
        que les formen i els seus identificadors, seguit de l'estructura de prequisits en preordre.
    */

    void llistat_sessions () const;

    /** @brief Retorna les estadístiques d'una sessió.
        \pre <em>cert</em>
        \post Si s no existeix s'imprimeix un miisatge d'error. S'imprimeix el nombre de problemes que formen
        la sessió i els seus identificadors, seguit de l'estructura de prequisits en preordre.
    */

    void escriure_sessio (const string s) const;
};
#endif
