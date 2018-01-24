/**
 *  file    Main.c
 *  date    2009/01/02
 *  author  kkamagui 
 *          Copyright(c)2008 All rights reserved by kkamagui
 *  brief   C ���� �ۼ��� Ŀ���� ��Ʈ�� ����Ʈ ����
 */

#include "Types.h"
#include "Keyboard.h"
#include "Descriptor.h"
#include "Utility.h"
#include "AssemblyUtility.h"

// �Լ� ����
void kPrintString( int iX, int iY, const char* pcString );

/**
 *  �Ʒ� �Լ��� C ��� Ŀ���� ���� �κ���
 */
void Main( void )
{
    char vcTemp[ 2 ] = { 0, };
    BYTE bFlags;
    BYTE bTemp;
    int i = 0;
    
    kPrintString( 0, 10, "Switch To IA-32e Mode Success~!!" );
    kPrintString( 0, 11, "IA-32e C Language Kernel Start..............[Pass]" );
    kPrintString( 0, 12, "Keyboard Activate...........................[    ]" );

    if( kActivateKeyboard() == TRUE )
    {
        kPrintString( 45, 12, "Pass" );
        kChangeKeyboardLED( FALSE, FALSE, FALSE );
    }
    else
    {
        kPrintString( 45, 12, "Fail" );
        while( 1 ) ;
    }
    
    kPrintString( 0, 13, "GDT Initialize And Switch to IA-32e.........[    ]" );
    kInitializeGDTTableAndTSS();
    kLoadGDTR(GDTR_STARTADDRESS);
    kPrintString( 45, 13, "Pass");

    kPrintString( 0, 14, "TSS Segment Load............................[    ]" );
    kLoadTR(GDT_TSSSEGMENT);
    kPrintString( 45, 14, "Pass");

    kPrintString( 0, 15, "IDT Initialize..............................[    ]" );
    kLoadIDTR(IDTR_STARTADDRESS);
    kPrintString( 45, 15, "Pass");

    while( 1 )
    {
        // ��� ����(��Ʈ 0x60)�� �� ������ ��ĵ �ڵ带 ���� �� ����
        if( kIsOutputBufferFull() == TRUE )
        {
            // ��� ����(��Ʈ 0x60)���� ��ĵ �ڵ带 �о ����
            bTemp = kGetKeyboardScanCode();

            if( kConvertScanCodeToASCIICode( bTemp, &( vcTemp[ 0 ] ), &bFlags ) == TRUE )
            {
                if( bFlags & KEY_FLAGS_DOWN )
                {
                    kPrintString( i++, 16, vcTemp );
                    if(vcTemp[0] == '0')
                    	bTemp = bTemp / 0;
                }
            }
        }
    }
}

/**
 *  ���ڿ��� X, Y ��ġ�� ���
 */

