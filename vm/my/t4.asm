        jump.i  #lab0                   ;jump.i  lab0
f:
        enter.i #4                     ;enter.i 
        add.i *BP+12,#10,BP-4
        mov.i   BP-4,*BP+12                      
        leave                           ;leave   
        return                          ;return  
lab0:
        exit                            ;exit    