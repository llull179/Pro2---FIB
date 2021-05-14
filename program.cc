/** @file program.cc
    @brief Programa principal.
*/
#include "CjtUsuaris.hh"
#include "CjtCursos.hh"
using namespace std;

int main() {
    CjtProblemes cjtProb;
    CjtSessions cjtSes;
    CjtCursos cjtCurs;
    CjtUsuaris cjtUs;

    string op;
    cjtProb.llegir_problemes_inicials();
    cjtSes.llegir_sessions_inicials();
    cjtCurs.llegir_cursos_inicials(cjtSes);
    cjtUs.llegir_usuaris_inicials();

    cin >> op;
    while(op != "fin") {
        string auxString;
        int auxInt;

        if (op == "np" or op == "nuevo_problema") {
            cout << '#' <<op<<' ';
            cin >> auxString;
            cout  << auxString <<endl;

            if(not cjtProb.existeix_problema(auxString)){
                cjtProb.nou_problema(auxString);
            }
            else cout<<"error: el problema ya existe"<<endl;
        }

        else if (op == "ns" or op == "nueva_sesion") {
            cout << '#' <<op<<' ';
            cin >> auxString;
            cout << auxString <<endl;

            if(not cjtSes.existeix_sessio(auxString)){
                cjtSes.nova_sessio( auxString );
            }
            else cout<<"error: la sesion ya existe"<<endl;
        }
        else if (op == "nc" or op == "nuevo_curso") {
            cout << '#' <<op<< endl;
            Curs c;
            if(c.curs_pot_crear(cjtSes)) cjtCurs.nou_curs(c);
            else cout << "error: curso mal formado" <<endl;

        }
        else if (op == "a" or op == "alta_usuario") {
            cout << '#' <<op<<' ';
            cin >> auxString;
            cout << auxString <<endl;
            bool insertat = cjtUs.alta_usuari(auxString);
            if(not insertat) cout << "error: el usuario ya existe" << endl;
        }

        else if (op == "b" or op == "baja_usuario") {
            cout << '#' <<op<<' ';
            cin >> auxString;
            cout << auxString <<endl;
            int curs = 0;
            bool eliminat = cjtUs.baixa_usuari( auxString, curs );
            if(not eliminat) cout << "error: el usuario no existe" << endl;
            else if(curs != 0){
                Curs& c = cjtCurs.accedir_curs(curs);
                c.act_inscrits(-1);
            }
        }

        else if (op == "i" or op == "inscribir_curso") {
            cout << '#' <<op<<' ';
            cin >> auxString >> auxInt;
            cout << auxString <<' ' << auxInt <<endl;
            bool found;
            Usuari& u=cjtUs.accedir_usuari(auxString, found);
            
            if (found) {
                if(cjtCurs.existeix_curs(auxInt)) {
                    if (u.curs_inscrit() == 0){
                        Curs& c =cjtCurs.accedir_curs( auxInt );
                        u.inscribir_curso( auxInt, cjtSes, c);
                        c.act_inscrits(1);
                        cout << c.usuaris_inscrits() <<endl;
                    }
                    else cout << "error: usuario inscrito en otro curso" <<endl;
                }
                else cout << "error: el curso no existe" << endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }

        else if (op == "cu" or op == "curso_usuario") {
            cout << '#' <<op<<' ';
            cin >> auxString;
            cout << auxString <<endl;
            bool found;
            Usuari& u=cjtUs.accedir_usuari(auxString, found);
             if (found) {
                cout << u.curs_inscrit() <<endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }

        else if (op == "sp" or op == "sesion_problema") {
            cout << '#' <<op<<' ';
            cin >> auxInt >> auxString;
            cout << auxInt <<' ' << auxString <<endl;

            if(cjtCurs.existeix_curs(auxInt)){
                if(cjtProb.existeix_problema(auxString)){
                    string ses = cjtCurs.accedir_curs( auxInt ).retorna_sessio(auxString);
                    if(ses!="0"){
                        cout << ses << endl;
                    }
                    else cout << "error: el problema no pertenece al curso" << endl;
                }
                else cout << "error: el problema no existe" << endl;
            }
            else cout << "error: el curso no existe" << endl;

        }

        else if (op == "pr" or op == "problemas_resueltos") {
            cout << '#' <<op<<' ';
            cin >> auxString;
            cout << auxString <<endl;
            bool found;
            Usuari& u=cjtUs.accedir_usuari(auxString, found);
            if(found) {

                u.problemes_resolts();
            }
            else cout << "error: el usuario no existe" << endl;
        }
        else if (op == "pe" or op == "problemas_enviables") {
            cout << '#' <<op<<' ';
            cin >> auxString;
            cout << auxString <<endl;
            bool found;
            Usuari& u=cjtUs.accedir_usuari(auxString, found);
            if(found) {
                if(u.curs_inscrit()){
                    u.problemes_enviables();
                }
                else cout << "error: usuario no inscrito en ningun curso" <<endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }

        else if (op == "e" or op == "envio") {

            cout << '#' <<op<<' ';
            bool r;
            string p;
            cin >> auxString >> p >> r;
            cout << auxString <<' ' << p << ' ' << r << endl;
            bool foundUser, foundProb, curs_completat = false;

            Usuari& us=cjtUs.accedir_usuari(auxString, foundUser);
            Problema& prob = cjtProb.accedir_problema( p, foundProb );
            prob.actualitzar_stats( r );
            Curs& c = cjtCurs.accedir_curs(us.curs_inscrit());
            
            us.actualitzar_stats(p, r,curs_completat, cjtSes, cjtCurs);
            if (curs_completat) c.actualitzar_completat();
            
        }

        else if (op == "lp" or op == "listar_problemas") {
            cout << '#' <<op;
            cout <<endl;
            cjtProb.ordenar_problemes();
            cjtProb.llistat_problemes();
        }

        else if (op == "ep" or op == "escribir_problema") {
            cout << '#' <<op<<' ';
            cin >> auxString;
            cout  << auxString <<endl;
            bool found;
            Problema& prob = cjtProb.accedir_problema ( auxString, found );
            if(found){
                cout << auxString;
                prob.escriure_problema();
            }
            else cout << "error: el problema no existe"  << endl;
        }

        else if (op == "ls" or op == "listar_sesiones") {
            cout << '#' <<op<<endl;
            cjtSes.llistat_sessions();

        }

        else if (op == "es" or op == "escribir_sesion") {
            cout << '#' <<op<<' ';
            cin >> auxString;
            cout << auxString <<endl;
            bool found;
            Sessio& ses = cjtSes.accedir_sessio ( auxString, found );
            if(found){
                cout << auxString;
                ses.escriure_sessio();
            }
            else cout << "error: la sesion no existe"  << endl;

        }

        else if (op == "lc" or op == "listar_cursos") {
            cout << '#' <<op<<endl;
            cjtCurs.llistat_cursos();

        }

        else if (op == "ec" or op == "escribir_curso") {
            cout << '#' <<op<<' ';
            cin >> auxInt;
            cout << auxInt <<endl;
             if (cjtCurs.existeix_curs( auxInt )) { 
                Curs& curs = cjtCurs.accedir_curs ( auxInt );
                cout << auxInt;
                curs.escriure_curs();
            }
            else cout << "error: el curso no existe" << endl;

        }

        else if (op == "lu" or op == "listar_usuarios") {
            cout << '#' << op << endl;
            cjtUs.llistat_usuaris();
        }

        else if (op == "eu" or op == "escribir_usuario") {
            cout << '#' <<op<<' ';
            cin >> auxString;
            cout << auxString <<endl;
            bool found;
            Usuari& u=cjtUs.accedir_usuari(auxString,found);
             if (found) {
                cout << auxString;
                u.escriure_usuari();
            }
            else cout << "error: el usuario no existe" << endl;
        }

        cin >> op;
    }
}
