#include "imovel.h"
#include "chacara.h"

using namespace std; 

//construtor
Chacara::Chacara(int id, float vlr, string prop, string r, string brr, string cdd, int nro, int qrto, int bnhr, bool sf, bool sjg, bool cf, bool churr, bool pisc)
: Imovel(id, vlr, prop, r, brr, cdd, nro, qrto, bnhr){
    salao_festa = sf;
    salao_jogos = sjg;
    campo_futebol = cf;
    churrasqueira = churr;
    piscina = pisc;
}

//sobrecarga do metodo print
ostream& Chacara::print(ostream& os) const{
    os << "----\n"
        << "\tPROPRIETÁRIO: " << this->getProprietario() << "\n"
        << "\tPRECO: " << this->getValor() << "\n"
        << "\tNRO DE QUARTOS: " << this->getQuartos() << "\n"
        << "\tRUA: " << this->getRua() << "\n"
        << "\tBAIRRO: " << this->getBairro() << "\n"
        << "\tCIDADE: " << this->getCidade() << "\n"
        << "\t" << ((this->getPiscina()) ? "POSSUI PISCINA" : "NAO POSSUI PISCINA") << "\n"
        << "----\n";

        return os;
}

//getters e setters
bool Chacara::getSalaoFesta() const{
    return salao_festa;
}
void Chacara::setSalaoFesta(bool sf){
    salao_festa = sf;
}
bool Chacara::getSalaoJogos() const{
    return salao_jogos;
}
void Chacara::setSalaoJogos(bool sjg){
    salao_jogos = sjg;
}
bool Chacara::getCampoFutebol() const{
    return campo_futebol;
}
void Chacara::setCampoFutebol(bool cf){
    campo_futebol = cf;
}
bool Chacara::getChurrasqueira() const{
    return churrasqueira;
}
void Chacara::setChurrasqueira(bool churr){
    churrasqueira = churr;
}
bool Chacara::getPiscina() const{
    return piscina;
}
void Chacara::setPiscina(bool pisc){
    piscina = pisc;
}