function NovoCaminho=Trocar(Caminho_Orig)

    n=numel(Caminho_Orig);
    
    V=randsample(n,2);
    
    v1=V(1);
    v2=V(2);


    
    NovoCaminho=Caminho_Orig;
    NovoCaminho([v1 v2])=Caminho_Orig([v2 v1]);
    %inverte um trecho aleatorio da rota original. [ O trecho inverttido 
    %fica entre v1 e v2 )

    
end