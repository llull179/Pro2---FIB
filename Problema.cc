#include "Problema.hh"

Problema::Problema() {}

void Problema::actualitzar_stats(bool r) {
    ++stats.env_totals;
    if( r ) ++stats.env_exit;
    stats.ratio = (stats.env_totals+1)/(stats.env_exit+1);
}

void Problema::escriure_problema()  {
    cout << '(' <<stats.env_totals << ',' << stats.env_exit << ',';
    cout << stats.ratio << ')' << endl;
}

int Problema::get_ratio() const {
  return stats.ratio;
}
