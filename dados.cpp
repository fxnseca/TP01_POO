#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

#include "apartamento.h"
#include "casa.h"
#include "chacara.h"
#include "imovel.h"

using namespace std;

//Função pra processar a linha do arquivo e transformar em vetor de strings
vector<string> processaString(string &str){
    str.erase(remove(str.begin(), str.end(), '\n'), str.end());
   
    vector<string> result;
    istringstream iss(str);

    for (string token; getline(iss, token, ';');){
        result.push_back(move(token));
    }
    return result;
}

//Função para carregar os dados do arquivo para a o vetor
void loadFile(vector<Imovel*> &imoveis){
    
    vector<string> dados;
    string linha;
    ifstream file("database_imoveis.txt");
    int id_count = 0;

    while(getline(file, linha)){
        dados = processaString(linha); //converte string em vetor

        //confere a primeira linha e cria o objeto
        //APARTAMENTO:
        if(dados[0] == "apartamento"){
            imoveis.push_back(new Apartamento(id_count,
                                            stof(dados[1]), //conversão string para float
                                            dados[2],
                                            dados[3],
                                            dados[4],
                                            dados[5],
                                            stoi(dados[6]), //conversão string para int
                                            stoi(dados[7]),
                                            stoi(dados[8]),
                                            stoi(dados[9]),
                                            stoi(dados[10]),
                                            stoi(dados[11]),
                                            stoi(dados[12])));
        }
        //CASA:
        else if(dados[0] == "casa"){
            imoveis.push_back(new Casa(id_count,
                                        stof(dados[1]),
                                        dados[2],
                                        dados[3],
                                        dados[4],
                                        dados[5],
                                        stoi(dados[6]),
                                        stoi(dados[7]),
                                        stoi(dados[8]),
                                        stoi(dados[9]),
                                        stoi(dados[10])));
        }
        //CHACARA:
        else if(dados[0] == "chacara"){
            imoveis.push_back(new Chacara(id_count,
                                        stof(dados[1]), 
                                        dados[2],
                                        dados[3],
                                        dados[4],
                                        dados[5],
                                        stoi(dados[6]), 
                                        stoi(dados[7]),
                                        stoi(dados[8]),
                                        stoi(dados[9]),
                                        stoi(dados[10]),
                                        stoi(dados[11]),
                                        stoi(dados[12]),
                                        stoi(dados[13])));
        }
        id_count++;
    }
    file.close();
}

// 2.Função pra verificar se um proprietário existe no doc
bool checkProprietario(vector<Imovel*> &imoveis, string proprietario){
    
    vector<Imovel*> resultado;

    for(int i = 0; i < imoveis.size(); i++){
        if(imoveis[i]->getProprietario() == proprietario){
            return true;
        }
    }
    return false;
}

// 3.Função pra filtrar o valor
vector<Imovel*> filtrarValor(vector<Imovel*> &imoveis, double valor){
    vector<Imovel*> resultado;

    for (int i = 0; i < imoveis.size(); i++){
        if(imoveis[i]->getValor() <= valor){
            resultado.push_back(imoveis[i]); //armazena no vetor resultado os precos
        }
    }
    return resultado;    
}

// 4.Função pra filtrar o imoveis pelo numero de quartos
vector<Imovel*> filtrarQuartos(vector<Imovel*> &imoveis, int quartos){
    vector<Imovel*> resultado;

    for (int i = 0; i < imoveis.size(); i++){
        if(imoveis[i]->getQuartos() >= quartos){
            resultado.push_back(imoveis[i]); //armazena no vetor resultado os precos
        }
    }
    return resultado;    
}

// 5.Função pra filtrar imoveis pelo tipo (casa, apto ou chacara)
vector<Imovel*> filtrarTipo(vector<Imovel*> &imoveis, string tipo){
    vector<Imovel*> resultado;

    for (int i = 0; i < imoveis.size(); i++){
        //Fazendo downcasting pra verificar se o objeto é um apto
        if(tipo == "apartamento" && dynamic_cast<Apartamento*> (imoveis[i]) != nullptr){
            resultado.push_back(imoveis[i]); //insere no vetor resultado dos precos
        }
        //Fazendo downcasting pra verificar se o objeto é uma casa
        else if(tipo == "casa" && dynamic_cast<Casa*> (imoveis[i]) != nullptr){
            resultado.push_back(imoveis[i]); //insere no vetor resultado dos precos
        }
        else if(tipo == "chacara" && dynamic_cast<Chacara*> (imoveis[i]) != nullptr){
            resultado.push_back(imoveis[i]); //insere no vetor resultado dos precos
        }
    }

    /**
     * Ordenando o vetor com o método sort utilizando como critério o valor
     * Para realizar isso é necessário passar uma função de comparação e isso
     * foi feito utilizando uma expressão lambda
     */
    sort(resultado.begin(), resultado.end(), [](const Imovel *l, const Imovel *r){
        return l->getValor() < r->getValor();
    });

    return resultado;    
}

//6. Função pra filtrar imoveis pela cidade
vector<Imovel*> filtrarCidade(vector<Imovel*> &imoveis, string cidade){
    vector<Imovel*> resultado;

    for (int i = 0; i < imoveis.size(); i++){
        if(imoveis[i]->getCidade() == cidade){
            resultado.push_back(imoveis[i]); //armazena no vetor resultado as cidades
        }
    }

    /**
     * Ordenando o vetor com o método sort utilizando como critério o valor
     * Para realizar isso é necessário passar uma função de comparação é isso
     * foi feito utilizando uma expressão lambda
     */
    sort(resultado.begin(), resultado.end(), [](const Imovel *l, const Imovel *r){
        return l->getValor() > r->getValor();
    });

    return resultado;    
}

//7. Função que retorna um iterador para cada tipo de imóvel que um proprietário tenha
// esse retorno é feito com um map do tipo <std::string, std::vector<Imovel*>::iterator>
map<string, vector<vector<Imovel*>::iterator>> filtrarProprietario(vector<Imovel*> &imoveis, string proprietario){
    
    vector<vector<Imovel*>::iterator> im;
    map<string, vector<vector<Imovel*>::iterator>> resultado { 
        {"apartamento", im}, 
        {"casa", im}, 
        {"chacara", im}  
    }; 
    vector<Imovel*>::iterator ptr;

    for(ptr = imoveis.begin(); ptr < imoveis.end(); ptr++){
        //Verificando se o apartamento é do proprietário
         if((*ptr)->getProprietario() == proprietario && dynamic_cast<Apartamento*>(*ptr) != nullptr){
            resultado["apartamento"].push_back(ptr);
        }
        //Verificando se a casa é do proprietário
        if((*ptr)->getProprietario() == proprietario && dynamic_cast<Casa*>(*ptr) != nullptr){
            resultado["casa"].push_back(ptr);
        }
        //Verificando se a chacara é do proprietário
        if((*ptr)->getProprietario() == proprietario && dynamic_cast<Chacara*>(*ptr) != nullptr){
            resultado["chacara"].push_back(ptr);
        }
    }

    return resultado;    
}

//8. Display de saída
void menuImovel(vector<Imovel*> &imoveis, int opcao){
    if(opcao == 0){
        for(int i = 0; i < imoveis.size(); i++){
            cout << *imoveis[i] << endl;
        }
    }
    else if(opcao == 1){
        ofstream file("saida.txt");
        for(int i = 0; i < imoveis.size(); i++){
            file << *imoveis[i] << endl;
        }
        file.close();
    }
}

void menuGeral(vector<Imovel*> &imoveis){
    int opcao, mode, min_quartos;
    string proprietario, tipo, cidade , proprietario2;
    bool proprietario_encontrado;
    double max_valor;
    vector<Imovel*> imoveis_filtro_valor, imoveis_filtro_quartos, imoveis_filtro_tipo, imoveis_filtro_cidade;
    map<string, vector<vector<Imovel*>::iterator>> imoveis_filtro_proprietario;
    

    do{ 
        cout << "\n====================> MENU GERAL <====================\n" << endl;
        cout << "1. Imoveis disponiveis" << endl;
        cout << "2. Imoveis de um proprietario" << endl;
        cout << "3. Imoveis por valor" << endl;
        cout << "4. Imoveis por numero minimo de quartos" << endl;
        cout << "5. Imoveis por tipo" << endl;
        cout << "6. Imoveis por cidade" << endl;
        cout << "7. Imoveis de um proprietario separados por tipo" << endl;
        cout << "8. Sair" << endl;
        cout << "\n===> Digite a opcao desejada: ";
        cin >> opcao;

        switch (opcao){
            case 1:  //impressão dos imoveis
                cout << "\n====================> MENU GERAL <====================\n" << endl;
                cout << "0. Mostrar no terminal" << endl;
                cout << "1. Imprimir em documento.txt" << endl;
                cout << "\n===> Digite a opcao desejada: ";
                cin >> mode;

                if(mode == 0){
                    menuImovel(imoveis, 0);
                }
                else if(mode == 1){
                    menuImovel(imoveis, 1);
                }
            break;
        
            case 2:  //pesquisa de proprietario
                cout << "\n====================> MENU GERAL <====================\n" << endl;
                cout << "Digite o nome do proprietario: ";  
                cin >> proprietario;

                proprietario_encontrado = checkProprietario(imoveis, proprietario);
                (proprietario_encontrado) ? cout << "EXISTE IMOVEL DESSE PROPRIETARIO!" << endl : cout << "NAO EXISTE IMOVEL DESSE PROPRIETARIO." << endl;
            break;

            case 3: //pesquisa por valor
                cout << "\n====================> MENU GERAL <====================\n" << endl;
                cout << "Digite o valor maximo que deseja: ";  
                cin >> max_valor;

                imoveis_filtro_valor = filtrarValor(imoveis, max_valor);
                menuImovel(imoveis_filtro_valor, 0);
            break;

            case 4: // pesquisa por nro de quartos
                cout << "\n====================> MENU GERAL <====================\n" << endl;
                cout << "Digite o numero minimo de quartos que deseja: ";  
                cin >> min_quartos;
                
                imoveis_filtro_quartos = filtrarQuartos(imoveis, min_quartos);
                menuImovel(imoveis_filtro_quartos, 0);
            break;

            case 5: // pesquisa por tipo
                cout << "\n====================> MENU GERAL <====================\n" << endl;
                cout << "Digite o tipo de imovel que deseja: ";  
                cin >> tipo;
                
                imoveis_filtro_tipo = filtrarTipo(imoveis, tipo);
                menuImovel(imoveis_filtro_tipo, 0);
            break;

            case 6: // pesquisa por cidade
                cout << "\n====================> MENU GERAL <====================\n" << endl;
                cout << "Digite a cidade que deseja: ";  
                cin >> cidade;
                
                imoveis_filtro_cidade = filtrarCidade(imoveis, cidade);
                menuImovel(imoveis_filtro_cidade, 0);
            break;

            case 7: //pesquisa dos imoveis de um proprietario separados por tipo
                cout << "\n====================> MENU GERAL <====================\n" << endl;
                cout << "Digite o nome do proprietario: ";  
                cin >> proprietario2;
                imoveis_filtro_proprietario = filtrarProprietario(imoveis, proprietario2);
        
                //Verificando se foi encontrado um apartamento no nome do proprietario
                if(imoveis_filtro_proprietario["apartamento"].size() == 0) cout << "NENHUM APARTAMENTO FOI ENCONTRADO NO NOME DESSE PROPRIETARIO." << endl;
                for(auto ptr : imoveis_filtro_proprietario["apartamento"]){
                    cout << **ptr << endl;
                }

                //Verificando se foi encontrado uma casa no nome do proprietario
                if(imoveis_filtro_proprietario["casa"].size() == 0) cout << "NENHUMA CASA FOI ENCONTRADA NO NOME DESSE PROPRIETARIO." << endl;
                for(auto ptr : imoveis_filtro_proprietario["casa"]){
                    cout << **ptr << endl;
                }

                //Verificando se foi encontrado uma chacara no nome do proprietario
                if(imoveis_filtro_proprietario["chacara"].size() == 0) cout << "NENHUMA CHACARA FOI ENCONTRADA NO NOME DESSE PROPRIETARIO." << endl;
                for(auto ptr : imoveis_filtro_proprietario["chacara"]){
                    cout << **ptr << endl;
                }       
            break;

            case 8: //sair
                cout << "\n====================> ENCERRANDO SISTEMA <====================\n" << endl;
                exit(0);
        }
    } while (opcao != 8);
}