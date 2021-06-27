//============================================================================
// Name        : templates.cpp
// Author      : Séb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "observer.h"
#include "client.h"
using namespace std;

int main() {

	Observer observer1(1);
	Observer observer2(2);
	Client client(1);
	client.addObserver(observer1);
	client.addObserver(observer2);

	client.notify();

	client.removeObserver(observer1);

	client.notify();

	client.clearObservers();

	return 0;
}
