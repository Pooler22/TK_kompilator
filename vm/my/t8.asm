        jump.i  #lab0                   ;jump.i  lab0
f:
        enter.i #28                     ;enter.i 
        mov.i   #4,BP-4                          
        add.r *BP+16,*BP+12,BP-12
        inttoreal.i BP-4,BP-28                        ;inttoreal.i
        add.r BP-12,BP-28,BP-20
        mov.r   BP-20,*BP+12                     
        leave                           ;leave   
        return                          ;return  