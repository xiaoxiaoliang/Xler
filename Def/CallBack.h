#pragma once
#include <stdint.h>
#include <memory.h>
#include <functional>

namespace Xler {
	class Server;
	namespace Def {
#define ON_START(func, _Object) std::bind(&func,_Object, std::placeholders::_1)
		typedef	std::function<void(const Server* ser)> CbStart;
		//typedef void (*CbStart)(const Server* ser);
		struct ServerCallBacks {
			CbStart cb_start;
			struct ServerCallBacksReg {
				ServerCallBacksReg(void) {
					memset(this, 0, sizeof(*this));
				}
				uint32_t reg_start:1;
			} reg;
		};
	}
}
