#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Qm {
public:
	int inputArr[16] = { 0, };  // �ʱ� input�� �Է� �迭
	vector<int> v;
	vector<vector <int>> v2;
	void inputSettingArr();
	void makeDoubleVector();
	void init();
};

// �ʱ� �迭 input ����
void Qm::inputSettingArr() {
	int num = 0;
	for (int i = 0; i < 16; i++) {
		cout << i  << "��° �Է� : ";
		cin >> num;
		inputArr[i] = num;
		if (num == 1) {  // num�� 1�̶�� ���Ϳ� i�� �߰��ؼ� ��� ���� ���õǾ����� �� �� �ְ� �Ѵ�.
			v.push_back(i);
		}
	}
}

// ���Ϳ� �ִ� 10���� ������ �ϳ��� �̾Ƽ� 2������ ��ȯ�ϴ� ������ ���� 2���� ���Ϳ� �־��ش�.
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