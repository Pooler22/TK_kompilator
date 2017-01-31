#!/bin/bash

make 

cd vm

for i in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
do
    ./komp "t$i.pas" "vm1/t$i.asm"
done

./komp "bubblesort.pas" "vm1/bubblesort.asm"

cd ..

echo "podzial"


for i in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 bubblesort
do
    ./comp "vm/t$i.pas" "vm/my/t$i"
done

./comp "vm/bubblesort.pas" "vm/my/bubblesort"
