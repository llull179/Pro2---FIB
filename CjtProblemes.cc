#include "CjtProblemes.hh"

CjtProblemes::CjtProblemes(){}

bool CjtProblemes::existeix_problema (const string & p ) const{

  int it =  problemes.find( p );
    if(it != problemes.end()) return true;
    else return false;
}




Problema CjtProblemes::accedir_problema (const string & p)){
    int P;
    cin >> P;
    list <string>::iterator it = problemes.end();
    for(int i=0; i < P; ++i) {
        int p;
        cin >> p;
        Problema(p) p;
        problemes.insert(it,prob);
    }
}

void CjtProblemes::nou_problema (const string & p){
    list <string>::iterator it = problemes.end();
    problemes.insert(it, p);

}

void CjtProblemes::llegir_problemes_inicials (){
    if(not consultar_problema(p) ) {
        //leltgir dades
    }
    else cout<<"ERROR"<<endl;

}

void CjtProblemes::llistat_problemes (){


}
