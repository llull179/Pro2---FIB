/** @file Usuari.hh
    @brief Especificació de la classe Usuari
*/

#ifndef _USUARI_HH_
#define _USUARI_HH_

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
      int intents = 0;
      int curs_in = 0;
  } stats;

 //string = identificador problema,int = enviaments al problema
    map <string, int> problemes_env;
    map <string, int> problemes_exit;

public:
//Constructoras

/** @brief Creadora por defecto. 

      S'executa automàticament al declarar un usuari.
      \pre <em>cert</em>.
      \post El resultat és un Usuari.
  */ 
 Usuari();

 /** @brief Creadora amb identificador. 

      \pre <em>cert</em>.
      \post El resultat és un Usuari amb identificador <em>u<em>
  */ 
 Usuari(const string& u);

//Consultores

/** @brief Consulta si l'estudiante està inscrit a algun curso

      \pre <em>cierto</em>
      \post  Retorna l'identificador del curso en el que està inscrit l'Usuari o un 0 si no hi està.
        
  */
  int esta_inscrit( ) const;


  /** @brief Consultora curs completat

      \pre El curs <em>c</em> existeix.
      \post Comprova si l'usuari ja ha completat el curs, revisant si els problemes enviables = 0.
       En cas afirmatiu l'usuari deixa d'estar inscrit al curs.
  */
  bool curs_completat () const;

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
  void problemes_enviables () const;

    /** @brief Retorna el nom de l'usuari.

      \pre <em>cierto</em>.
      \post Retorna el nom de l'usuari.
  */
  string consultar_nom () const;


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
  
  void actualitzar_stats(string p, int r);

    //Escriure

    /** @brief Retorna les estadístiques d'un usuari.
        \pre <em>cert</em>.
        \post Mostran quants enviamnets ha realitzat en total, quants satisfactoriament, quants ha intentat
         almenys un cop i l'identificador de quin curs está inscrit o un 0 si no està inscrit a cap
    */

    void escriure_usuari ();
};
#endif