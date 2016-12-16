
function ImprimeGrafico(Rota,modelo, final)

    Caminho=Rota.Caminho;
    Caminho=[Caminho Caminho(1)]; %ligando a ultima cidade à primeira

if final==0 %imprimir solucao intermediaria

    plot(modelo.x(Caminho),modelo.y(Caminho),'k-o',...
        'MarkerSize',14,...
        'MarkerFaceColor','b',...
        'LineWidth',2);
    
else  %imprimir solucao final
    
    n=numel(Caminho) ; %O ultimo elemento é o fechamento do circuito
    rota_expand=0;
    rota_aux=0;
    L=0;
    maiorvalor = sum(sum(modelo.d));
    for k=1:n-1   
        i=Caminho(k);
        j=Caminho(k+1);
        [L rota_aux] = dijkstra(modelo.d,i,j,maiorvalor);
        rota_expand = [rota_expand rota_aux];
    end
    rota_expand = rota_expand(2:end);
    plot(modelo.x(rota_expand),modelo.y(rota_expand),'k-o',...
        'MarkerSize',14,...
        'MarkerFaceColor','b',...
        'LineWidth',2);
   title (strcat('Solução [ ' ,(num2str(Caminho)),']'))
%     title (strcat('Solução [ ' ,(num2str(rota_expand)),']'))
end

    axis equal;
    grid on;
  
     xlim([-10 110]);
     ylim([-10 110]);

end