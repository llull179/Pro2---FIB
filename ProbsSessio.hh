/** @file ProbsSessio.hh
    @brief Especificació de la classe ProbsSessio.
*/

#ifndef _PROBSSESSIO_HH_
#define _PROBSSESSIO_HH_


#ifndef NO_DIAGRAM
#include <map>
#include <string>
#include <iostream>
using namespace std;
#endif


/** @class ProbsSessio
    @brief Representa un Grup de problemes que pertanyen a un curs i la Sessió a la qual pertanyen. 

*/
class ProbsSessio
{
    
private:    
 //string = identificador problema,int = enviaments al problema
    map<string, string> probs_ses;   
//
public:
    
    //Constructora
    
    /** @brief Creadora por defecte.
        \pre <em>cert</em>.
        \post El resultat és un nou Grup de Problemes.
    */

    ProbsSessio();
    

    //Consultors

    /** @brief Retorna true si el map està buid.
        \pre <em>cert</em>.
        \post Retorna true si el map està buid.

    */

    bool empty() const;

    /** @brief Retorna la sessió a la qual pertany el problema.
        \pre <em>cert</em>.
        \post Retorna la sessió a la qual pertany el problema.

    */

    string retorna_sessio(const string& p) const;

    //Modificadors
    /** @brief Afegeix el problema p al grup de problemes amb la sessio s.
        \pre <em>cert</em>.
        \post Afegeix l'element p al grup de problemes amb la Sessió s.
    */

    bool afegeix_i_comprova(const string& p, const string& s);
    /** @brief Afegeix el problema p al grup de problemes amb la sessio s.
        \pre <em>cert</em>.
        \post Afegeix l'element p al grup de problemes amb la Sessió s.
    */

    void afegeix(const string& p, const string& s);

    

    //Escriure
     
void mostra();

};
#endif