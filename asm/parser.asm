.global _start

.bss
    string: .space 16
    integer: .space 4

.data
overflow_msg:
    .asciz "overflow\n"
    msg_length = . - overflow_msg


.text

# Returns value in R8
parse:
    xor R8, R8

# Stores digit in R9
.next_digit:
    xor R9, R9

    movzx R9, byte ptr [rsi]
    # sets ZF when R9 = 0?
    test R9, R9
    jz .end

    sub R9, '0'
    mov rax, 10
    mul R8
    add R8, R9

    inc rsi
    jmp .next_digit


.end:
    ret

_start:
    # read
    mov rax, 0
    mov rdi, 0
    lea rsi, [string]
    mov rdx, 16
    syscall

    lea rsi, [string]
    call parse

    mov eax, dword ptr [R8]
    cmp eax, 4294967295
    jae overflow


    # write
    mov rax, 1
    mov rdi, 1
    lea rsi, [R8] # why not?
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

