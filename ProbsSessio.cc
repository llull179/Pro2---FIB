#include "ProbsSessio.hh"

ProbsSessio::ProbsSessio() {}

void ProbsSessio::afegeix(const string& p, const string& s) {
     probs_ses.insert(make_pair(p,s));
}   

bool ProbsSessio::afegeix_i_comprova(const string& p, const string& s) {
    pair<map<string,string>::const_iterator,bool> r = probs_ses.insert(make_pair(p,s));
    return r.second;
}

string ProbsSessio::retorna_sessio(const string& p) const{
    map<string,string>::const_iterator it = probs_ses.find(p);
    if(it != probs_ses.end()) return (*it).second;
    return "0";
}

void ProbsSessio::mostra() {
   for( map<string,string>::const_iterator it = probs_ses.begin();it!=probs_ses.end();++it) {
       cout<<(*it).first<<" i " << (*it).second<<endl;
   }
}
bool ProbsSessio::empty() const{
    if(probs_ses.size() == 0) return true;
    else return false;
}