#include <iostream>
#include "BinTree.hh"
#include <map>
using namespace std;
map<string, pair<string,string>> m;
void lletgir_BinTree(BinTree<string>& a) {
    string x;
    cin >> x;
    
    if (x != "0") {
        BinTree<string> l;
        BinTree<string> r;
        lletgir_BinTree(l);
        lletgir_BinTree(r);
        a = BinTree<string>(x,l,r);
         string esq, dre;
        esq = dre = "0";
        if (not a.left().empty()) esq = a.left().value();
        if (not a.right().empty()) dre = a.right().value();
        m.insert(make_pair(x,make_pair(esq,dre)));
    }
}

string agafa_iessim(int x) {
    map<string,pair<string,string>>::const_iterator it = m.begin();
    for(int i = 0; i < x; ++i) ++it;
   return (*it).first;
}


int main() {
    BinTree<string> a;
    lletgir_BinTree(a);
     cout<<"----m---"<<endl;
    for(map<string,pair<string,string>>::const_iterator it = m.begin(); it!=m.end();it++) {
        cout<<"father: "<<(*it).first<<" /children: "<<(*it).second.first<< " i "<<(*it).second.second<<endl;
    }
    

}