#include<vm.h>

int get_opcode(int fd) 
{
    if(pos < BUFLEN) {
	return buf[pos++];
    } else {
	size = read(fd,buf,BUFLEN);
	pos = 0;
	return buf[pos++];
    }
}

int get_operand(int fd)
{
    int old_pos;
    int old,new;
    switch(pos) {
    case BUFLEN - 1:
	read(fd,buf,BUFLEN);
	pos = 0;
	break;
    case BUFLEN - 2:
	old = buf[pos++];
	pos = 0;
	size = read(fd,buf,BUFLEN);
	new = (u16)buf[pos] << 8 | (u8) old;
	break;
    }

    old_pos = pos;
    pos += 2;
    return *((unsigned short int *) &buf[old_pos]);
}

void pass1(char *argv[])
{
    FILE *fp;
    int c,c1,c2;
    fp = fopen(argv[1],"r");
    fseek(fp,8,SEEK_SET);
    while((c = getc(fp))!= EOF) {
	if(c == LOAD_ATTR) {
	    c1 = getc(fp);
	    c2 = getc(fp);
	    const_array[const_index++] = ((c2 & 0xFF) << 8) | (c1 & 0xFF);
	}
    }
}
	
void pass2(int fd,char *buf,int size) 
{

   int opcode;
   init_ptr_array();
   config_ptr_array();
    while ((opcode = get_opcode(fd)) != RETURN_VALUE) {
	ptr_array[opcode](fd);
    }
}

int read_magic(char *filename)
{
    FILE *fp;
    char magic[4];
    fp = fopen(filename,"r");
    return ((getc(fp) & 0xFF ) >> 24) | ((getc(fp) & 0xFF ) >> 8) |
	((getc(fp) & 0xFF ) << 8) | ((getc(fp) & 0xFF ) << 24) ; 
}

int main(int argc,char *argv[])
{
    int fd,i;
    int magic;
    char timestamp[4];

    if((fd = open(argv[1],O_RDONLY)) < 0) {
	perror("open");
	exit(errno);
    }
 
    if(read(fd,&magic,MAGIC_LEN) < 0) {
	perror("magic");
	exit(errno);
    }
 
    if(read(fd,timestamp,TIME_STAMP_LEN) < 0) {
	perror("time");
	exit(errno);
    }
	
    read(fd,buf,BUFLEN);
    pos = 22;
    pass1(argv);
    pass2(fd,buf,size);

}
