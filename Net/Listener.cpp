/*
 * Listener.cpp
 *
 *  Created on: Dec 20, 2016
 *      Author: xiaoliang
 */

#include <cstddef>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Listener.h"
#include "../Server.h"
using namespace Xler::Net;
Listener* Listener::instance = NULL;
Listener::Listener() {
	ser = 0;
	tcp_fd = 0;
	udp_fd = 0;
}

Listener::~Listener() {
}

void Listener::init(Server *ser) {
	this->ser = ser;
}

void Listener::create(void) {
	const ServerConf *conf = ser->get_conf();
	for(Def::NetProSetVec::const_iterator it = conf->net_lisen.begin();
			it != conf->net_lisen.end(); ++it) {
		switch(it->type) {
			case NPT_TCP: {
				listen_tcp(*it);
				break;
			};
			case NPT_UDP: {
				listen_udp(*it);
				break;
			};
		}
	}
}

bool Listener::listen_tcp(const Def::NetProSet &set) {
	if(this->tcp_fd == 0) {
		this->tcp_fd = socket(AF_INET, SOCK_STREAM, 0);
	}
	if(this->tcp_fd == -1) return false;
	/*sockaddr_in结构体相关参数*/
	struct sockaddr_in sockaddr;
	memset(&sockaddr,0,sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	//sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	inet_pton(AF_INET,set.ip.c_str(),&sockaddr.sin_addr);
	sockaddr.sin_port = htons(set.port);
	int bres = bind(this->tcp_fd,(struct sockaddr *) &sockaddr,sizeof(sockaddr));
	int lres = listen(this->tcp_fd,1024);
	return true;
}

bool Listener::listen_udp(const Def::NetProSet &set) {
	return true;
}
