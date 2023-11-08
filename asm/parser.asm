.global _start

.bss
    string: .space 16
    integer: .space 4

.data
overflow_msg:
    .asciz "overflow\n"
    msg_length = . - overflow_msg


.text

parse:
    xor rdi, rdi


.next_digit:
    xor rax, rax

    movzx rax, byte ptr [rsi]
    test rax, rax
    jz .end

    sub rax, '0'
    mul rdi
    add rdi, rax

    inc rsi
    jmp .next_digit


.end:
    ret

_start:
    mov rax, 0
    mov rdi, 0
    lea rsi, [string]
    mov rdx, 16
    syscall

    lea rsi, [string]
    call parse

    mov rax, 4294967295
    cmp rdi, rax
    jae overflow

    # it works the same without this line
    mov [integer], edi

    # write
    mov rax, 1
    mov rdi, 1
    lea rsi, [integer]
    mov rdx, 4
    syscall
    jmp .exit

overflow:
    mov rax, 1
    mov rdi, 1
    lea rsi, [overflow_msg]
    mov rdx, msg_length
    syscall
    jmp .exit


.exit:
    mov rax, 60
    mov rdi, 0
    syscall

