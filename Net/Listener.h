/*
 * Listener.h
 *
 *  Created on: Dec 20, 2016
 *      Author: xiaoliang
 */
#pragma once
#include "../Def/Config.h"
namespace Xler {
	class Server;
	namespace Net {
		class Listener {
		public:
			static Listener* getInstance() {
				if (instance == NULL)
					instance = new Listener();
				return instance;
			}
			void init(Server *ser);
			void create(void);
		private:
			Listener();
			virtual ~Listener();
			bool listen_tcp(const Def::NetProSet &set);
			bool listen_udp(const Def::NetProSet &set);

			static Listener *instance;
			Server *ser;
			int tcp_fd;
			int udp_fd;
		};

#define LISTENER Listener::getInstance()
	}
}
