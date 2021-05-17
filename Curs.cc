#include "Curs.hh"

Curs::Curs() {}


void Curs::escriure_curs( ) const{
    cout <<' ' << users.first << ' ' << users.second << ' ' << sessions.size() <<' ';
    cout << '(';
    for(int i = 0; i < sessions.size(); ++i) {
        if(i != 0) cout << ' ';
        cout << sessions[i];
    }
    cout<< ')' <<endl;
}
int Curs::usuaris_inscrits() {
    return users.second;
}

void Curs::act_inscrits(int x){
    users.second += x;
}

string Curs::retorna_sessio(const string& p) const{
   return problemes.retorna_sessio(p);
}


int Curs::num_sessions() const{
    return sessions.size();
}

string Curs::get_sessio(int i) const{
    return sessions[i];
}

bool Curs::curs_pot_crear(const CjtSessions& cjtses){
   int num;
    string aux;
    bool creat;
    cin >> num;
    vector<string> auxSes(num);
    for(int i = 0; i < num; ++i) { 
        cin >> aux;
        auxSes[i] = aux;
        creat = cjtses.accedir_sessio(aux).recorrer_i_afegir(problemes);
       if(not creat) return false;
    }
    sessions = auxSes;
   return true;
}

void Curs::actualitzar_completat() {
    ++users.first;
    --users.second;
}
