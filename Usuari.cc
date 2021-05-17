#include "Usuari.hh"


Usuari::Usuari() {}

int Usuari::curs_inscrit() const {
    return stats.curs_in;
}

void Usuari::problemes_enviables() const {
    problemes_env.mostrar_problemes();
}

void Usuari::problemes_resolts() const{
    problemes_exit.mostrar_problemes();
}

void Usuari::inscribir_curso(int c, const CjtSessions& cjtses,  const Curs& curs) {
    stats.curs_in = c;
    for(int i = 0; i < curs.num_sessions(); ++i ) {       
         cjtses.accedir_sessio(curs.get_sessio(i)).iniciar_enviables(problemes_exit, problemes_env);
    }
   
}

void Usuari::actualitzar_stats(const string& p, int r, bool& cur_completat,  const CjtSessions& cjtses,  const Curs& curs) {
    ++stats.env_tot;
        if(problemes_env.get_intents(p) == 0) ++stats.probs_intents;
        problemes_env.suma_int(p);
        if( r == 1 ) {
            problemes_exit.afegeix(p,problemes_env.get_intents(p));
            problemes_env.elimina(p);
            
            cjtses.accedir_sessio(curs.retorna_sessio(p)).actualitza_env(problemes_exit, problemes_env,p);
            
            
            if(problemes_env.get_size()==0){
                cur_completat = stats.curs_in;
                stats.curs_in = 0;
                
            }  
        }      
}

void Usuari::escriure_usuari( ) {
    cout << '(' << stats.env_tot << ',' << problemes_exit.get_size();
    cout << ',' << stats.probs_intents << ',' << stats.curs_in << ')' << endl;
}