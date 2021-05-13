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

void Sessio::escriure_BinTree(const BinTree<string>& a) const{
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
string Sessio::obtenir_arrel() {
    return prerequisits.value();
}

pair<string,string> Sessio::retorna_fills(const string& p) {
    
    map<string,pair<string,string>>::const_iterator it = copia_pre.find(p);
    if(it != copia_pre.end()) return (*it).second;
    return make_pair("0","0");
    
}