#include "Curs.hh"

Curs::Curs() {}

string Curs::trobar_sessio(const string& p) {
    bool trobat = false;
    string problema;
    map<string,Sessio>::const_iterator it = sessions.begin();
    while (not trobat or it != sessions.end()) {
        trobat = (*it).second.trobar_problema(p);
        if(trobat) problema = (*it).first;
        ++it;
    }
    return problema;
}

void Curs::escriure_curs( ) const{
    cout <<"Usuaris completat: "<<users.first<<"; Usuaris inscrits"<<users.second<<endl;
    cout << "Identificadors de Sessions:";
    for(map <string,Sessio>::const_iterator it = sessions.begin(); it != sessions.end(); ++it) {
        cout <<' '<< (*it).first;
    }
    cout<<endl;
}