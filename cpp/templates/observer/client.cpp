/*
 * client.cpp
 *
 *  Created on: May 24, 2021
 *      Author: seb
 */

#include "client.h"

Client::Client(unsigned int id):m_id(id) {
}

void Client::notify() {
	notifyObserver(&ObserverInterface::update, m_id);
}
