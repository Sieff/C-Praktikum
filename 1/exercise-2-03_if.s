	.file	"exercise-2-03_if.c"
	.text
	.section	.rodata
.LC0:
	.string	"null"
.LC1:
	.string	"eins"
.LC2:
	.string	"zwei"
.LC3:
	.string	"drei"
.LC4:
	.string	"vier"
.LC5:
	.string	"f\303\274nf"
.LC6:
	.string	"sechs"
.LC7:
	.string	"sieben"
.LC8:
	.string	"acht"
.LC9:
	.string	"neun"
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
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	cmpl	$1, -20(%rbp)
	jle	.L2
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	jmp	.L3
.L2:
	movl	$0, %eax
.L3:
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jne	.L4
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L4:
	cmpl	$1, -4(%rbp)
	jne	.L5
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L5:
	cmpl	$2, -4(%rbp)
	jne	.L6
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L6:
	cmpl	$3, -4(%rbp)
	jne	.L7
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L7:
	cmpl	$4, -4(%rbp)
	jne	.L8
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L8:
	cmpl	$5, -4(%rbp)
	jne	.L9
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L9:
	cmpl	$6, -4(%rbp)
	jne	.L10
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L10:
	cmpl	$7, -4(%rbp)
	jne	.L11
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L11:
	cmpl	$8, -4(%rbp)
	jne	.L12
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L12:
	cmpl	$9, -4(%rbp)
	jne	.L13
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L13:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
