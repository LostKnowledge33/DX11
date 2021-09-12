#pragma once

template<typename T>
class CSingleton {
protected:
	static T* instance;

public:
	static T* Get() {
		if (instance == NULL)
			instance = new T();

		return instance;
	}

	static void Delete() {
		delete instance;
	}
};

template<typename T>
T* CSingleton<T>::instance = NULL;