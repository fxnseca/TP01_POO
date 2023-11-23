#ifndef CASA_H
#define CASA_H

#include "imovel.h"

using namespace std;

class Casa : public Imovel{
    int andares;
    bool sala_jantar;

public:
    Casa(int id, float vlr,string prop, string r, string brr, string cdd, int nro, int qrto, int bnhr, int andrs, bool sj);
    Casa();
    
    ostream& print(ostream& os) const override;

    int getAndares()const;
    void setAndares(int andrs);
    bool getSalaJantar()const;
    void setSalaJantar(bool sj);
};

#endif