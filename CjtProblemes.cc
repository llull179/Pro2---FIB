#include "CjtProblemes.hh"

CjtProblemes::CjtProblemes(){}

bool CjtProblemes::existeix_problema (const string & p ) const{
    for (int i = 0; i < problemes.size(); ++i) {
        if(p == problemes[i].consultar_ident()) return true;
    }
    return false;
}

Problema& CjtProblemes::accedir_problema (const string & p) {
    int k = problemes.size();
   for (int i = 0; i < k; ++i ){
       if (p == problemes[i].consultar_ident()) return problemes[i];
   }
   return problemes[k-1];
}

void CjtProblemes::nou_problema (const string & p){
    Problema prob = Problema(p);
    problemes.push_back( prob);
}

void CjtProblemes::llegir_problemes_inicials (){
   int P;
   string p;
   cout << "Nombre inicial de problemes:";
   cin >> P;
   vector<Problema> aux(P);
   for(int i = 0; i < P; ++i) {
       cin >> p;
       Problema prob = Problema(p);
       aux[i] = prob;
   }
   problemes = aux;
}

void CjtProblemes::llistat_problemes(){
    for (int i = 0; i < problemes.size(); ++i) {
        problemes[i].escriure_problema();
    }
}