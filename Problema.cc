#include "Problema.hh"

Problema::Problema() {}

void Problema::actualitzar_stats(bool r) {
    ++stats.env_totals;
    if( r ) ++stats.env_exit;
    
}
void Problema::actualitzar_ratio() {
  stats.ratio = double(stats.env_totals + 1)/(stats.env_exit + 1);
}

void Problema::escriure_problema()  {
    cout << '(' <<stats.env_totals << ',' << stats.env_exit << ',';
    cout  << double(stats.env_totals + 1)/(stats.env_exit + 1) << ')' << endl;
}

double Problema::get_ratio() const {
  return stats.ratio;
}
