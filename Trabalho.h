#include<iostream>
#include<string>
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
#define MINIMO 0.00000000000000000000000000001

using namespace std;

class Grafo
{
    private:
        int V; //número de vértices do grafo

        /// ponteiro para um array contendo uma lista de adjacências
        list<pair<int, int> > *adj;
        vector<vector<int>> distCid; // matriz de distâncias

        //int matDist[17][17];

    public:
        /// construtor
        Grafo(int V)
        {
            this->V = V; // atrin=bui o número de vértices

            /*
            cria as listas onde cada lista é composto por pairs.
            Pairs são pares de formados por vértices de destino e o custo.
            */

            adj = new list<pair<int, int> >[V];
            distCid[V][V]; // dimencionando a matriz de distências no método construtor
        }

        /// adiciona aresta ao grafo de v1 à v2
        void addAresta(int v1, int v2, int custo)
        {
            adj[v1].push_back(make_pair(v2, custo));
        }

        /// preenchimento da matriz de distâncias
        void preencherMatrizDist()
        {
            int k, i, j;
            ofstream ofs("matriz.xls",fstream::app);

            for(i = 0; i < V; i++)
            {
                distCid.push_back(vector<int>());

                for(j = 0; j < V; j++)
                {
                    k = dijkstra(i,j);
                    distCid[i].push_back(k);
                }
            }

            for(i = 0; i < V; i++)
            {
                for(j = 0; j < V; j++)
                {
                    cout << " " << distCid[i][j] << "\t";
                    ofs << " "<< distCid[i][j] << "\t";
                }
                ofs << endl;
                cout << endl;
            }
            ofs.close();
        }

        /// mostrar solução
        void  mostarSolucao(list<int> s)
        {
            list<int>::iterator it;
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

        void gravarArquivo(vector<double> x, vector<int> y, string dado) // gravação de dados no arquivo externo para plotar o gráfico
        {
            ofstream ofs(dado,fstream::app); // adiciona no fim do arquivo
            int tam = x.size();
            for(int i = 0; i < tam; i++)
                ofs << x[i] << " " << y[i] << endl;

            ofs.close();
        }

        void gravarArquivo2(vector<int> x, vector<double> y, string dado) // gravação de dados no arquivo externo para plotar o gráfico
        {
            ofstream ofs(dado,fstream::app); // adiciona no fim do arquivo
            int tam = x.size();
            for(int i = 0; i < tam; i++)
                ofs << x[i] << " " << y[i] << endl;

            ofs.close();
        }

        void gravarArquivo3(vector<int> x, vector<int> y, string dado) // gravação de dados no arquivo externo para plotar o gráfico
        {
            ofstream ofs(dado,fstream::app); // adiciona no fim do arquivo
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

            for(int i = 0; i < (v.size() - 1); i++)
                custo += distCid[v[i]][v[i + 1]];

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
            cam[m] = INFINITO;

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

        /// método para gerar arquivo resumo da procura da procura de uma solução melhor
        void gravarDados(tuple<list<int>, int> solIni, tuple<list<int>, int> solMelhor, double tempAtual, int itMaxTemp, int j, string dado) // gravação de dados no arquivo externo para avaliação
        {
            list<int> s, m;

            s = get<0>(solIni);
            m = get<0>(solMelhor);

            ofstream ofs(dado,fstream::app); // adiciona no fim do arquivo

            ofs << "Solução aleatória: " << endl;

            list<int>::iterator it;
            ofs << endl;
            for(it = s.begin(); it != s.end(); it++)
                ofs << *it << " -> ";
            ofs << endl;

            ofs << "Custo: " << get<1>(solIni) << endl;
            ofs << "Temperatura Final: " << tempAtual << endl;
            ofs << "Número máximo de iterações na Temperatura: " << itMaxTemp << endl;
            ofs << "Número máximo de iterações total: " << j << endl;
            ofs << "--------------------------------------------" << endl;
            ofs << endl;
            ofs << "Solução final do Simulated Annealing" << endl;

            for(it = m.begin(); it != m.end(); it++)
                ofs << *it << " -> ";

            ofs << endl;
            ofs << "Custo: " << get<1>(solMelhor) << endl;
            ofs << endl;

            ofs.close();
        }

        tuple<list<int>,int> simulated_Annealing(double alpha, double tempIni, int itMaxTemp, string dado, string dado4, string dado3)
        {
            /// inicialização dos parametros
            tuple<list<int>, int> solMelhor, solIni, solAtual;
            tuple<list<int>, int> solViz;
            vector<int> vy, vy1, vx2; // vetores para plotar gráficos
            vector<double> vx, vx1;
            int j = 0, i = 0, delta; // contador, número de sucesso e variação de custo
            solIni = solucaoAleatoria(); // inicia a solução inicial com uma solução aleatória
            solAtual = solIni;
            solMelhor = solAtual;
            double tempAtual = tempIni; // temperatura atual recebe temperatura inicial
            double exp;


            while(tempAtual > MINIMO) // Enquanto a temperatura atual for maior 0
            {

                while(i < itMaxTemp)
                {
                    solViz = gerarVizinho(get<0>(solMelhor)); // pertubação da solução aleatória produzindo uma outra solução
                    /// Teste de aceitação
                    delta = get<1>(solViz)-get<1>(solAtual);

                    cout << "custo Sol vizinha - custo Sol Atual" << endl;
                    cout << get<1>(solViz) << " - " << get<1>(solAtual) << endl;
                    cout << "Delta: " << delta << endl;

                    if(delta < 0)
                    {
                        if(get<1>(solViz) < get<1>(solMelhor)) // teste de aceitação do vizinho como melhor solução
                            solMelhor = solViz;

                        else
                        {
                            exp = pow(M_E, (-delta/tempAtual));

                            if(exp > numAleatorio_01()) // aceitação aleatória de uma solução ruim - fugir do ótimo local
                                solAtual = solViz;
                        }
                    }

                    cout << "Número de iteração na temperatura: " << i << endl;
                    cout << "Temperatura Atual: " << tempAtual << endl;
                    cout << endl;

                    i++; // iterador para temperatura

                    /// dados para o gráfico
                    vx.push_back(tempAtual);
                    vy.push_back(get<1>(solMelhor));
                    vy1.push_back(j);
                }

                /// dados gráfico temp x iter
                vx1.push_back(tempAtual);
                vx2.push_back(get<1>(solMelhor));


                /// iterador da Temperatura (vizinhança)
                i = 0;

                /// iterador geral
                j++;

                /// atualização da temperatura
                tempAtual = alpha * tempAtual;

            }

            cout << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "Solução aleatória: " << endl;
            mostarSolucao(get<0>(solIni));
            cout << "Custo: " << get<1>(solIni) << endl;
            cout << "Temperatura Final: " << tempAtual << endl;
            cout << "Número máximo de iterações na Temperatura: " << itMaxTemp << endl;
            cout << "Número máximo de iterações total: " << j << endl;
            cout << endl;
            gravarArquivo(vx, vy, dado); // gravando arquivo externo
            gravarDados(solIni, solMelhor, tempAtual, itMaxTemp, j, dado4); // gravando arquivo externo dados para análise
            gravarArquivo3(vy, vy1, dado3); // gravando arquivo externo custo x iter


            return solMelhor;
        }
};


