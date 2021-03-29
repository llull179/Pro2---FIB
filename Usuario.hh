/** @file Usuario.hh
    @brief Especificació de la classe Usuario
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#include <iostream>
using namespace std;

/** @class Usuario
    @brief Representa un Usuario
    . 

    asdasd. 
*/

//Constructoras

/** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un usuario.
      \pre <em>cierto</em>
      \post El resultado es un usuario
  */ 
 Usuario();

 /** @brief Creadora con identificador. 

      \pre <em>cierto</em>
      \post El resultado es un usuario con identificador <em>u<em>
  */ 
 Usuario(int u);

//Consultores

/** @brief Consulta si el estudiante esta inscrito a algún curso

      \pre <em>cierto</em>
      \post Si el usuario no existe se imprime un error. En caso contrario, devuelve el
       identiificador del curso en el que esta inscrito el usuario o un 0 si no está 
        inscrito en ninguno.    
  */
  int esta_inscrito() const;

  void problemes_resolts () const;

  /** @brief Consultora curs completat

      \pre <em>cierto</em>
      \post Comprova si l'usuari ja ha completat el curs c.
  */
  void curs_completat (int c) const;

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
  void problemes_resolts () const;

//Modificadores

/** @brief Inscriu l'usuari al curs amb identificador c.

      \pre <em>cierto</em>
      \post Si l'usuari no existeix,està inscrit a un curs no finalitzat o el curs no existeix, 
      imprimeix un erros. En cas contrari s'imprimeix el número d'usuaris inscrits al curs c.    
  */
  void inscribir_curso(int c) const;

  /** @brief Inscriu l'usuari al curs amb identificador c.

      \pre r es el resultat, 1 resolt i 0 fallo. Es garantitza que l'usuari existeix i que
      està inscrit al curs on es situa el problema, a més el problema forma part del conjunt
      el qual l'usuari pot enviar la solució per els prerequisits.
      \post S'actualitzen les estadístiques de l'usuari i comprova si ha completat el curs.    
  */
  void envio_problema(int p, int r) const;

// Escritura y lectura

  /** @brief Operación de escritura

      \pre El parámetro implícito existe
      \post Escribe el identificador <em>u<em> del usuario.
  */
  void escribir() const;

#endif