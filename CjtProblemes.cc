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
    for (map<string,Problema>::const_iterator it = problemes.begin(); it != problemes.end(); ++it) {
        cout << (*it).first;
        (*it).second.escriure_problema();
    }
}