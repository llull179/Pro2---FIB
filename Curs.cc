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

void Curs::lletgir_sessions () {
    int num;
    cin >> num;
    vector<string> auxSes(num);
    for( int i = 0; i < num; ++i) {
        string aux;
        cin >> aux;
        auxSes[i] = aux;
    }
    sessions = auxSes;
}

vector<string> Curs::llista_sesions() {
   return sessions;
}