#include "Problema.hh"

Problema::Problema() {}

Problema::Problema(i) {
    ident = i;
}

void Problema::actualitzar_problema() {

}

bool Problema::operator<(const Problema &d);

void Problema::escriure_problema() {
    cout<< "Problema: "<< nom << endl;
    cout<< "Enviamnets totals: "<< estadist.env_totals <<endl;
    cout<< "Enviaments amn éxit: " << estadist.env_exit <<endl;
    cout<< "Ratio: "<< estadist.ratio << endl;
        
    
}


void Problema::esborrar_tret(int n, string p, Cjt_individus & cjt){
    map<string,tretstr>::iterator it = trets.find(p); // it
    (*it).second.individus.erase(n); // s'ha esborrat l'individu
    if(it->second.individus.empty()) trets.erase(p); // borro la clau
    else {
        //el set no esta buit 
        //toca recalcular tot el parcrom
        set<int>::iterator it2 = (*it).second.individus.begin(); // primera pos del set individus;
        Individu i = cjt.agafar_individu(*it2);
        Parcrom inter = i.cromosomes();
        ++it2;
        while(it2 != (*it).second.individus.end()) {
            inter.interseccio_tret( inter , cjt.agafar_individu(*it2).cromosomes());
            ++it2;
        }
        it->second.p = inter;
    }
    
}


bool Problema::consultar_tret(const string & p) const  {
    map <string,tretstr>::const_iterator it = trets.find(p);
    if(it != trets.end()) return true;
    else return false;
}



void Problema::escriure(const string & s) const {
    map <string,tretstr>::const_iterator it = trets.find(s);
    it->second.p.escriure_parcrom();
    set <int>::const_iterator it2 = (*it).second.individus.begin();
    while(it2 != (*it).second.individus.end()) {
        cout << "  " << *it2 << endl;
        ++it2;
    }
}
// funcion consulta_tret


