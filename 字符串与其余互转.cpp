#include <string>
#include <sstream>
#include <iostream>

using namespace std;

// 把一个字符串转整数

int strToint(char *string){
	int number = 0;
	while(*string != 0){
		number = number * 10 + *string - '0';
		string++;
	}
	return number;
}

// 字符转其他
template <class T>
T string_To_T(const string &s){
	T t;
	istringstream ist(s);
	ist >> t;
	return t;
}

// 其他转字符串
template<class T>
T T_to_string(const T& t){
	ostringstream ost;
	ost << t;
	return ost.str();
}

