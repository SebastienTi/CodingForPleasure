CC=gcc 
LIBS+=-lpthread
BUILD_OUTPUT=build

.PHONY: create_dir clean mrproper

all: create_dir build/main

build/main: build/thread.o
	$(CC) -o $@ $^ $(LIBS)

build/thread.o: POSIXThread.c
	$(CC) $(CFLAGS) -o $@ -c $< $(LIBS)

create_dir:
	mkdir $(BUILD_OUTPUT)

clean:
	rm -f $(BUILD_OUTPUT)/*~ $(BUILD_OUTPUT)/*.o

mrproper: clean
	rm -rf $(BUILD_OUTPUT)


