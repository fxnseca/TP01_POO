#include <iostream>
#include <string>
#include "imovel.h"

using namespace std;

//construtor
Imovel::Imovel(int id, float vlr,string prop, string r, string brr, string cdd, int nro, int qrto, int bnhr){
    id = id;
    valor = vlr;
    proprietario = prop;
    rua = r;
    bairro = brr;
    cidade = cdd;
    numero = nro;
    quartos = qrto;
    banheiros = bnhr;
}

/** 
 * Método virtual que vai ser sobrecarregado pelas classes que importarem Imovel
 *  É necessário para possibilidar que o polimorfismo no momento de imprimir os dados seja mantido:
 * 
 *  Ex:         
 *  std::vector<Imovel*> imoveis;
 *  Se neste container tiver um objeto Apartamento, sem o método virtual, caso esse objeto
 *  seja impresso, ele vai ser tratado como um objeto de tipo Imovel em vez de Apartamento
 */

ostream& Imovel::print(ostream& os) const{
    os << "----\n" 
        << "\tPROPRIETÁRIO: " << this->getProprietario() << "\n"
        << "\tPRECO: " << this->getValor() << "\n"
        << "\tNRO DE QUARTOS: " << this->getQuartos() << "\n"
        << "\tRUA: " << this->getRua() << "\n"
        << "\tBAIRRO: " << this->getBairro() << "\n"
        << "\tCIDADE: " << this->getCidade() << "\n"
        << "----\n";
    return os;
}

//sobrecarga do operador << pra sintaxe: cout << Imovel:
ostream& operator<<(ostream& os, const Imovel& imovel){
    return imovel.print(os);
}


//Getters e Setters
int Imovel::getId() const{
    return id;
}
void Imovel::setId(int id){
    id = id;
}
float Imovel::getValor() const{
    return valor;
}
void Imovel::setValor(float vlr){
    valor = vlr;
}
string Imovel::getProprietario() const{
    return proprietario;
}
void Imovel::setProprietario(string prop){
    proprietario = prop;
}
string Imovel::getRua() const{
    return rua;
}
void Imovel::setRua(string r){
    rua = r;
}
string Imovel::getBairro() const{
    return bairro;
}
void Imovel::setBairro(string brr){
    bairro = brr;
}
string Imovel::getCidade() const{
    return cidade;
}
void Imovel::setCidade(string cdd){
    cidade = cdd;
}
int Imovel::getNumero() const{
    return numero;
}
void Imovel::setNumero(int nro){
    numero = nro;
}
int Imovel::getQuartos() const{
    return quartos;
}
void Imovel::setQuartos(int qrto){
    quartos = qrto;
}
int Imovel::getBanheiro() const{
    return banheiros;
}
void Imovel::setBanheiro(int bnhr){
    banheiros = bnhr;
}