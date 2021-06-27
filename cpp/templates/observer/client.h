/*
 * client.h
 *
 *  Created on: May 24, 2021
 *      Author: seb
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "observer.h"
#include "publisher.h"

class Client: public Publisher<ObserverInterface> {
public:
	Client() = default;
	Client(unsigned int id);
	~Client() = default;
	void notify();
private:
	unsigned int m_id{0};
};

#endif /* CLIENT_H_ */
