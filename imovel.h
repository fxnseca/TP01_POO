#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>
#include <iostream>

using namespace std;

class Imovel{
    int id;
    string proprietario;
    string rua;
    string bairro;
    string cidade;
    int numero;
    int quartos;
    int banheiros;

public:
    float valor; //tava na parte publica (entender o pq)

    //sobrecarga de metodos
    Imovel(int id, float vlr,string prop, string r, string brr, string cdd, int nro, int qrto, 
    int bnhr);
    Imovel(); //polimorfismo

    //função amiga
    friend ostream& operator<<(ostream& os, const Imovel& imovel);

    //virtual
    virtual ostream& print(ostream& os) const = 0;
    
    int getId() const;
    void setId(int id);
    float getValor() const;
    void setValor(float valor);
    string getProprietario() const;
    void setProprietario(string prop);
    string getRua() const;
    void setRua(string r);
    string getBairro() const;
    void setBairro(string brr);
    string getCidade() const;
    void setCidade(string cdd);
    int getNumero() const;
    void setNumero(int nro);
    int getQuartos() const;
    void setQuartos(int qrto);
    int getBanheiro() const;
    void setBanheiro(int bnhr);

};

#endif