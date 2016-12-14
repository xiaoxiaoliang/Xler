#include <iostream>
#include <queue>
#include "StreamQueue.h"
#include "Stream.h"

using namespace Xler::Base;
StreamQueue::StreamQueue(void) {

}


StreamQueue::~StreamQueue(void) {

}

Stream *StreamQueue::pop() {
	if (queue.empty()) return 0;
	Stream *st = queue.front();
	queue.pop();
	return st;
}
void StreamQueue::push(Stream *stream) {
	queue.push(stream);
}