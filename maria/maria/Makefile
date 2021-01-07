SRCS	= matmult_nat.c matmult_lib.c
OBJS	= $(SRCS:.c=.o)
TARGET	= libmatmult.so
CC	= gcc -std=c99 -fPIE
INCS	= 
DBG	= -g
OPT	= -O3
PARA	= 
LIBS	= -lm -L/usr/Lib64/atlas -lsatlas
CFLAGS	= $(DBG) $(OPT) $(PARA) $(XOPTS) $(LIBS)

$(TARGET): $(OBJS)  
	$(CC) *.o  -shared -o $(TARGET) 

clean:
	rm -f *.o *.so 