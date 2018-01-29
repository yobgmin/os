/**
 *  file    Utility.h
 *  date    2009/01/17
 *  author  kkamagui 
 *          Copyright(c)2008 All rights reserved by kkamagui
 *  brief   OS���� ����� ��ƿ��Ƽ �Լ��� ���õ� ����
 */

#ifndef __UTILITY_H__
#define __UTILITY_H__

#include "Types.h"
#include <stdarg.h>
////////////////////////////////////////////////////////////////////////////////
//
//  �Լ�
//
////////////////////////////////////////////////////////////////////////////////
void kMemSet( void* pvDestination, BYTE bData, int iSize );
int kMemCpy( void* pvDestination, const void* pvSource, int iSize );
int kMemCmp( const void* pvDestination, const void* pvSource, int iSize );
void kPrintString( int iX, int iY, const char* pcString );
BOOL kSetInterruptFlag( BOOL bEnableInterrupt );
int kStrLen( const char * pcBuffer);
void kCheckTotalRAMSize(void);
QWORD kGetTotalRAMSize(void);
long kAToI(const char * pcBuffer, int iRadix);
QWORD kHexStringToQword(const char * pcBuffer);
long kDecimalStringToLong(const char * pcBuffer);
int kIToA(long lValue, char * pcBuffer, int iRadix);
int kHexToString( QWORD qwValue, char * pcBuffer);
int kDecimalToString( long lValue, char * pcBuffer);
void kReverseString( char * pcBuffer);
int kSPrintf( char * pcBuffer, const char * pcFormatString, ...);
int kVSPrintf( char * pcBuffer, const char * pcFormatString, va_list ap);


#endif /*__UTILITY_H__*/
