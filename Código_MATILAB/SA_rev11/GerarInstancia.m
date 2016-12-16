function modelo=GerarInstancia()


    % instancia do problema de rotas em manaus
    
    x=[97	66	34	76	65	90	78	62	46	26	32	21	41	31	22	12	-4];
    
    y=[82	91	100	48	27	31	13	67	71	63	86	85	43	31	17	35	50];
    
    elementos=numel(x);
    
    d=zeros(elementos,elementos);
    d_aux=zeros(elementos,elementos);
    NPC=0;
d(1,1)=0;			d(2,1)=430;			d(3,1)=NPC;			d(4,1)=582;			d(5,1)=NPC;			d(6,1)=866;			d(7,1)=NPC;			d(8,1)=602;			d(9,1)=NPC;			d(10,1)=NPC;		d(11,1)=NPC;		d(12,1)=NPC;		d(13,1)=NPC;		d(14,1)=NPC;		d(15,1)=NPC;		d(16,1)=NPC;		d(17,1)=NPC;		
d(1,2)=430;			d(2,2)=0;			d(3,2)=526;			d(4,2)=NPC;			d(5,2)=NPC;			d(6,2)=NPC;			d(7,2)=NPC;			d(8,2)=NPC;			d(9,2)=NPC;			d(10,2)=NPC;		d(11,2)=NPC;		d(12,2)=NPC;		d(13,2)=NPC;		d(14,2)=NPC;		d(15,2)=NPC;		d(16,2)=NPC;		d(17,2)=NPC;	
d(1,3)=NPC;			d(2,3)=526;			d(3,3)=0;			d(4,3)=NPC;			d(5,3)=NPC;			d(6,3)=NPC;			d(7,3)=NPC;			d(8,3)=NPC;			d(9,3)=NPC;			d(10,3)=NPC;		d(11,3)=NPC;		d(12,3)=2894;		d(13,3)=NPC;		d(14,3)=NPC;		d(15,3)=NPC;		d(16,3)=NPC;		d(17,3)=NPC;	
d(1,4)=582;			d(2,4)=NPC;			d(3,4)=NPC;			d(4,4)=0;			d(5,4)=377;			d(6,4)=NPC;			d(7,4)=NPC;			d(8,4)=NPC;			d(9,4)=NPC;			d(10,4)=NPC;		d(11,4)=NPC;		d(12,4)=NPC;		d(13,4)=NPC;		d(14,4)=NPC;		d(15,4)=NPC;		d(16,4)=NPC;		d(17,4)=NPC;	
d(1,5)=NPC;			d(2,5)=NPC;			d(3,5)=NPC;			d(4,5)=377;			d(5,5)=0;			d(6,5)=NPC;			d(7,5)=3022;		d(8,5)=NPC;			d(9,5)=NPC;			d(10,5)=NPC;		d(11,5)=NPC;		d(12,5)=NPC;		d(13,5)=NPC;		d(14,5)=NPC;		d(15,5)=3361;		d(16,5)=NPC;		d(17,5)=NPC;	
d(1,6)=866; 		d(2,6)=NPC;			d(3,6)=NPC;			d(4,6)=NPC;			d(5,6)=NPC;			d(6,6)=0;			d(7,6)=238;			d(8,6)=NPC;			d(9,6)=NPC;         d(10,6)=NPC;		d(11,6)=NPC;		d(12,6)=NPC;		d(13,6)=NPC;		d(14,6)=NPC;		d(15,6)=NPC;		d(16,6)=NPC;		d(17,6)=NPC;	
d(1,7)=NPC;			d(2,7)=NPC;			d(3,7)=NPC;			d(4,7)=NPC;			d(5,7)=3022;		d(6,7)=238;			d(7,7)=0;			d(8,7)=NPC;			d(9,7)=NPC;			d(10,7)=NPC;		d(11,7)=NPC;		d(12,7)=NPC;		d(13,7)=NPC;		d(14,7)=NPC;		d(15,7)=NPC;		d(16,7)=NPC;		d(17,7)=NPC;	
d(1,8)=602;			d(2,8)=NPC;			d(3,8)=NPC;			d(4,8)=NPC;			d(5,8)=NPC;			d(6,8)=NPC;			d(7,8)=NPC;			d(8,8)=0;			d(9,8)=112;			d(10,8)=NPC;		d(11,8)=NPC;		d(12,8)=NPC;		d(13,8)=NPC;		d(14,8)=NPC;		d(15,8)=NPC;		d(16,8)=NPC;		d(17,8)=NPC;	
d(1,9)=NPC;			d(2,9)=NPC;			d(3,9)=NPC;			d(4,9)=NPC;			d(5,9)=NPC;			d(6,9)=NPC;			d(7,9)=NPC;			d(8,9)=112;			d(9,9)=0;			d(10,9)=125;		d(11,9)=206;		d(12,9)=NPC;		d(13,9)=366;		d(14,9)=NPC;		d(15,9)=NPC;		d(16,9)=NPC;		d(17,9)=NPC;	
d(1,10)=NPC;		d(2,10)=NPC;		d(3,10)=NPC;		d(4,10)=NPC;		d(5,10)=NPC;		d(6,10)=NPC;		d(7,10)=NPC;		d(8,10)=NPC;		d(9,10)=125;		d(10,10)=0;			d(11,10)=NPC;		d(12,10)=NPC;		d(13,10)=NPC;		d(14,10)=NPC;		d(15,10)=NPC;		d(16,10)=572;		d(17,10)=688;		
d(1,11)=NPC;		d(2,11)=NPC;		d(3,11)=NPC;		d(4,11)=NPC;		d(5,11)=NPC;		d(6,11)=NPC;		d(7,11)=NPC;		d(8,11)=NPC;		d(9,11)=206;		d(10,11)=NPC;		d(11,11)=0;			d(12,11)=62;		d(13,11)=NPC;		d(14,11)=NPC;		d(15,11)=NPC;		d(16,11)=NPC;		d(17,11)=NPC;		
d(1,12)=NPC;		d(2,12)=NPC;		d(3,12)=2894;		d(4,12)=NPC;		d(5,12)=NPC;		d(6,12)=NPC;		d(7,12)=NPC;		d(8,12)=NPC;		d(9,12)=NPC;		d(10,12)=NPC;		d(11,12)=62;		d(12,12)=0;			d(13,12)=NPC;		d(14,12)=NPC;		d(15,12)=NPC;		d(16,12)=NPC;		d(17,12)=1795;		
d(1,13)=NPC;		d(2,13)=NPC;		d(3,13)=NPC;		d(4,13)=NPC;		d(5,13)=NPC;		d(6,13)=NPC;		d(7,13)=NPC;		d(8,13)=NPC;		d(9,13)=366;		d(10,13)=NPC;		d(11,13)=NPC;		d(12,13)=NPC;		d(13,13)=0; 		d(14,13)=53;		d(15,13)=NPC;		d(16,13)=NPC;		d(17,13)=NPC;		
d(1,14)=NPC;		d(2,14)=NPC;		d(3,14)=NPC;		d(4,14)=NPC;		d(5,14)=NPC;		d(6,14)=NPC;		d(7,14)=NPC;		d(8,14)=NPC;		d(9,14)=NPC;		d(10,14)=NPC;		d(11,14)=NPC;		d(12,14)=NPC;		d(13,14)=53;		d(14,14)=0;			d(15,14)=68;		d(16,14)=NPC;		d(17,14)=NPC;		
d(1,15)=NPC;		d(2,15)=NPC;		d(3,15)=NPC;		d(4,15)=NPC;		d(5,15)=3361;		d(6,15)=NPC;		d(7,15)=NPC;		d(8,15)=NPC;		d(9,15)=NPC;		d(10,15)=NPC;		d(11,15)=NPC;		d(12,15)=NPC;		d(13,15)=NPC;		d(14,15)=68;		d(15,15)=0;			d(16,15)=2595;		d(17,15)=NPC;		
d(1,16)=NPC;		d(2,16)=NPC;		d(3,16)=NPC;		d(4,16)=NPC;		d(5,16)=NPC;		d(6,16)=NPC;		d(7,16)=NPC;		d(8,16)=NPC;		d(9,16)=NPC;		d(10,16)=572;		d(11,16)=NPC;		d(12,16)=NPC;		d(13,16)=NPC;		d(14,16)=NPC;		d(15,16)=2595;		d(16,16)=0;			d(17,16)=2787;		
d(1,17)=NPC;		d(2,17)=NPC;		d(3,17)=NPC;		d(4,17)=NPC;		d(5,17)=NPC;		d(6,17)=NPC;		d(7,17)=NPC;		d(8,17)=NPC;		d(9,17)=NPC;		d(10,17)=688;		d(11,17)=NPC;		d(12,17)=1795;		d(13,17)=NPC;		d(14,17)=NPC;		d(15,17)=NPC;		d(16,17)=2787;		d(17,17)=0;		

    
    modelo.n=elementos;
    modelo.x=x;
    modelo.y=y;
    modelo.d=d;
    
    custo=0;
    maiorvalor = sum(sum(modelo.d));
    for L=1:elementos
        for C=1:elementos
            if L==C
                d_aux(L,C)=0;
            else    
                custo = dijkstra(modelo.d,L,C, maiorvalor);  
                d_aux(L,C)=custo;
            end    
        end
    end
    modelo.distancias = d_aux;
    
end