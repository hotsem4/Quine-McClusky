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
	void printPage1();
	void init();
};

void Qm::inputSettingArr() {      // �ʱ� �迭 input ����
	int num = 0;
	for (int i = 0; i < 16; i++) {
		cout << i  << "��° �Է� : ";
		cin >> num;
		inputArr[i] = num;
		if (num == 1) {     // num�� 1�̶�� ���Ϳ� i�� �߰��ؼ� ��� ���� ���õǾ����� �� �� �ְ� �Ѵ�.
			v.push_back(i);
		}
	}
}

void Qm::makeDoubleVector() {       // ���Ϳ� �ִ� 10���� ������ �ϳ��� �̾Ƽ� 2������ ��ȯ�ϴ� ������ ���� 2���� ���Ϳ� �־��ش�.
	for (int i = 0; i < v.size(); i++) {
		vector<int> binary;
		int n = v[i];
		for (int i = 0; i < 4; i++){  // 10���� --> 2����
			binary.insert(binary.begin(), n % 2);
			n /= 2;
		}
		v2.push_back(binary);
	}
}


void Qm::printPage1() {    // 2���� ���Ͱ� �ϼ��Ǿ����� 1������ ��º� �����
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

// 1�� ������ ���� ���� grouping �۾��� �ǽ��ؾ� �Ѵ�.


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
v[i]�� v2[i][]�� 10����
v2[i][]�� v[i]�� 2����
*/