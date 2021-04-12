#include "Problema.hh"

Problema::Problema() {}

Problema::Problema(const string& i) {
    stats.ident = i;
}

void Problema::actualitzar_problema(bool r) {
    ++stats.env_totals;
    if( r ) ++stats.env_exit;
    stats.ratio = stats.env_totals/stats.env_exit;
}

void Problema::escriure_problema() {
    cout<< "Problema: "<< stats.ident << endl;
    cout<< "Enviamnets totals: "<< stats.env_totals <<endl;
    cout<< "Enviaments amn éxit: " << stats.env_exit <<endl;
    cout<< "Ratio: "<< stats.ratio << endl;
}