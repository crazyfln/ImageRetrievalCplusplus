#pragma once

#include "VF.h"

using namespace System::Collections;

ref class VFComparer: public System::Collections::IComparer
{
public:
	
	virtual int Compare( System::Object^ l, System::Object^ r ) {
		return ((gcnew CaseInsensitiveComparer)->Compare( l, r ));
	}
	
	virtual int Compare( VF^ l, VF^ r ) {
		if( l->c < r->c )
			return -1;
		else if( l->c == r->c )
			return 0;
		else
			return 1;
	}
};