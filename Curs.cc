#include "Curs.hh"

Curs::Curs() {}

string Curs::trobar_sessio(int x) {
    return sessions[x];   
}

void Curs::escriure_curs( ) const{
    cout <<"Usuaris completat: "<<users.first<<"; Usuaris inscrits"<<users.second<<endl;
    cout << "Identificadors de Sessions:";
    for(int i = 0; i < sessions.size(); ++i) {
        cout <<' '<< sessions[i];
    }
    cout<<endl;
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
