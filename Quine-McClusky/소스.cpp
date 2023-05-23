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
	void init();
};

// 초기 배열 input 진행
void Qm::inputSettingArr() {
	int num = 0;
	for (int i = 0; i < 16; i++) {
		cout << i  << "번째 입력 : ";
		cin >> num;
		inputArr[i] = num;
		if (num == 1) {  // num이 1이라면 벡터에 i를 추가해서 어느 수가 선택되었는지 알 수 있게 한다.
			v.push_back(i);
		}
	}
}

// 벡터에 있는 10진수 값들을 하나씩 뽑아서 2진수로 변환하는 과정을 거쳐 2차원 벡터에 넣어준다.
void Qm::makeDoubleVector() {
	for (int i = 0; i < v.size(); i++) {
		vector<int> binary;
		int n = v[i];
		for (int i = 0; i < 4; i++){
			binary.insert(binary.begin(), n % 2);
			n /= 2;
		}
		for (int j = 0; j < binary.size(); j++) {
			cout << binary[j] << " ";
		}
		cout << "\n";
		v2.push_back(binary);
	}

	// v2 print
	cout << "\n";
	for (int i = 0; i < v2.size(); i++) {
		for (int j = 0; j < v2[i].size(); j++) {
			cout << v2[i][j] << " ";
		}
		cout << endl;
	}
}

void Qm::init() {
	inputSettingArr();
	makeDoubleVector();
}

int main() {
	Qm nm;
	nm.init();
}