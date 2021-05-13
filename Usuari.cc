#include "Usuari.hh"
#include "Curs.hh"

Usuari::Usuari() {}

int Usuari::curs_inscrit() const {
    return stats.curs_in;
}

void Usuari::problemes_enviables()  {
    for(map<string,int>::const_iterator it = problemes_env.begin(); it != problemes_env.end(); ++it) {
        cout << (*it).first << '('<< (*it).second <<')' << endl;
    }
}

void Usuari::problemes_resolts() {
    for(map<string,int>::const_iterator it = problemes_exit.begin(); it != problemes_exit.end(); ++it) {
        cout << (*it).first << '('<< (*it).second <<')' << endl;
    }
}

void Usuari::inscribir_curso(int c, CjtSessions ses,  Curs curs) {
    stats.curs_in = c;
    for(int i = 0; i < curs.num_sessions(); ++i ) {       
        bool found;
        string s = ses.accedir_sessio(curs.get_sessio(i),found).obtenir_arrel();
        map<string,int>::const_iterator it = problemes_exit.find(s);
        if(it == problemes_exit.end())problemes_env.insert(make_pair(s,0));
    }
   
}

void Usuari::actualitzar_stats(const string& p, const pair<string,string>& fills, int r, bool& cur_completat) {
    ++stats.env_tot;
    map <string, int>::iterator it_env = problemes_env.find(p);

        
    if((*it_env).second == 0) ++stats.probs_intents;
    ++(*it_env).second;
    if( r == 1 ) {
        problemes_exit.insert(make_pair(p,(*it_env).second));
        problemes_env.erase(p);

        
        
        if(fills.first != "0") {
            map <string, int>::iterator it_fill1 = problemes_exit.find(fills.first);
            if(it_fill1 == problemes_exit.end()) problemes_env.insert(make_pair(fills.first,0));
        }
        else propaga(fills.first);
        if(fills.second != "0") {
            map <string, int>::iterator it_fill2 = problemes_exit.find(fills.second);
            if(it_fill2 == problemes_exit.end()) problemes_env.insert(make_pair(fills.second,0));
        }  
        else propaga(fills.second);
        if(problemes_env.size()==0){
            stats.curs_in = 0;
            cur_completat = true;
        } 
    
    }
}

/*void propaga(string p) {
    if(problemes_exit.find(p) == problemes_exit.end()) problemes_env.insert(make_pair(p,0));
    else{
        buscar sucesores de p -> p.first y p.second
        if(p.first != 0) propaga(p.first);
        if(p.second != 0)propaga(p.second);
    }
}
*/
void Usuari::escriure_usuari( ) {
    cout << '(' << stats.env_tot << ',' << problemes_exit.size();
    cout << ',' << stats.probs_intents << ',' << stats.curs_in << ')' << endl;
}