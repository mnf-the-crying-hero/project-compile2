MOV f6, T0
SUB T2, j, 1
MOV f8, T2
MOV f9, T4
MOV temp, A[f9]
MOV f13, A[f6]
MOV A[f9], f13
MOV A[f6], temp
