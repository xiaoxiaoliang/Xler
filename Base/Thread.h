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
			virtual void run() = 0;		//ҵ��ӿ�
			int	start();				//�����߳�
			inline int	get_thread_id()	{ return thr_id_; } //��ȡ�߳�ID
		private:
			xl_pthread_t	thr_id_;        //�߳�ID
			
		};
	}
}
