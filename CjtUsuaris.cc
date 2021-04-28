#include "CjtUsuaris.hh"
#include "Usuari.hh"

CjtUsuaris::CjtUsuaris() {}

void CjtUsuaris::llistat_usuaris() {
    for(list<Usuari>::iterator it = llistUsers.begin(); it != llistUsers.end(); ++it) {
        (*it).escriure_usuari();
    }
}

bool CjtUsuaris::accedir_usuari( Usuari& u) {
   for(list<Usuari>::const_iterator it = llistUsers.begin(); it != llistUsers.end(); ++it) {
        if(u.consultar_nom() == (*it).consultar_nom()){
            u = *it;
            return true;
        }  
    }
    return false;
}

void CjtUsuaris::alta_usuari(const Usuari& u) {
    llistUsers.insert(llistUsers.end(), u);
    cout << llistUsers.size() <<endl;
}

void CjtUsuaris::baixa_usuari(const string& u) {
     bool trobat = false;
    list<Usuari>::iterator it = llistUsers.begin();
    //fallo aqui fiinal del while
    
    while(it != llistUsers.end() and (not trobat)) {
        if(u == (*it).consultar_nom()){
            trobat = true;
            llistUsers.erase(it);
        } 
        else ++it;
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
