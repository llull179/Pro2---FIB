#include "CjtProblemes.hh"

CjtProblemes::CjtProblemes(){}

bool CjtProblemes::existeix_problema (const string & p ) const{
    if( problemes.find(p) != problemes.end()) return true;
    return false;
}

Problema& CjtProblemes::accedir_problema (const string & p, bool& found) {
    map<string,Problema>::iterator it = problemes.find(p);
   if(it != problemes.end()) {
       found = true;
       return (*it).second;
   }
   found = false;
   return nulo;
}

void CjtProblemes::nou_problema (const string & p){
    Problema prob;
    problemes.insert(make_pair(p,prob) );
    cout << problemes.size() << endl;
}

void CjtProblemes::llegir_problemes_inicials (){
   int P;
   string p;
   cin >> P;
   for(int i = 0; i < P; ++i) {
       string pro;
       cin >> pro;
       problemes.insert(make_pair(pro, Problema()));
   }
}

void CjtProblemes::llistat_problemes(){
    for (int i = 0; i < prob_ord.size(); i++) {
        cout << prob_ord[i].first;
        prob_ord[i].second.escriure_problema();
    }
}

void CjtProblemes::ordenar_problemes() {
  vector<pair<string,Problema>> aux(problemes.size());
  int i = 0;
  for(map<string,Problema>::const_iterator it = problemes.begin(); it != problemes.end(); ++it) {
    aux[i] = *it;
  }
  sort(aux.begin(), aux.end(), cmp);
  prob_ord = aux;
}

bool CjtProblemes::cmp(const pair<string,Problema>& a, const pair<string,Problema>& b) {
  if(a.second.get_ratio()!= b.second.get_ratio()) return a.second.get_ratio() > b.second.get_ratio();
  return a.first > b.first;
}
