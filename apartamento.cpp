#include "imovel.h"
#include "apartamento.h"

using namespace std;

//construtor
Apartamento::Apartamento(int id, float vlr, string prop, string r, string brr, string cdd, int nro, int qrto, int bnhr, int andar, float taxa, bool elvd, bool scd)
: Imovel(id, vlr, prop, r, brr, cdd, nro, qrto, bnhr){
    andar = andar;
    taxa_condominio = taxa;
    elevador = elvd;
    sacada = scd;
}

//sobrecarga do metodo print
ostream& Apartamento::print(ostream& os) const{
    os << "----\n"
        << "\tPROPRIETÁRIO: " << this->getProprietario() << "\n"
        << "\tPRECO: " << this->getValor() << "\n"
        << "\tNRO DE QUARTOS: " << this->getQuartos() << "\n"
        << "\tRUA: " << this->getRua() << "\n"
        << "\tBAIRRO: " << this->getBairro() << "\n"
        << "\tCIDADE: " << this->getCidade() << "\n"
        << "\t" << ((this->getElevador()) ? "POSSUI ELEVADOR" : "NAO POSSUI ELEVADOR") << "\n"
        << "----\n";

        return os;
}

//getter e setters
int Apartamento::getAndar() const{
    return andar;
}
void Apartamento::setAndar(int andar){
    andar = andar;
}
float Apartamento::getTaxaCondominio() const{
    return taxa_condominio;
}
void Apartamento::setTaxaCondominio(float taxa){
    taxa_condominio = taxa;
}
bool Apartamento::getElevador() const{
    return elevador;
}
void Apartamento::setElevador(bool elvd){
    elevador = elvd;
}
bool Apartamento::getSacada() const{
    return sacada;
}
void Apartamento::setSacada(bool scd){
    sacada = scd;
}