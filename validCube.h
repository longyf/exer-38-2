#ifndef VALID_CUBE_H
#define VALID_CUBE_H
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;
bool validPermutation(const vector<int> &v1) {
	if (v1[0] + v1[1] + v1[2] + v1[3] == v1[4] + v1[5] + v1[6] + v1[7] &&
		v1[0] + v1[2] + v1[4] + v1[6] == v1[1] + v1[3] + v1[5] + v1[7] &&
		v1[0] + v1[1] + v1[4] + v1[5] == v1[2] + v1[3] + v1[6] + v1[7])
		return true;
	else 
		return false;
}

void print(const vector<int> &v1) {
	for (auto iter = v1.begin(); iter != v1.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

bool validCube(vector<int> &v1, int index) {
	if (v1.size() != 8) 
		throw invalid_argument("Pay attention to the input.");

	if (index == v1.size()) {
		print(v1);
		if (validPermutation(v1)) return true;
	}
	auto i = index;
	while (i != v1.size()) {
		swap(v1[i], v1[index]);
		validCube(v1, index + 1);
		swap(v1[i], v1[index]);
		i++;
	}
	return false;
}
#endif
