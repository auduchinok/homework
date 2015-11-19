; Eugene Auduchinok, 2015

; extern "C" int sum(int a, int b);
.CODE            ; Code segment begin
sum PROC         ; Procedure begin
	add rdx, rcx ; Add RXC to RDX
	mov rax, rdx ; Copy RDX to RAX
	ret          ; Return from the procedure
sum ENDP         ; Procedure end
END              ; Program code end