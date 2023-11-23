#ifndef APTO_H
#define APTO_H

#include "imovel.h"

using namespace std;

class Apartamento : public Imovel{
    int andar;
    float taxa_condominio;
    bool elevador;
    bool sacada;

public:
    Apartamento(int id, float vlr, string prop, string r, string brr, string cdd, int nro, int qrto, int bnhr, int andar, float taxa, bool elvd, bool scd);
    Apartamento();

    ostream& print(ostream& os) const override; //sobreescrita do metodo print
 
    int getAndar() const;
    void setAndar(int andar);
    float getTaxaCondominio() const;
    void setTaxaCondominio(float taxa);
    bool getElevador() const;
    void setElevador(bool elvd);
    bool getSacada() const;
    void setSacada(bool elvd);
};

#endif