        jump.i  #lab0                   ;jump.i  lab0
f:
        enter.i #4                     ;enter.i 
        add.i *BP+16,#10,BP-4
        mov.i   BP-4,*BP+12                      
        leave                           ;leave   
        return                          ;return  
lab0:
        realtoint.r 8,24                    ;realtoint.r
        push.i  #24                     ;push.i  &$t1
        inttoreal.i 0,28                        ;inttoreal.i
        push.i  #28                     ;push.i  &$t2
        push.i  #36                     ;push.i  &$t3
        call.i  #f                      ;call.i  &f
        incsp.i #12                     ;incsp.i 12
        mov.i   36,0                             
        exit                            ;exit    