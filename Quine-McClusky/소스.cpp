#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

class Qm {
public:
	int inputArr[16] = { 0, };  // �ʱ� input�� �Է� �迭
	int min_arr_index[16] = { 0, };
	vector<int> min_arr;
	vector<int> v;
	vector<vector <int>> v2;
	vector<vector <int>> v3;   // 10������ 1�� ������ ������ ����
	vector<vector <int>> v4;
	vector<vector <int>> v5;
	vector<vector <int>> v6;
	vector<vector<int>> primeImplicants;
	vector<vector<int>> decimal;   // 10������ ����Ǿ� �ִ� ����
	vector<vector<int>> binary;
	vector<vector<int>> copyVectorDecimal;
	vector<vector<int>> mainEPI;

	void inputSettingArr();
	void convertToBinary();
	void printPage1();
	void copyVector();
	void sortV3();
	void printPage2();
	void findPairs();
	void backD();
	void init();

	vector<int> mergeBitStringsV3(const vector<int>& v1, const vector<int>& v2);
	vector<int> mergeBitStringsV4(const vector<int>& v1, const vector<int>& v2);
	vector<int> mergeBitStringsV5(const vector<int>& v1, const vector<int>& v2);
};

int main() {
	Qm nm;
	nm.init();
	return 0;
}

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
	cout << "�����̽��ٸ� ���� ��� �������ּ���.";
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
				return {};
			}
		}
	}
	if (diffIndex == -1) {
		return {};
	}
	else {
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
				return {};
			}
		}
	}

	if (diffIndex == -1) {
		return {};
	}
	else {
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
				return {};
			}
		}
	}
	if (diffIndex == -1) {
		return {};
	}
	else {
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
					vector<int> newPair;
					newPair.push_back(v3[i][0]);
					newPair.push_back(v3[j][0]);
					newPair.push_back(merged[0]);
					for (int k = 1; k < merged.size(); k++) {
						newPair.push_back(merged[k]);
					}
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
	for (int i = 0; i < v4.size() - 1; i++) {
		for (int j = i + 1; j < v4.size(); j++) {
			if (abs(v4[i][2] - v4[j][2]) == 1) {
				vector<int> merged = mergeBitStringsV4(v4[i], v4[j]);
				if (!merged.empty()) {
					vector<int> newPair1;
					newPair1.push_back(v4[i][0]);
					newPair1.push_back(v4[i][1]);
					newPair1.push_back(v4[j][0]);
					newPair1.push_back(v4[j][1]);
					newPair1.push_back(merged[0]);
					for (int k = 1; k < merged.size(); k++) {
						newPair1.push_back(merged[k]);
					}
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
	// v6�� ����� ����
	for (int i = 0; i < v5.size() - 1; i++) {
		for (int j = i + 1; j < v5.size(); j++) {
			if (abs(v5[i][4] - v5[j][4]) == 1) {
				vector<int> merged = mergeBitStringsV5(v5[i], v5[j]);
				if (!merged.empty()) {
					vector<int> newPair2;
					newPair2.push_back(v5[i][0]);
					newPair2.push_back(v5[i][1]);
					newPair2.push_back(v5[i][2]);
					newPair2.push_back(v5[i][3]);
					newPair2.push_back(v5[j][0]);
					newPair2.push_back(v5[j][1]);
					newPair2.push_back(v5[j][2]);
					newPair2.push_back(v5[j][3]);
					newPair2.push_back(merged[0]);
					for (int k = 1; k < merged.size(); k++) {
						newPair2.push_back(merged[k]);
					}
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

void Qm::backD() {
	int count_check = 0;
	int check_arr[16] = { 5, };    // �ε��� ���� �뵵
	int up_count = 0;
	if (v4.size() == 0) {  // merge�� �ϳ��� �ȵ� ���   --> 10�� �ڸ� 1�ڸ�
		primeImplicants = v3;  // ���� primeImplicants��.
		for (int i = 0; i < primeImplicants.size(); i++) {
			vector<int> emp;
			vector<int> binaryEmp;
			if (primeImplicants[i].size() == 6) {
				for (int j = 0; j < 1; j++) {
					min_arr_index[primeImplicants[i][j]] += 1;
					emp.push_back(primeImplicants[i][j]);
				}
				decimal.push_back(emp);
				for (int jj = 2; jj < 6; jj++) {
					binaryEmp.push_back(primeImplicants[i][jj]);
				}
				binary.push_back(binaryEmp);
			}
		}
		cout << endl;
		for (int i = 0; i < 16; i++) {  // �ּ��� ����
			if (min_arr_index[i] > 0) {
				min_arr.push_back(i);
			}
		}
		mainEPI = binary;  // decimal ��ü�� mainEPI�� �ȴ�.
		// �׸� �׸� �ð�
		int maxTermLength = 0;
		for (int term : min_arr) {
			int termLength = to_string(term).length();
			if (termLength > maxTermLength) {
				maxTermLength = termLength;
			}
		}
		// Draw the table header
		cout << "\n                 |";
		for (int term : min_arr) {
			cout << " " << setw(maxTermLength) << term;
		}
		cout << "\n" << string(maxTermLength + 15, '-') << " |";
		cout << string(min_arr.size() * (maxTermLength + 2), '-') << endl;
		// Draw the prime implicants
		for (const auto& prime : decimal) {
			cout << "(";
			for (size_t i = 0; i < prime.size(); i++) {
				if (i > 0) {
					cout << ", ";
				}
				if (prime[i] < 10) cout << " " << prime[i];
				else cout << prime[i];
			}
			if (prime.size() == 2) {
				cout << ")         |";;
			}
			else {
				cout << ")             |";
			}
			for (int term : min_arr) {
				bool isMatched = false;
				for (int j = 0; j < prime.size(); j++) {
					if (prime[j] == term) {
						cout << " " << setw(maxTermLength) << "X";
						isMatched = true;
						break;
					}
				}
				if (!isMatched) {
					cout << " " << setw(maxTermLength) << " ";
				}
			}
			cout << endl;
		}
		cout << "\n\n";
		mainEPI.erase(unique(mainEPI.begin(), mainEPI.end()), mainEPI.end());
		if (mainEPI.size() == 0) {
			cout << "���� �������� �ʽ��ϴ�.";
			return;
		}
		cout << "f(��) = ";
		for (int i = 0; i < mainEPI.size(); i++) {
			int number = 0;
			for (int dd : mainEPI[i]) {
				if (number == 0) {
					if (dd == 1) cout << 'A';
					else if (dd == 0) cout << "A'";
					else if (dd == -1) cout << "";
				}
				if (number == 1) {
					if (dd == 1) cout << 'B';
					else if (dd == 0) cout << "B'";
					else if (dd == -1) cout << "";
				}
				if (number == 2) {
					if (dd == 1) cout << 'C';
					else if (dd == 0) cout << "C'";
					else if (dd == -1) cout << "";
				}
				if (number == 3) {
					if (dd == 1) cout << 'D';
					else if (dd == 0) cout << "D'";
					else if (dd == -1) cout << "";
				}
				number++;
			}
			if (i == mainEPI.size() - 1) {
				cout << "";
			}
			else {
				cout << " + ";
			}
		}
	}
	else if (v5.size() == 0) {  // 1�� merge���� ����� ���   --> 10���ڸ� 2�ڸ�
		for (auto& termV3 : v3) {
			bool isPrime = true;
			for (auto& termV4 : v4) {
				if (includes(termV4.begin(), termV4.begin() + 2, termV3.begin(), termV3.begin() + 1)) {
					// If termV4 is included in termV5, it's not a prime implicant
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				primeImplicants.push_back(termV3);
			}
		}
		for (auto& termvV4 : v4) {  // primeImplicants �ϼ�
			primeImplicants.push_back(termvV4);
		}
		for (int i = 0; i < primeImplicants.size(); i++) {
			vector<int> emp;
			vector<int> binaryEmp;
			if (primeImplicants[i].size() == 6) {
				for (int j = 0; j < 1; j++) {
					min_arr_index[primeImplicants[i][j]] += 1;
					emp.push_back(primeImplicants[i][j]);
				}
				decimal.push_back(emp);
				for (int jj = 2; jj < 6; jj++) {
					binaryEmp.push_back(primeImplicants[i][jj]);
				}
				binary.push_back(binaryEmp);
			}
			if (primeImplicants[i].size() == 7) {
				for (int j = 0; j < 2; j++) {
					min_arr_index[primeImplicants[i][j]] += 1;
					emp.push_back(primeImplicants[i][j]);
				}
				decimal.push_back(emp);
				for (int jj = 3; jj < 7; jj++) {
					binaryEmp.push_back(primeImplicants[i][jj]);
				}
				binary.push_back(binaryEmp);
			}
		}
		for (int i = 0; i < 16; i++) {  // �ּ��� ����
			if (min_arr_index[i] > 0) {
				min_arr.push_back(i);
			}
		}
		for (int i = 0; i < 16; i++) {  // mainEPI ����
			if (min_arr_index[i] == 1) {
				for (int j = 0; j < decimal.size(); j++) {
					if (find(decimal[j].begin(), decimal[j].end(), i) != decimal[j].end()) {
						mainEPI.push_back(binary[j]);
					}
				}
			}
		}
		// �׸� �׸� �ð�
		int maxTermLength = 0;
		for (int term : min_arr) {
			int termLength = to_string(term).length();
			if (termLength > maxTermLength) {
				maxTermLength = termLength;
			}
		}
		// Draw the table header
		cout << "\n                 |";
		for (int term : min_arr) {
			cout << " " << setw(maxTermLength) << term;
		}
		cout << "\n" << string(maxTermLength + 15, '-') << "|";
		cout << string(min_arr.size() * (maxTermLength + 2), '-') << endl;
		// Draw the prime implicants
		for (const auto& prime : decimal) {
			cout << "(";
			for (size_t i = 0; i < prime.size(); i++) {
				if (i > 0) {
					cout << ", ";
				}
				if (prime[i] < 10) cout << " " << prime[i];
				else cout << prime[i];
			}
			if (prime.size() == 2) {
				cout << ")         |";;
			}
			else {
				cout << ")             |";
			}
			for (int term : min_arr) {
				bool isMatched = false;
				for (int j = 0; j < prime.size(); j++) {
					if (prime[j] == term) {
						cout << " " << setw(maxTermLength) << "X";
						isMatched = true;
						break;
					}
				}
				if (!isMatched) {
					cout << " " << setw(maxTermLength) << " ";
				}
			}
			cout << endl;
		}
		cout << "\n"; // �ּ��� O�� ����
		maxTermLength = 0;
		for (int term : min_arr) {
			int termLength = to_string(term).length();
			if (termLength > maxTermLength) {
				maxTermLength = termLength;
			}
		}
		// Draw the table header
		cout << "\n                 |";
		for (int term : min_arr) {
			cout << " " << setw(maxTermLength) << term;
		}
		cout << "\n" << string(maxTermLength + 15, '-') << "|";
		cout << string(min_arr.size() * (maxTermLength + 2), '-') << endl;
		// Draw the prime implicants
		for (const auto& prime : decimal) {
			cout << "(";
			for (size_t i = 0; i < prime.size(); i++) {
				if (i > 0) {
					cout << ", ";
				}
				if (prime[i] < 10) cout << " " << prime[i];
				else cout << prime[i];
			}
			if (prime.size() == 2) {
				cout << ")         |";;
			}
			else {
				cout << ")             |";
			}
			for (int term : min_arr) {
				bool isMatched = false;
				for (int j = 0; j < prime.size(); j++) {
					if (prime[j] == term) {
						if (min_arr_index[term] == 1) {
							cout << " " << setw(maxTermLength) << "O";
							isMatched = true;
							break;
						}
						cout << " " << setw(maxTermLength) << "X";
						isMatched = true;
						break;
					}
				}
				if (!isMatched) {
					cout << " " << setw(maxTermLength) << " ";
				}
			}
			cout << endl;
		}
		copyVectorDecimal = decimal;   // ���ſ� ����
		vector<vector<int>> temporaryVector;
		int count = 0;
		int NUM = 0;
		for (int index : min_arr_index) {
			if (index == 1) {
				for (const auto& todo : decimal) { // mainEPI�� �����ϴ� �׵� ����
					if (find(todo.begin(), todo.end(), count) != todo.end()) {
						temporaryVector.push_back(todo);
					}
				}
			}
			count++;
		}
		for (const auto& tempVector : temporaryVector) {
			for (int kk : tempVector) {
				for (auto& vec : copyVectorDecimal) {
					vec.erase(remove(vec.begin(), vec.end(), kk), vec.end());
				}
			}
		}
		for (int i = 0; i < copyVectorDecimal.size(); i++) {  // ������ epi �� ã�Ҵٸ� push_back
			bool isTrue = false;
			if (copyVectorDecimal[i].size() == 2) {
				if (copyVectorDecimal[i][0] == decimal[i][0] && copyVectorDecimal[i][1] == decimal[i][1]) {
					mainEPI.push_back(binary[i]);
				}
			}
		}
		// �����ٷ� �ٽ� �����
		cout << "\n";
		maxTermLength = 0;
		for (int term : min_arr) {
			int termLength = to_string(term).length();
			if (termLength > maxTermLength) {
				maxTermLength = termLength;
			}
		}
		// Draw the table header
		cout << "\n                 |";
		for (int term : min_arr) {
			cout << " " << setw(maxTermLength) << term;
		}
		cout << "\n" << string(maxTermLength + 15, '-') << "|";
		cout << string(min_arr.size() * (maxTermLength + 2), '-') << endl;
		int temp_count = 0; // temp_count ���� ����
		// Draw the prime implicants
		for (const auto& prime : decimal) {
			cout << "(";
			for (size_t i = 0; i < prime.size(); i++) {
				if (i > 0) {
					cout << ", ";
				}
				if (prime[i] < 10) cout << " " << prime[i];
				else cout << prime[i];
			}
			if (prime.size() == 2) {
				cout << ")         |";
			}
			else {
				cout << ")             |";
			}
			for (int term : min_arr) {
				bool isMatched = false;
				for (int j = 0; j < prime.size(); j++) {
					if (prime[j] == term) {
						if (min_arr_index[term] == 1) {
							cout << " " << setw(maxTermLength) << "O";
							isMatched = true;
							break;
						}
						if (find(copyVectorDecimal[temp_count].begin(), copyVectorDecimal[temp_count].end(), term) == copyVectorDecimal[temp_count].end()) {
							cout << " " << setw(maxTermLength) << " ��";
						}
						else {
							cout << " " << setw(maxTermLength) << "X";
						}
						isMatched = true;
						break;
					}
				}
				if (!isMatched) {
					cout << " " << setw(maxTermLength) << " ";
				}
			}
			cout << endl;
			temp_count++;
		}
		// �̷��� �ؼ� ���� vector���� decimal�� �ε��� ���Ϳ� ���ؼ� �Ϻ��� ��ġ�ϴ°� �ִٸ� mainEPI�� �߰��ϴ� ����� ��ұ�?
		// ��¥�� ��ü index���� �������ݾ�
		cout << "\n\n";
		sort(mainEPI.begin(), mainEPI.end());
		mainEPI.erase(unique(mainEPI.begin(), mainEPI.end()), mainEPI.end());
		if (mainEPI.size() == 0) {
			cout << "���� �������� �ʽ��ϴ�.";
			return;
		}
		cout << "f(��) = ";
		for (int i = 0; i < mainEPI.size(); i++) {
			int number = 0;
			for (int dd : mainEPI[i]) {
				if (number == 0) {
					if (dd == 1) cout << 'A';
					else if (dd == 0) cout << "A'";
					else if (dd == -1) cout << "";
				}
				if (number == 1) {
					if (dd == 1) cout << 'B';
					else if (dd == 0) cout << "B'";
					else if (dd == -1) cout << "";
				}
				if (number == 2) {
					if (dd == 1) cout << 'C';
					else if (dd == 0) cout << "C'";
					else if (dd == -1) cout << "";
				}
				if (number == 3) {
					if (dd == 1) cout << 'D';
					else if (dd == 0) cout << "D'";
					else if (dd == -1) cout << "";
				}
				number++;
			}
			if (i == mainEPI.size() - 1) {
				cout << "";
			}
			else {
				cout << " + ";
			}
		}
	}
	else if (v6.size() == 0) {   // 2�� merge���� ����� ���̽�   -->  10�� �ڸ� 4�ڸ�
		for (auto& termV4 : v4) {
			bool isPrime = true;
			for (auto& termV5 : v5) {
				if (includes(termV5.begin(), termV5.begin() + 4, termV4.begin(), termV4.begin() + 2)) {
					// If termV4 is included in termV5, it's not a prime implicant
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				primeImplicants.push_back(termV4);
			}
		}
		for (auto& termvV5 : v5) {  // primeImplicants �ϼ�
			primeImplicants.push_back(termvV5);
		}
		for (int i = 0; i < primeImplicants.size(); i++) {
			vector<int> emp;
			vector<int> binaryEmp;
			if (primeImplicants[i].size() == 7) {
				for (int j = 0; j < 2; j++) {
					min_arr_index[primeImplicants[i][j]] += 1;
					emp.push_back(primeImplicants[i][j]);
				}
				decimal.push_back(emp);
				for (int jj = 3; jj < 7; jj++) {
					binaryEmp.push_back(primeImplicants[i][jj]);
				}
				binary.push_back(binaryEmp);
			}
			if (primeImplicants[i].size() == 9) {
				for (int j = 0; j < 4; j++) {
					min_arr_index[primeImplicants[i][j]] += 1;
					emp.push_back(primeImplicants[i][j]);
				}
				decimal.push_back(emp);
				for (int jj = 5; jj < 9; jj++) {
					binaryEmp.push_back(primeImplicants[i][jj]);
				}
				binary.push_back(binaryEmp);
			}
		}
		for (int i = 0; i < 16; i++) {  // �ּ��� ����
			if (min_arr_index[i] > 0) {
				min_arr.push_back(i);
			}
		}
		for (int i = 0; i < 16; i++) {
			if (min_arr_index[i] == 1) {
				for (int j = 0; j < decimal.size(); j++) {
					if (find(decimal[j].begin(), decimal[j].end(), i) != decimal[j].end()) {
						mainEPI.push_back(binary[j]);
					}
				}
			}
		}
		// �׸� �׸� �ð�
		int maxTermLength = 0;
		for (int term : min_arr) {
			int termLength = to_string(term).length();
			if (termLength > maxTermLength) {
				maxTermLength = termLength;
			}
		}
		// Draw the table header
		cout << "\n                 |";
		for (int term : min_arr) {
			cout << " " << setw(maxTermLength) << term;
		}
		cout << "\n" << string(maxTermLength + 15, '-') << "|";
		cout << string(min_arr.size() * (maxTermLength + 2), '-') << endl;
		// Draw the prime implicants
		for (const auto& prime : decimal) {
			cout << "(";
			for (size_t i = 0; i < prime.size(); i++) {
				if (i > 0) {
					cout << ", ";
				}
				if (prime[i] < 10) cout << " " << prime[i];
				else cout << prime[i];

			}
			if (prime.size() == 2) {
				cout << ")         |";;
			}
			else {
				cout << ") |";
			}
			for (int term : min_arr) {
				bool isMatched = false;
				for (int j = 0; j < prime.size(); j++) {
					if (prime[j] == term) {
						cout << " " << setw(maxTermLength) << "X";
						isMatched = true;
						break;
					}
				}
				if (!isMatched) {
					cout << " " << setw(maxTermLength) << " ";
				}
			}
			cout << endl;
		}
		cout << "\n\n"; // �ּ��� O�� ����
		maxTermLength = 0;
		for (int term : min_arr) {
			int termLength = to_string(term).length();
			if (termLength > maxTermLength) {
				maxTermLength = termLength;
			}
		}
		// Draw the table header
		cout << "\n                 |";
		for (int term : min_arr) {
			cout << " " << setw(maxTermLength) << term;
		}
		cout << "\n" << string(maxTermLength + 15, '-') << "|";
		cout << string(min_arr.size() * (maxTermLength + 2), '-') << endl;
		// Draw the prime implicants
		for (const auto& prime : decimal) {
			cout << "(";
			for (size_t i = 0; i < prime.size(); i++) {
				if (i > 0) {
					cout << ", ";
				}
				if (prime[i] < 10) cout << " " << prime[i];
				else cout << prime[i];
			}
			if (prime.size() == 2) {
				cout << ")         |";;
			}
			else {
				cout << ") |";
			}
			for (int term : min_arr) {
				bool isMatched = false;
				for (int j = 0; j < prime.size(); j++) {
					if (prime[j] == term) {
						if (min_arr_index[term] == 1) {
							cout << " " << setw(maxTermLength) << "O";
							isMatched = true;
							break;
						}
						cout << " " << setw(maxTermLength) << "X";
						isMatched = true;
						break;
					}
				}
				if (!isMatched) {
					cout << " " << setw(maxTermLength) << " ";
				}
			}
			cout << endl;
		}
		// 5,7 ã��
		copyVectorDecimal = decimal;   // ���ſ� ����
		vector<vector<int>> temporaryVector;
		int count = 0;
		int NUM = 0;
		for (int index : min_arr_index) {
			if (index == 1) {
				for (const auto& todo : decimal) { // mainEPI�� �����ϴ� �׵� ����
					if (find(todo.begin(), todo.end(), count) != todo.end()) {
						temporaryVector.push_back(todo);
					}
				}
			}
			count++;
		}
		for (const auto& tempVector : temporaryVector) {
			for (int kk : tempVector) {
				for (auto& vec : copyVectorDecimal) {
					vec.erase(remove(vec.begin(), vec.end(), kk), vec.end());
				}
			}
		}
		for (int i = 0; i < copyVectorDecimal.size(); i++) {  // ������ epi �� ã�Ҵٸ� push_back
			bool isTrue = false;
			if (copyVectorDecimal[i].size() == 2 && decimal[i].size() == 2) {
				if (copyVectorDecimal[i][0] == decimal[i][0] && copyVectorDecimal[i][1] == decimal[i][1]) {
					mainEPI.push_back(binary[i]);
				}
			}
		}
		// �����ٷ� �ٽ� �����
		cout << "\n\n"; // �ּ��� O�� ����
		maxTermLength = 0;
		for (int term : min_arr) {
			int termLength = to_string(term).length();
			if (termLength > maxTermLength) {
				maxTermLength = termLength;
			}
		}
		cout << "\n                 |";
		for (int term : min_arr) {
			cout << " " << setw(maxTermLength) << term;
		}
		cout << "\n" << string(maxTermLength + 15, '-') << "|";
		cout << string(min_arr.size() * (maxTermLength + 2), '-') << endl;
		int temp_count = 0; // temp_count ���� ����
		for (const auto& prime : decimal) {
			cout << "(";
			for (size_t i = 0; i < prime.size(); i++) {
				if (i > 0) {
					cout << ", ";
				}
				if (prime[i] < 10) cout << " " << prime[i];
				else cout << prime[i];
			}
			if (prime.size() == 2) {
				cout << ")         |";
			}
			else {
				cout << ") |";
			}
			for (int term : min_arr) {
				bool isMatched = false;
				for (int j = 0; j < prime.size(); j++) {
					if (prime[j] == term) {
						if (min_arr_index[term] == 1) {
							cout << " " << setw(maxTermLength) << "O";
							isMatched = true;
							break;
						}
						if (find(copyVectorDecimal[temp_count].begin(), copyVectorDecimal[temp_count].end(), term) == copyVectorDecimal[temp_count].end()) {
							cout << " " << setw(maxTermLength) << " ��";
						}
						else {
							cout << " " << setw(maxTermLength) << "X";
						}
						isMatched = true;
						break;
					}
				}
				if (!isMatched) {
					cout << " " << setw(maxTermLength) << " ";
				}
			}
			cout << endl;
			temp_count++;
		}
		// �̷��� �ؼ� ���� vector���� decimal�� �ε��� ���Ϳ� ���ؼ� �Ϻ��� ��ġ�ϴ°� �ִٸ� mainEPI�� �߰��ϴ� ����� ��ұ�?
		// ��¥�� ��ü index���� �������ݾ�
		cout << "\n\n";
		sort(mainEPI.begin(), mainEPI.end());
		mainEPI.erase(unique(mainEPI.begin(), mainEPI.end()), mainEPI.end());
		if (mainEPI.size() == 0) {
			cout << "���� �������� �ʽ��ϴ�.";
			return;
		}
		cout << "f(��) = ";
		for (int i = 0; i < mainEPI.size(); i++) {
			int number = 0;
			for (int dd : mainEPI[i]) {
				if (number == 0) {
					if (dd == 1) cout << 'A';
					else if (dd == 0) cout << "A'";
					else if (dd == -1) cout << "";
				}
				if (number == 1) {
					if (dd == 1) cout << 'B';
					else if (dd == 0) cout << "B'";
					else if (dd == -1) cout << "";
				}
				if (number == 2) {
					if (dd == 1) cout << 'C';
					else if (dd == 0) cout << "C'";
					else if (dd == -1) cout << "";
				}
				if (number == 3) {
					if (dd == 1) cout << 'D';
					else if (dd == 0) cout << "D'";
					else if (dd == -1) cout << "";
				}
				number++;
			}
			if (i == mainEPI.size() - 1) {
				cout << "";
			}
			else {
				cout << " + ";
			}
		}
	}
	else if (v6.size() != 0) {   // 3�� merge���� �� ���̽�    --> 10�� �ڸ� 8�ڸ�
		for (auto& termV5 : v5) {
			bool isPrime = true;
			for (auto& termV6 : v6) {
				if (includes(termV6.begin(), termV6.begin() + 8, termV5.begin(), termV5.begin() + 4)) {
					// If termV4 is included in termV5, it's not a prime implicant
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				primeImplicants.push_back(termV5);
			}
		}
		for (auto& termvV6 : v6) {  // primeImplicants �ϼ�
			primeImplicants.push_back(termvV6);
		}
		for (int i = 0; i < primeImplicants.size(); i++) {
			vector<int> emp;
			vector<int> binaryEmp;
			if (primeImplicants[i].size() == 9) {
				for (int j = 0; j < 4; j++) {
					min_arr_index[primeImplicants[i][j]] += 1;
					emp.push_back(primeImplicants[i][j]);
				}
				decimal.push_back(emp);
				for (int jj = 5; jj < 9; jj++) {
					binaryEmp.push_back(primeImplicants[i][jj]);
				}
				binary.push_back(binaryEmp);
			}
			if (primeImplicants[i].size() == 13) {
				for (int j = 0; j < 8; j++) {
					min_arr_index[primeImplicants[i][j]] += 1;
					emp.push_back(primeImplicants[i][j]);
				}
				decimal.push_back(emp);
				for (int jj = 9; jj < 13; jj++) {
					binaryEmp.push_back(primeImplicants[i][jj]);
				}
				binary.push_back(binaryEmp);
			}
		}
		for (int i = 0; i < 16; i++) {  // �ּ��� ����
			if (min_arr_index[i] > 0) {
				min_arr.push_back(i);
			}
		}
		for (int i = 0; i < 16; i++) {
			if (min_arr_index[i] == 1) {
				for (int j = 0; j < decimal.size(); j++) {
					if (find(decimal[j].begin(), decimal[j].end(), i) != decimal[j].end()) {
						mainEPI.push_back(binary[j]);
					}
				}
			}
		}
		// �׸� �׸� �ð�
		int maxTermLength = 0;
		for (int term : min_arr) {
			int termLength = to_string(term).length();
			if (termLength > maxTermLength) {
				maxTermLength = termLength;
			}
		}
		cout << "\n                                 |";
		for (int term : min_arr) {
			cout << " " << setw(maxTermLength) << term;
		}
		cout << "\n" << string(maxTermLength + 31, '-') << "|";
		cout << string(min_arr.size() * (maxTermLength + 2), '-') << endl;
		for (const auto& prime : decimal) {
			cout << "(";
			for (size_t i = 0; i < prime.size(); i++) {
				if (i > 0) {
					cout << ", ";
				}
				if (prime[i] < 10) cout << " " << prime[i];
				else cout << prime[i];
			}
			if (prime.size() == 4) {
				cout << ")                 |";;
			}
			else {
				cout << ") |";
			}
			for (int term : min_arr) {
				bool isMatched = false;
				for (int j = 0; j < prime.size(); j++) {
					if (prime[j] == term) {
						cout << " " << setw(maxTermLength) << "X";
						isMatched = true;
						break;
					}
				}
				if (!isMatched) {
					cout << " " << setw(maxTermLength) << " ";
				}
			}
			cout << endl;
		}
		cout << "\n\n"; // �ּ��� O�� ����
		maxTermLength = 0;
		for (int term : min_arr) {
			int termLength = to_string(term).length();
			if (termLength > maxTermLength) {
				maxTermLength = termLength;
			}
		}
		cout << "\n                                 |";
		for (int term : min_arr) {
			cout << " " << setw(maxTermLength) << term;
		}
		cout << "\n" << string(maxTermLength + 31, '-') << "|";
		cout << string(min_arr.size() * (maxTermLength + 2), '-') << endl;
		for (const auto& prime : decimal) {
			cout << "(";
			for (size_t i = 0; i < prime.size(); i++) {
				if (i > 0) {
					cout << ", ";
				}
				if (prime[i] < 10) cout << " " << prime[i];
				else cout << prime[i];
			}
			if (prime.size() == 4) {
				cout << ")                 |";;
			}
			else {
				cout << ") |";
			}
			for (int term : min_arr) {
				bool isMatched = false;
				for (int j = 0; j < prime.size(); j++) {
					if (prime[j] == term) {
						if (min_arr_index[term] == 1) {
							cout << " " << setw(maxTermLength) << "O";
							isMatched = true;
							break;
						}
						cout << " " << setw(maxTermLength) << "X";
						isMatched = true;
						break;
					}
				}
				if (!isMatched) {
					cout << " " << setw(maxTermLength) << " ";
				}
			}
			cout << endl;
		}
		copyVectorDecimal = decimal;   // ���ſ� ����
		vector<vector<int>> temporaryVector;
		int count = 0;
		int NUM = 0;
		for (int index : min_arr_index) {
			if (index == 1) {
				for (const auto& todo : decimal) { // mainEPI�� �����ϴ� �׵� ����
					if (find(todo.begin(), todo.end(), count) != todo.end()) {
						temporaryVector.push_back(todo);
					}
				}
			}
			count++;
		}
		for (const auto& tempVector : temporaryVector) {
			for (int kk : tempVector) {
				for (auto& vec : copyVectorDecimal) {
					vec.erase(remove(vec.begin(), vec.end(), kk), vec.end());
				}
			}
		}
		
		for (int i = 0; i < copyVectorDecimal.size(); i++) {  // ������ epi �� ã�Ҵٸ� push_back
			bool isTrue = false;
			if (copyVectorDecimal[i].size() == 4) {
				if (copyVectorDecimal[i][0] == decimal[i][0] && copyVectorDecimal[i][1] == decimal[i][1] && copyVectorDecimal[i][2] == decimal[i][2] && copyVectorDecimal[i][3] == decimal[i][3]) {
					mainEPI.push_back(binary[i]);
				}
			}
		}
		// �����ٷ� �ٽ� �����
		cout << "\n\n"; // �ּ��� O�� ����
		maxTermLength = 0;
		for (int term : min_arr) {
			int termLength = to_string(term).length();
			if (termLength > maxTermLength) {
				maxTermLength = termLength;
			}
		}
		// Draw the table header
		cout << "\n                                 |";
		for (int term : min_arr) {
			cout << " " << setw(maxTermLength) << term;
		}
		cout << "\n" << string(maxTermLength + 31, '-') << "|";
		cout << string(min_arr.size() * (maxTermLength + 2), '-') << endl;
		int temp_count = 0; // temp_count ���� ����
		// Draw the prime implicants
		for (const auto& prime : decimal) {
			cout << "(";
			for (size_t i = 0; i < prime.size(); i++) {
				if (i > 0) {
					cout << ", ";
				}
				if (prime[i] < 10) cout << " " << prime[i];
				else cout << prime[i];
			}
			if (prime.size() == 4) {
				cout << ")                 |";;
			}
			else {
				cout << ") |";
			}
			for (int term : min_arr) {
				bool isMatched = false;
				for (int j = 0; j < prime.size(); j++) {
					if (prime[j] == term) {
						if (min_arr_index[term] == 1) {
							cout << " " << setw(maxTermLength) << "O";
							isMatched = true;
							break;
						}
						if (find(copyVectorDecimal[temp_count].begin(), copyVectorDecimal[temp_count].end(), term) == copyVectorDecimal[temp_count].end()) {
							cout << " " << setw(maxTermLength) << " ��";
						}
						else {
							cout << " " << setw(maxTermLength) << "X";
						}
						isMatched = true;
						break;
					}
				}
				if (!isMatched) {
					cout << " " << setw(maxTermLength) << " ";
				}
			}
			cout << endl;
			temp_count++;
		}
		cout << "\n\n";
		sort(mainEPI.begin(), mainEPI.end());
		mainEPI.erase(unique(mainEPI.begin(), mainEPI.end()), mainEPI.end());
		if (mainEPI.size() == 0) {
			cout << "���� �������� �ʽ��ϴ�.";
			return;
		}
		cout << "f(��) = ";
		for (int i = 0; i < mainEPI.size(); i++) {
			int number = 0;
			for (int dd : mainEPI[i]) {
				if (number == 0) {
					if (dd == 1) cout << 'A';
					else if (dd == 0) cout << "A'";
					else if (dd == -1) cout << "";
				}
				if (number == 1) {
					if (dd == 1) cout << 'B';
					else if (dd == 0) cout << "B'";
					else if (dd == -1) cout << "";
				}
				if (number == 2) {
					if (dd == 1) cout << 'C';
					else if (dd == 0) cout << "C'";
					else if (dd == -1) cout << "";
				}
				if (number == 3) {
					if (dd == 1) cout << 'D';
					else if (dd == 0) cout << "D'";
					else if (dd == -1) cout << "";
				}
				number++;
			}
			if (i == mainEPI.size() - 1) {
				cout << "";
			}
			else {
				cout << " + ";
			}
		}
	}
}

void Qm::init() {
	int key;
	int i = 0;
	inputSettingArr();
	if (v.empty()) {
		cout << "�峭ġ�� ����";
		return;
	}
	while (1) {
		if (_kbhit()) {
			key = _getch();
			if (key == 32) {
				if (i == 4) return;
				if (i == 0) {
					system("cls");
					convertToBinary();
					printPage1();
					cout << "\n\n�����̽��ٸ� �����ּ���!!" << endl;
				}
				if (i == 1) {
					system("cls");
					copyVector();
					sortV3();
					printPage2();
					cout << "\n\n�����̽��ٸ� �����ּ���!!" << endl;
				}
				if (i == 2) {
					system("cls");
					findPairs();
					cout << "\n\n�����̽��ٸ� �����ּ���!!" << endl;
				}
				if (i == 3) {
					system("cls");
					backD();
					cout << "\n\n�����̽��ٸ� �����ּ���!!" << endl;
				}
				i++;
			}
		}
	}
}

//int main() {
//	Qm nm;
//	nm.init();
//	return 0;
//}

/*
v[i]�� v2[i][]�� 10����
v2[i][]�� v[i]�� 2����
v3�� 0��°�� 10������ �ְ� 1��°�� 2������ 1�� �����̴�.
v4�� [0][1]���� 10����, [2]���� ����, �������� 2����
v5�� [0][1][2][3]���� 10����, [4]�� ���� ����, �������� 2����
v6�� [0][1][2][3][4][5][6][7]���� 10����, [8]�� ���� ����, �������� 2����
*/