        jump.i  #lab0                   ;jump.i  lab0
czytajtab:
        enter.i #8                     ;enter.i 
        sub.i #1,#1,BP-4
        mul.i    BP-4,#4,BP-4
        add.i BP+8,BP-4,BP-8
        mov.i   #10,*BP-8                        
        leave                           ;leave   
        return                          ;return  
bubblesort:
        enter.i #0                     ;enter.i 
        push.i  BP+8                    ;push.i  &a
        call.i  #czytajtab              ;call.i  &czytajtab
        incsp.i #4                      ;incsp.i 4
        leave                           ;leave   
        return                          ;return  
lab0:
        push.i  #12                     ;push.i  &p
        call.i  #czytajtab              ;call.i  &czytajtab
        incsp.i #4                      ;incsp.i 4
        sub.i #3,#1,56
        mul.i    56,#4,56
        add.i #12,56,60
        mov.i   #10,*60                          
        exit                            ;exit    