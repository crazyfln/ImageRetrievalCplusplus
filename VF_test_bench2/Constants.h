#pragma once

// GET RID OF THIS - READ IT FROM DB ON LOAD
#define DB_SIZE 100
#define MAX_VF_NUMBER 100000
//#define DB_SIZE 10038
#define LARGE_IMG_FOLDER "C:\\ucr_db\\ucr_img_db\\"
#define SMALL_IMG_FOLDER "C:\\ucr_db\\ucr_img_db\\low\\"

#define NUM_D_RESULTS 12 //CHANGE TO 20 FOR PERFORMANCE TESTING
#define NUM_Q_POSSIBILITIES 6

//used as the maximum possible PF distance between two images
#define MAX_PF_DISTANCE 9999

#define BFLY_DB "ucr_img_db"
#define BFLY_DB_SERVER "localhost"
#define BFLY_DB_USER "root"
#define BFLY_DB_PASS "root"

#define BFLY_OBJECTS_TABLE "ucr_objects"//
#define BFLY_FEATURES_TABLE "ucr_features"
#define VF_COUNTER_TABLE "vf_counter"

#define NUM_PFS 22
#define NUM_VFS_PER_IMAGE 250
#define DB_INDEX_OF_FIRST_PF 1
#define DB_INDEX_OF_FIRST_VF 25

#define MINIMUM_ETA 0.0001

//Query Vector Modification (QVM) constants
//values used in the paper: alpha: 0.1, beta: 0.8, gamma: 0.1
#define ALPHA 0.1
#define BETA 0.8
#define GAMMA 0.1
