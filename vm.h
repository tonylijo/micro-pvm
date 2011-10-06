#ifndef _VM_H
#define _VM_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<opcode.h>

#define u16 unsigned short int
#define u8 unsigned char 
#define BUFLEN 4096
#define MAGIC_LEN 4
#define TIME_STAMP_LEN 4
#define SYM_TAB_LEN 100
#define CONST_ARR_LEN 100

typedef void (*funptr) (int );
extern funptr ptr_array[0x90];


int sim_tab[SYM_TAB_LEN];
int size;
int pos;

char buf[ BUFLEN ] ;
int const_array[CONST_ARR_LEN];
int const_index;
int loop_start,loop_end;

#endif
