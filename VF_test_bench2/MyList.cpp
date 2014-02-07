#include "StdAfx.h"
#include "MyList.h"

MyList::MyList(void)
{
	max_length = NUM_D_RESULTS;
	
	pids = gcnew List<int>;
	distances = gcnew List<double>;

	for( int i = 0; i < NUM_D_RESULTS; i++ ) {
		pids->Add(-1);
		distances->Add(-1);
	}

	longest_distance = length = 0;
}

MyList::MyList( int max ) {
	MyList();
	max_length = max;
}


void MyList::reset() {
	longest_distance = length = 0;
	for( int i = 0; i < max_length; i++ ) {
		pids[i] = -1;
		distances[i] = -1;
	}
}

double MyList::get_longest_distance() {
	return longest_distance;
}

bool MyList::conditional_insert( int pid, double distance ) {
	
	if( (distance >= longest_distance && length == max_length) || distance < 0 )
		return false;

	int i = 0;

	while( distance > distances[i] && distances[i] >= 0 && i < max_length ) {
		i++;
	}

	if( length == max_length ) {
		pids->RemoveAt( max_length - 1);
		distances->RemoveAt( max_length - 1);
	}
	else {
		length++;
	}

	pids->Insert( i, pid );
	distances->Insert( i, distance );

	longest_distance = distances[length - 1];

	return true;
}

array<int>^ MyList::get_pids() {
	
	array<int> ^ r = gcnew array<int>(length);

	for( int i = 0; i < length; i++ ) {
		r[i] = pids[i];
	}

	return r;
}


int MyList::get_length() {
	return length;
}