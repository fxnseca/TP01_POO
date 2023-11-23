#ifndef CHACARA_H
#define CHACARA_H

#include "imovel.h"

using namespace std;

class Chacara : public Imovel{
    bool salao_festa;
    bool salao_jogos;
    bool campo_futebol;
    bool churrasqueira;
    bool piscina;

public:
    Chacara(int id, float vlr, string prop, string r, string brr, string cdd, int nro, int qrto, int bnhr, bool sf, bool sjg, bool cf, bool churr, bool pisc);
    Chacara();

    ostream& print(ostream& os) const override;

    bool getSalaoFesta() const;
    void setSalaoFesta(bool sf);
    bool getSalaoJogos() const;
    void setSalaoJogos(bool sjg);
    bool getCampoFutebol() const;
    void setCampoFutebol(bool cf);
    bool getChurrasqueira() const;
    void setChurrasqueira(bool churr);
    bool getPiscina() const;
    void setPiscina(bool pisc);
};

#endif