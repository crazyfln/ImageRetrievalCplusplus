#pragma once

#include <mysql++.h>

public ref class BflyFeatures
{
public:
	BflyFeatures(void);
	virtual ~BflyFeatures(void);

	int pid;
	array<double>^ PFs;
	array<int>^ VF_cs;
	array<double>^ VF_es;
	
	bool has_VFs();

	void parse_all_features();
	void parse_PFs();
	void parse_VFs();
};
