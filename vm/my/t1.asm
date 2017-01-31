        jump.i  #lab0                   ;jump.i  lab0
lab0:
        inttoreal.i 4,32                        ;inttoreal.i
        mul.r    32,16,24
        inttoreal.i 0,48                        ;inttoreal.i
        add.r 48,24,40
        mov.r   40,8                             
        write.r 8                        ;write   
        exit                            ;exit    