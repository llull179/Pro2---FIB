/*#include "Problema.hh"

Problema::Problema() {}

Problema::Problema(i) {
    Stats.ident = i;
}

void Problema::actualitzar_problema(bool r) {
    ++Stats.env_totals;
    if( r ) ++Stats.env_exit;
    Stats.ratio = Stats.env_totals/Stats.env_exit;
}

void Problema::escriure_problema() {
    cout<< "Problema: "<< Stats.ident << endl;
    cout<< "Enviamnets totals: "<< Stats.env_totals <<endl;
    cout<< "Enviaments amn éxit: " << Stats.env_exit <<endl;
    cout<< "Ratio: "<< Stats.ratio << endl;


}
