# file to compile
OBJS = main.cpp

#CC compiler
CC = g++

#compiler_flags
#-w suppress warnings
COMPILER_FLAGS = -w

#linker flags specifies te librries we are linking
LINKER_FLAGS = -lSDL2

# output file
OBJ_NAME = draw_image

#file extension
FILE_EXT = run

# target command
all : $(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME).$(FILE_EXT)