#include<iostream>
#include<tuple>
#include<list>
#include "Grafo.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));

    int tamanho_garfo = 17;
    //int caminho[tamanho_garfo];
    Grafo g(tamanho_garfo);
    tuple<list<int>,int> t, tv_1, tv_2, tv_3, tv_SA;
    list<int> s, sv1, sv2, sv3, svSA;

    /*
    g.addAresta(0, 2, 2);
    g.addAresta(0, 1, 4);
    g.addAresta(0, 3, 5);
    g.addAresta(1, 4, 1);
    g.addAresta(1, 2, 1);
    g.addAresta(2, 1, 1);
    g.addAresta(2, 3, 2);
    g.addAresta(2, 4, 1);
    g.addAresta(3, 4, 1);
    g.addAresta(3, 2, 2);
    g.addAresta(4, 2, 1);
    g.addAresta(4, 3, 1);
    */

    g.addAresta(0, 1, 430);
    g.addAresta(1, 0, 430);
    g.addAresta(1, 2, 526);
    g.addAresta(2, 1, 526);
    g.addAresta(2, 11, 2894);
    g.addAresta(11, 2, 2894);
    g.addAresta(0, 7, 602);
    g.addAresta(7, 0, 602);
    g.addAresta(7, 8, 112);
    g.addAresta(8, 7, 112);
    g.addAresta(8, 10, 206);
    g.addAresta(10, 8, 206);
    g.addAresta(10, 11, 62);
    g.addAresta(11, 10, 62);
    g.addAresta(8, 9, 125);
    g.addAresta(9, 8, 125);
    g.addAresta(8, 12, 366);
    g.addAresta(12, 8, 366);
    g.addAresta(9, 16, 688);
    g.addAresta(16, 9, 688);
    g.addAresta(9, 15, 572);
    g.addAresta(15, 9, 572);
    g.addAresta(11, 16, 1795);
    g.addAresta(16, 11, 1795);
    g.addAresta(15, 16, 2787);
    g.addAresta(16, 15, 2787);
    g.addAresta(12, 13, 53);
    g.addAresta(13, 12, 53);
    g.addAresta(13, 14, 68);
    g.addAresta(14, 13, 68);
    g.addAresta(14, 15, 2595);
    g.addAresta(15, 14, 2595);
    g.addAresta(0, 3, 582);
    g.addAresta(3, 0, 582);
    g.addAresta(3, 4, 377);
    g.addAresta(4, 3, 377);
    g.addAresta(4, 14, 3361);
    g.addAresta(14, 4, 3361);
    g.addAresta(0, 5, 866);
    g.addAresta(5, 0, 866);
    g.addAresta(5, 6, 238);
    g.addAresta(6, 5, 238);
    g.addAresta(6, 4, 3022);
    g.addAresta(4, 6, 3022);


//    cout << "Usando Algoritmo de Dijkstra" << endl;
//    cout << "A menor distância de 2 a 1 é: " << g.dijkstra(2,1) << endl;
//    cout << "\n\n";
//
//    t = g.solucaoAleatoria();
//    s = get<0>(t);
//
//    list<int>::iterator it;
//    cout << "Solução aleatória " << endl;
//    for(it = s.begin(); it != s.end(); it++)
//        cout << *it << " -> ";
//    cout << "\nO custo dessa solução é: " << get<1>(t) << endl;
//    cout << endl;
//
//    // Solução derivada - vizinhança 1
//
//    tv_1 = g.vizinho_1(s);
//    sv1 = get<0>(tv_1);
//    cout << "Vizinho 1 da solução aleatória" << endl;
//    list<int>::iterator it2;
//    for(it2 = sv1.begin(); it2 != sv1.end(); it2++)
//        cout << *it2 << " -> ";
//
//    cout << "\nO custo dessa solução vizinha é: " << get<1>(tv_1) << endl;
//    cout << endl;
//
//    // Solução derivada - vizinhaça 2
//
//    tv_2 = g.vizinho_2(s);
//    sv2 = get<0>(tv_2);
//    cout << "Vizinho 2 da solução aleatória" << endl;
//    list<int>::iterator it3;
//    for(it3 = sv2.begin(); it3 != sv2.end(); it3++)
//        cout << *it3 << " -> ";
//
//    cout << "\nO custo dessa solução vizinha é: " << get<1>(tv_2) << endl;
//    cout << endl;
//    cout << endl;
//
//    // Solução derivada - gerador de vizinhança
//
//    tv_3 = g.gerarVizinho(s);
//    sv3 = get<0>(tv_3);
//    cout << "Gerador de Vizinhança da solução aleatória" << endl;
//    list<int>::iterator it4;
//    for(it4 = sv3.begin(); it4 != sv3.end(); it4++)
//        cout << *it4 << " -> ";
//
//    cout << "\nO custo dessa solução vizinha é: " << get<1>(tv_3) << endl;
//    cout << endl;
//    cout << "--------------------------------------------------------------" << endl;
//    cout << endl;


    /// resultado do Simulated Annealing
    double alpha = 0.99;// alpha = fator de redução da temperatura
    double tempIni = 10;// tempIni = temperatura inicial
    int itMaxTemp = 5;// itMaxTemp = número máximo de iterações para cada temperatura (Geração de vizinhança)

    tv_SA = g.simulated_Annealing(alpha, tempIni, itMaxTemp);
    svSA = get<0>(tv_SA);
    cout << "Resultado do Simulated Annealing" << endl;
    list<int>::iterator it5;
    for(it5 = svSA.begin(); it5 != svSA.end(); it5++)
        cout << *it5 << " -> ";

    cout << "\nO custo da MELHOR SOLUÇÃO do SA é: " << get<1>(tv_SA) << endl;

    //system("./plotar.sh");
    system("gnuplot -persist script.gnu");
    system("rm -f dados.grafico");

    return 0;
}
