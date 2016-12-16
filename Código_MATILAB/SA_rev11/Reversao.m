function Novo=Reversao(original)

    n=numel(original);
    
    R=randsample(n,2); % seleciona dois valores aleatorios dentro do 
                       % conjunto de numeros inteiros compreendido entre 
                       % [1 e numero de cidades]
    
    r1=min(R);
    r2=max(R);
   
    Novo=original;
    
    Novo(r1:r2)=original(r2:-1:r1);
    %inverte um trecho aleatorio da rota original. [ O trecho invertido 
    %fica entre de r1(que sempre é o menor valor) e r2 (que sempre é o
    %maior valor)]
    
end