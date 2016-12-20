#include "Thread.h"

using namespace Xler::Base;
Thread::Thread(void)
{
	tid = 0;
	status = THREAD_STATUS_INIT;
}


Thread::~Thread(void)
{
}

bool Thread::start(void)
{
#ifndef _WIN32
	bool res = pthread_create(&tid, NULL, thread_callback_func, this) == 0;
#else
	bool res = CreateThread(NULL, 0, thread_callback_func, this, 0, &tid) != NULL;
#endif
	if(res) status = THREAD_STATUS_RUNNING;
	return res;
}

THREAD_CALLBACK_DEF(Thread::thread_callback_func) { //线程开始函数
	Thread *thr =(Thread*)args;
	thr->run();
	return 0;
}
