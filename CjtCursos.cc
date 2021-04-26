#include "CjtCursos.hh"

CjtCursos::CjtCursos() {}

bool CjtCursos::existeix_curs(int c) const{
    if(cursos.size() >= c) return true;
    else return false;
}

 Curs& CjtCursos::accedir_curs (int c){
    return cursos[c-1];
}

void CjtCursos::llistat_cursos () const {
    for (int i = 0; i < cursos.size(); ++i) {
        cout << "Curs" << i+1 <<endl;
        cursos[i].escriure_curs();
    }
}

void CjtCursos::nou_curs ()  {
    Curs c;
    cursos.push_back(c);
}

void CjtCursos::llegir_cursos_inicials ()  {
    int C;
    cout << "Nombre inicial de cursos:";
    cin >> C;
    vector<Curs> aux(C);
    for (int i = 0; i < C; ++i) {
        Curs c;
        c.lletgir_sessions();
        aux[i] = c;
    }
    cursos = aux;
}

