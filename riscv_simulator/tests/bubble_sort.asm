addi x1 x0 5
addi x2 x0 10
jal x3 loop
addi x4 x0 20
jal x16 exit  

loop:
    addi x5 x0 7
    add x6 x1 x2
    jalr x0 x3 0

exit:
    addi x17 x0 0
