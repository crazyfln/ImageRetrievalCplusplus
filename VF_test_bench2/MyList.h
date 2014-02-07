#pragma once

#include "Constants.h"

using namespace System::Collections::Generic;

ref class MyList
{
public:
	MyList(void);
	MyList(int n);

	double get_longest_distance();
	int get_length();

	//inserts if the element is relevant based on the distance
	//return whether the element was inserted or not
	bool conditional_insert( int pid, double distance );
	void reset();

	array<int>^ get_pids();

private:
	List<int> ^ pids;
	List<double> ^ distances;

	double longest_distance;
	int length;
	int max_length;
};
