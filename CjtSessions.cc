#include "CjtSessions.hh"

CjtSessions::CjtSessions() {}

bool CjtSessions::existeix_sessio(const string& s) const {
    if(sessions.find(s) != sessions.end()) return true;
    else return false;
}

Sessio& CjtSessions::accedir_sessio(const string& s, bool& found) {
  map<string,Sessio>::iterator it = sessions.find(s);
  if(it != sessions.end()) {
      found = true;
      return (*it).second;
  }
  found = false;
  return nulo;
}

void CjtSessions::nova_sessio(const string& s){
    BinTree<string> prereq;
    
    Sessio ses;
    ses.lletgir_BinTree(prereq);
    sessions.insert(pair<string,Sessio>(s,ses));
    cout << sessions.size() <<endl;
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

void CjtSessions::llistat_sessions(){
    for(map<string,Sessio>::iterator it = sessions.begin(); it != sessions.end(); ++it) {
        cout << (*it).first;
        (*it).second.escriure_sessio();  
    }
}

string CjtSessions::existeix_prob(const vector<string>& v, string p){
        for(int i = 0; i < v.size(); ++i) {
            map<string, Sessio>::iterator it = sessions.find(v[i]);
            if((*it).second.trobar_problema(p)) return (*it).first;
        }
        return "0";
    }