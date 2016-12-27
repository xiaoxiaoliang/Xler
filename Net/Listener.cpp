/*
 * ListerWorker.cpp
 *
 *  Created on: Dec 20, 2016
 *      Author: root
 */

#include <cstddef>
#include "Listener.h"
#include "../Server.h"
using namespace Xler::Net;

Listener::Listener() {
	ser = 0;
}

Listener::~Listener() {
}

void Listener::init(Server *ser) {
	this->ser = ser;
}

void Listener::create(void) {

}
