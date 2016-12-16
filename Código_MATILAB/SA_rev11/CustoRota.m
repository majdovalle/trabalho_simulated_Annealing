function L=CustoRota(caminho,modelo)

    n=numel(caminho);
    
    caminho=[caminho caminho(1)]; %ligando a ultima cidade à primeira
    
    L=0;
    maiorvalor = sum(sum(modelo.distancias));
    for k=1:n
        
        i=caminho(k);
        j=caminho(k+1);
        L=L+ modelo.distancias(i,j);
%         L=L+ dijkstra(modelo.d,i,j, maiorvalor);
    end

end