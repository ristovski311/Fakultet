.486
.model flat,c
.data
	N dd 3
	M dd 5
	MAT dd 5,3,2,7,0
		dd 8,1,1,3,8
		dd 2,0,5,7,9
.code
main proc
	
	mov esp, MAT ; ESP cuva prvi element matrice

	mov eax, N
	mov ebx, M
	mul ebx
	shr eax,1
	mov ebp, eax; EBP cuva broj polovine ukupnog broja matrice uvecan za 1

	mov eax, M
	shl eax,2 ; EAX ce cuvati 4*M koji cemo dodavati na ebx kada prelazimo u novu vrstu
 
	mov edi, 0
	dec edi ; EDI je brojac koji ce ustanoviti kada stignemo do polovine matrice

	mov ecx, N ; Koristimo ECX za loop

	mov ebx,0 ; VRSTE

	mov edx, M
	dec edx
	shl edx,2 ; EDX cuva broj 4(M-1) sa kojim poredimo ESI da utvrdimo da li prelazimo u sledecu vrstu

	spolja: 
	
	mov esi,0 ; KOLONE
	sub esi,4

	unutra:

	inc edi
	cmp edi, ebp
	je kraj

	add esi,4
	mov MAT[ebx][esi], esp
	
	
	cmp esi, edx 
	jb unutra

	add ebx,eax
	loop spolja

	kraj:
	mov eax,1

	ret
main endp
end main