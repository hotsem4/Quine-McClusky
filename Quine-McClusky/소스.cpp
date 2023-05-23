#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class Qm {
public:
	int inputArr[16] = { 0, };  // �ʱ� input�� �Է� �迭
	vector<int> v;
	vector<vector <int>> v2;
	vector<vector <int>> v3;   // 10������ 1�� ������ ������ �迭
	void inputSettingArr();
	void makeDoubleVector();
	void printPage1();
	void copyVector();
	void printV3();
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
int countOnes(const vector<int>& v) { return count(v.begin(), v.end(), 1); }  // �迭 �ȿ� 1�� �� �� �ִ��� ī���� �Լ�  --> �Ű����� ���� ���� ������ 1�� ������ ��ȯ

// �켱 v3�� v2�� �����Ѵ�.
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

// 1�� ������ ���� ���� grouping �۾��� �ǽ��ؾ� �Ѵ�.

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
v[i]�� v2[i][]�� 10����
v2[i][]�� v[i]�� 2����
v3�� 0��°�� 10������ �ְ� 1��°�� 2������ 1�� �����̴�.
*/