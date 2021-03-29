#include "CjtProblemes.hh"


CjtProblemes::CjtProblemes(){}

bool CjtProblem::consultar_problema (const string & p ) const{
    
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