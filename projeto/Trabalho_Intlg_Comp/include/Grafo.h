#ifndef GRAFO_H
#define GRAFO_H
#include<iostream>
#include<fstream>
#include<list>
#include<vector>
#include<tuple>
#include<queue>
#include <cstdlib>
#include <ctime>
#include<chrono>
#include<cmath>
#define INFINITO 100000
#define MINIMO 0.0000000000000000000000000000000000000000000001

using namespace std;

class Grafo
{
    private:
        int V; //número de vértices do grafo

        /// ponteiro para um array contendo uma lista de adjacências
        list<pair<int, int> > *adj;

    public:
        /// contrutos
        Grafo(int V)
        {
            this->V = V; // atrin=bui o número de vértices

            /*
            cria as listas onde cada lista é composto por pairs.
            Pairs são pares de formados por vértices de destino e o custo.
            */

            adj = new list<pair<int, int> >[V];
        }

        /// adiciona aresta ao grafo de v1 à v2
        void addAresta(int v1, int v2, int custo)
        {
            adj[v1].push_back(make_pair(v2, custo));
        }

        /// mostrar solução
        void  mostarSolucao(list<int> s)
        {
            list<int>::iterator it;
            cout << "Mostrando solução";
            cout << endl;
            for(it = s.begin(); it != s.end(); it++)
                cout << *it << " -> ";
            cout << endl;
        }

        /// algoritmo de dijkstra
        int dijkstra(int orig, int dest)
        {
            // vetor de distâncias
            int dist[V];

            /*
                vetor de visitados serve para marcar um vértice
                 que já tenha sido expandido para que não seja feito novamente.
            */
            int visitados[V];

            // conteiner fila que coloca no topo o destino com menor custo
            priority_queue < pair<int, int>,
                vector<pair<int, int> >, greater<pair<int, int> > > pq;

            for(int i = 0; i < V; i++)
            {
                dist[i] = INFINITO;
                visitados[i] = false;
            }

            // a distâncoa da origem para ela mesma é zero
            dist[orig] = 0;

            // insere na fila
            pq.push(make_pair(dist[orig], orig));

            //loop do algoritmo
            while(!pq.empty())
            {
                pair<int, int> p = pq.top(); // extrai o pair do topo
                int u = p.second; // obtem o vértice do pair
                pq.pop(); // remove da fila

                // verifica se o vértice não foi expandido
                if(visitados[u] == false)
                {
                    // marca como visitado
                    visitados[u] = true;

                    // percorre os vértices "v" adjacentes de "u"
                    list<pair<int, int> > ::iterator it;

                    for(it = adj[u].begin(); it != adj[u].end(); it++)
                    {
                        // obtém o vértice adjacente e o custo da aresta
                        int v = it->first;
                        int custo_aresta = it->second;

                        // relaxamento (u, v)
                        if(dist[v] > (dist[u] + custo_aresta))
                        {
                            //atualiza a distância de "v" e insere na fila de prioridades
                            dist[v] = dist[u] + custo_aresta;
                            pq.push(make_pair(dist[v], v));
                        }

                    }
                }
            }
            // retorna a distância mínima até o destino
            return dist[dest];
        }

        void gravarArquivo(vector<int> x, vector<int> y) // gravação de dados no arquivo externo para plotar o gráfico
        {
            ofstream ofs("dados.grafico",fstream::app); // adiciona no fim do arquivo
            int tam = x.size();
            for(int i = 0; i < tam; i++)
                ofs << x[i] << " " << y[i] << endl;

            ofs.close();
        }

        int numAleatorio(int numIni, int numFim)
        {
            //srand((unsigned)time(NULL));
            int num = numIni + rand()%numFim;
            return num;
        }

        double numAleatorio_01() // número aleatório entre 0 e 1
        {
            int num = numAleatorio(1, 100);
            double  num2 = (double) num/100;
            return num2;
        }

        int custoSolucao(list<int> sol)// recebe uma solução (lista de vetores) e retorna um custo desta solução
        {
            int custo = 0;
            vector<int> v;

            list<int>::iterator it;                        // inicializando o vetor
            for(it = sol.begin(); it != sol.end(); it++)   // com os elementos da lista
                v.push_back(*it);

            for(unsigned int i = 0; i < (v.size() - 1); i++)
                custo += dijkstra(v[i], v[i + 1]);// calculando o custo cumulativo

            return custo;
        }

        tuple<list<int>,int> solucaoAleatoria() // retorna uma lista vom vértices de uma solução aleatória
        {
            //srand((unsigned)time(NULL));
            list<int> s1;
            int cam[V];
            int i = 1;// tendo em vista que a posição zero do vetor será sempre o vértice inicial (zero)
            int num, cont = 0;
            int cost = 0;

            // inicializar o vetor cam em cada posição com INFINITO
            for(int m = 0; m < V; m++)
            {
                cam[m] = INFINITO;
            }

            cam[0] = 0;// todas as soluções deve iniciar na posição zero

            while(i < V)// esse loop gera os vértices aleatórios, não repetidos, de uma solução inicial
            {
                num = rand()%V; // gera números aleatórios entre 0 e o tamanho do grafo
                for(int j = 0; j < V; j++)
                {
                    if(num == cam[j])
                        cont++;
                }

                if(cont == 0)
                {
                    cam[i] = num; // vértices sendo guardados em um vetor
                    i++;
                }
                cont = 0;

            }

            s1.assign(cam, cam + V); // lista sendo preenchida com os valores do vetor solução - gerando uma lista com a solução
            cost = custoSolucao(s1);
            return make_tuple(s1,cost);
        }

        tuple<list<int>,int> vizinho_1(list<int> s) // coloca o conteúdo da uma posição aleatória no final da lista
        {
            list<int> sv1;
            vector<int> cam1;
            int pos = 0;
            int costsv1 = 0;

            do
            {
                pos = numAleatorio(1, V - 1); // escolha de uma posição

            }while(pos == (V - 1));

            list<int>::iterator it;
            for(it = s.begin(); it != s.end(); it++)
                cam1.push_back(*it);// inicializando o vetor

            vector<int>::iterator it2;
            it2 = cam1.begin();
            it2 = it2 + pos;
            int troca = *it2;          // coloca o elemento da
            cam1.erase(it2);             // segunda posição no final
            cam1.push_back(troca);

            for(it2 = cam1.begin(); it2 != cam1.end(); it2++)
                sv1.push_back(*it2);     // carrega uma lista

            costsv1 = custoSolucao(sv1);
            return make_tuple(sv1,costsv1);
        }

        tuple<list<int>,int> vizinho_2(list<int> s) // Troca duas posições aleatórias de lugar
        {
            list<int> sv1;
            vector<int> cam1;
            int pos1 = 0, pos2 = 0;
            int costsv1 = 0;

            while(pos1 == pos2) //escolha das posições envolvidas na troca
            {
                pos1 = numAleatorio(1, V - 1);
                pos2 = numAleatorio(1, V - 1);
            }

            list<int>::iterator it;
            for(it = s.begin(); it != s.end(); it++)
                cam1.push_back(*it);// inicializando o vetor

            // fazendo a troca das posição de dois números
            vector<int>::iterator it2;
            it2 = cam1.begin();
            it2 = it2 + pos1;
            int troca1 = *it2;

            it2 = cam1.begin();
            it2 = it2 + pos2;
            int troca2 = *it2;

            it2 = cam1.begin();
            it2 = it2 + pos1;
            cam1.erase(it2);
            cam1.insert(it2, troca2);

            it2 = cam1.begin();
            it2 = it2 + pos2;
            cam1.erase(it2);
            cam1.insert(it2, troca1);

            for(it2 = cam1.begin(); it2 != cam1.end(); it2++)
                sv1.push_back(*it2);     // carrega uma lista

            costsv1 = custoSolucao(sv1);
            return make_tuple(sv1,costsv1);
        }

        tuple<list<int>,int> gerarVizinho(list<int> s)
        {
            int escolha;
            escolha = numAleatorio(1, 2);
            switch(escolha)
            {
                case 1:
                    return vizinho_1(s);
                case 2:
                    return vizinho_2(s);
            }
        }

        tuple<list<int>,int> simulated_Annealing(double alpha, double tempIni, int itMaxTemp)
        {
            // alpha = fator de redução da temperatura
            // tempIni = temperatura inicial
            // itMaxTemp = número máximo de iterações na temperatura

            /// inicialização dos parametros
            tuple<list<int>, int> solMelhor, solIni, solAtual;
            tuple<list<int>, int> solViz[itMaxTemp];
            vector<int> vx, vy; // vetores para plotar gráficos
            int j = 1, i, delta; // contador, número de sucesso e variação de custo
            solIni = solucaoAleatoria(); // inicia a solução inicial com uma solução aleatória
            solAtual = solIni;
            solMelhor = solAtual;
            double tempAtual = tempIni; // temperatura atual recebe temperatura inicial
            double exp;


            while(tempAtual > MINIMO) // Enquanto a temperatura atual for maior 0
            {
                for(int v = 0; v < itMaxTemp; v++)
                {
                    solViz[v] = gerarVizinho(get<0>(solMelhor)); // pertubação da solução aleatória produzindo uma outra solução
                    mostarSolucao(get<0>(solViz[v]));
                }

                while(i < itMaxTemp)
                {
                    /// Teste de aceitação
                    delta = get<1>(solViz[i])-get<1>(solAtual);

                    cout << "custo Sol vizinha - custo Sol Atual" << endl;
                    cout << get<1>(solViz[i]) << " - " << get<1>(solAtual) << endl;
                    cout << "Delta: " << delta << endl;

                    if(delta < 0)
                    {
                        if(get<1>(solViz[i]) < get<1>(solMelhor)) // teste de aceitação do vizinho como melhor solução
                            solMelhor = solViz[i];

                        else
                        {
                            exp = pow(M_E, (-delta/tempAtual));

                            if(exp > numAleatorio_01()) // aceitação aleatória de uma solução ruim - fugir do ótimo local
                                solAtual = solViz[i];
                        }

                    }

                    cout << "Número de iteração na temperatura: " << i << endl;
                    cout << "Temperatura Atual: " << tempAtual << endl;
                    cout << endl;

                    i++; // iterador para temperatura

                }
                /// iterador da Temperatura (vizinhança)
                i = 0;

                /// atualização da temperatura
                tempAtual = alpha * tempAtual;

                /// dados para o gráfico
                vx.push_back(j);
                vy.push_back(get<1>(solMelhor));

            }

            cout << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "Solução aleatória: " << endl;
            mostarSolucao(get<0>(solIni));
            cout << "Custo: " << get<1>(solIni) << endl;
            cout << "Temperatura Final: " << tempAtual << endl;
            cout << "Número máximo de iterações na Temperatura: " << itMaxTemp << endl;
            cout << endl;
            gravarArquivo(vx, vy); // gravando arquivo externo

            return solMelhor;
        }
};

#endif // GRAFO_H
