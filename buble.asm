			jump.i  #lab0
czytajtab:
	enter.i #20
	mov.i #1,BP-4
lab2:
	jl.i BP-4,#11,#lab3
	mov.i #0,BP-8
	jump.i #lab4
lab3:
	mov.i #1,BP-8
lab4:
	je.i BP-8,#0,#lab1
	sub.i BP-4,#1,BP-12
	mul.i BP-12,#4,BP-12
	add.i BP+8,BP-12,BP-16
	read.i *BP-16
	add.i BP-4,#1,BP-20
	mov.i BP-20,BP-4
	jump.i #lab2
lab1:
	leave
	return
bubblesort:
	enter.i #88
	mov.i #1,BP-4
lab6:
	jl.i BP-4,#11,#lab7
	mov.i #0,BP-20
	jump.i #lab8
lab7:
	mov.i #1,BP-20
lab8:
	je.i BP-20,#0,#lab5
	add.i BP-4,#1,BP-24
	mov.i BP-24,BP-8
lab10:
	jl.i BP-8,#11,#lab11
	mov.i #0,BP-28
	jump.i #lab12
lab11:
	mov.i #1,BP-28
lab12:
	je.i BP-28,#0,#lab9
	sub.i BP-4,#1,BP-32
	mul.i BP-32,#4,BP-32
	add.i BP+8,BP-32,BP-36
	sub.i BP-8,#1,BP-40
	mul.i BP-40,#4,BP-40
	add.i BP+8,BP-40,BP-44
	jg.i *BP-36,*BP-44,#lab13
	mov.i #0,BP-48
	jump.i #lab14
lab13:
	mov.i #1,BP-48
lab14:
	je.i BP-48,#0,#lab15
	sub.i BP-4,#1,BP-52
	mul.i BP-52,#4,BP-52
	add.i BP+8,BP-52,BP-56
	inttoreal.i *BP-56,BP-16
	sub.i BP-4,#1,BP-60
	mul.i BP-60,#4,BP-60
	add.i BP+8,BP-60,BP-64
	sub.i BP-8,#1,BP-68
	mul.i BP-68,#4,BP-68
	add.i BP+8,BP-68,BP-72
	mov.i *BP-72,*BP-64
	sub.i BP-8,#1,BP-76
	mul.i BP-76,#4,BP-76
	add.i BP+8,BP-76,BP-80
	realtoint.r BP-16,*BP-80
	jump.i #lab16
lab15:
lab16:
	add.i BP-8,#1,BP-84
	mov.i BP-84,BP-8
	jump.i #lab10
lab9:
	add.i BP-4,#1,BP-88
	mov.i BP-88,BP-4
	jump.i #lab6
lab5:
	leave
	return
wypisztab:
	enter.i #20
	mov.i #1,BP-4
lab18:
	jl.i BP-4,#11,#lab19
	mov.i #0,BP-8
	jump.i #lab20
lab19:
	mov.i #1,BP-8
lab20:
	je.i BP-8,#0,#lab17
	sub.i BP-4,#1,BP-12
	mul.i BP-12,#4,BP-12
	add.i BP+8,BP-12,BP-16
	write.i *BP-16
	add.i BP-4,#1,BP-20
	mov.i BP-20,BP-4
	jump.i #lab18
lab17:
	leave
	return
lab0:
	push.i #12
	call.i #czytajtab
	incsp.i #4
	push.i #12
	call.i #bubblesort
	incsp.i #4
	push.i #12
	call.i #wypisztab
	incsp.i #4
	exit
