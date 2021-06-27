CC=g++ -std=c++17
CFLAGS+=-Wall
BUILD_OUTPUT=build

.PHONY: create_dir clean mrproper

all: create_dir build/main

build/main: build/main.o build/client.o build/observer.o
	$(CC) -o $@ $^

build/main.o: main.cpp client.h publisher.h
	$(CC) $(CFLAGS) -o $@ -c $<

build/client.o: client.cpp client.h
	$(CC) $(CFLAGS) -o $@ -c $<  

build/observer.o: observer.cpp  observer.h  observer_interface.h
	$(CC) $(CFLAGS) -o $@ -c $<  

create_dir:
	mkdir $(BUILD_OUTPUT)

clean:
	rm -f $(BUILD_OUTPUT)/*~ $(BUILD_OUTPUT)/*.o

mrproper: clean
	rm -rf $(BUILD_OUTPUT)


