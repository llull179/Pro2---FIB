#include "Sessio.hh"
 
Sessio::Sessio() {}

int Sessio::get_size() {
    return copia_pre.size();
}

void Sessio::escriure_sessio( ) {
    cout << ' '<< get_size() << ' ';
    escriure_BinTree(prerequisits);
    cout << endl;
}

void Sessio::lletgir_BinTree(BinTree<string>& a) {
    string x;
    cin >> x;
    
    if (x != "0") {
        BinTree<string> l;
        BinTree<string> r;
        lletgir_BinTree(l);
        lletgir_BinTree(r);
        a = BinTree<string>(x,l,r);
        prerequisits = a;
         string esq, dre;
        esq = dre = "0";
        if (not a.left().empty()) esq = a.left().value();
        if (not a.right().empty()) dre = a.right().value();
        copia_pre.insert(make_pair(x,make_pair(esq,dre)));
    }
}

void Sessio::escriure_BinTree(const BinTree<string>& a) {
    if(not a.empty()){
        BinTree<string> l = a.left();
        BinTree<string> r = a.right();
        cout << '(';
        escriure_BinTree(l);
        escriure_BinTree(r);
        cout << a.value();
        cout << ')';
    }
} 

string Sessio::agafa_iessim(int x) {
    map<string,pair<string,string>>::const_iterator it = copia_pre.begin();
    for(int i = 0; i < x; ++i) ++it;
    if(it != copia_pre.end()) return (*it).first;
    return "0";
}

BinTree<string> Sessio::cerca_subarbre(const BinTree<string>& a, const string& problema) {
    BinTree<string> r;
    if(a.empty()) return r;
    else if(a.value() == problema) return a;
    else {
        r = cerca_subarbre(a.left(),problema);
        if(r.empty()) r = cerca_subarbre(a.right(),problema);
        return r;
    }
}

void Sessio::iniciar_enviables( const GrupProb& resolts, GrupProb& env) {
    iniciar_enviables_recursiu(prerequisits, resolts, env);
}

void Sessio::iniciar_enviables_recursiu(const BinTree<string>& a, const GrupProb& resolts, GrupProb& env) {
    if(not a.empty()) {
        if(not resolts.pertany(a.value())) env.afegeix(a.value(),0);

        else {
            iniciar_enviables_recursiu(a.left(), resolts, env);
            iniciar_enviables_recursiu(a.right(), resolts, env);
        }
    }
}

void Sessio::actualitza_env(const GrupProb& resolts, GrupProb& env, const string& p) {
    BinTree<string> a = cerca_subarbre(prerequisits, p);
    iniciar_enviables_recursiu(a, resolts,env );
}