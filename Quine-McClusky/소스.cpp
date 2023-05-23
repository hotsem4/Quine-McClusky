#include <iostream>
#include <string.h>

using namespace std;

class Qm {
public:
	int inputArr[16] = { 0, };  // 초기 input값 입력 배열

	void inputSettingArr();
	void init();
};
void Qm::inputSettingArr() {
	int num = 0;
	for (int i = 0; i < 16; i++) {
		cout << i + 1 << "번째 입력 : ";
		cin >> num;
		inputArr[i] = num;
	}
}
void Qm::init() {
	inputSettingArr();
	for (int i = 0; i < 16; i++) {
		cout << inputArr[i] << " ";
	}
}

int main() {
	Qm nm;
	nm.init();
}