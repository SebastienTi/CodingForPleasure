/*
 * observer.h
 *
 *  Created on: May 24, 2021
 *      Author: seb
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include "observer_interface.h"

class Observer: public ObserverInterface {
public:
	Observer() = delete;
	Observer(unsigned int id);
	~Observer() = default;
	void update(unsigned int id) override;

private:
	unsigned int m_id{0};
};

#endif /* OBSERVER_H_ */
