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
	vector<vector <int>> v3;   // 10������ 1�� ������ ������ ����
	vector<vector <int>> v4;
	vector<vector <int>> v5;
	vector<vector <int>> v6;
	void inputSettingArr();
	void convertToBinary();
	void printPage1();
	void copyVector();
	void sortV3();
	void printPage2();
	void findPairs();
	void init();

	vector<int> mergeBitStringsV3(const vector<int>& v1, const vector<int>& v2);
	vector<int> mergeBitStringsV4(const vector<int>& v1, const vector<int>& v2);
	vector<int> mergeBitStringsV5(const vector<int>& v1, const vector<int>& v2);
};

void Qm::inputSettingArr() {      // �ʱ� �迭 input ����
	int num = 0;
	for (int i = 0; i < 16; i++) {
		cout << i << "��° �Է� : ";
		cin >> num;
		inputArr[i] = num;
		if (num == 1) {     // num�� 1�̶�� ���Ϳ� i�� �߰��ؼ� ��� ���� ���õǾ����� �� �� �ְ� �Ѵ�.
			v.push_back(i);
		}
	}
}

void Qm::convertToBinary() {       // ���Ϳ� �ִ� 10���� ������ �ϳ��� �̾Ƽ� 2������ ��ȯ�ϴ� ������ ���� 2���� ���Ϳ� �־��ش�.
	for (int i = 0; i < v.size(); i++) {
		vector<int> binary;
		int n = v[i];
		for (int i = 0; i < 4; i++) {  // 10���� --> 2����
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

void Qm::copyVector() {    // �켱 v3�� v2�� �����Ѵ�.
	v3 = v2;
	for (int i = 0; i < v.size(); i++) {
		v3[i].insert(v3[i].begin(), v[i]);
	}
	int k = 0;
	for (const auto& row : v2) {
		int ones = countOnes(row);
		v3[k].insert(v3[k].begin() + 1, ones);
		k++;
	}
}

void Qm::sortV3() {  // v3[i][1]�� �������� v3�� �����Ѵ�.
	sort(v3.begin(), v3.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[1] < b[1];
		});
}

void Qm::printPage2() {    // ���ĵ� v3�� ���� ���� ����Ʈ�Ѵ�.
	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i][2] << "  " << v3[i][3] << "  " << v3[i][4] << "  " << v3[i][5] << "  " << "(" << v3[i][0] << ")" << endl;
		if (i != v3.size() - 1 && v3[i][1] != v3[i + 1][1]) {
			cout << "-----------------" << endl;
		}
	}
}

vector<int> Qm::mergeBitStringsV3(const vector<int>& v1, const vector<int>& v2) {
	vector<int> a(v1.begin() + 2, v1.end());  // 2���� �κи� ����
	vector<int> b(v2.begin() + 2, v2.end());  // 2���� �κи� ����

	int diffIndex = -1;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			if (diffIndex == -1) {
				diffIndex = i;
			}
			else {
				// �� �� �̻��� ��ġ�� �ٸ��� ������ �� �����ϴ�.
				return {};
			}
		}
	}

	if (diffIndex == -1) {
		// �� 2������ ������ ������ ������ �� �����ϴ�.
		return {};
	}
	else {
		// �� ��ġ�� �ٸ��ٸ� �� ��ġ�� -1�� �Ͽ� �����մϴ�.
		a[diffIndex] = -1;
		return a;
	}
}

vector<int> Qm::mergeBitStringsV4(const vector<int>& v1, const vector<int>& v2) {
	vector<int> a(v1.begin() + 3, v1.end());  // 2���� �κи� ����
	vector<int> b(v2.begin() + 3, v2.end());  // 2���� �κи� ����

	int diffIndex = -1;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			if (diffIndex == -1) {
				diffIndex = i;
			}
			else {
				// �� �� �̻��� ��ġ�� �ٸ��� ������ �� �����ϴ�.
				return {};
			}
		}
	}

	if (diffIndex == -1) {
		// �� 2������ ������ ������ ������ �� �����ϴ�.
		return {};
	}
	else {
		// �� ��ġ�� �ٸ��ٸ� �� ��ġ�� -1�� �Ͽ� �����մϴ�.
		a[diffIndex] = -1;
		return a;
	}
}

vector<int> Qm::mergeBitStringsV5(const vector<int>& v1, const vector<int>& v2) {
	vector<int> a(v1.begin() + 5, v1.end());  // 2���� �κи� ����
	vector<int> b(v2.begin() + 5, v2.end());  // 2���� �κи� ����

	int diffIndex = -1;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			if (diffIndex == -1) {
				diffIndex = i;
			}
			else {
				// �� �� �̻��� ��ġ�� �ٸ��� ������ �� �����ϴ�.
				return {};
			}
		}
	}

	if (diffIndex == -1) {
		// �� 2������ ������ ������ ������ �� �����ϴ�.
		return {};
	}
	else {
		// �� ��ġ�� �ٸ��ٸ� �� ��ġ�� -1�� �Ͽ� �����մϴ�.
		a[diffIndex] = -1;
		return a;
	}
}


void Qm::findPairs() {
	for (int i = 0; i < v3.size() - 1; i++) {
		for (int j = i + 1; j < v3.size(); j++) {
			if (abs(v3[i][1] - v3[j][1]) == 1) {
				vector<int> merged = mergeBitStringsV3(v3[i], v3[j]);
				if (!merged.empty()) {
					// vector to hold the new pair
					vector<int> newPair;
					// add the 10-decimal numbers
					newPair.push_back(v3[i][0]);
					newPair.push_back(v3[j][0]);
					// add the count of 1s
					newPair.push_back(merged[0]);
					// add the merged bitstring
					for (int k = 1; k < merged.size(); k++) {
						newPair.push_back(merged[k]);
					}
					// add the new pair to v4
					v4.push_back(newPair);
					
				}
			}
		}
	}
	cout << endl;
	int k = 0;
	for (const auto& row : v4) {
		int ones = count(row.begin() + 2, row.end(), 1);
		v4[k].insert(v4[k].begin() + 2, ones);
		k++;
	}
	if (v4.size() == 0) return;
	// Print v4
	cout << "\nFinal v4 after finding all pairs and merging:\n";
	for (const auto& row : v4) {
		cout << "(";
		for (int i = 0; i < 2; i++) {
			cout << row[i] << ",";
		}
		cout << ") -> ";
		for (int i = 3; i < row.size(); i++) {
			if (row[i] == -1) cout << "-";
			else cout << row[i];
		}
		cout << endl;
	}

	// ������� 1merge ����  --> v4 �ϼ�
	///////////////////////////////////////////////////////////////////////
	for (int i = 0; i < v4.size() - 1; i++) {
		for (int j = i + 1; j < v4.size(); j++) {
			if (abs(v4[i][2] - v4[j][2]) == 1) {
				vector<int> merged = mergeBitStringsV4(v4[i], v4[j]);
				if (!merged.empty()) {
					// vector to hold the new pair
					vector<int> newPair1;
					// add the 10-decimal numbers
					newPair1.push_back(v4[i][0]);
					newPair1.push_back(v4[i][1]);
					newPair1.push_back(v4[j][0]);
					newPair1.push_back(v4[j][1]);
					// add the count of 1s
					newPair1.push_back(merged[0]);
					// add the merged bitstring
					for (int k = 1; k < merged.size(); k++) {
						newPair1.push_back(merged[k]);
					}
					// add the new pair to v4
					v5.push_back(newPair1);
				}
			}
		}
	}
	k = 0;
	for (const auto& row : v5) {
		int ones = count(row.begin() + 4, row.end(), 1);
		v5[k].insert(v5[k].begin() + 4, ones);
		k++;
	}
	auto get_binary_part = [](const vector<int>& a) {   // v5���� 2������ �����ϴ� ���ٽ�
		return vector<int>(a.begin() + 5, a.end());
	};

	// Vector to hold unique elements
	vector<vector<int>> unique_v5;

	for (const auto& elem : v5) {
		auto binary_part = get_binary_part(elem);
		bool is_duplicate = false;

		for (const auto& unique_elem : unique_v5) {
			if (get_binary_part(unique_elem) == binary_part) {
				is_duplicate = true;
				break;
			}
		}

		if (!is_duplicate) {
			unique_v5.push_back(elem);
		}
	}

	v5 = move(unique_v5);

	if (v5.size() == 0) return;
	// Print v5
	cout << "\nFinal v5 after finding all pairs and merging:\n";
	for (const auto& row : v5) {
		cout << "(";
		for (int i = 0; i < 4; i++) {
			cout << row[i] << ",";
		}
		cout << ") -> ";
		for (int i = 5; i < row.size(); i++) {
			if (row[i] == -1) cout << "-";
			else cout << row[i];
		}
		cout << endl;
	}

	//////////////////////////////////////////////////////////////
	// v6�� ����� ����
	for (int i = 0; i < v5.size() - 1; i++) {
		for (int j = i + 1; j < v5.size(); j++) {
			if (abs(v5[i][4] - v5[j][4]) == 1) {
				vector<int> merged = mergeBitStringsV5(v5[i], v5[j]);
				if (!merged.empty()) {
					// vector to hold the new pair
					vector<int> newPair2;
					// add the 10-decimal numbers
					newPair2.push_back(v5[i][0]);
					newPair2.push_back(v5[i][1]);
					newPair2.push_back(v5[i][2]);
					newPair2.push_back(v5[i][3]);
					newPair2.push_back(v5[j][0]);
					newPair2.push_back(v5[j][1]);
					newPair2.push_back(v5[j][2]);
					newPair2.push_back(v5[j][3]);
					// add the count of 1s
					newPair2.push_back(merged[0]);
					// add the merged bitstring
					for (int k = 1; k < merged.size(); k++) {
						newPair2.push_back(merged[k]);
					}
					// add the new pair to v4
					v6.push_back(newPair2);
				}
			}
		}
	}
	k = 0;
	for (const auto& row : v6) {
		int ones = count(row.begin() + 8, row.end(), 1);
		v6[k].insert(v6[k].begin() + 8, ones);
		k++;
	}
	auto get_binary_part1 = [](const vector<int>& a) {   // v5���� 2������ �����ϴ� ���ٽ�
		return vector<int>(a.begin() + 9, a.end());
	};

	// Vector to hold unique elements
	vector<vector<int>> unique_v6;

	for (const auto& elem : v6) {
		auto binary_part1 = get_binary_part1(elem);  // error ������ ����
		bool is_duplicate = false;

		for (const auto& unique_elem : unique_v6) {
			if (get_binary_part1(unique_elem) == binary_part1) {
				is_duplicate = true;
				break;
			}
		}

		if (!is_duplicate) {
			unique_v6.push_back(elem);
		}
	}

	v6 = move(unique_v6);

	if (v6.size() == 0) return;
	// Print v5
	cout << "\nFinal v6 after finding all pairs and merging:\n";
	for (const auto& row : v6) {
		cout << "(";
		for (int i = 0; i < 8; i++) {
			cout << row[i] << ",";
		}
		cout << ") -> ";
		for (int i = 9; i < row.size(); i++) {
			if (row[i] == -1) cout << "-";
			else cout << row[i];
		}
		cout << endl;
	}
}

// ����� �۾�.
// �۾��� �ϱ� �ռ� �ش� �ڵ�� v6, v5, v4�� ���縦 �������� ���۵Ǿ��� ������ ����� �۾��� �� ��쿡�� �ش� ��츦 ������ �۾��� �ؾ� �Ѵ�.

void Qm::init() {
	inputSettingArr();
	if (v.empty()) {
		cout << "�峭ġ�� ����";
		return;
	}
	convertToBinary();
	printPage1();
	copyVector();
	sortV3();
	printPage2();
	findPairs();
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