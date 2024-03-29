#ifndef __OPCOD_H__
#define __OPCOD_H__

enum{STOP_CODE,
     POP_TOP,
     ROT_TWO,
     ROT_THREE,
     DUP_TOP,
     ROT_FOUR,
     NOP=0x09,
     UNARY_POSITIVE,
     UNARY_NEGATIVE,
     UNARY_NOT,
     UNARY_CONVERT,
     UNARY_INVERT=0x0F,
     LIST_APPEND=0x12,
     BINARY_POWER,
     BINARY_MULTIPLY,
     BINARY_DIVIDE,
     BINARY_MODULO,
     BINARY_ADD,
     BINARY_SUBSTRACT,
     BINARY_SUBSCR,
     BINARY_FLOOR_DIVIDE,
     BINARY_TRUE_DIVIDE,
     INPLACE_FLOOR_DIVIDE,
     INPLACE_TRUE_DIVIDE,
     SLICE,
     SLICE1,
     SLICE2,
     SLICE3,
     STORE_SLICE=0x28,
     STORE_SLICE1,
     STORE_SLICE2,
     STORE_SLICE3,
     DELETE_SLICE=0X32,
     DELETE_SLICE1,
     DELETE_SLICE2,
     DELETE_SLICE3,
     INPLACE_ADD=0X37,
     INPLACE_SUBSTRACT,
     INPLACE_MULTIPLY,
     INPLACE_DEVIDE,
     INPLACE_MODULO,
     STORE_SUBSCR,
     DELETE_SUBSCR,
     BINARY_LSHIFT,
     BINARY_RSHIFT,
     BINARY_AND,
     BINARY_XOR,
     BINARY_OR,
     INPLACE_POWER,
     GET_ITER,
     PRINT_EXPR=0X46,
     PRINT_ITEM,
     PRINT_NEWLINE,
     PRINT_ITEM_TO,
     PRINT_NEWLINE_TO,
     INPLACE_LSHIFT,
     INPLACE_RSHIFT,
     INPLACE_AND,
     INPLACE_XOR,
     INPLACE_OR,
     BREAK_LOOP,
     WITH_CLEANUP,
     LOAD_LOCALS,
     RETURN_VALUE,
     IMPORT_STAR,
     EXEC_STMT,
     YIELD_VALUE,
     POP_BLOCK,
     END_FINALLY,
     BUILD_CLASS,
     STORE_NAME,
     DELETE_NAME,
     UNPACK_SEQUENCE,
     FOR_ITER,
     SOTRE_ATTR=0x5F,
     DELETE_ATTR,
     STORE_GLOBAL,
     DELETE_GLOBAL,
     DUP_TOPX,
     LOAD_CONST,
     LOAD_NAME,
     BUILD_TUPLE,
     BUILD_LIST,
     BUILD_MAP,
     LOAD_ATTR,
     COMPARE_OP,
     IMPORT_NAME,
     IMPORT_FROM,
     JUMP_FORWARD=0x6E,
     JUMP_IF_FALSE,
     JUMP_IF_TRUE,
     JUMP_ABSOLUTE,
     LOAD_GLOBAL=0x74,
     CONTINUE_LOOP=0x77,
     SETUP_LOOP,
     SETUP_EXCEPT,
     SETUP_FINALLY,
     LOAD_FAST=0x7C,
     STORE_FAST,
     DELETE_FAST,
     RAISE_VARARGS=0x82,
     CALL_FUNCTION,
     MAKE_FUNCTION,
     BUILD_SLICE,
     MAKE_CLOSURE,
     LOAD_CLOSURE,
     LOAD_DEREF,
     STORE_DEREF,
     CALL_FUCTION_VAR=0x8C,
     CALL_FUCNTION_KW,
     CALL_FUNCTION_VAR_KW,
     EXTENDED_VAR
};

struct opcode{
  char bc_instruction[30];
  int bc_len;
};

static struct opcode op_buf[144] ={
  {"STOP_CODE",0},
  {"POP_TOP",0},
  {"ROT_TWO",0},
  {"ROT_THREE",0},
  {"DUP_TOP",0},
  {"ROT_FOUR",0},
  {"INVALID",2},
  {"INVALID",2},
  {"INVALID",2},
  {"NOP",0},
  {"UNARY_POSITIVE",0},
  {"UNARY_NEGATIVE",0},
  {"UNARY_NOT",0},
  {"UNARY_CONVERT",0},
  {"INVALID",2},
  {"UNARY_INVERT",0},

  {"INVALID",2},
  {"INVALID",2},
  {"LIST_APPEND",0},
  {"BINARY_POWER",0},
  {"BINARY_MULTIPLY",0},
  {"BINARY_DIVIDE",0},
  {"BINARY_MODULO",0},
  {"BINARY_ADD",0},
  {"BINARY_SUBSTRACT",0},
  {"BINARY_SUBSCR",0},
  {"BINARY_FLOOR_DEVIDE",0},
  {"BINARY_TRUE_DEVIDE",0},
  {"INPLACE_FLOOR_DEVIDE",0},
  {"INPLACE_TRUE_DEVIDE",0},
  {"SLICE",0},
  {"SLICE+1",0},

  {"SLICE+2",0},
  {"SLICE+3",0},
  {"INVALID",2},
  {"INVALID",2},
  {"INVALID",2},
  {"INVALID",2},
  {"INVALID",2},
  {"INVALID",2},
  {"STORE_SLICE",0},
  {"STORE_SLICE+1",0},
  {"STORE_SLICE+2",0},
  {"STORE_SLICE+3",0},
  {"INVALID",2},
  {"INVALID",2},
  {"INVALID",2},
  {"INVALID",2},

  {"INVALID",2},
  {"INVALID",2},
  {"DELETE_SLICE",0},
  {"DELETE_SLICE+1",0},
  {"DELETE_SLICE+2",0},
  {"DELETE_SLICE+3",0},
  {"INVALID",0},
  {"INPLACE_ADD",0},
  {"INPLACE_SUBSTRACT",0},
  {"INPLACE_MULTIPLY",0},
  {"INPLACE_DEVIDE",0},
  {"INPLACE_MODULO",0},
  {"STORE_SUBSCR",0},
  {"DELETE_SUBSCR",0},
  {"BINARY_LSHIFT",0},
  {"BINARY_RSHIFT",0},

  {"BINARY_ADD",0},
  {"BINARY_XOR",0},
  {"BINARY_OR",0},
  {"INPLACE_POWER",0},
  {"GET_ITER",0},
  {"INVALID",2},
  {"PRINT_EXPR",0},
  {"PRINT_ITEM",0},
  {"PRINT_NEWLINE",0},
  {"PRINT_ITEM_TO",0},
  {"PRINT_NEWLINE_TO",0},
  {"INPLACE_LSHIFT",0},
  {"INPLACE_RSHIFT",0},
  {"INPLACE_AND",0},
  {"INPLACE_XOR",0},
  {"INPLACE_OR",0},

  {"BREAK_LOOP",0},
  {"WITH_CLEANUP",0},
  {"LOAD_LOCALS",0},
  {"RETURN_VALUE",0},
  {"IMPORT_STAR",0},
  {"EXEC_STMT",0},
  {"YIELD_VALUE",0},
  {"POP_BLOCK",0},
  {"END_FINALLY",0},
  {"BUILD_CLASS",0},
  {"STORE_NAME",2},
  {"DELETE_NAME",2},
  {"UNPACK_SEQUENCE",2},
  {"FOR_ITER",2},
  {"INVALID",2},
  {"STORE_ATTR",2},

  {"DELETE_ATTR",2},
  {"STORE_GLOBAL",2},
  {"DELETE_GLOBAL",2},
  {"DUP_TOPX",2},
  {"LOAD_CONST",2},
  {"LOAD_NAME",2},
  {"BUILD_TUPLE",2},
  {"BUILD_LIST",2},
  {"BUILD_MAP",2},
  {"LOAD_ATTR",2},
  {"COMPARE_OP",2},
  {"IMPORT_NAME",2},
  {"IMPORT_FROM",2},
  {"INVALID",2},
  {"JUMP_FORWARD",2},
  {"JUMP_IF_FALSE",2},

  {"JUMP_IF_TRUE",2},
  {"JUMP_ABSOLUTE",2},
  {"INVALID",2},
  {"<115>",2},
  {"LOAD_GLOABAL",2},
  {"INVALID",2},
  {"INVALID",2},
  {"CONTINUE_LOOP",2},
  {"SETUP_LOOP",2},
  {"SETUP_EXCEPT",2},
  {"SETUP_FINALLY",2},
  {"INVALID",2},
  {"LOAD_FAST",2},
  {"STORE_FAST",2},
  {"DELETE_FAST",2},
  {"INVALID",2},

  {"INVALID",2},
  {"INVALID",2},
  {"RAISE_VARARGS",2},
  {"CALL_FUNCTION",2},
  {"MAKE_FUNCTION",2},
  {"BUILD_SLICE",2},
  {"MAKE_CLOSURE",2},
  {"LOAD_CLOSURE",2},
  {"LOAD_DEREF",2},
  {"STORE_DEREF",2},
  {"INVALID",2},
  {"INVALID",2},
  {"CALL_FUNCTION_VAR",2},
  {"CALL_FUNCTION_KW",2},
  {"CALL_FUNCTION_VAR_KW",2},
  {"EXTENDED_ARG",2}
};

#define read_byte(i) (unsigned char) op_buf[i].bc_len


#endif
