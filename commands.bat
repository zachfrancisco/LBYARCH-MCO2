nasm -f win64 function.asm
gcc -c main.c -o main.obj -m64 -O0
gcc main.obj function.obj -o main.exe -m64
main.exe < input10.txt