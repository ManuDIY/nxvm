/* This file is a part of NXVM project. */

#ifndef NXVM_VAPI_H
#define NXVM_VAPI_H

#ifdef __cplusplus
extern "C" {
#endif

int  vapiPrint(const char *, ...);
void vapiPrintByte(unsigned char n);
void vapiPrintWord(unsigned short n);
void vapiPrintAddr(unsigned short segment,unsigned short offset);

#include "stdio.h"

#undef  VLOG_DEBUG
#define VLOG_COUNT_MAX 0xffff

typedef struct {
	char  flag;
	int   count;
	char  fname[0x100];
	FILE *fptr;
} t_apirecord;

extern t_apirecord vapirecord;

void vapiRecordStart();
void vapiRecordWrite();
void vapiRecordEnd();
void vapiTrace();

void vapiFloppyInsert(const char *fname);
void vapiFloppyRemove(const char *fname);

void vapiSleep();
void vapiDisplaySetScreen();
void vapiDisplayPaint();
void vapiStartDisplay();
void vapiStartKernel();

#ifdef __cplusplus
}
#endif

#endif
