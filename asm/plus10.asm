.global _start

.bss
    string: .space 16
    integer: .space 4

.data
overflow_msg:
    .asciz "overflow\n"
    msg_length = . - overflow_msg

new_line:
    .asciz "\n"

.text

# Returns value in rax
parse:
    xor rax, rax
    mov r10, 10
    mov r11, 4294967295

# Stores digit in r9
.next_digit:
    xor r9, r9

    movzx r9, byte ptr [rsi]
    cmp r9, r10
    je .end

    sub r9, '0'
    mul r10
    add rax, r9
    cmp rax, r11
    jg overflow

    inc rsi
    jmp .next_digit

.end:
    ret

# Returns string value in 'string'
write_int:
    mov r10, 10

# parses integer stored in eax
mov ebx, 16
.next_char:
    xor edx, edx
    div r10 # reminder in edx
    add edx, '0'
    dec ebx
    mov byte ptr [string + ebx], dl
    cmp eax, 0
    jg .next_char

.write:
    mov rax, 1
    mov rdi, 1
    lea rsi, [string + ebx]
    mov rdx, 16
    sub rdx, rbx
    syscall

    mov rax, 1
    mov rdi, 1
    lea rsi, [new_line]
    mov rdx, 1
    syscall
    ret


_start:
    # read
    mov rax, 0
    mov rdi, 0
    lea rsi, [string]
    mov rdx, 16
    syscall

    ; lea rsi, [string]
    call parse # parsed value in rax(eax)

    add rax, r10
    call write_int
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
