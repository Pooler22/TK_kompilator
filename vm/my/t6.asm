        jump.i  #lab0                   ;jump.i  lab0
f:
        enter.i #4                     ;enter.i 
        add.i *BP+16,#10,BP-4
        mov.i   BP-4,*BP+12                      
        leave                           ;leave   
        return                          ;return  
lab0:
        push.i  #0                      ;push.i  &x
        push.i  #8                      ;push.i  &g
        push.i  #24                     ;push.i  &$t1
        call.i  #f                      ;call.i  &f
        incsp.i #12                     ;incsp.i 12
        mov.i   24,0                             
        exit                            ;exit    