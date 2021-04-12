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
    
}

void Usuari::inscribir_curso(int c) {
    stats.curs_in = c;
}

void Usuari::actualitzar_stats(int p, int r) {

}

void Usuari::escriure_usuari( ) {
    cout <<"Enviaments totals: "<< stats.env_tot<<endl;
    cout <<"Problemes resolts: "<< stats.prob_resolt<<endl;
    cout <<"Problemes intentats: "<< stats.prob_int<<endl;
    cout <<"Curs inscrit: "<< stats.curs_in<<endl;
}