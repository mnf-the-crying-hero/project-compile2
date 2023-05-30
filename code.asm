ORG 100h

; Quadruplet 0
MOV AX, 1
MOV BX, -3
SUB AX, BX
MOV T0, AX

; Quadruplet 1
MOV AX, T0
MOV z, AX

; Quadruplet 2
MOV AX, z
MOV BX, 7
ADD AX, BX
MOV T2, AX

; Quadruplet 3
MOV AX, T2
MOV BX, f
ADD AX, BX
MOV T3, AX

; Quadruplet 4
MOV AX, 5.30
MOV BX, -2
SUB AX, BX
MOV T4, AX

; Quadruplet 5
MOV AX, T3
MOV BX, T4
DIV BX
MOV T5, AX

; Quadruplet 6
MOV AX, T5
MOV x, AX

; Quadruplet 7
MOV AX, n
MOV x, AX

; Quadruplet 8
MOV AX, 3
MOV Var3.F1, AX

; Quadruplet 9
MOV AX, 1.50
MOV Var3.x2, AX

; Quadruplet 10
MOV AX, 13
MOV BX, f
MOV z, AX

; Quadruplet 11
MOV AX, 2
MOV z, AX

; Quadruplet 12
MOV AX, 14
MOV vide, AX

; Quadruplet 13
MOV AX, 3
MOV z, AX

; Quadruplet 14
MOV AX, 17
MOV BX, f
MOV z, AX

; Quadruplet 15
MOV AX, 2
MOV z, AX

; Quadruplet 16
MOV AX, 18
MOV vide, AX

; Quadruplet 17
MOV AX, 3
MOV z, AX

; Quadruplet 18
MOV AX, 22
MOV BX, e
MOV x, AX

; Quadruplet 19
MOV AX, e
MOV BX, 2
ADD AX, BX
MOV T19, AX

; Quadruplet 20
MOV AX, T19
MOV e, AX

; Quadruplet 21
MOV AX, 18
MOV vide, AX

; Quadruplet 22
MOV AX, 0
MOV i, AX

; Quadruplet 23
MOV AX, 2
MOV BX, i
ADD AX, BX
MOV T23, AX

; Quadruplet 24
MOV AX, 28
MOV BX, T23
MOV n, AX

; Quadruplet 25
MOV AX, i
MOV BX, 2
ADD AX, BX
MOV T25, AX

; Quadruplet 26
MOV AX, T25
MOV i, AX

; Quadruplet 27
MOV AX, 23
MOV vide, AX

; Quadruplet 28
MOV AX, 5
MOV BX, 2
DIV BX
MOV T28, AX

; Quadruplet 29
MOV AX, T28
MOV x, AX

; Quadruplet 30
MOV AX, 5.50
MOV BX, 5.50
DIV BX
MOV T30, AX

; Quadruplet 31
MOV AX, T30
MOV i, AX

; Quadruplet 32
MOV AX, 5.50
MOV BX, 2.50
DIV BX
MOV T32, AX

; Quadruplet 33
MOV AX, T32
MOV x, AX

MOV AH, 4Ch
INT 21h
