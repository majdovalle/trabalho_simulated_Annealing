function NovaRota=GerarVizinho(Rota)
 
 Metodo = SelecaoAleatoria();
    switch Metodo
        case 1
            NovaRota=Trocar(Rota);
            
        case 2
            NovaRota=Reversao(Rota);
            
        case 3
            NovaRota=Inserir(Rota);
            
    end

end