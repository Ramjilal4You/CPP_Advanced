	.file	"Default Template Argument.cpp"
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
.lcomm __ZStL8__ioinit,1,1
	.section	.text$_ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev
	.def	__ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev;	.scl	2;	.type	32;	.endef
__ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev:
LFB1450:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1450:
	.section	.text$_ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev
	.def	__ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev;	.scl	2;	.type	32;	.endef
__ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev:
LFB1453:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1453:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Hello\0"
LC2:
	.ascii "World\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1447:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1447
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$144, %esp
	call	___main
	leal	-37(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcEC1Ev
	leal	-64(%ebp), %eax
	leal	-37(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	$LC0, (%esp)
	movl	%eax, %ecx
LEHB0:
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
LEHE0:
	subl	$8, %esp
	leal	-96(%ebp), %eax
	leal	-64(%ebp), %edx
	movl	%edx, 8(%esp)
	flds	LC1
	fstps	4(%esp)
	movl	$10, (%esp)
	movl	%eax, %ecx
LEHB1:
	call	__ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1EifS5_
LEHE1:
	subl	$12, %esp
	leal	-64(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	leal	-37(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcED1Ev
	leal	-9(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcEC1Ev
	leal	-36(%ebp), %eax
	leal	-9(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	$LC2, (%esp)
	movl	%eax, %ecx
LEHB2:
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
LEHE2:
	subl	$8, %esp
	leal	-136(%ebp), %eax
	leal	-36(%ebp), %edx
	movl	%edx, 12(%esp)
	fldl	LC3
	fstpl	4(%esp)
	movl	$65, (%esp)
	movl	%eax, %ecx
LEHB3:
	call	__ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1EcdS5_
LEHE3:
	subl	$16, %esp
	leal	-36(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	leal	-9(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcED1Ev
	leal	-96(%ebp), %eax
	movl	%eax, %ecx
LEHB4:
	call	__ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE9getValuesEv
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	leal	-136(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE9getValuesEv
LEHE4:
	movl	$0, %ebx
	leal	-136(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev
	leal	-96(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev
	movl	%ebx, %eax
	jmp	L16
L12:
	movl	%eax, %ebx
	leal	-64(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	L6
L11:
	movl	%eax, %ebx
L6:
	leal	-37(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB5:
	call	__Unwind_Resume
L14:
	movl	%eax, %ebx
	leal	-36(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	L8
L13:
	movl	%eax, %ebx
L8:
	leal	-9(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcED1Ev
	jmp	L9
L15:
	movl	%eax, %ebx
	leal	-136(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev
L9:
	leal	-96(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE5:
L16:
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1447:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA1447:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1447-LLSDACSB1447
LLSDACSB1447:
	.uleb128 LEHB0-LFB1447
	.uleb128 LEHE0-LEHB0
	.uleb128 L11-LFB1447
	.uleb128 0
	.uleb128 LEHB1-LFB1447
	.uleb128 LEHE1-LEHB1
	.uleb128 L12-LFB1447
	.uleb128 0
	.uleb128 LEHB2-LFB1447
	.uleb128 LEHE2-LEHB2
	.uleb128 L13-LFB1447
	.uleb128 0
	.uleb128 LEHB3-LFB1447
	.uleb128 LEHE3-LEHB3
	.uleb128 L14-LFB1447
	.uleb128 0
	.uleb128 LEHB4-LFB1447
	.uleb128 LEHE4-LEHB4
	.uleb128 L15-LFB1447
	.uleb128 0
	.uleb128 LEHB5-LFB1447
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
LLSDACSE1447:
	.text
	.section	.text$_ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1EifS5_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1EifS5_
	.def	__ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1EifS5_;	.scl	2;	.type	32;	.endef
__ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1EifS5_:
LFB1666:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	flds	12(%ebp)
	fstps	4(%eax)
	movl	-12(%ebp), %eax
	leal	8(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE1666:
	.section	.text$_ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1EcdS5_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1EcdS5_
	.def	__ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1EcdS5_;	.scl	2;	.type	32;	.endef
__ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1EcdS5_:
LFB1669:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movb	%al, -16(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-12(%ebp), %eax
	movzbl	-16(%ebp), %edx
	movb	%dl, (%eax)
	movl	-12(%ebp), %eax
	fldl	-24(%ebp)
	fstpl	8(%eax)
	movl	-12(%ebp), %eax
	leal	16(%eax), %edx
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE1669:
	.section .rdata,"dr"
LC5:
	.ascii " \0"
	.section	.text$_ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE9getValuesEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE9getValuesEv
	.def	__ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE9getValuesEv;	.scl	2;	.type	32;	.endef
__ZN7MyClassIifNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE9getValuesEv:
LFB1670:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	leal	8(%eax), %ebx
	movl	-12(%ebp), %eax
	flds	4(%eax)
	fstps	-16(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$LC5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	flds	-16(%ebp)
	fstps	(%esp)
	movl	%eax, %ecx
	call	__ZNSolsEf
	subl	$4, %esp
	movl	$LC5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1670:
	.section	.text$_ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE9getValuesEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE9getValuesEv
	.def	__ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE9getValuesEv;	.scl	2;	.type	32;	.endef
__ZN7MyClassIcdNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE9getValuesEv:
LFB1673:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	leal	16(%eax), %ebx
	movl	-12(%ebp), %eax
	fldl	8(%eax)
	fstpl	-24(%ebp)
	movl	-12(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movl	$LC5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	fldl	-24(%ebp)
	fstpl	(%esp)
	movl	%eax, %ecx
	call	__ZNSolsEd
	subl	$8, %esp
	movl	$LC5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1673:
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1901:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1901:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1900:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L24
	cmpl	$65535, 12(%ebp)
	jne	L24
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L24:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1900:
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
LFB1902:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1902:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
	.section .rdata,"dr"
	.align 4
LC1:
	.long	1085632676
	.align 8
LC3:
	.long	1374389535
	.long	1074339512
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEf;	.scl	2;	.type	32;	.endef
	.def	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEd;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
