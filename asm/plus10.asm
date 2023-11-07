.global _start

.bss
input: resb 1

.text

_start

    # read
    mov rax, 0
    mov rdi, 0
    mov rdx, 1
    lea rsi, [input]
    syscall

    # add 10
    add byte [input], 10

    # write
    mov rax, 1
    mov rdi, 1
    mov rdx, 1
    lea rsi, [input]
    syscall

    # close
    mov rax, 3
    mov rdi, 1
    syscall

    # exit
    mov rax, 60
    mov rdi, 0
    syscall