#include "Sessio.hh"
 
Sessio::Sessio() {}

Sessio::Sessio(const string& x) {
    ident =x;
}

void Sessio::escriure_sessio( ) const{
    cout << ' '<< copia_pre.size() << ' ';
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
    bool acaba = false;
    iniciar_enviables_recursiu(prerequisits, resolts, env, acaba);
}

void Sessio::iniciar_enviables_recursiu(const BinTree<string>& a, const GrupProb& resolts, GrupProb& env, bool acaba) {
    if(not a.empty()) {
        if(not resolts.pertany(a.value())) {
        
            env.afegeix(a.value(),0);
        } 
        else {
            iniciar_enviables_recursiu(a.left(), resolts, env,acaba);
            iniciar_enviables_recursiu(a.right(), resolts, env,acaba);
        }
    }
}

void Sessio::actualitza_env(const GrupProb& resolts, GrupProb& env, const string& p) {
    bool acaba = false;
    BinTree<string> a = cerca_subarbre(prerequisits, p);
    iniciar_enviables_recursiu(a, resolts,env,acaba );
}

bool Sessio::recorrer_i_afegir(ProbsSessio& probs) {
    bool creat = true;
    recorrer(prerequisits, probs, ident, creat);
    return creat;
}

void Sessio::recorrer(const BinTree<string>& a, ProbsSessio& probs, const string& s, bool& creable) {
    if(not a.empty() and creable) {
        creable = probs.afegeix_i_comprova(a.value(), s);
        recorrer(a.left(),probs,s, creable);
        recorrer(a.right(),probs,s, creable);
        
    }
}

bool Sessio::existeix_prob(const string& p) {
   return existeix_BinTree_prob(prerequisits, p);

}

bool Sessio::existeix_BinTree_prob(const BinTree<string>& a, const string& p) {
    bool b;
    if (a.empty()) b=false;
    else if (a.value()==p) return true;
    else {
        b=existeix_BinTree_prob(a.left(),p);
        if (not b) b=existeix_BinTree_prob(a.right(),p);
    }
    return b;
}
