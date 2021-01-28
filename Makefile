CC=gcc
FILE=task.c

### unified cross-platform clean function
#checks for env var of win 
ifeq ($(OS),Windows_NT)
    RM=del /Q
    TARGET=task.exe
else
    RM=rm -f
    TARGET=task
endif

all:
	$(CC) $(FILE) -o $(TARGET)

clean:
	$(RM) $(TARGET)
