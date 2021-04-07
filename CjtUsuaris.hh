/** @file CjtUsuaris.hh
    @brief Especificació de la classe CjtUsuaris
*/

#ifndef _CJTUSUARIS_HH_
#define _CJTUSUARIS_HH_

#include "Usuari.hh"
#ifndef NO_DIAGRAM
#include <set>
#endif

/** @class CjtUsuaris
    @brief Representa el conjunt de tots els usuaris
    . 

    Conté Usuaris. 
*/
class CjtUsuaris
{
    
private:    

    set <Usuari> llistUsers;

public:
//Constructores

/** @brief Creadora per defecto. 

      S'executa automàticament al declarar el conjunto d'usuarios.
      \pre <em>cierto</em>
      \post El resultat és un conjunt d'usuaris.
  */ 
 CjtUsuaris();
 

//Consultors

/** @brief Comprova si ja existeix l'usuari u.

      \pre <em>cierto</em>
      \post Retorna true si existeix i fals si no existeix.
  */ 

bool existeix_usuari(const string& u) const;

/** @brief Llistat d'usuaris.
        \pre <em>cert</em>
        \post Es llisten tots els usuaris en ordre creixent pel nom, mostrant quants enviamnets ha realitzat
        en total, quants satisfactoriament, quants ha intentat almenys un cop i l'identificador de quin curs
        está inscrit o un 0 si no està inscrit a cap, per cada usuari.
    */

    void llistat_usuaris ();

    /** @brief Accedeix a l'Usuari <em>u</em>
        \pre L'Usuari u existeix.
        \post Retorna l'Usuari u.

    */

    Usuari& accedir_usuari (const string& s);

//Modificadors


/** @brief Dona d'alta un nou usuari 

      \pre <em>cierto</em>
      \post Si ja existia l'usuari <em>u</em> imprimeix un error, sinó imprimeix el número
      d'usuaris després d'afegir-lo.
  */ 

void alta_usuari(Usuari u);

/** @brief Dona de baixa un usuari 

      \pre L'Usuari existeix.
      \post Imprimeix el número d'usuaris després de donar-lo de baixa després d'eliminar u.
  */ 

void baixa_usuari(const string& u);

//Llegir i escriure

    /** @brief Llegeix els usuaris inicials
        \pre cert
        \post Guarda el conjunt d'usuaris inicials.

    */

    void llegir_usuaris_inicials ();
};
#endif