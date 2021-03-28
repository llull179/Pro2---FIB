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
      \post El resultado indica si el parámetro implícito está inscrito a algún curso 
  */
  bool esta_inscrito() const;

//Modificadores


// Escritura y lectura

  /** @brief Operación de escritura

      \pre El parámetro implícito existe
      \post Escribe el identificador <em>u<em> del usuario.
  */
  void escribir() const;

#endif