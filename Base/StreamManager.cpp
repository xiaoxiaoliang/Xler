#include <iostream>
#include <list>
#include <set>
#include "StreamManager.h"
#include "Stream.h"

using namespace Xler::Base;
StreamManager *StreamManager::instance = NULL;
StreamManager::StreamManager(void) {
	pthread_mutex_init(&m_mutex, NULL);
	max_idle = 1024;
}


StreamManager::~StreamManager(void) {
}

Stream* StreamManager::get() {
	pthread_mutex_lock(&m_mutex);
	Stream *st = NULL;
	if(this->idle_list.empty()) {
		st = new Stream();
		this->using_list.insert(st);
	} else {
		st = this->idle_list.front();
		this->idle_list.pop_front();
		this->using_list.insert(st);
	}
	pthread_mutex_unlock(&m_mutex);
	st->reset();
	return st;
}

void StreamManager::put(Stream* stream) {
	pthread_mutex_lock(&m_mutex);
	Stream_Set::iterator it = this->using_list.find(stream);
	if(it != this->using_list.end()) {
		if(this->idle_list.size() < this->max_idle) {
			this->idle_list.push_back(*it);
		} else {
			delete (*it);
		}
		this->using_list.erase(it);
	}
	pthread_mutex_unlock(&m_mutex);
}
