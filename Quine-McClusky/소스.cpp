#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class Qm {
public:
	int inputArr[16] = { 0, };  // 초기 input값 입력 배열
	vector<int> v;
	vector<vector <int>> v2;
	vector<vector <int>> v3;   // 10진수와 1의 갯수를 포함한 배열
	void inputSettingArr();
	void makeDoubleVector();
	void printPage1();
	void copyVector();
	void printV3();
	void init();
};

void Qm::inputSettingArr() {      // 초기 배열 input 진행
	int num = 0;
	for (int i = 0; i < 16; i++) {
		cout << i  << "번째 입력 : ";
		cin >> num;
		inputArr[i] = num;
		if (num == 1) {     // num이 1이라면 벡터에 i를 추가해서 어느 수가 선택되었는지 알 수 있게 한다.
			v.push_back(i);
		}
	}
}

void Qm::makeDoubleVector() {       // 벡터에 있는 10진수 값들을 하나씩 뽑아서 2진수로 변환하는 과정을 거쳐 2차원 벡터에 넣어준다.
	for (int i = 0; i < v.size(); i++) {
		vector<int> binary;
		int n = v[i];
		for (int i = 0; i < 4; i++){  // 10진수 --> 2진수
			binary.insert(binary.begin(), n % 2);
			n /= 2;
		}
		v2.push_back(binary);
	}
}


void Qm::printPage1() {    // 2차원 벡터가 완성되었으니 1페이지 출력부 만들기
	cout << "    " << "   A  " << "B" << "  C" << "  D  " << endl;
	cout << "-------------------" << endl;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < 10) {
			cout << " " << v[i] << " " << " |  " << v2[i][0] << "  " << v2[i][1] << "  " << v2[i][2] << "  " << v2[i][3] << endl;
		}
		else {
			cout << " " << v[i] << " " << "|  " << v2[i][0] << "  " << v2[i][1] << "  " << v2[i][2] << "  " << v2[i][3] << endl;
		}
	}
}
int countOnes(const vector<int>& v) { return count(v.begin(), v.end(), 1); }  // 배열 안에 1이 몇 개 있는지 카운팅 함수  --> 매개변수 단일 벡서 넣으면 1의 갯수로 반환

// 우선 v3에 v2를 복사한다.
void Qm::copyVector() {
	v3 = v2;
	for (int i = 0; i < v.size(); i++) {
		v3[i].insert(v3[i].begin(), v[i]);
	}
	int k = 0;
	for (const auto & row : v2) {
		int ones = countOnes(row);
		v3[k].insert(v3[k].begin() + 1, ones);
		k++;
		
	}
}

void Qm::printV3() {
	for (int i = 0; i < v3.size(); i++) {
		for (int j = 0; j < v3[i].size(); j++) {
			cout << v3[i][j] << " ";
		}
		cout << endl;
	}
}

// 1의 원소의 갯수 별로 grouping 작업을 실시해야 한다.

void Qm::init() {
	inputSettingArr();
	makeDoubleVector();	
	printPage1();
	copyVector();
	printV3();
}

int main() {
	Qm nm;
	nm.init();
	return 0;
}

/*
v[i]는 v2[i][]의 10진수
v2[i][]는 v[i]의 2진수
v3는 0번째는 10진수가 있고 1번째는 2진수의 1의 갯수이다.
*/