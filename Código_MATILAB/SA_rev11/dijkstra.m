function [Custo Rota]=dijkstra(dados,origem, destino, dist_max)
%tic;
    n=size(dados,1);   
    v=zeros(1,n);%n�s j� visitados
    d=ones(1,n)*dist_max;%distancia acumulada da origem ao destino a cada no visitado
    p=zeros(1,n);%previous node matrix
    s=origem; %origem
    v(s)=1;%marca o no inicial como visitado e inicializa distancia(d) e rota anterior(p).
    d(s)=0; %distancia at� o n� selecionado (dele para ele mesmo) � zero
    p(s)=0; %n� anterior na rota mais economica partindo da origem
    stop=0;

    while(stop~=n)
         if s~=destino  %se n�o chegou ao final da rota solicitada continua
           stop=0;
         else
            stop = n;
            continue;
         end
        for i=1:n
            if(v(i)~=1&&dados(s,i)~=0) %se o n� n�o foi visitado E
                %o custo do n� � maior que zero
                if(d(s)+ dados(s,i)<d(i))%se a rota for menor que a anteriror 
                    d(i)=dados(s,i)+d(s); %atualiza os valores de custo
                    p(i)=s; %e registra a posicao atual como origem
   %                 stop = 0;
                end
            else
                stop=stop+1;%incrementa o numero de n�s avaliados           
            end
        end
        tempmat=d;
        for i=1:n
            if((v(i)==1)) %|| (p(i) ~=s)  %se o vertice j� foi visitado ou se o valor armazenado for de outro calculo
                tempmat(i)=dist_max;%atribui um custo alto para que ele n�o seja avaliado novamente
            end
        end
        [k z]=min(tempmat); %obtem o menor valor e armazena em z
        s=z;% define o menor n� atual como n� inicial
        v(s)=1; % marca que j� foi visitado
        if v(destino)==0 %se o n� de destino n�o foi visitado...
           stop = 0; %for�a a continua��o pois o algoritmo ainda n�o visitou
                     %o n� de destino
            
        end
    end
    

i=1;
aux=2;
dest_encontrado(1)=destino;
Custo = 0;  
while(i==1)     %montando a rota do destino para o inicio
     destino=p(destino);
     
     dest_encontrado(aux)=destino;
     aux=aux+1;
     if(destino==origem)
         i=0;
     end
end

for ii=1:size(dest_encontrado,2)-1
   Custo = Custo + dados(dest_encontrado(ii),dest_encontrado(ii+1));  
end
Rota = fliplr(dest_encontrado); %inverte a ordem pois o algoritmo monta a rota do final para o inicio
%toc
end
