#include <iostream>
#include <list>
#include <set>
#include "StreamManager.h"
#include "Stream.h"

using namespace Xler::Base;

StreamManager::StreamManager(void) {
	max_idle = 1024;
}


StreamManager::~StreamManager(void) {
}

Stream* StreamManager::get() {
	if(this->idle_list.empty()) {
		Stream *st = new Stream();
		this->using_list.insert(st);
		return st;
	} else {
		Stream *st = this->idle_list.front();
		this->idle_list.pop_front();
		this->using_list.insert(st);
		return st;
	}
}

void StreamManager::put(Stream* stream) {
	Stream_Set::iterator it = this->using_list.find(stream);
	if(it != this->using_list.end()) {
		if(this->idle_list.size() < this->max_idle) {
			this->idle_list.push_back(*it);
		} else {
			delete (*it);
		}
		this->using_list.erase(it);
	}
}
