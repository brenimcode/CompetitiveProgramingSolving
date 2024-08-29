.data
    prompt_a: .asciiz "Digite o coeficiente 'a': "
    prompt_b: .asciiz "Digite o coeficiente 'b': "
    prompt_c: .asciiz "Digite o coeficiente 'c': "
    result_msg: .asciiz "O polinômio é igual a zero para os seguintes valores de x: "
    error_msg_a_is_zero: .asciiz "Erro: O coeficiente 'a' não pode ser zero."
    error_msg_negative_discriminant: .asciiz "Erro: O discriminante é negativo, indicando raízes complexas."
    zero: .float 0.0

.text
.globl main

main:

    li $v0, 4
    la $a0, prompt_a
    syscall

    li $v0, 6
    syscall
    mov.s $f12, $f0

    mfc1 $t0, $f12

    beq $t0, $0, error_a_is_zero

    li $v0, 4
    la $a0, prompt_b
    syscall

    li $v0, 6
    syscall
    mov.s $f13, $f0

    li $v0, 4
    la $a0, prompt_c
    syscall

    li $v0, 6
    syscall
    mov.s $f14, $f0


    mul.s $f1, $f12, $f12
    mul.s $f2, $f13, $f13
    mul.s $f3, $f12, $f14
    mul.s $f3, $f3, $f0
    sub.s $f0, $f2, $f3


    c.lt.s $f0, $f0
    bc1t negative_discriminant


    sqrt.s $f2, $f0


    c.lt.s $f13, $f0
    bc1t modo2

    	neg.s $f13, $f13


    	sub.s $f1, $f13, $f2
    	div.s $f1, $f14, $f1



    	sub.s $f3, $f13, $f2
    	div.s $f3, $f3, $f12

    	j exibe_raiz

    modo2:
        neg.s $f13, $f13


    	add.s $f1, $f13, $f2
    	div.s $f1, $f1, $f12


    	add.s $f3, $f13, $f2
    	div.s $f3, $f14, $f3

exibe_raiz:

    li $v0, 4
    la $a0, result_msg
    syscall

    li $v0, 2
    mov.s $f12, $f1
    syscall


    mov.s $f12, $f3
    syscall

    j exit_program

error_a_is_zero:

    li $v0, 4
    la $a0, error_msg_a_is_zero
    syscall

    j exit_program

negative_discriminant:

    li $v0, 4
    la $a0, error_msg_negative_discriminant
    syscall

exit_program:
    li $v0, 10
    syscall
