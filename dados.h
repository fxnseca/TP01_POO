#ifndef DADOS_H
#define DADOS_H

using namespace std;

#include <vector>
#include <string>
#include <map>
#include "imovel.h"

vector<string> processaString(string &str);
void loadFile(vector<Imovel*> &imoveis);
bool checkProprietario(vector<Imovel*> &imoveis, string proprietario);
vector<Imovel*> filtrarValor(vector<Imovel*> &imoveis, double valor);
vector<Imovel*> filtrarQuartos(vector<Imovel*> &imoveis, int quartos);
vector<Imovel*> filtrarTipo(vector<Imovel*> &imoveis, string tipo);
vector<Imovel*> filtrarCidade(vector<Imovel*> &imoveis, string cidade);
map<string, vector<vector<Imovel*>::iterator>> filtrarProprietario(vector<Imovel*> &imoveis, string proprietario);
void menuImovel(vector<Imovel*> &imoveis, int opcao);
void menuGeral(vector<Imovel*> &imoveis);

#endif
