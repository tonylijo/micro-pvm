CC := gcc
INCLUDE := -I.
DEBUG := 
CFLAGS := -c $(INCLUDE) $(DEBUG)
OBJS := vm.o stack.o bc_instruction.o ptr_arr.o

pyvm: $(OBJS)
	$(CC) $(OBJS) -o pyvm

vm.o: vm.c vm.h
	$(CC) $(CFLAGS) vm.c

stack.o: stack.c
	$(CC) $(CFLAGS) stack.c

ptr_arr.o: ptr_arr.c ptr_arr.h
	$(CC) $(CFLAGS) ptr_arr.c

bc_instruction.o: bc_instruction.c bc_inst.h 
	$(CC) $(CFLAGS) bc_instruction.c

clean:
	rm *.o pyvm
