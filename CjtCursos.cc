#include "CjtCursos.hh"

CjtCursos::CjtCursos() {}

bool CjtCursos::existeix_curs(int c) const{
    if (c==0) return false;
    else if(cursos.size() >= c) return true;
    else return false;
}

 Curs& CjtCursos::accedir_curs (int c){
    return cursos[c-1];
}

void CjtCursos::llistat_cursos () const {
    for (int i = 0; i < cursos.size(); ++i) {
        cout << i+1;
        cursos[i].escriure_curs();
    }
}

void CjtCursos::nou_curs (const Curs& c)  {
    cursos.push_back(c);
    cout << cursos.size() << endl;
}

void CjtCursos::llegir_cursos_inicials (CjtSessions cjtses)  {
    int C;
    cin >> C;
    vector<Curs> aux(C);
    for (int i = 0; i < C; ++i) {
        Curs c;
        bool creat = c.curs_pot_crear(cjtses);
        if(creat)aux[i] = c;
    }
    cursos = aux;
}
