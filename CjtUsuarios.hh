/** @file CjtUsuarios.hh
    @brief Especificació de la classe CjtUsuarios
*/

#ifndef _CJTUSUARIS_HH_
#define _CJTUSUARIS_HH_

#include "Usuario.hh"

/** @class CjtUsuarios
    @brief Representa el conjunto de todos los usuarios
    . 

    Contiene Usuarios. 
*/

//Constructoras

/** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar el conjunto de usuarios.
      \pre <em>cierto</em>
      \post El resultado es un conjunto de usuarios.
  */ 
 CjtUsuarios();
 

//Consultores

/** @brief Comprova si ja existeix l'usuari u.

      \pre <em>cierto</em>
      \post Retorna true si existeix i fals si no existeix.
  */ 

bool existeix_usuari(int u);



//Modificadores


/** @brief Dona d'alta un nou usuari 

      \pre <em>cierto</em>
      \post Si ja existia l'usuari <em>u</em> imrpimeix un error, sinó imprimeix el número
      d'usuaris després d'afegir-lo.
  */ 

void alta_usuari(int u);

/** @brief Dona d'alta un nou usuari 

      \pre <em>cierto</em>
      \post Si no existia l'usuari <em>u</em> imrpimeix un error, sinó imprimeix el número
      d'usuaris després de donar-lo de baixa.
  */ 

void baixa_usuari(int u);

//Llegir i escriure

    /** @brief Llegeix els usuaris inicials
        \pre cert
        \post Guarda el conjunt d'usuaris inicials.

    */

    void llegir_usuaris_inicials (Sessio& s);

#endif