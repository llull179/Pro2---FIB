/** @file Usuari.hh
    @brief Especificació de la classe Usuari
*/

#ifndef _USUARI_HH_
#define _USUARI_HH_

#include "CjtCursos.hh"
#include "GrupProb.hh"

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
      int env_tot = 0; //enviaments totals
      int probs_intents = 0; // problemes intentats
      int curs_in = 0; //curs on l'usuari està inscrit
  } stats;

    GrupProb problemes_env;
    GrupProb problemes_exit;

public:

//Constructoras

/** @brief Creadora por defecto.

      S'executa automàticament al declarar un usuari.
      \pre <em>cert</em>.
      \post El resultat és un Usuari.
  */
 Usuari();


//Consultores

/** @brief Consulta si l'estudiante està inscrit a algun curso

      \pre <em>cierto</em>
      \post  Retorna l'identificador del curso en el que està inscrit l'Usuari o un 0 si no hi està.

  */
  int curs_inscrit( ) const;


  /** @brief Llista tots els problemes resolts per l'usuari

      \pre <em>cierto</em>.
      \post Llista en ordre creixent per identificador de tots els problemes solucionats.
        També s'imprimeix el nombre d'enviaments a cada problema.
  */
  void problemes_resolts ();

  /** @brief Llista tots els problemes enviats i resolts per l'usuari

      \pre <em>cierto</em>.
      \post Llista en ordre creixent per identificador de tots els problemes solucionats.
        També s'imprimeix el nombre d'enviaments a cada problema  resolt.
  */
  void problemes_enviables () ;


//Modificadores

/** @brief Inscriu l'usuari al curs amb identificador c.

      \pre <em>cierto</em>
      \post Inscriu l'usuari al curs c.
  */
  void inscribir_curso(int c, CjtSessions ses,  Curs curs);

    /** @brief Comprova quins problemes ja han estat resolts i actualitza la llista de problemes enviables.

      \pre <em>cierto</em>
      \post Comprova quins problemes ja han estat resolts i actualitza la llista de problemes enviables.
  */
    void propaga(const string& p,  CjtSessions cjtses,  CjtCursos cjtcurs);

  /** @brief Actualitza les estadístiques de l'Usuari.

      \pre p es el problema on ha fet l'enviament i r si l'ha completat amb èxit .
      \post Retorna l'Usuari amb les estadístiques actualitzades.
  */

  void actualitzar_stats(const string& p, int r, bool& cur_completat,  CjtSessions cjtses,  CjtCursos cjtcurs);

    //Escriure

    /** @brief Retorna les estadístiques d'un usuari.
        \pre <em>cert</em>.
        \post Mostran quants enviamnets ha realitzat en total, quants satisfactoriament, quants ha intentat
         almenys un cop i l'identificador de quin curs está inscrit o un 0 si no està inscrit a cap
    */

    void escriure_usuari ();

    
};
#endif
