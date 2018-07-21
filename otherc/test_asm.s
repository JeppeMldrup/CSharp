	.file	"test.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d\n"
	.align 8
.LC1:
	.string	"Press ENTER key to Continue... "
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
	subq	$432, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, -424(%rbp)
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movl	$0, -420(%rbp)
	jmp	.L2
.L3:
	call	rand@PLT
	movl	%eax, %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$5, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$100, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	-420(%rbp), %edx
	movslq	%edx, %rdx
	movl	%eax, -416(%rbp,%rdx,4)
	addl	$1, -420(%rbp)
.L2:
	cmpl	$99, -420(%rbp)
	jle	.L3
	jmp	.L4
.L8:
	movl	$0, -424(%rbp)
	movl	$0, -420(%rbp)
	jmp	.L5
.L7:
	movl	-420(%rbp), %eax
	cltq
	movl	-416(%rbp,%rax,4), %edx
	movl	-420(%rbp), %eax
	addl	$1, %eax
	cltq
	movl	-416(%rbp,%rax,4), %eax
	cmpl	%eax, %edx
	jle	.L6
	movl	-420(%rbp), %eax
	cltq
	movl	-416(%rbp,%rax,4), %eax
	movl	%eax, -424(%rbp)
	movl	-420(%rbp), %eax
	addl	$1, %eax
	cltq
	movl	-416(%rbp,%rax,4), %edx
	movl	-420(%rbp), %eax
	cltq
	movl	%edx, -416(%rbp,%rax,4)
	movl	-420(%rbp), %eax
	addl	$1, %eax
	cltq
	movl	-424(%rbp), %edx
	movl	%edx, -416(%rbp,%rax,4)
	nop
.L6:
	addl	$1, -420(%rbp)
.L5:
	cmpl	$98, -420(%rbp)
	jle	.L7
.L4:
	cmpl	$0, -424(%rbp)
	jne	.L8
	movl	$0, -420(%rbp)
	jmp	.L9
.L10:
	movl	-420(%rbp), %eax
	cltq
	movl	-416(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -420(%rbp)
.L9:
	cmpl	$99, -420(%rbp)
	jle	.L10
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	call	getchar@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L12
	call	__stack_chk_fail@PLT
.L12:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
