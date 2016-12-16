function i=SelecaoAleatoria()
   
    r=ceil(rand*100);
    i=(mod(r,3))+1;% O comando mod(r,3) sempre retorna um numero entre 0..2.
                   % Como na rotina principal espera-se um valor entre 1 e
                   % 3 faz-se a soma +1;

end