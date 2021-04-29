#include "Problema.hh"

Problema::Problema() {}

void Problema::actualitzar_stats(bool r) {
    ++stats.env_totals;
    if( r ) ++stats.env_exit;
    stats.ratio = stats.env_totals/stats.env_exit;
}

void Problema::escriure_problema() const {
    cout << '(' <<stats.env_totals << ',' << stats.env_exit << ',';
    cout << stats.ratio << ')' << endl;
}
