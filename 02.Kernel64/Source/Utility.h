#ifndef __UTILITY_H__
#define __UTILITY_H__

#include "Types.h"

void kMemSet(void * pvDestination, BYTE bData, int iSize);
int kMemCpy(void * pvDestination, const void * pvSource, int iSize);
int kMemCpy(void * pvDestination, const void * pvSource, int iSize);
void kPrintString( int iX, int iY, const char* pcString );
#endif
