#include "CjtProblemes.hh"
 

CjtProblemes::CjtProblemes(){}

bool CjtProblemes::consultar_problema (const string & p ) const{
    
    list <string>::const_iterator it;
    for(it = problemes.begin(); it != problemes.end(); ++it ){
        if( (*it) == p) return true;
    }
    else return false;
}


void CjtProblemes::nou_problema (const string & p){
    list <string>::iterator it = problemes.end();
    problemes.insert(it, p);
    
}

void CjtProblemes::llegir_problemes_inicials (){
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

void CjtProblemes::llistat_problemes (){

    
}

void CjtProblemes::escriure_problema (const string& p){
    if(not consultar_problema(p) ) {
        //leltgir dades
    }
    else cout<<"ERROR"<<endl;
    
}