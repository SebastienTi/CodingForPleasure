/*
 * observer.cpp
 *
 *  Created on: May 24, 2021
 *      Author: seb
 */

#include "observer.h"

#include <iostream>

using namespace std;

Observer::Observer(unsigned int id):m_id(id) {

}

void Observer::update(unsigned int id) {
	cout << "Observer "<< m_id << " is updated by client " << id << endl;
}
