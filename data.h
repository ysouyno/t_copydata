#pragma once

#include <Windows.h>
#include <deque>

struct PARAM {
	int len;
	int data[0];
};

class Data {
public:
	static Data* get_instance() {
		if (!g_data) {
			g_data = new Data();
		}
		return g_data;
	}

public:
	std::deque<int> d;
	static Data* g_data;
};
