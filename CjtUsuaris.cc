#include "CjtUsuaris.hh"
#include "Usuari.hh"

CjtUsuaris::CjtUsuaris() {}

void CjtUsuaris::llistat_usuaris() {
    for(map<string,Usuari>::iterator it = llistUsers.begin(); it != llistUsers.end(); ++it) {
        cout << (*it).first;
        (*it).second.escriure_usuari();
    }
}

Usuari& CjtUsuaris::accedir_usuari(const string& s, bool& found) {
    map<string,Usuari>::iterator it = llistUsers.find(s);
   if(it != llistUsers.end()) {
       found = true; 
       return (*it).second;
   }
   found = false; 
   return nulo;
} 


bool CjtUsuaris::alta_usuari(const string& u) {
    pair<map<string,Usuari>::iterator, bool> r= llistUsers.insert(make_pair(u, Usuari()));
    if (r.second) cout << llistUsers.size() <<endl;
    return r.second; 
}

bool CjtUsuaris::baixa_usuari(const string& u, int& curs) {
    map <string,Usuari>::iterator it = llistUsers.find(u);
    if(it != llistUsers.end()) {  
        curs = (*it).second.curs_inscrit();
        llistUsers.erase(it);
        cout << llistUsers.size() <<endl;
        return true;
    }
    return false;
}

void CjtUsuaris::llegir_usuaris_inicials() {
    int M;
    cin >> M;
    for (int i=0; i < M; ++i) {
        string s;
        cin >> s;
        llistUsers.insert(make_pair(s,Usuari()));
    }
}
