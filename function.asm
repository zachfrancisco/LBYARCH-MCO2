section .data
    float_255 dq 255.0
    fmt_val db "%d, ", 0
    fmt_nl db 10, 0
section .text
bits 64
default rel
global imgCvtGrayDoubleToInt
extern printf

; RCX = matrix_ptr (double*)
; RDX = rows (int)
; R8  = cols (int)
imgCvtGrayDoubleToInt:  
    push rbx
    push r12
    push r13
    push r14
    push r15
    
    sub rsp, 8*5
    
    mov rbx, rcx
    mov r12, rdx
    mov r13, r8
    
    xor r14, r14
    
    OuterLoop:
        cmp r14, r12
        jge End
        
        xor r15, r15
    
    InnerLoop:
        cmp r15, r13
        jge EndInner
        
        mov rax, r14
        imul rax, 500
        add rax, r15
        
        movsd xmm0, [rbx + rax * 8]
        mulsd xmm0, [float_255]
        cvttsd2si rdx, xmm0
        
        lea rcx, [fmt_val]
        call printf
        
        inc r15
        jmp InnerLoop

      EndInner:
        lea rcx, [fmt_nl]
        call printf
        
        inc r14
        jmp OuterLoop
        
       End:
        add rsp, 40
        pop r15
        pop r14
        pop r13
        pop r12
        pop rbx
        
        ret