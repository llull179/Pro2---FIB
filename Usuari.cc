#include "Usuari.hh"
#include "Curs.hh"

Usuari::Usuari() {}

int Usuari::curs_inscrit() const {
    return stats.curs_in;
}

bool Usuari::curs_completat() const {
    if (problemes_env.size() == 0) return true;
    else return false;
}

void Usuari::problemes_enviables()  {
    for(map<string,int>::const_iterator it = problemes_env.begin(); it != problemes_env.end(); ++it) {
        cout << (*it).first << '('<< (*it).second <<')' << endl;
    }
}

void Usuari::problemes_resolts() {
    for(map<string,int>::iterator it = problemes_exit.begin(); it != problemes_exit.end(); ++it) {
        cout << (*it).first << '('<< (*it).second <<')' << endl;
    }
}

void Usuari::inscribir_curso(int c, const list<string>& l) {
    stats.curs_in = c;
    for(list<string>::const_iterator it = l.begin(); it != l.end(); ++it) {
        problemes_env.insert(make_pair((*it),0));
    }
}

void Usuari::actualitzar_stats(string p, int r) {
    ++stats.env_tot;
    
    map <string, int>::iterator it = problemes_exit.find(p);
    if(it == problemes_env.end()){
        ++stats.intents;
        if( r == 1 ) problemes_exit.insert(make_pair(p,1));
    } 
    else {
        if(r == 1) {
            (*it).second++;
        }
    }
    
}

void Usuari::escriure_usuari( ) {
    cout << '(' << stats.env_tot << ',' << problemes_exit.size();
    cout << ',' << stats.intents << ',' << stats.curs_in << ')' << endl;
}