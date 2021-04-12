#include "CjtSessions.hh"

CjtSessions::CjtSessions() {}

bool CjtSessions::existeix_sessio(const string& s) const {
    if(sessions.find(s) != sessions.end()) return true;
    else return false;
}

Sessio& CjtSessions::accedir_sessio(const string& s) {
  map<string,Sessio>::iterator it = sessions.find(s);
  Sessio prob = (*it).second;
  return prob;
}

void CjtSessions::nova_sessio(const string& s){
    BinTree<string> prereq;
    
    Sessio ses;
    ses.lletgir_BinTree(prereq);
    ses = Sessio(prereq);
    sessions.insert(pair<string,Sessio>(s,ses));
}

void CjtSessions::llegir_sessions_inicials(){
   int Q;
   cin >> Q;
   for (int i = 0; i < Q; ++i) {
       Sessio ses;
       string ident;
       cin >> ident;
       BinTree<string> a;
       ses.lletgir_BinTree(a);

       sessions.insert(pair<string,Sessio>(ident,ses));
   }
}

void CjtSessions::llistat_sessions() const{
    for(map<string,Sessio>::const_iterator it = sessions.begin(); it != sessions.end(); ++it) {
        (*it).second.escriure_sessio();
    }
}