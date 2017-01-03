#include <iostream>
#include "StreamQueue.h"
#include "Stream.h"

using namespace Xler::Base;
StreamQueue::StreamQueue(void) {
	sem_init(&m_sem, 0, 0);
	pthread_mutex_init(&m_mutex, NULL);
}


StreamQueue::~StreamQueue(void) {
	sem_destroy(&m_sem);
	pthread_mutex_destroy(&m_mutex);
}

Stream *StreamQueue::pop() {
	if (queue.empty()) sem_wait(&m_sem);
	pthread_mutex_lock(&m_mutex);
	Stream *st = queue.front();
	queue.pop();
	pthread_mutex_unlock(&m_mutex);
	return st;
}
void StreamQueue::push(Stream *stream) {
	queue.push(stream);
	sem_post(&m_sem);
}
