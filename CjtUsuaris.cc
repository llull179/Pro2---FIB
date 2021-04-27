#include "CjtUsuaris.hh"
#include "Usuari.hh"

CjtUsuaris::CjtUsuaris() {}

bool CjtUsuaris::existeix_usuari(const string & u) const{
    
    for(list<Usuari>::const_iterator it = llistUsers.begin(); it != llistUsers.end(); ++it) {
        if(u == (*it).consultar_nom()) return true;
    }
    return false;
}

void CjtUsuaris::llistat_usuaris() {
    for(list<Usuari>::iterator it = llistUsers.begin(); it != llistUsers.end(); ++it) {
        (*it).escriure_usuari();
    }
}

Usuari CjtUsuaris::accedir_usuari(const string& s) {
   for(list<Usuari>::const_iterator it = llistUsers.begin(); it != llistUsers.end(); ++it) {
        if(s == (*it).consultar_nom())  return (*it);
    }
    return *llistUsers.end();
}

void CjtUsuaris::alta_usuari(const Usuari& u) {
    llistUsers.insert(llistUsers.end(), u);
    cout << llistUsers.size() <<endl;
}

void CjtUsuaris::baixa_usuari(const string& u) {
     bool trobat = false;
    list<Usuari>::iterator it = llistUsers.begin();
    while(it != llistUsers.end() or trobat) {
        if(u == (*it).consultar_nom()){
            trobat = true;
            llistUsers.erase(it);
        } 
        ++it;
    }
}

void CjtUsuaris::llegir_usuaris_inicials() {
    int M;
    cout << "Nombre inicial de usuaris:";
    cin >> M;
    for (int i=0; i < M; ++i) {
        string s;
        cin >> s;
        Usuari u = Usuari(s);
        llistUsers.insert(llistUsers.end(), u);
    }
}
