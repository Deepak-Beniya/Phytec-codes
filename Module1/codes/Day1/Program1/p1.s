	.file	"p1.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Addition   of two numbers :%d\n"
	.align 8
.LC1:
	.string	"Subtraction  of two numbers :%d\n"
	.align 8
.LC2:
	.string	"Multiplication  of two numbers :%d\n"
.LC3:
	.string	"Division  of two numbers :%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$5, %esi
	movl	$10, %edi
	call	add@PLT
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$5, %esi
	movl	$10, %edi
	call	sub@PLT
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$5, %esi
	movl	$10, %edi
	call	mup@PLT
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$5, %esi
	movl	$10, %edi
	call	div@PLT
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
