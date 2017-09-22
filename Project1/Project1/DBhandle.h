#include <string>

#ifndef DBhandle_H
#define DBhandle_H

class DBhandle {
	private:
		std::string dbname = "database.db";
		void set_dbname(std::string name) { dbname = name;}
	public:
		int setDB(std::string name);
		int execute(std::string sqls);
		int showAllInTable(std::string tname);
		int deleteTableContent(std::string tname);
		int saveJoints(const char * data); //data is a string with the form "'move','joint0','joint1',...,'joint19'"
		int saveAngles(std::string data); //data is a string with the form "'move',angle1,angle2,...angle13"
		int convertJoints2Angles();
};
#endif