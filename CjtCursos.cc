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
        cursos[i].escriure_curs();
    }
}

void CjtCursos::nou_curs ()  {
    Curs c;
    cursos.push_back(c);
}

void CjtCursos::llegir_cursos_inicials ()  {
    int C;
    cin >> C;
    for (int i = 0; i < C; ++i) {
        Curs c;
        cursos[i] = c;
    }
}

