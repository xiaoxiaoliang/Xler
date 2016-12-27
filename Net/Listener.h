/*
 * ListerWorker.h
 *
 *  Created on: Dec 20, 2016
 *      Author: root
 */
#pragma once

namespace Xler {
	namespace Net {
		class Server;
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
			static Listener *instance;
			Server *ser;
		};

#define LISTENER Listener::getInstance()
	}
}
