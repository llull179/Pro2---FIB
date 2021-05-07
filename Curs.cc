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



string Curs::retorna_sessio( CjtSessions cs,const string& s) {
    bool found;
    for(int i = 0; i< sessions.size(); ++i) {
        if( cs.accedir_sessio(sessions[i], found).trobar_problema(s)) return sessions[i];
    }
   return "0";
}

vector<string> Curs::llista_sesions() {
   return sessions;
}
bool Curs::curs_pot_crear() const{

  return true;
}

int Curs::num_sessions() {
    return sessions.size();
}

string Curs::get_sessio(int i) {
    return sessions[i];
}
/*void Curs::afegir_sessio (const string& s, const Sessio& ses) {
  sessions.push_back(s);


}
*/
