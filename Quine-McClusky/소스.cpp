#include <iostream>
#include <string.h>

using namespace std;

class Qm {
public:
	int inputArr[16] = { 0, };  // �ʱ� input�� �Է� �迭

	void inputSettingArr();
	void init();
};
void Qm::inputSettingArr() {
	int num = 0;
	for (int i = 0; i < 16; i++) {
		cout << i + 1 << "��° �Է� : ";
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