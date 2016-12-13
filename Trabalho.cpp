#include<iostream>
#include<string>
#include<tuple>
#include<list>
#include<vector>
#include "Trabalho.h"

using namespace std;

int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));

	int tamanho_garfo = 17;
	//int caminho[tamanho_garfo];
	Grafo g(tamanho_garfo);
	tuple<list<int>,int> t, tv_1, tv_2, tv_3, tv_SA;
	list<int> s, sv1, sv2, sv3, svSA;
	vector<int> vetor = {1,2,3,4,5,6};

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

	g.preencherMatrizDist(); // preenchimento da matriz de distâncias

	/// resultado do Simulated Annealing
	double alpha = 0.99;// alpha = fator de redução da temperatura
	double tempIni = 150;// tempIni = temperatura inicial
	int itMaxTemp = 100;// itMaxTemp = número máximo de iterações para cada temperatura (Geração de vizinhança)
	string dado("solucao_"); // nome do arquivo gerado para plotar o gráfico
	string dado4("simulacao");
	string dado3("custInt");

	for(int i = 0; i < 5; i++)
		{
			dado = dado + to_string(i+1);
			dado4 = dado4 + to_string(i+1);
			dado3 = dado3 + to_string(i+1);

			tv_SA = g.simulated_Annealing(alpha, tempIni, itMaxTemp, dado, dado4, dado3);
			svSA = get<0>(tv_SA);
			cout << "Resultado do Simulated Annealing" << endl;
			list<int>::iterator it5;
			for(it5 = svSA.begin(); it5 != svSA.end(); it5++)
				cout << *it5 << " -> ";
			cout << "0";

			cout << "\nO custo da MELHOR SOLUÇÃO do SA é: " << get<1>(tv_SA) << endl;
			dado.pop_back();
			dado4.pop_back();
			dado3.pop_back();

		}

	system("gnuplot -persist 01script.gnu");
	system("gnuplot -persist 02script2.gnu");
	system("gnuplot -persist 03script3.gnu");
	system("gnuplot -persist 04sml1_script.gnu");
	system("gnuplot -persist 05sml1_script2.gnu");

	return 0;
}







