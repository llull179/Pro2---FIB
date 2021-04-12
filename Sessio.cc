#include "Sessio.hh"

Sessio::Sessio() {}

Sessio::Sessio(BinTree<string> a) {
    prerequisits = a;
}

int Sessio::BinTree_size(const BinTree<string>& a) {
    int x;
    if(not a.empty()) x = 0;
    else x = BinTree_size(a.left()) + BinTree_size(a.right()) + 1;
    return x;
}

void Sessio::escriure_sessio( ) {
    int p = BinTree_size(prerequisits);
    cout <<"Problemes totals: "<<p<<endl;
    escriure_BinTree(prerequisits);
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
    }
}

void Sessio::escriure_BinTree(const BinTree<string>& a) const{
    if(not a.empty()){
        BinTree<string> l = a.left();
        BinTree<string> r = a.right();
        escriure_BinTree(l);
        escriure_BinTree(r);
        cout << a.value() << endl;
    }
}

bool Sessio::trobar_problema( const string& p) const {
    return trobar_valor_BinTree(prerequisits,p);
}

bool Sessio::trobar_valor_BinTree( BinTree<string> & a, const string&p) const {
    bool b;
    if( a.empty()) b = false;
    else if(a.value() == p) b = true;
    else {
        b = trobar_valor_BinTree(a.left(),p);
        if(not b) b = trobar_valor_BinTree(a.right(),p);
    }
}