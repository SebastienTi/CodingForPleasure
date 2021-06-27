/*
 * publisher.h
 *
 *  Created on: May 24, 2021
 *      Author: seb
 */

#ifndef PUBLISHER_H_
#define PUBLISHER_H_

#include <vector>
#include <algorithm>
#include <functional>

/**
 * Class used as general publisher to provide basic method for all other publisher
 */
template <class ObserverClass>
class Publisher {
public:

	void addObserver(ObserverClass& observer) {
		m_listObserver.push_back(observer);
	}

	void removeObserver(ObserverClass& observer){
		m_listObserver.erase(std::remove_if(m_listObserver.begin(), m_listObserver.end(), [&observer](ObserverClass& other){return &observer == &other;}));
	}

	void clearObservers(){m_listObserver.clear();}

protected:

	template<typename FunctionType, typename... Types>
	void notifyObserver(FunctionType function, Types... args) {
		for(auto& observer: m_listObserver){
			(observer.get().*function)(args...);
		}
	}

private:
	std::vector<std::reference_wrapper<ObserverClass>> m_listObserver{};

};



#endif /* PUBLISHER_H_ */
