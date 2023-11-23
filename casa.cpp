#include "imovel.h"
#include "casa.h"

using namespace std;

//construtor
Casa::Casa(int id, float vlr, string prop, string r, string brr, string cdd, int nro, int qrto, int bnhr, int andrs, bool sj) 
: Imovel(id, vlr, prop, r, brr, cdd, nro, qrto, bnhr){
    andares = andrs;
    sala_jantar = sj;
}

//sobrecarga do metodo print
ostream& Casa::print(ostream& os) const{
    os << "----\n"
        << "\tPROPRIETÁRIO: " << this->getProprietario() << "\n"
        << "\tPRECO: " << this->getValor() << "\n"
        << "\tNRO DE QUARTOS: " << this->getQuartos() << "\n"
        << "\tRUA: " << this->getRua() << "\n"
        << "\tBAIRRO: " << this->getBairro() << "\n"
        << "\tCIDADE: " << this->getCidade() << "\n"
        << "\tANDARES: " << this->getAndares() << "\n"
        << "----\n";

        return os;
}

//getters e setters
int Casa::getAndares()const {
    return andares;
}
void Casa::setAndares(int andrs){
    andares = andrs;
}
bool Casa::getSalaJantar()const {
    return sala_jantar;
}
void Casa::setSalaJantar(bool sj){
    sala_jantar = sj;
}