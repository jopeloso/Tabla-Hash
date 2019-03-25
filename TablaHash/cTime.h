#ifndef CTIME_H
#define CTIME_H

#include <time.h>

using namespace std;
class cTime{
	clock_t t1, t2;


public:
	cTime()
	{
		t1 = clock();
		t2 = clock();
	}

	~cTime(){};

	void start()
	{
		t1 = clock();
	}

	void stop()
	{
		t2 = clock();
	}

	unsigned  long long getMiliseconds()
	{
		return double(t2 - t1) * 1000 / CLK_TCK;
	}

	unsigned long long getMicroseconds()
	{
		return double(t2 - t1) * 1000000 / CLK_TCK;
	}

	unsigned  long long getSeconds()
	{
		return double(t2 - t1) / CLK_TCK;
	}

};
#endif
