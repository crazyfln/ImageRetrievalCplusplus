#pragma once
#include "BflyFeatures.h"

public ref class BflyObject :
public BflyFeatures
{
	public:

		BflyObject(void);
		virtual ~BflyObject(void);

		System::Text::StringBuilder photo_top;
		System::Text::StringBuilder photo_bottom;
		int group_index;
		float mu;
		float precision_pre;
		float average_pre;
		int local_vf_counter;

		System::String^ print_info();
		
		void parse_metadata( mysqlpp::Row r );

	private:
		void parse_photos( System::String ^ top, System::String ^ bottom );

};
