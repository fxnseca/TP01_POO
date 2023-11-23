#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

#include "dados.h"

//MAIN:
int main(){

    //Coleção polimórfica de imóveis
    vector<Imovel*> imoveis;
   
    //Carrega os dados do arquivo
    loadFile(imoveis);

    //Menu geral
    menuGeral(imoveis);
   
    return 0;
}