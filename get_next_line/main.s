	.file	"main.c"
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
	movabsq	$7885630463507786083, %rax
	movq	%rax, -18(%rbp)
	movabsq	$17840083510324591, %rax
	movq	%rax, -12(%rbp)
	movl	$3, -4(%rbp)
	movl	$213, -4(%rbp)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.data
	.align 4
	.type	cavallo.0, @object
	.size	cavallo.0, 4
cavallo.0:
	.long	3
	.ident	"GCC: (GNU) 14.0.1 20240411 (Red Hat 14.0.1-0)"
	.section	.note.GNU-stack,"",@progbits
