/*
 * observer_interface.h
 *
 *  Created on: May 24, 2021
 *      Author: seb
 */

#ifndef OBSERVER_INTERFACE_H_
#define OBSERVER_INTERFACE_H_

class ObserverInterface {
public:
	virtual ~ObserverInterface() = default;
	virtual void update(unsigned int id) = 0;
};



#endif /* OBSERVER_INTERFACE_H_ */
