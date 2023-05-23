#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Qm {
public:
	int inputArr[16] = { 0, };  // 초기 input값 입력 배열
	vector<int> v;

	void inputSettingArr();
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

void Qm::init() {
	inputSettingArr();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

int main() {
	Qm nm;
	nm.init();
}