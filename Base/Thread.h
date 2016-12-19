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
				THREAD_STATUS_INIT = 0,//���̳߳�ʼ��
				THREAD_STATUS_RUNNING = 1, //������
				THREAD_STATUS_EXIT = -1, //�˳���
			};
			public:
				Thread(void);
				virtual ~Thread(void);
				virtual void run(void) = 0;		//ҵ��ӿ�
				bool start(void);				//�����߳�
				inline xl_pid_t	get_thread_id()	{ return tid; } //��ȡ�߳�ID
			private:
				static THREAD_CALLBACK_DEF(thread_callback_func);//��ʼ�̵߳Ļص�

				xl_pid_t tid; //�߳�ID
				ThreadStatus status; //�߳�״̬
		};
	}
}
