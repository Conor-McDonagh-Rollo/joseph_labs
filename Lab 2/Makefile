# Conor McDonagh Rollo
# Makefile for software engineering for games II

BLUE='\033[0;34m'
WHITE= '\033[0;37m' 
RED= '\033[0;31m'  

COMPILER=gcc
OPTIONS=-g -w
COMPILE=$(COMPILER) $(OPTIONS)
SOURCES=listmain.c
INCLUDES=minunit.h DLinkedList.h

OUTPUT_NAME=build

%.o: %.c
	$(COMPILE) -Wall -c $< -o $@

.SILENT:
build: $(SOURCES) $(INCLUDES)
	echo "$(RED)Building..."
	$(COMPILE) $(SOURCES) $(INCLUDES) -o $(OUTPUT_NAME).bin
	echo "$(BLUE)DONE! (run ./$(OUTPUT_NAME).bin)"

clean:
	rm -f *.o *.bin
