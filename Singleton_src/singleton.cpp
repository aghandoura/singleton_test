#include<iostream>
#include<mutex>

#include"singleton.h"

singleton* singleton::m_instance = NULL;
int singleton::m_instances_count = 0;


singleton*
singleton::get_instance(){
	std::cout <<"getting instance "<<std::endl;
	m_instances_count++;
	if(m_instance == NULL){
		std::mutex my_mutex;
		my_mutex.lock();
		if(m_instance == NULL){
			m_instance = new singleton;
		}
		my_mutex.unlock();
	}

	return m_instance;
};

void
singleton::kill(){
	if(m_instance != NULL){
		std::mutex my_mutex;
		my_mutex.lock();
		m_instances_count--;
			if(m_instance != NULL){
			  std::cout <<"killing "<<std::endl;
			  delete m_instance;
			  m_instance =NULL;
			}
		my_mutex.unlock();
	}
}

singleton::singleton(){
	std::cout << "object created"<<std::endl;
}

singleton::~singleton(){
	std::cout << "object destroyed"<<std::endl;
}
