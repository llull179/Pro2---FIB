/** @file Usuari.hh
    @brief Especificació de la classe Usuari
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
using namespace std;
#endif

/** @class Usuari
    @brief Representa un Usuari.

*/
class Usuari
{
    
private:    

  struct {
      string name;
      int env_tot = 0;
      int prob_resolt = 0;
      int prob_int = 0;
      int curs_in = 0;
  } stats;

 //string = identificador problema,int = enviaments al problema
    map <string, int> problemes_env;
    map <string, int> problemes_exit;

public:
//Constructoras

/** @brief Creadora por defecto. 

      S'executa automàticament al declarar un usuari.
      \pre <em>cierto</em>
      \post El resultat és un usuari.
  */ 
 Usuari();

 /** @brief Creadora amb identificador. 

      \pre <em>cert</em>
      \post El resultat és un usuari amb identificador <em>u<em>
  */ 
 Usuari(const string& u);

//Consultores

/** @brief Consulta si l'estudiante està inscrit a algun curso

      \pre <em>cierto</em>
      \post  Retorna l'identificador del curso en el que està inscrit l'Usuari o un 0 si no hi està.
        inscrito en ninguno.    
  */
  int esta_inscrit( ) const;


  /** @brief Consultora curs completat

      \pre El curs c existeix, el;
      \post Comprova si l'usuari ja ha completat el curs, revisant si els problemes enviables = 0.
       En cas afirmatiu l'usuari deixa d'estar inscrit al curs.
  */
  bool curs_completat () const;

  /** @brief Llista tots els problemes resolts per l'usuari

      \pre <em>cierto</em>
      \post llista en ordre creixent per identificador de tots els problemes solucionats.
        També s'imprimeix el nombre d'enviaments a cada problema.
  */
  void problemes_resolts () const;

  /** @brief Llista tots els problemes enviats i no resolts per l'usuari

      \pre <em>cierto</em>
      \post llista en ordre creixent per identificador de tots els problemes no solucionats.
        També s'imprimeix el nombre d'enviaments a cada problema no resolt.
  */
  void problemes_enviables () const;


//Modificadores

/** @brief Inscriu l'usuari al curs amb identificador c.

      \pre <em>cierto</em>
      \post Inscriu l'usuari al curs c.    
  */
  void inscribir_curso(int c);


  /** @brief Actualitza les estadístiques de l'Usuari.

      \pre p es el problema on ha fet l'enviament i r si l'ha completat amb èxit .
      \post Retorna l'Usuari amb les estadístiques actualitzades.    
  */
  
  void actualitzar_stats(int p, int r);

    //Escriure

    /** @brief Retorna les estadístiques d'un usuari.
        \pre <em>cert</em>
        \post Mostran quants enviamnets ha realitzat en total, quants satisfactoriament, quants ha intentat
         almenys un cop i l'identificador de quin curs está inscrit o un 0 si no està inscrit a cap
    */

    void escriure_usuari ();
};
#endif