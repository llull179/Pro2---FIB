/** @file main.cc
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
    cjtCurs.llegir_cursos_inicials();
    cjtUs.llegir_usuaris_inicials();

    cin >> op;
    while(op != "fin") {
        string auxString;
        int auxInt;
        if (op == "np" or op == "nuevo_problema") {
            cin >> auxString;

            if(not cjtProb.existeix_problema(auxString)){
                cjtProb.nou_problema(auxString);
            }
            else cout<<"ERROR, ja existeix el problema"<<endl;
        }

        else if (op == "ns" or op == " nueva_sesion ") {
            cin >> auxString;

            if(not cjtSes.existeix_sessio(auxString)){
                cjtSes.nova_sessio( auxString );
            }
            else cout<<"ERROR, ja existeix la Sessió"<<endl;
        }
        else if (op == "nc" or op == " nuevo_curso ") {
            cjtCurs.nou_curs();
        }
        else if (op == "a" or op == " alta_usuario ") {
            cin >> auxString;

            if (cjtUs.existeix_usuari( auxString )) {
                Usuari u = Usuari(auxString);
                cjtUs.alta_usuari(u);
            }
            else cout << "ERROR: no existeix el Curs"<< auxInt << endl;
        }

        else if (op == "b" or op == " baja_usuario ") {
            cin >> auxString;

             if (cjtUs.existeix_usuari( auxString )) {
                cjtUs.baixa_usuari( auxString );
            }
            else cout << "ERROR: no existeix el Curs"<< auxInt << endl;
        }

        else if (op == "i" or op == " inscribir_curso ") {
            cin >> auxString >> auxInt;

            if (cjtUs.existeix_usuari(auxString) and cjtCurs.existeix_curs(auxInt)) {
                Usuari user = cjtUs.accedir_usuari( auxString );
                if (user.esta_inscrit() == 0) user.inscribir_curso( auxInt );
                else cout << "ERROR: l'Usuari ja està inscrit a un curs." << endl;

            }
            else cout << "ERROR: L'Usuari o el curs no existeixen." << endl;
        }

        else if (op == "cu" or op == " curso_usuario ") {
            cin >> auxString;

             if (cjtUs.existeix_usuari( auxString )) {
                Usuari user = cjtUs.accedir_usuari ( auxString );
                cout << user.esta_inscrit() <<endl;
            }
            else cout << "ERROR: no existeix el Curs"<< auxInt << endl;
        }

        else if (op == "sp" or op == " sesion_problema ") {
            cin >> auxInt >> auxString;
            if (not cjtCurs.existeix_curs( auxInt)) cout << "ERROR: no existeix el Curs" << auxInt << endl;
            else if (not cjtProb.existeix_problema( auxString)) cout << "ERROR: no existeix el Problema" << auxString << endl;
            else {
                Curs curs = cjtCurs.accedir_curs( auxInt );
                cout << curs.trobar_sessio( auxString ) << endl;
            }
        }

        else if (op == "pr" or op == " problemas_resueltos ") {
            cin >> auxString;
            if(cjtUs.existeix_usuari( auxString)) {
                Usuari user = cjtUs.accedir_usuari( auxString );
                user.problemes_resolts();
            }
            else cout << "ERROR: no existeix l'Usuari" << auxString << endl;
        }
        else if (op == "pe" or op == " problemas_enviables ") {
            cin >> auxString;
            if(cjtUs.existeix_usuari( auxString)) {
                Usuari user = cjtUs.accedir_usuari( auxString );
                user.problemes_enviables();
            }
            else cout << "ERROR: no existeix l'Usuari" << auxString << endl;
        }

        else if (op == "e" or op == " envio ") {
            bool r;
            string p;
            cin >> auxString >> p >> r;

            Usuari user = cjtUs.accedir_usuari( auxString );
            Problema prob = cjtProb.accedir_problema( p );

            prob.actualitzar_stats( r );
            user.actualitzar_stats(auxInt, r);

            if ( r ) {
                Curs cur = cjtCurs.accedir_curs(user.esta_inscrit());
                user.curs_completat(cur);
            }
        }

        else if (op == "lp" or op == " listar_problemas ") {
            cjtProb.llistat_problemes();
        }

        else if (op == "ep" or op == " escribir_problema ") {
            cin >> auxString;
            if (cjtProb.existeix_problema( auxString )) {
                Problema prob = cjtProb.accedir_problema ( auxString );
                prob.escriure_problema();
            }
            else cout << "ERROR: no existeix el Problema" << auxString << endl;
        }

        else if (op == "ls" or op == " listar_sesiones ") {
            cjtSes.llistat_sessions();
        }

        else if (op == "es" or op == " escribir_sesion ") {
            cin >> auxString;

            if (cjtSes.existeix_sessio( auxString )) {
                Sessio ses = cjtSes.accedir_sessio ( auxString );
                ses.escriure_sessio();
            }
            else cout << "ERROR: no existeix la Sessió" << auxString << endl;

        }

        else if (op == "lc" or op == " listar_cursos ") {
            cjtCurs.llistat_cursos();
        }

        else if (op == "ec" or op == " escribir_curso ") {
            cin >> auxInt;

             if (cjtCurs.existeix_curs( auxInt )) {
                Curs curs = cjtCurs.accedir_curs ( auxInt );
                curs.escriure_curs();
            }
            else cout << "ERROR: no existeix el Curs"<< auxInt << endl;

        }

        else if (op == "lu" or op == " listar_usuarios ") {
            cjtUs.llistat_usuaris();
        }

        else if (op == "eu" or op == " escribir_usuario ") {
            cin >> auxString;

             if (cjtUs.existeix_usuari( auxString )) {
                Usuari user = cjtUs.accedir_usuari ( auxString );
                user.escriure_usuari();
            }
            else cout << "ERROR: no existeix el Curs"<< auxInt << endl;
        }

        cin >> op;
    }
}