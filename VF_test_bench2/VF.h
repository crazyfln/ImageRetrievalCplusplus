//Virtual Feauture class
//used in the transformations of virtual feature vectors
//(defined so that the microsoft library's sorting algorithm can be used)

#pragma once

using namespace System;
using namespace System::Collections;

public ref class VF : public IComparable {
public:
	VF() { c = 0; e = 0; }
	VF( int cc, double ee ) {
		c = cc;
		e = ee;
	}
	VF( const VF^ two ) {
		c = two->c;
		e = two->e;
	}

	virtual Int32 CompareTo( Object^ obj ) {
      if ( obj->GetType() == VF::typeid ) {
         VF^ r = dynamic_cast<VF^>(obj);

         return c.CompareTo( r->c );
      }
      throw gcnew ArgumentException(  "Object being compared is not a VF." );
   }

	bool operator<(const VF^ two) {
		return this->c < two->c;
	}

	int c;
	double e;

};