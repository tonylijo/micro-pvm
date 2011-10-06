#include<stdio.h>
#include<opcode.h>
#include<globals.h>

void do_load_const(int fd)
{
    push(const_array[get_operand(fd)]);
}

void do_store_name(int fd)
{
    int i,op;
    op = get_operand(fd);
    i = sim_tab[op] = pop();
 
#ifdef __DEBUG
    printf("store name stored:%d to operand %d\n",i,op);
#endif

}

void do_binary_add(int fd)
{
    push(pop() + pop());
}

void do_binary_substract(int fd)
{
    int op1,op2;
    op1 = pop();
    op2 = pop();
    push(op2 - op1);
}

void do_binary_divide(int fd)
{
    int op1,op2;
    op1 = pop();
    op2 = pop();
    if(op1 != 0) {
	push(op2/op1);
    } else {
	printf("error zero divisor\n");
    }
}


void do_binary_mul(int fd)
{
    push(pop() * pop());
}

void do_binary_modulas(int fd)
{
    int op1,op2;
    op1 = pop();
    op2 = pop();
    push(op2 % op1);
}

void do_load_name(int fd)
{
    push(sim_tab[get_operand(fd)]);
}

void do_print_item(int fd)
{
    printf("%d",pop());
}

void do_print_new_line(int fd)
{
    printf("\n");
}

void do_setup_loop(int fd)
{
    int count;
    count = get_operand(fd);
    loop_end = pos + count;
    loop_start = pos;

#ifdef __DEBUG
    printf("setup_loop\n");
#endif

}

void do_pop_block(int fd)
{
    return;
}

void do_jump_if_false(int fd)
{
    if(getval() == 0) {
	pos = pos + get_operand(fd);
    } else {
	get_operand(fd);
    }

#ifdef __DEBUG
    printf("jump_if_false position is:%d\n",pos);
#endif

    return ;
}

void do_jump_abs(int fd)
{
    pos = 22 + get_operand(fd);
	
#ifdef __DEBUG
    printf("jump_absolute posistion is: %d\n",pos);
#endif

    return ;

}

void do_pop_top(int fd)
{
    pop();
#ifdef __DEBUG
    printf("pop_top\n");
#endif
    return;
}

void do_jump_fw(int fd)
{
    	    pos = pos + get_operand(fd);
	    return;
}

void do_nothing(int fd)
{
    printf("not implemented now\n");
}

