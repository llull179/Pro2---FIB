#include "CjtUsuaris.hh"
#include "CjtCursosz.hh"
using namespace std;

int main() {
    CjtProblemes cjtProb;
    CjtSessions cjtSess;
    CjtCursos cjtCurs;
    CjtUsuaris cjtUs;

    string op;
    int P;

    cjtProb.llegir_problemes_inicials();
    cjtSess.llegir_sessions_inicials();
    cjtCurs.llegir_cursos_inicials();
    cjtUs.llegir_usuaris_inicials();  

    cin >> op;
    while(op != "fin") {
        string p;
        int aux;
        if (op == "np" or op == "nuevo_problema") {
            cin>>p;
            if(not cjtProb.consultar_problema(p)){
                cjtProb.nou_problema(p);
            }
            else cout<<"ERROR, ja existeix el problema"<<endl;
            
        }
        else if (op == "ns" or op == " nueva_sesion ") {
            cin >> aux;
            cjtSess.nova_sessio();
        }
        else if (op == "nc" or op == " nuevo_curso ") {
            cjtCurs.nou_curs();
        }
        else if (op == "a" or op == " alta_usuario ") {
            cin >> aux;
            Usuari u = Usuario(aux)
            cjtUs.alta_usuari( u );
        }
        else if (op == "b" or op == " baja_usuario ") {
            cin >> aux;
            cjtUs.baja_usuari(aux);
        }
        else if (op == "i" or op == " inscribir_curso ") {
            cin >> aux;
            
        }
        else if (op == "cu" or op == " curso_usuario ") {
            
        }
        else if (op == "sp" or op == " sesion_problema ") {
            
        }
        else if (op == "pr" or op == " problemas_resueltos ") {
            
        }
        else if (op == "pe" or op == " problemas_enviables ") {
            
        }
        else if (op == "e" or op == " envio ") {
            
        }
        else if (op == "lp" or op == " listar_problemas ") {
            cjtCurs.llistat_problemes();
        }
        else if (op == "ep" or op == " escribir_problema ") {
            
        }
        else if (op == "ls" or op == " listar_sesiones ") {
            cjtCurs.llistat_sessions();
        }
        else if (op == "es" or op == " escribir_sesion ") {
            
        }
        else if (op == "lc" or op == " listar_cursos ") {
            cjtCurs.llistat_cursos();
        }
        else if (op == "ec" or op == " escribir_curso ") {
            
        }
        else if (op == "lu" or op == " listar_usuarios ") {
            cjtUs.llistat_usuaris();
        }
        else if (op == "eu" or op == " escribir_usuario ") {
            
        }

        cin >> op;
    }
}