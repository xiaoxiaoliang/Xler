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
	return pthread_create(&tid, NULL, thread_callback_func, this) == 0;
#else
	return CreateThread(NULL, 0, thread_callback_func, this, 0, &tid) != NULL;
#endif
}

THREAD_CALLBACK_DEF(Thread::thread_callback_func) {
	return 0;
}