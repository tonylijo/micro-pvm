#include<ptr_arr.h>

void init_ptr_array(void )
{
    int i;
    for(i = 0; i < 0x90;i++) {
	ptr_array[i]  = do_nothing;
    }
}

void config_ptr_array(void)
{
    ptr_array[LOAD_CONST] = do_load_const;
    ptr_array[BINARY_MODULO] = do_binary_modulas;
    ptr_array[STORE_NAME] = do_store_name;
    ptr_array[LOAD_NAME] = do_load_name;
    ptr_array[BINARY_ADD] = do_binary_add;
    ptr_array[BINARY_SUBSTRACT] = do_binary_substract;
    ptr_array[BINARY_DIVIDE] = do_binary_divide;
    ptr_array[BINARY_MULTIPLY] = do_binary_mul;
    ptr_array[PRINT_ITEM] = do_print_item;
    ptr_array[PRINT_NEWLINE] = do_print_new_line;
    ptr_array[SETUP_LOOP] = do_setup_loop;
    ptr_array[POP_TOP] = do_pop_top;
    ptr_array[JUMP_IF_FALSE] = do_jump_if_false;
    ptr_array[JUMP_ABSOLUTE] = do_jump_abs;
    ptr_array[POP_BLOCK] = do_pop_block;
    ptr_array[JUMP_FORWARD] = do_jump_fw;
}
