	.file	"01_template.cpp"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2225:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	movl	$7, %edx
	movl	$3, %ecx
	call	_Z5myMaxIiET_S0_S0_
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	movsd	.LC0(%rip), %xmm0
	movq	.LC1(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	_Z5myMaxIdET_S0_S0_
	movq	%xmm0, %rax
	movq	%rax, %xmm1
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEd
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	movl	$101, %edx
	movl	$103, %ecx
	call	_Z5myMaxIcET_S0_S0_
	movsbl	%al, %eax
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z5myMaxIiET_S0_S0_,"x"
	.linkonce discard
	.globl	_Z5myMaxIiET_S0_S0_
	.def	_Z5myMaxIiET_S0_S0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5myMaxIiET_S0_S0_
_Z5myMaxIiET_S0_S0_:
.LFB2481:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %eax
	cmpl	24(%rbp), %eax
	jle	.L4
	movl	16(%rbp), %eax
	jmp	.L6
.L4:
	movl	24(%rbp), %eax
.L6:
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z5myMaxIdET_S0_S0_,"x"
	.linkonce discard
	.globl	_Z5myMaxIdET_S0_S0_
	.def	_Z5myMaxIdET_S0_S0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5myMaxIdET_S0_S0_
_Z5myMaxIdET_S0_S0_:
.LFB2484:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movsd	16(%rbp), %xmm0
	comisd	24(%rbp), %xmm0
	jbe	.L13
	movsd	16(%rbp), %xmm0
	jmp	.L11
.L13:
	movsd	24(%rbp), %xmm0
.L11:
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z5myMaxIcET_S0_S0_,"x"
	.linkonce discard
	.globl	_Z5myMaxIcET_S0_S0_
	.def	_Z5myMaxIcET_S0_S0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5myMaxIcET_S0_S0_
_Z5myMaxIcET_S0_S0_:
.LFB2486:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%edx, %eax
	movl	%ecx, %edx
	movb	%dl, 16(%rbp)
	movb	%al, 24(%rbp)
	movzbl	16(%rbp), %eax
	cmpb	24(%rbp), %al
	jle	.L15
	movzbl	16(%rbp), %eax
	jmp	.L17
.L15:
	movzbl	24(%rbp), %eax
.L17:
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.align 8
.LC0:
	.long	0
	.long	1075576832
	.align 8
.LC1:
	.long	0
	.long	1074266112
	.ident	"GCC: (Rev3, Built by MSYS2 project) 13.2.0"
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEd;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
