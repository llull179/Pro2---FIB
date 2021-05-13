/** @file CjtUsuaris.hh
    @brief Especificació de la classe CjtUsuaris
*/

#ifndef _CJTUSUARIS_HH_
#define _CJTUSUARIS_HH_

#include "Usuari.hh"

/** @class CjtUsuaris
    @brief Representa el conjunt de tots els usuaris (Usuari).
    . 

    Conté Usuaris. 
*/
class CjtUsuaris
{
    
private:    

    map <string, Usuari> llistUsers;
    Usuari nulo; 
public:
//Constructores

/** @brief Creadora per defecto. 

      S'executa automàticament al declarar el conjunto d'usuarios.
      \pre <em>cert</em>.
      \post El resultat és un conjunt d'usuaris ( CjtUsuaris).
  */ 
 CjtUsuaris();
 

//Consultors

/** @brief Llistat d'usuaris.
        \pre <em>cert</em>
        \post Es llisten tots els usuaris en ordre creixent pel nom, mostrant quants enviamnets ha realitzat
        en total, quants satisfactoriament, quants ha intentat almenys un cop i l'identificador de quin curs
        está inscrit o un 0 si no està inscrit a cap, per cada usuari.
    */

    void llistat_usuaris () ;

    /** @brief Accedeix a l'Usuari <em>u</em>
        \pre cert
        \post Comprova si l'usuari u existeix, si és així copia l'usuari al p.i i retorna true
        en cas contrari retorna false

    */

     Usuari& accedir_usuari ( const string& s, bool & found);

//Modificadors


/** @brief Dona d'alta un nou usuari 

      \pre <em>cert</em>.
      \post Si ja existia l'usuari <em>u</em> imprimeix un error, sinó imprimeix el número
      d'usuaris després d'afegir-lo.
  */ 

bool alta_usuari(const string& u);

/** @brief Dona de baixa un usuari 

      \pre L'Usuari existeix.
      \post Imprimeix el número d'usuaris després de donar-lo de baixa després d'eliminar u.
  */ 

bool baixa_usuari(const string& u, int& inscrit);

//Llegir i escriure

    /** @brief Llegeix els usuaris inicials
        \pre cert
        \post Guarda el conjunt d'usuaris inicials.

    */

    void llegir_usuaris_inicials ();
};
#endif