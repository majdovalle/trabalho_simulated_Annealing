function NovaRota=Inserir(RotaOri)

    n=numel(RotaOri);
    
    R=randsample(n,2); % seleciona dois valores aleatorios dentro do 
                       % conjunto de numeros inteiros compreendido entre 
                       % [1 e numero de cidades]
    
    r1=R(1);
    r2=R(2);
    
    if r1<r2
        NovaRota=RotaOri([1:r1-1 r1+1:r2 r1 r2+1:end]);
    else
        NovaRota=RotaOri([1:r2 r1 r2+1:r1-1 r1+1:end]);
    end
    
end