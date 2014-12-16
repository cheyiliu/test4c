#include "Ref.h"

Ref::Ref() :
		_referenceCount(1) // when the Ref is created, the reference count of it is 1
{
}

Ref::~Ref() {
}

void Ref::retain() {
	++_referenceCount;
}

void Ref::release() {
	--_referenceCount;

	if (_referenceCount == 0) {
		delete this;
	}
}

unsigned int Ref::getReferenceCount() const {
	return _referenceCount;
}

