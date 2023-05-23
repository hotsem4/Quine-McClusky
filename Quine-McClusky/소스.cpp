#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Qm {
public:
	int inputArr[16] = { 0, };  // 초기 input값 입력 배열
	vector<int> v;
	vector<vector <int>> v2;
	void inputSettingArr();
	void makeDoubleVector();
	void printPage1();
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
	cout << "--------------------------------------------------" << endl;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < 10) {
			cout << " " << v[i] << " " << " |  " << v2[i][0] << "  " << v2[i][1] << "  " << v2[i][2] << "  " << v2[i][3] << endl;
		}
		else {
			cout << " " << v[i] << " " << "|  " << v2[i][0] << "  " << v2[i][1] << "  " << v2[i][2] << "  " << v2[i][3] << endl;
		}
	}
}

// 1의 원소의 갯수 별로 grouping 작업을 실시해야 한다.


void Qm::init() {
	inputSettingArr();
	makeDoubleVector();
	printPage1();
}

int main() {
	Qm nm;
	nm.init();
	return 0;
}

/*
v[i]는 v2[i][]의 10진수
v2[i][]는 v[i]의 2진수
*/