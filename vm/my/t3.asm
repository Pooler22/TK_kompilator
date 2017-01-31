        jump.i  #lab0                   ;jump.i  lab0
p:
        enter.i #0                     ;enter.i 
        leave                           ;leave   
        return                          ;return  
f:
        enter.i #0                     ;enter.i 
        mov.i   #10,*BP+12                       
        leave                           ;leave   
        return                          ;return  
lab0:
	call.i #p

	call.i #f
	incsp.i #4
        mov.i   24,0                             
        exit                            ;exit    