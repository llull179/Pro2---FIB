#include "GrupProb.hh"

GrupProb::GrupProb() {}

void GrupProb::mostrar_problemes()  {
    for(map<string,int>::const_iterator it = probs.begin(); it != probs.end(); ++it) {
        cout << (*it).first << '('<< (*it).second <<')' << endl;
    }
}
int GrupProb::get_size()  {
    return probs.size();
}

bool GrupProb::pertany(const string& p) const {
    if(probs.find(p) == probs.end()) return false;
    return true;
}

void GrupProb::afegeix(const string& p, int x) {
    probs.insert(make_pair(p,x));
}
void GrupProb::elimina(const string& p) {
    probs.erase(p);
}
int GrupProb::get_intents(const string& p) {
    map<string,int>::const_iterator it = probs.find(p);
    return (*it).second;
}
void GrupProb::suma_int(const string& p) {
    map<string,int>::iterator it = probs.find(p);
    ++(*it).second;
}