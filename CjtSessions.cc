#include "CjtSessions.hh"

CjtSessions::CjtSessions() {}

bool CjtSessions::existeix_sessio(const string& s) const {
    if(sessions.find(s) != sessions.end()) return true;
    else return false;
}

Sessio CjtSessions::accedir_sessio(const string& s) const{
  map<string,Sessio>::const_iterator it = sessions.find(s);
  if(it != sessions.end()) {
      
      return (*it).second;
  }
  return nulo;
}

void CjtSessions::nova_sessio(const string& s){
    BinTree<string> prereq;
    
    Sessio ses(s);
    ses.lletgir_BinTree(prereq);
    sessions.insert(pair<string,Sessio>(s,ses));
    cout << sessions.size() <<endl;
}

void CjtSessions::llegir_sessions_inicials(){
   int Q;
   cin >> Q;
   for (int i = 0; i < Q; ++i) {
         string ident;
        cin >> ident;
       Sessio ses(ident);
       BinTree<string> a;
       ses.lletgir_BinTree(a);
       sessions.insert(pair<string,Sessio>(ident,ses));
   }
}

void CjtSessions::llistat_sessions(){
    for(map<string,Sessio>::const_iterator it = sessions.begin(); it != sessions.end(); ++it) {
        cout << (*it).first;
        (*it).second.escriure_sessio();  
    }
}

