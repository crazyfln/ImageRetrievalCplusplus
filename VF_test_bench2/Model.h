#pragma once

#include <mysql++.h>
#include "MyList.h"
#include "D_small_display_object.h"
#include "VF.h"

using namespace System::Collections;

public ref class Model
{
public:
	Model(void);

	mysqlpp::StoreQueryResult get_knn( BflyObject ^ );
	void do_qvm( BflyObject ^ q, array<D_small_display_object ^> ^ );
	void update_q_mu_and_precision( BflyObject ^ q, array<D_small_display_object ^> ^ );
	void update_D_VFs( BflyObject ^ q, array<D_small_display_object ^> ^ );
	void update_q_VFs( BflyObject ^ q, array<D_small_display_object ^> ^ );
	int increment_VF_counter();
	int return_vf();

private:
	array<BflyFeatures^>^ bfly_features;
	array<int>^ pid_to_array_index; //are you using this??
	MyList ^ knn_list;
	int vf_counter;
	bool new_vf;/////////////////////////////

	void load_vf_counter();
	
	mysqlpp::StoreQueryResult PF_only_knn( BflyObject ^ );
	mysqlpp::StoreQueryResult PF_and_VF_knn( BflyObject ^ );

	array<VF^>^ normalize_VF_vector( ArrayList ^ );
	void store_VF_changes_in_DB( List<D_small_display_object^> ^ );
	void store_Q_VF_changes_in_DB( BflyObject ^ );

	double get_PF_distance( BflyObject^ q, int index );
	double get_VF_cosine_theta( BflyObject^ q, int index );

	//loads the all the butterflies' features from the DB into bfly_features
	void load_bfly_features();

	//two different qvm approaches
	//QVM described in Long-Term Cross-Session Relevance Feedback Using Virtual Feedback
	//(Yin et al.)
	void standard_qvm( BflyObject ^ q, array<D_small_display_object ^> ^ );

	//my idea (Krystof Litomisky)
	void krystof_qvm( BflyObject ^ q, array<D_small_display_object ^> ^ );
};
