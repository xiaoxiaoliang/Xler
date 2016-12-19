#pragma once
#ifndef _WIN32
#include <pthread.h>
typedef pthread_t xl_pid_t;
#else
#include <windows.h>
typedef DWORD xl_pid_t;
#endif

namespace Xler {
	namespace Base {
		class Thread {
#ifndef _WIN32
#define THREAD_CALLBACK_DEF(name) void* name(void * args)
#else
#define THREAD_CALLBACK_DEF(name) DWORD CALLBACK name(void * args)
#endif
			enum ThreadStatus {
				THREAD_STATUS_INIT = 0,//新线程初始化
				THREAD_STATUS_RUNNING = 1, //运行中
				THREAD_STATUS_EXIT = -1, //退出中
			};
			public:
				Thread(void);
				virtual ~Thread(void);
				virtual void run(void) = 0;		//业务接口
				bool start(void);				//启动线程
				inline xl_pid_t	get_thread_id()	{ return tid; } //获取线程ID
			private:
				static THREAD_CALLBACK_DEF(thread_callback_func);//开始线程的回调

				xl_pid_t tid; //线程ID
				ThreadStatus status; //线程状态
		};
	}
}
