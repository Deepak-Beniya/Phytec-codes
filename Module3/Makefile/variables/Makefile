#Where to install the binary
INSTALL_PATH =../..

#Name of the Application
TAR_NAME= App

#Path of the source Directory
SRC_DIR=.

#Path of the current Directory
CUR_DIR=.

#O_Flag
OFLAG=-o

#compiler
CC=gcc

#compiler flags
CFLAG=-c -g

# O files
O_FILES=*.o

App:App.o print.o add.o header.h
	$(CC) $^ $(OFLAG) $@
App.o:App.c
	$(CC) $^ $(CFLAG) $(OFLAG) $@
	@echo "App.o binary generated"
add.o:add.c
	$(CC) $^ $(CFLAG) $(OFLAG) $@	
	@echo "add.o binary generated"
print.o:print.c
	@echo "print.c binary generated"
	$(CC) $^ $(CFLAG) $(OFLAG) $@	
install:${TAR_NAME}
	cp -rf ${CUR_DIR}/${TAR_NAME} $(INSTALL_PATH)/$(TAR_NAME)
clean:
	rm $(CUR_DIR)/$(O_FILES) $(CUR_DIR)/$(TAR_NAME) $(INSTALL_PATH)/$(TAR_NAME)

