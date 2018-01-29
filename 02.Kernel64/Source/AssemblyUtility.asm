# file      Assembly Utility
# date      2009/01/07
# author    kkamagui 
#           Copyright(c)2008 All rights reserved by kkamagui
# brief     ������� ��ƿ��Ƽ �Լ��� ���õ� �ҽ� ����

[BITS 64]           ; ������ �ڵ�� 64��Ʈ �ڵ�� ����

SECTION .text       ; text ����(���׸�Ʈ)�� ����

; C ���� ȣ���� �� �ֵ��� �̸��� ������(Export)
global kInPortByte, kOutPortByte, kLoadGDTR, kLoadTR, kLoadIDTR
global kEnableInterrupt, kDisableInterrupt, kReadRFLAGS

; ��Ʈ�κ��� 1����Ʈ�� ����
;   PARAM: ��Ʈ ��ȣ
kInPortByte:
    push rdx        ; �Լ����� �ӽ÷� ����ϴ� �������͸� ���ÿ� ����
                    ; �Լ��� ������ �κп��� ���ÿ� ���Ե� ���� ���� ����

    mov rdx, rdi    ; RDX �������Ϳ� �Ķ���� 1(��Ʈ ��ȣ)�� ����
    mov rax, 0      ; RAX �������͸� �ʱ�ȭ
    in al, dx       ; DX �������Ϳ� ����� ��Ʈ ��巹������ �� ����Ʈ�� �о�
                    ; AL �������Ϳ� ����, AL �������ʹ� �Լ��� ��ȯ ������ ����

    pop rdx         ; �Լ����� ����� ���� �������͸� ����
    ret             ; �Լ��� ȣ���� ���� �ڵ��� ��ġ�� ����
    
; ��Ʈ�� 1����Ʈ�� ��
;   PARAM: ��Ʈ ��ȣ, ������
kOutPortByte:
    push rdx        ; �Լ����� �ӽ÷� ����ϴ� �������͸� ���ÿ� ����
    push rax        ; �Լ��� ������ �κп��� ���ÿ� ���Ե� ���� ���� ����
    
    mov rdx, rdi    ; RDX �������Ϳ� �Ķ���� 1(��Ʈ ��ȣ)�� ����
    mov rax, rsi    ; RAX �������Ϳ� �Ķ���� 2(������)�� ����
    out dx, al      ; DX �������Ϳ� ����� ��Ʈ ��巹���� AL �������Ϳ� �����
                    ; �� ����Ʈ�� ��

    pop rax         ; �Լ����� ����� ���� �������͸� ����
    pop rdx
    ret             ; �Լ��� ȣ���� ���� �ڵ��� ��ġ�� ����


; GDTR �������Ϳ� GDT ���̺��� ����
;   PARAM: GDT ���̺��� ������ �����ϴ� �ڷᱸ���� ��巹��
kLoadGDTR:
    lgdt [ rdi ]    ; �Ķ���� 1(GDTR�� ��巹��)�� ���μ����� �ε��Ͽ� 
                    ; GDT ���̺��� ����
    ret

; TR �������Ϳ� TSS ���׸�Ʈ ��ũ���� ����
;   PARAM: TSS ���׸�Ʈ ��ũ������ ������
kLoadTR:
    ltr di          ; �Ķ���� 1(TSS ���׸�Ʈ ��ũ������ ������)�� ���μ�����
                    ; �����Ͽ� TSS ���׸�Ʈ�� �ε�
    ret
    
; IDTR �������Ϳ� IDT ���̺��� ����
;   PARAM: IDT ���̺��� ������ �����ϴ� �ڷᱸ���� ��巹��
kLoadIDTR:
    lidt [ rdi ]
    ret

kEnableInterrupt:
	sti
	ret

kDisableInterrupt:
	cli
	ret

kReadRFLAGS:
	pushfq
	pop rax
	ret


