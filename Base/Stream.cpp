#include <stdlib.h>
#include "Stream.h"
using namespace Xler::Base;
Stream::Stream(size_t size) {
	reset();
	this->max_size = size;
	this->buffer = (unsigned char *)malloc(size);
}

Stream::~Stream(void) {
	free(this->buffer);
}

void Stream::reset(void) {
	this->fd = 0;
	this->read_idx = 0;
	this->write_idx = 0;
}
