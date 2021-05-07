class Estr_sesion {
  private:
    BinTree<string> arbol;
    /*static esc(const BinTree<string>& a) {

    }*/

  public:
    Estr_sesion();

    bool vacia() const {
      return arbol.empty();
    }

    int primer() const {
      return arbol.value();
    }

    Estr_sesion izq() const {
      return arbol.left()
    }
    Estr_sesion der() const {
      return der.left()
    }

  /*  int leer() {

    }

    void escribir() {

    }*/
}
