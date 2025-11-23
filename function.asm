section .data
msg db 'asm works', 0

section .text
bits 64
default rel
global imgCvtGrayDoubltToInt
extern printf

imgCvtGrayDoubltToInt:
    sub rsp, 8*5
    mov rcx, msg
    call printf
    add rsp, 8*5
    
    ret