section .data
    float_255 dq 255.0
    stride_500 dq 500

section .text
bits 64
default rel
global imgCvtGrayDoubleToInt

; RCX = matrix_ptr (double*)
; RDX = dest_ptr (int*)
; R8  = rows (int)
; R9  = cols (int)

imgCvtGrayDoubleToInt:
    push rbx
    push r12
    push r13
    push r14
    push r15
    
    mov rbx, rcx    ; rbx = matrix_ptr
    mov r12, rdx    ; r12 = dest_ptr
    mov r13, r8     ; r13 = rows
    mov r14, r9     ; r14 = cols
    
    xor r15, r15    ; r15 = row index (i)
    
    OuterLoop:
        cmp r15, r13
        jge End
        
        xor rdi, rdi    ; rdi = col index (j)
    
    InnerLoop:
        cmp rdi, r14
        jge EndInner
        
        mov rax, r15
        imul rax, [stride_500]
        add rax, rdi
        
        movsd xmm0, [rbx + rax * 8]
        
        mulsd xmm0, [float_255]
        
        cvttsd2si rdx, xmm0
        
        mov rsi, r15
        imul rsi, r14
        add rsi, rdi
        
        mov [r12 + rsi * 4], rdx
        
        inc rdi
        jmp InnerLoop

      EndInner:
        inc r15
        jmp OuterLoop
        
       End:
        pop r15
        pop r14
        pop r13
        pop r12
        pop rbx
        
        ret