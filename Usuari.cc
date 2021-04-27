#include "Usuari.hh"
#include "Curs.hh"

Usuari::Usuari() {}

Usuari::Usuari(const string & u) {
    stats.name = u;
}

int Usuari::esta_inscrit() const {
    return stats.curs_in;
}

bool Usuari::curs_completat() const {
    if (problemes_env.size() == 0) return true;
    else return false;
}

void Usuari::problemes_enviables() const {
    for(map<string,int>::const_iterator it = problemes_env.begin(); it != problemes_exit.end(); ++it) {
        cout << "Problema: " << (*it).first <<" "<< (*it).second <<"intents" << endl;
    }
}

void Usuari::problemes_resolts() {
    for(map<string,int>::iterator it = problemes_exit.begin(); it != problemes_exit.end(); ++it) {
        cout << "Problema: " << (*it).first <<" "<< (*it).second <<"intents" << endl;
    }
}

string Usuari::consultar_nom () const {
    return stats.name;
}

void Usuari::inscribir_curso(int c) {
    stats.curs_in = c;
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
    cout << "Nom: " << stats.name <<endl;
    cout <<"Enviaments totals: "<< stats.env_tot<<endl;
    cout <<"Problemes resolts: "<< problemes_exit.size()<<endl;
    cout <<"Problemes intentats: "<< problemes_env.size()<<endl;
    cout <<"Curs inscrit: "<< stats.curs_in<<endl;
}