#include "DBhandle.h"
#include "Utils.h"
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string>
#include <iostream>
#include <fstream>

using Record = std::vector<std::string>;
using Records = std::vector<Record>;

static std::string float2str(float num) {
	std::ostringstream ss;
	ss << num;
	return ss.str();
}
static std::string int2str(int num) {
	std::ostringstream ss;
	ss << num;
	return ss.str();
}

static int CB_doNothing(void *NotUsed, int ncolumns, char **rowfields, char **columnnames) {
	return 0;
}

static int CB_showFetch(void *NotUsed, int ncolumns, char **rowfields, char **columnnames) {
	int i;
	printf("ROW--> [ ");
	for (i = 0; i<ncolumns; i++) {
		printf("%s",rowfields[i] ? rowfields[i] : "NULL");
		printf(";");
	}
	printf(" ]");
	printf("\n");
	return 0;
}


static int CB_getData(void* data, int ncolumns, char **rowfields, char **columnnames) {
	Utils U;
	Records* records = static_cast<Records*>(data);

	try {
		records->emplace_back(rowfields, rowfields + ncolumns);
	}catch (...) {
		// Abort select on failure, don't let exception propogate thru sqlite3 call-stack
		return 1;
	}
	return 0;
}

int DBhandle::saveAngles(std::string data) {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	std::string sqls;
	/* Open database */
	rc = sqlite3_open(DBhandle::dbname.c_str(), &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		//nothing
	}

	sqls = "INSERT INTO angles (N_SAMPLE,MOVE,NECK_TORSO,SHOULDER_ARM_R,SHOULDER_ARM_L,"  \
		"ARM_ARM_R,ARM_ARM_L, HIP_LEG_R, HIP_LEG_L,LEG_LEG_R,LEG_LEG_L,ARM_HIPLINE_R,"  \
		"ARM_HIPLINE_L,THIGH_HIPLINE_R,THIGH_HIPLINE_L) "  \
		"VALUES (NULL, " + data + " ); ";

	rc = sqlite3_exec(db, sqls.c_str(), CB_doNothing, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		// fprintf(stderr, "Angles saved successfully\n");
	}
	sqlite3_close(db);
	return 0;
}


int DBhandle::showAllInTable(std::string tname) {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char* data = "Callback(showFetch) function called";
	std::string sqls;
	/* Open database */
	rc = sqlite3_open(DBhandle::dbname.c_str(), &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}

	/* Create SQL statement */
	sqls = "SELECT * from " +tname;

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sqls.c_str(), CB_showFetch, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Content showed successfully\n");
	}
	sqlite3_close(db);
	return 0;
}

int DBhandle::deleteTableContent(std::string tname) {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char* data = "Callback(showFetch) function called";
	std::string sqls;
	/* Open database */
	rc = sqlite3_open(DBhandle::dbname.c_str(), &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		//fprintf(stderr, "Opened database successfully\n");
	}

	/* Create SQL statement */
	sqls = "DELETE FROM " + tname;

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sqls.c_str(), CB_doNothing, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		//fprintf(stdout, "Content from %s deleted successfully\n", tname.c_str());
	}
	sqlite3_close(db);
	return 0;
}


int DBhandle::setDB(std::string name) {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	std::string dbname;
	dbname = name + ".db";
	/* Open database */
	rc = sqlite3_open(dbname.c_str(), &db);
	

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		//fprintf(stdout, "Opened database successfully\n");
	}
	DBhandle::set_dbname(dbname);
	sqlite3_close(db);
	return 0;
}

int DBhandle::execute(std::string sqls) {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	/* Open database */
	rc = sqlite3_open(DBhandle::dbname.c_str(), &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		//fprintf(stdout, "Opened database successfully\n");
	}

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sqls.c_str(), CB_doNothing, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Sentence executed successfully\n");
	}
	sqlite3_close(db);
	return 0;
}

int DBhandle::saveJoints(std::string data) {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	std::string sqls;
	/* Open database */
	rc = sqlite3_open(DBhandle::dbname.c_str(), &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		//fprintf(stdout, "Opened database successfully\n");
	}

	sqls = "CREATE TABLE IF NOT EXISTS joints" \
		"(N_SAMPLE INTEGER PRIMARY KEY,"\
			"MOVE TEXT NOT NULL,"\
			"HIP_CENTER TEXT NOT NULL,"\
			"SPINE TEXT NOT NULL,"\
			"SHOULDER_CENTER TEXT NOT NULL,"\
			"HEAD TEXT NOT NULL,"\
			"SHOULDER_LEFT TEXT NOT NULL,"\
			"ELBOW_LEFT TEXT NOT NULL,"\
			"WRIST_LEFT TEXT NOT NULL,"\
			"HAND_LEFT TEXT NOT NULL,"\
			"SHOULDER_RIGHT TEXT NOT NULL,"\
			"ELBOW_RIGHT TEXT NOT NULL,"\
			"WRIST_RIGHT TEXT NOT NULL,"\
			"HAND_RIGHT TEXT NOT NULL,"\
			"HIP_LEFT TEXT NOT NULL,"\
			"KNEE_LEFT TEXT NOT NULL,"\
			"ANKLE_LEFT TEXT NOT NULL,"\
			"FOOT_LEFT TEXT NOT NULL,"\
			"HIP_RIGHT TEXT NOT NULL,"\
			"KNEE_RIGHT TEXT NOT NULL,"\
			"ANKLE_RIGHT TEXT NOT NULL,"\
			"FOOT_RIGHT TEXT NOT NULL); ";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sqls.c_str(), CB_doNothing, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else {
		//fprintf(stdout, " Table Joints created/accessed\n");
	}

	sqls = "INSERT INTO joints (N_SAMPLE,MOVE,HIP_CENTER,SPINE,SHOULDER_CENTER," \
		"HEAD,SHOULDER_LEFT,ELBOW_LEFT,WRIST_LEFT,HAND_LEFT,SHOULDER_RIGHT,"\
		"ELBOW_RIGHT,WRIST_RIGHT,HAND_RIGHT,HIP_LEFT,KNEE_LEFT,ANKLE_LEFT,"\
		"FOOT_LEFT,HIP_RIGHT,KNEE_RIGHT,ANKLE_RIGHT,FOOT_RIGHT) "\
		"VALUES (NULL," + data + "); ";

	rc = sqlite3_exec(db, sqls.c_str(), CB_doNothing, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else {
		fprintf(stdout, "Joints saved successfully\n");
	}
	sqlite3_close(db);
	return 0;
}

int DBhandle::convertJoints2Angles() {
	Records recs;
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char* data = "Callback(CB_getData) function called";
	std::string sqls;
	rc = sqlite3_open(DBhandle::dbname.c_str(), &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		//fprintf(stderr, "Opened database successfully\n");
	}

	sqls = "CREATE TABLE IF NOT EXISTS angles"\
		"(N_SAMPLE INTEGER PRIMARY KEY,"\
		"MOVE TEXT NOT NULL,"\
		"NECK_TORSO REAL NOT NULL,"\
		"SHOULDER_ARM_R REAL NOT NULL,"\
		"SHOULDER_ARM_L REAL NOT NULL,"\
		"ARM_ARM_R REAL NOT NULL,"\
		"ARM_ARM_L REAL NOT NULL,"\
		"HIP_LEG_R REAL NOT NULL,"\
		"HIP_LEG_L REAL NOT NULL,"\
		"LEG_LEG_R REAL NOT NULL,"\
		"LEG_LEG_L REAL NOT NULL,"\
		"ARM_HIPLINE_R REAL NOT NULL,"\
		"ARM_HIPLINE_L REAL NOT NULL,"\
		"THIGH_HIPLINE_R REAL NOT NULL,"\
		"THIGH_HIPLINE_L REAL NOT NULL); ";

	rc = sqlite3_exec(db, sqls.c_str(), CB_doNothing, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		//fprintf(stdout, "Table angles created/accessed\n");
	}

	DBhandle::deleteTableContent("angles");

	sqls = "SELECT * FROM joints";

	rc = sqlite3_exec(db, sqls.c_str(), CB_getData, &recs, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		// nothing
	}

	sqls = "";
	for (int i = 0; i < recs.size(); ++i) {
		Utils U;
		sqls = "";
		Utils::Joint J1, J2, J3;
		sqls = sqls + "'" + recs[i][1] + "'";
		// Neck - Head Angle :
		J3 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_SPINE + 2]);
		J2 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_SHOULDER_CENTER + 2]);
		J1 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HEAD + 2]);
		sqls += "," + float2str(U.calculateAngleProjection(J1, J2, J3));
		// Neck - Elbow - Right Angle :
		J1 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_SHOULDER_CENTER + 2]);
		J2 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_SHOULDER_RIGHT + 2]);
		J3 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_ELBOW_RIGHT + 2]);
		sqls += "," + float2str(U.calculateAngleProjection(J1, J2, J3));
		//  Neck-Elbow-Left Angle:
		J1 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_SHOULDER_CENTER + 2]);
		J2 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_SHOULDER_LEFT + 2]);
		J3 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_ELBOW_LEFT + 2]);
		sqls += "," + float2str(U.calculateAngleProjection(J1, J2, J3));
		// Elbow-Hand-Right Angle:
		J1 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_SHOULDER_RIGHT + 2]);
		J2 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_ELBOW_RIGHT + 2]);
		J3 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HAND_RIGHT + 2]);
		sqls += "," + float2str(U.calculateAngleProjection(J1, J2, J3));
		// Elbow-Hand-Left Angle:
		J1 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_SHOULDER_LEFT + 2]);
		J2 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_ELBOW_LEFT + 2]);
		J3 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HAND_LEFT + 2]);
		sqls += "," + float2str(U.calculateAngleProjection(J1, J2, J3));
		// Hip-Leg-Right Angle:
		J1 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HIP_CENTER + 2]);
		J2 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HIP_RIGHT + 2]);
		J3 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_KNEE_RIGHT + 2]);
		sqls += "," + float2str(U.calculateAngleProjection(J1, J2, J3));
		// Hip-Leg-Left Angle:
		J1 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HIP_CENTER + 2]);
		J2 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HIP_LEFT + 2]);
		J3 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_KNEE_LEFT + 2]);
		sqls += "," + float2str(U.calculateAngleProjection(J1, J2, J3));
		// Leg-Leg-Right Angle:
		J1 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HIP_RIGHT + 2]);
		J2 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_KNEE_RIGHT + 2]);
		J3 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_FOOT_RIGHT + 2]);
		sqls += "," + float2str(U.calculateAngleProjection(J1, J2, J3));
		// Leg-Leg-Left Angle:
		J1 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HIP_LEFT + 2]);
		J2 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_KNEE_LEFT + 2]);
		J3 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_FOOT_LEFT + 2]);
		sqls += "," + float2str(U.calculateAngleProjection(J1, J2, J3));
		// Arm-Hip-Right Angle:
		J1 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_ELBOW_RIGHT + 2]);
		J2 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_SHOULDER_RIGHT + 2]);
		J3 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HIP_RIGHT + 2]);
		sqls += "," + float2str(U.calculateAngleProjection(J1, J2, J3));
		// Arm-Hip-Left Angle:
		J1 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_ELBOW_LEFT + 2]);
		J2 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_SHOULDER_LEFT + 2]);
		J3 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HIP_LEFT + 2]);
		sqls += "," + float2str(U.calculateAngleProjection(J1, J2, J3));
		// Thigh-Hipline-Right
		J1 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HIP_LEFT + 2]);
		J2 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HIP_RIGHT + 2]);
		J3 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_KNEE_RIGHT + 2]);
		sqls += "," + float2str(U.calculateAngleProjection(J1, J2, J3));
		// Thigh-Hipline-Left
		J1 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HIP_RIGHT + 2]);
		J2 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_HIP_LEFT + 2]);
		J3 = U.str2joint(recs[i][U.JD.NUI_SKELETON_POSITION_KNEE_LEFT + 2]);
		sqls += "," + float2str(U.calculateAngleProjection(J1, J2, J3));

		DBhandle::saveAngles(sqls);
	}
	//fprintf(stderr, "Angles saved succesfully\n");
	sqlite3_close(db);
	return 0;
}

int DBhandle::saveDataForTraining() {
	Records recs;
	sqlite3 *db;
	Utils U;
	remove("data_for_training");
	std::ofstream file;
	file.open("data_for_training");
	char *zErrMsg = 0;
	int rc;
	const char* data = "Callback(CB_getData) function called";
	std::string sqls;
	rc = sqlite3_open(DBhandle::dbname.c_str(), &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		//fprintf(stderr, "Opened database successfully\n");
	}

	sqls = "SELECT * FROM angles";
	rc = sqlite3_exec(db, sqls.c_str(), CB_getData, &recs, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		// nothing
	}
	U.classtointeger.insert(std::pair<std::string, std::string>("unknown", "0"));
	for (int i = 0; i < recs.size(); ++i) {
		// recs[i][0] id
		// recs[i][1] move
		// recs[i][2,:] angulos
		if (U.classtointeger.count(recs[i][1]) == 0) {
			U.classtointeger.insert(std::pair<std::string, std::string>(recs[i][1], int2str(U.classtointeger.size())));
		}
		file << U.classtointeger[recs[i][1]] + " 1:" + recs[i][2] + " 2:" + recs[i][3] + " 3:" + recs[i][4]
			+ " 4:" + recs[i][5] + " 5:" + recs[i][6] + " 6:" + recs[i][7] + " 7:" + recs[i][8]
			+ " 8:" + recs[i][9] + " 9:" + recs[i][10] + " 10:" + recs[i][11] + " 11:" + recs[i][12]
			+ " 12:" + recs[i][13] + " 13:" + recs[i][14]+"\n";
	}

	file.close();
	sqlite3_close(db);
	return 0;
}