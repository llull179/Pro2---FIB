#include "GrupProb.hh"

GrupProb::GrupProb() {}

void GrupProb::mostrar_problemes() const {
    for(map<string,int>::const_iterator it = probs_enviaments.begin(); it != probs_enviaments.end(); ++it) {
        cout << (*it).first << '('<< (*it).second <<')' << endl;
    }
}

int GrupProb::get_size() {
    return probs_enviaments.size();
}

bool GrupProb::pertany(const string& p) const {
    if(probs_enviaments.find(p) == probs_enviaments.end()) return false;
    return true;
}

void GrupProb::afegeix(const string& p, int x) {
    probs_enviaments.insert(make_pair(p,x));
}

void GrupProb::elimina(const string& p) {
    probs_enviaments.erase(p);
}

int GrupProb::get_intents(const string& p){
    map<string,int>::const_iterator it = probs_enviaments.find(p);
    return (*it).second;
}

void GrupProb::suma_int(const string& p) {
    map<string,int>::iterator it = probs_enviaments.find(p);
    ++(*it).second;
}