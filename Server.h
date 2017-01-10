#pragma once
#include "Def/CallBack.h"
#include "Def/Config.h"
#include "Base/Stream.h"
namespace Xler {
	using namespace Def;
	enum ServerStatus {
		INITING = 0,
		RUNNING = 1,
		CLOSEING = 2,
	};
	class Server {
	public:
		Server(void);
		virtual ~Server(void);
		void set(const ServerConf *conf);
		int add_listen(const Def::NetProType type,const char* ip,const uint16_t port);

		void on_start(CbStart cb);
		void on_receive(void);

		void start(void);
		void receive(Base::Stream *data);

		const ServerConf* get_conf(void);
	private:
		ServerConf conf;
		ServerCallBacks call_backs;
		ServerStatus status;
	};
}
