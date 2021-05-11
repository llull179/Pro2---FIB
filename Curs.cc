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
int Curs::usuaris_inscrits( ){
    return users.second;
}

void Curs::act_inscrits(int x){
    users.second += x;
}

string Curs::retorna_sessio(const string& p) {
    map<string,string>::const_iterator it = problemes.find(p);
    map<string,string>::const_iterator ita = problemes.begin();
    if(it!=problemes.end()) return (*it).second;
    return "0";
}


int Curs::num_sessions() {
    return sessions.size();
}

string Curs::get_sessio(int i) {
    return sessions[i];
}

bool Curs::curs_pot_crear( CjtSessions cjtses) {
    int num;
    cin >> num;
    vector<string> auxSes(num);
    for(int i = 0; i < num; ++i) {
        string aux;
        cin >> aux;
        auxSes[i] = aux;
        bool found;
        Sessio& s = cjtses.accedir_sessio(aux, found);
        if (found) {
            int numSes = s.get_size();
            for(int j = 0; j < numSes; ++j) {
                string p = s.agafa_iessim(j);
                pair<map<string,string>::iterator,bool> r = problemes.insert(make_pair(p,aux));
                if(not r.second) return false;
            }
        }
    }
    sessions = auxSes;
   return true;
}

void Curs::actualitzar_completat() {
    ++users.first;
    --users.second;
}