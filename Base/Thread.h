#pragma once
#include "def/os.h"
#ifndef _WIN32
	#include <pthread.h>
#else
	#include <process.h> 
#endif

namespace Xler {
	namespace Base {
		class Thread
		{
		public:
			Thread(void);
			virtual ~Thread(void);
			virtual void run() = 0;		//业务接口
			int	start();				//启动线程
			inline int	get_thread_id()	{ return thr_id_; } //获取线程ID
		private:
			xl_pthread_t	thr_id_;        //线程ID
			
		};
	}
}
