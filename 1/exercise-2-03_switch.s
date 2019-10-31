	.file	"exercise-2-03_switch.c"
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
	.string	"fuenf"
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
	cmpl	$9, -4(%rbp)
	ja	.L4
	movl	-4(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L6(%rip), %rax
	movl	(%rdx,%rax), %eax
	movslq	%eax, %rdx
	leaq	.L6(%rip), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L6:
	.long	.L5-.L6
	.long	.L7-.L6
	.long	.L8-.L6
	.long	.L9-.L6
	.long	.L10-.L6
	.long	.L11-.L6
	.long	.L12-.L6
	.long	.L13-.L6
	.long	.L14-.L6
	.long	.L15-.L6
	.text
.L5:
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L7:
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L8:
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L9:
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L10:
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L11:
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L12:
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L13:
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L14:
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L15:
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
.L4:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
