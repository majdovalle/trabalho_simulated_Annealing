clc;
clear all;
close all;
rand('twister',1); %Inicializa RAND com um novo gerador 
% Defini��o do problema

modelo=GerarInstancia();    
%  Criando uma instancia com as cidades (mapeamento cartesiano x/y), 
% distancia  entre elas (propriedade d), numero de cidades (propriedade n).

% Parametros do S.A. 

Num_Max_Viz=250;    % Numero maximo de itera�oes em uma mesma temperatura
%(Numero de vizinhos a serem gerados nesta temperatura)

T_Ini=2300;       % Temp Inicial.

alpha=0.98;     % Taxa redu��o temperatura
num_it_sem_melhora=0;%numero de itera�oes sem melhora
max_it_sem_melhora = 600; % maximo de itera�oes sem melhora
%num_forces = 0; %numero de tentativas for�adas de melhora
%max_forces = 15; % 15 maximo de tentativas for�adas de melhora
% Inicializa��o dos valores

% Gerando uma solu��o inicial randomica
Atual.Caminho=GerarSolucaoAleatoria(modelo);


Atual.Custo=CustoRota(Atual.Caminho,modelo);

% Melhor solucao encontrada ate agora
MelhorSol=Atual;

% Vetor com os melhores valores encontrados
MelhoresCustos=zeros(1,1);

% Temperatura inicial.
T=T_Ini;
temperaturas=zeros(1,1);
it=0;
% reaquecimento = 0;
% Processo iterativo do S.A.
aceita=0;
while (T > 0.00005)
    it=it+1;
    for II=1:Num_Max_Viz
        
        % Gerando um novo vizinho e avaliando o seu custo
        NovoVizinho.Caminho=GerarVizinho(Atual.Caminho);
        NovoVizinho.Custo=CustoRota(NovoVizinho.Caminho,modelo);
        
        if NovoVizinho.Custo<= Atual.Custo % se Novo vizinho for melhor que vizinho atual aceita
            Atual=NovoVizinho;
            aceita = aceita + 1;
        else % se Novo vizinho nao for melhor que vizinho atual
               
            DELTA=(NovoVizinho.Custo-Atual.Custo);%/sol.Custo;
            P=exp(-DELTA/T);
            if rand<=P
                Atual=NovoVizinho;
                aceita = aceita + 1;
            end
        end
        
        % Armazena a melhor solu��o ja encontrada
        if Atual.Custo<=MelhorSol.Custo
            MelhorSol=Atual;
        end    
        
%         if Atual.Custo<MelhorSol.Custo %se efetivamente melhorar nesta temperatura o contador � zerado
%             num_it_sem_melhora=0;%numero de itera�oes sem melhora
% %             break; %a busca por um vizinho melhor nesta temperatura � finalizada
%         else
%             num_it_sem_melhora = num_it_sem_melhora + 1;
%         end
    end
%     if ((num_it_sem_melhora >= max_it_sem_melhora)) && (reaquecimento ==0)
%         T = T+(T_Ini-T)*0.5;
%         num_it_sem_melhora = ceil(max_it_sem_melhora/2);%busca somente a metade do limite de iter. sem melhora
%         reaquecimento = 1;
%     end    
%     if ((num_it_sem_melhora >= max_it_sem_melhora)) && (reaquecimento ==1)
%         T = 0; %finaliza o loop   
%     end
%     %Armazena os melhores valores encontrados
    MelhoresCustos(it)=MelhorSol.Custo;
    
    disp(['Itera��o ' num2str(it) ': Melhor custo = ' num2str(MelhoresCustos(it)) ': Temperatura: ' num2str(T) ' Aceitos: ' num2str(aceita/Num_Max_Viz*100) '%']);
    
    % Nova Temp.
    temperaturas(it) = T;
    T=alpha*T;
    aceita = 0;
    pause(0.2);
    % Plotando a melhor solucao ate agora...
%     figure(1);
%     ImprimeGrafico(MelhorSol,modelo, 0);%0 para imprimir solucao temporaria
% T=0;
end
% 
% % Mostrando a resposta
% figure;
% plot(MelhoresCustos,'LineWidth',2);
% xlabel('Itera��es');
% ylabel('Melhor Custo');
% grid on;
% 
%  figure
%  plot(temperaturas,'LineWidth',2);
% xlabel('Itera��es');
% ylabel('Temperatura');
% grid on;
% 

% eixo_x = -10:110;
% eixo_y = 110:-1:1-0; 
% cfig = figure;%('Position', [100, 100, 100+932, 100 + 732]); 
% da_map = './Grafo2.gif';
% [I,Imap] = imread(da_map);
% % This converts your image with indexed colors to a true color image
% Itc = ind2rgb(I,Imap);
% % if you invoke image() like that it won't reverse axis direction etc.
% ih = image('XData',eixo_x([1 end]),'YData',eixo_y([1 end]),'CData',Itc); 
% hold on;
% fim=0;
% 
% while fim == 0
%     if MelhorSol.Caminho(1)==1
%         fim=1;
%         continue;
%     end
%     MelhorSol.Caminho=MelhorSol.Caminho([2:end 1]);
% end
% 
% ImprimeGrafico(MelhorSol,modelo, 1);%1 para imprimir solucao final
%     
% 



