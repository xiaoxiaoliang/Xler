#pragma once
#include <memory.h>
namespace Xler {
	class Server;
	namespace Def {
		typedef void (*CbStart)(const Server* ser);
		struct ServerCallBacks {
			ServerCallBacks(void) {
				memset(this, 0, sizeof(*this));
			}
			CbStart cb_start;
		};
	}
}