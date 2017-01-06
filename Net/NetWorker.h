#pragma once
#include <stdint.h>
#include "../Base/StreamQueue.h"

namespace Xler {
	class Server;
	namespace Net {
		class NetWorker {
		public:
			static NetWorker* getInstance() {
				if (instance == NULL)
					instance = new NetWorker();
				return instance;
			}
			void start(Server *ser);
			void run(void);
		private:
			NetWorker();
			virtual ~NetWorker();

			static NetWorker *instance;
			Server *ser;
			Base::StreamQueue msg_list;
		};
#define NETWORKER NetWorker::getInstance()
	}
}
