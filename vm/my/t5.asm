        jump.i  #lab0                   ;jump.i  lab0
f:
        enter.i #4                     ;enter.i 
        add.i *BP+12,#10,BP-4
        mov.i   BP-4,*BP+12                      
        leave                           ;leave   
        return                          ;return  
lab0:
        mov.i   #3,24                            
        push.i  #24                     ;push.i  &$t1
        push.i  #28                     ;push.i  &$t2
        call.i  #f                      ;call.i  &f
        incsp.i #8                      ;incsp.i 8
        mov.i   28,0                             
        exit                            ;exit    