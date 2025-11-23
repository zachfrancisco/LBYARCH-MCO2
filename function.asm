section .data
    msg db 'asm works', 0
    float_255 dq 255.0

section .text
bits 64
default rel
global imgCvtGrayDoubleToInt
extern printf

; RCX = matrix_ptr (double*)
; RDX = rows (int)
; R8  = cols (int)
imgCvtGrayDoubleToInt:
    sub rsp, 8*5
    mov rcx, msg
    call printf
    add rsp, 8*5
    
    ret