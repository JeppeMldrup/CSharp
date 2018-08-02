	.file	"server.c"
	.text
	.section	.rodata
.LC0:
	.string	"Failed to set up socket"
	.align 8
.LC1:
	.string	"Failed to bind socket to address"
.LC2:
	.string	"Failed to start listening"
.LC3:
	.string	"Failed to accept connection"
.LC4:
	.string	"Client connected"
.LC5:
	.string	"Failed to read message"
.LC6:
	.string	"Recieved: %s"
.LC7:
	.string	"Failed to recieve message"
.LC8:
	.string	"Failed to close connection"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movl	%edi, -100(%rbp)
	movq	%rsi, -112(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -76(%rbp)
	movl	$0, %edx
	movl	$1, %esi
	movl	$2, %edi
	call	socket@PLT
	movl	%eax, -72(%rbp)
	movl	-72(%rbp), %eax
	movl	%eax, -76(%rbp)
	cmpl	$-1, -76(%rbp)
	jne	.L2
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	-76(%rbp), %eax
	jmp	.L16
.L2:
	movw	$2, -64(%rbp)
	movl	$0, %edi
	call	htonl@PLT
	movl	%eax, -60(%rbp)
	movl	$8000, %edi
	call	htons@PLT
	movw	%ax, -62(%rbp)
	leaq	-64(%rbp), %rcx
	movl	-72(%rbp), %eax
	movl	$16, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	bind@PLT
	movl	%eax, -76(%rbp)
	cmpl	$-1, -76(%rbp)
	jne	.L4
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	movl	-76(%rbp), %eax
	jmp	.L16
.L4:
	movl	-72(%rbp), %eax
	movl	$4, %esi
	movl	%eax, %edi
	call	listen@PLT
	movl	%eax, -76(%rbp)
	cmpl	$-1, -76(%rbp)
	jne	.L5
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movl	-76(%rbp), %eax
	jmp	.L16
.L5:
	movl	$16, -80(%rbp)
	leaq	-80(%rbp), %rdx
	leaq	-48(%rbp), %rcx
	movl	-72(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	accept@PLT
	movl	%eax, -68(%rbp)
	movl	-68(%rbp), %eax
	movl	%eax, -76(%rbp)
	cmpl	$-1, -76(%rbp)
	jne	.L6
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	movl	-76(%rbp), %eax
	jmp	.L16
.L6:
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
.L9:
	leaq	-18(%rbp), %rsi
	movl	-68(%rbp), %eax
	movl	$0, %ecx
	movl	$10, %edx
	movl	%eax, %edi
	call	recv@PLT
	testq	%rax, %rax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -76(%rbp)
	cmpl	$0, -76(%rbp)
	jne	.L19
	jmp	.L9
.L19:
	nop
	cmpl	$-1, -76(%rbp)
	jne	.L10
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	movl	-76(%rbp), %eax
	jmp	.L16
.L10:
	movzbl	-18(%rbp), %eax
	testb	%al, %al
	je	.L11
	leaq	-18(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$10, %edi
	call	putchar@PLT
	jmp	.L12
.L11:
	leaq	.LC7(%rip), %rdi
	call	puts@PLT
.L12:
	movl	-68(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	%eax, -76(%rbp)
	cmpl	$-1, -76(%rbp)
	jne	.L13
	leaq	.LC8(%rip), %rdi
	call	puts@PLT
	movl	-76(%rbp), %eax
	jmp	.L16
.L13:
	leaq	-81(%rbp), %rax
	movl	$1, %edx
	movq	%rax, %rsi
	movl	$0, %edi
	call	read@PLT
	testq	%rax, %rax
	je	.L20
	movzbl	-81(%rbp), %eax
	cmpb	$113, %al
	jne	.L5
	movl	$0, %eax
	jmp	.L16
.L20:
	nop
	jmp	.L5
.L16:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L17
	call	__stack_chk_fail@PLT
.L17:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
