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
	tcp_fd.clear();
	udp_fd.clear();
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

int Listener::listen_tcp(const Def::NetProSet &set) {
	int tcp_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(tcp_fd == -1) return -1;
	/*sockaddr_in结构体相关参数*/
	struct sockaddr_in sockaddr;
	memset(&sockaddr,0,sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	//sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	inet_pton(AF_INET,set.ip.c_str(),&sockaddr.sin_addr);
	sockaddr.sin_port = htons(set.port);
	if(bind(tcp_fd,(struct sockaddr *) &sockaddr,sizeof(sockaddr)) == -1) return -1;
	if(listen(tcp_fd,1024) == -1) return -1;
	this->tcp_fd.push_back(tcp_fd);
	return tcp_fd;
}

int Listener::listen_udp(const Def::NetProSet &set) {
	return true;
}
