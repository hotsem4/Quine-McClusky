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
	int inputArr[16] = { 0, };  // 초기 input값 입력 배열
	int min_arr_index[16] = { 0, };
	vector<int> min_arr;
	vector<int> v;
	vector<vector <int>> v2;
	vector<vector <int>> v3;   // 10진수와 1의 갯수를 포함한 벡터
	vector<vector <int>> v4;
	vector<vector <int>> v5;
	vector<vector <int>> v6;
	vector<vector<int>> primeImplicants;
	vector<vector<int>> decimal;   // 10진수만 저장되어 있는 벡터
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

void Qm::inputSettingArr() {      // 초기 배열 input 진행
	int num = 0;
	for (int i = 0; i < 16; i++) {
		cout << i << "번째 입력 : ";
		cin >> num;
		inputArr[i] = num;
		if (num == 1) {     // num이 1이라면 벡터에 i를 추가해서 어느 수가 선택되었는지 알 수 있게 한다.
			v.push_back(i);
		}
	}
	cout << "스페이스바를 눌러 계속 진행해주세요.";
}

void Qm::convertToBinary() {       // 벡터에 있는 10진수 값들을 하나씩 뽑아서 2진수로 변환하는 과정을 거쳐 2차원 벡터에 넣어준다.
	for (int i = 0; i < v.size(); i++) {
		vector<int> binary;
		int n = v[i];
		for (int i = 0; i < 4; i++) {  // 10진수 --> 2진수
			binary.insert(binary.begin(), n % 2);
			n /= 2;
		}
		v2.push_back(binary);
	}
}

void Qm::printPage1() {    // 2차원 벡터가 완성되었으니 1페이지 출력부 만들기
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
int countOnes(const vector<int>& v) { return count(v.begin(), v.end(), 1); }  // 배열 안에 1이 몇 개 있는지 카운팅 함수  --> 매개변수 단일 벡서 넣으면 1의 갯수로 반환

void Qm::copyVector() {    // 우선 v3에 v2를 복사한다.
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
void Qm::sortV3() {  // v3[i][1]을 기준으로 v3를 정렬한다.
	sort(v3.begin(), v3.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[1] < b[1];
		});
}
void Qm::printPage2() {    // 정렬된 v3를 보기 좋게 프린트한다.
	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i][2] << "  " << v3[i][3] << "  " << v3[i][4] << "  " << v3[i][5] << "  " << "(" << v3[i][0] << ")" << endl;
		if (i != v3.size() - 1 && v3[i][1] != v3[i + 1][1]) {
			cout << "-----------------" << endl;
		}
	}
}
vector<int> Qm::mergeBitStringsV3(const vector<int>& v1, const vector<int>& v2) {
	vector<int> a(v1.begin() + 2, v1.end());  // 2진수 부분만 추출
	vector<int> b(v2.begin() + 2, v2.end());  // 2진수 부분만 추출
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
	vector<int> a(v1.begin() + 3, v1.end());  // 2진수 부분만 추출
	vector<int> b(v2.begin() + 3, v2.end());  // 2진수 부분만 추출

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
	vector<int> a(v1.begin() + 5, v1.end());  // 2진수 부분만 추출
	vector<int> b(v2.begin() + 5, v2.end());  // 2진수 부분만 추출
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
	// 여기까지 1merge 종료  --> v4 완성
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
	auto get_binary_part = [](const vector<int>& a) {   // v5에서 2진수만 추출하는 람다식
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
	// v6를 만드는 과정
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
	auto get_binary_part1 = [](const vector<int>& a) {   // v5에서 2진수만 추출하는 람다식
		return vector<int>(a.begin() + 9, a.end());
	};
	// Vector to hold unique elements
	vector<vector<int>> unique_v6;
	for (const auto& elem : v6) {
		auto binary_part1 = get_binary_part1(elem);  // error 날수도 있음
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
	int check_arr[16] = { 5, };    // 인덱스 관리 용도
	int up_count = 0;
	if (v4.size() == 0) {  // merge가 하나도 안된 경우   --> 10의 자리 1자리
		primeImplicants = v3;  // 모든게 primeImplicants다.
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
		for (int i = 0; i < 16; i++) {  // 최소항 추출
			if (min_arr_index[i] > 0) {
				min_arr.push_back(i);
			}
		}
		mainEPI = binary;  // decimal 자체가 mainEPI가 된다.
		// 그림 그릴 시간
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
			cout << "값이 존재하지 않습니다.";
			return;
		}
		cout << "f(Σ) = ";
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
	else if (v5.size() == 0) {  // 1차 merge에서 종료된 경우   --> 10의자리 2자리
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
		for (auto& termvV4 : v4) {  // primeImplicants 완성
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
		for (int i = 0; i < 16; i++) {  // 최소항 추출
			if (min_arr_index[i] > 0) {
				min_arr.push_back(i);
			}
		}
		for (int i = 0; i < 16; i++) {  // mainEPI 추출
			if (min_arr_index[i] == 1) {
				for (int j = 0; j < decimal.size(); j++) {
					if (find(decimal[j].begin(), decimal[j].end(), i) != decimal[j].end()) {
						mainEPI.push_back(binary[j]);
					}
				}
			}
		}
		// 그림 그릴 시간
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
		cout << "\n"; // 최소항 O로 변경
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
		copyVectorDecimal = decimal;   // 제거용 벡터
		vector<vector<int>> temporaryVector;
		int count = 0;
		int NUM = 0;
		for (int index : min_arr_index) {
			if (index == 1) {
				for (const auto& todo : decimal) { // mainEPI가 존재하는 항들 모임
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
		for (int i = 0; i < copyVectorDecimal.size(); i++) {  // 숨겨진 epi 를 찾았다면 push_back
			bool isTrue = false;
			if (copyVectorDecimal[i].size() == 2) {
				if (copyVectorDecimal[i][0] == decimal[i][0] && copyVectorDecimal[i][1] == decimal[i][1]) {
					mainEPI.push_back(binary[i]);
				}
			}
		}
		// 세로줄로 다시 지우기
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
		int temp_count = 0; // temp_count 변수 선언
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
							cout << " " << setw(maxTermLength) << " ▲";
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
		// 이렇게 해서 나온 vector값을 decimal의 인덱스 벡터와 비교해서 완벽히 일치하는게 있다면 mainEPI에 추가하는 방식은 어떠할까?
		// 어짜피 전체 index값은 같은거잖아
		cout << "\n\n";
		sort(mainEPI.begin(), mainEPI.end());
		mainEPI.erase(unique(mainEPI.begin(), mainEPI.end()), mainEPI.end());
		if (mainEPI.size() == 0) {
			cout << "값이 존재하지 않습니다.";
			return;
		}
		cout << "f(Σ) = ";
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
	else if (v6.size() == 0) {   // 2차 merge에서 종료된 케이스   -->  10의 자리 4자리
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
		for (auto& termvV5 : v5) {  // primeImplicants 완성
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
		for (int i = 0; i < 16; i++) {  // 최소항 추출
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
		// 그림 그릴 시간
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
		cout << "\n\n"; // 최소항 O로 변경
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
		// 5,7 찾기
		copyVectorDecimal = decimal;   // 제거용 벡터
		vector<vector<int>> temporaryVector;
		int count = 0;
		int NUM = 0;
		for (int index : min_arr_index) {
			if (index == 1) {
				for (const auto& todo : decimal) { // mainEPI가 존재하는 항들 모임
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
		for (int i = 0; i < copyVectorDecimal.size(); i++) {  // 숨겨진 epi 를 찾았다면 push_back
			bool isTrue = false;
			if (copyVectorDecimal[i].size() == 2 && decimal[i].size() == 2) {
				if (copyVectorDecimal[i][0] == decimal[i][0] && copyVectorDecimal[i][1] == decimal[i][1]) {
					mainEPI.push_back(binary[i]);
				}
			}
		}
		// 세로줄로 다시 지우기
		cout << "\n\n"; // 최소항 O로 변경
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
		int temp_count = 0; // temp_count 변수 선언
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
							cout << " " << setw(maxTermLength) << " ▲";
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
		// 이렇게 해서 나온 vector값을 decimal의 인덱스 벡터와 비교해서 완벽히 일치하는게 있다면 mainEPI에 추가하는 방식은 어떠할까?
		// 어짜피 전체 index값은 같은거잖아
		cout << "\n\n";
		sort(mainEPI.begin(), mainEPI.end());
		mainEPI.erase(unique(mainEPI.begin(), mainEPI.end()), mainEPI.end());
		if (mainEPI.size() == 0) {
			cout << "값이 존재하지 않습니다.";
			return;
		}
		cout << "f(Σ) = ";
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
	else if (v6.size() != 0) {   // 3차 merge까지 간 케이스    --> 10의 자리 8자리
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
		for (auto& termvV6 : v6) {  // primeImplicants 완성
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
		for (int i = 0; i < 16; i++) {  // 최소항 추출
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
		// 그림 그릴 시간
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
		cout << "\n\n"; // 최소항 O로 변경
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
		copyVectorDecimal = decimal;   // 제거용 벡터
		vector<vector<int>> temporaryVector;
		int count = 0;
		int NUM = 0;
		for (int index : min_arr_index) {
			if (index == 1) {
				for (const auto& todo : decimal) { // mainEPI가 존재하는 항들 모임
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
		
		for (int i = 0; i < copyVectorDecimal.size(); i++) {  // 숨겨진 epi 를 찾았다면 push_back
			bool isTrue = false;
			if (copyVectorDecimal[i].size() == 4) {
				if (copyVectorDecimal[i][0] == decimal[i][0] && copyVectorDecimal[i][1] == decimal[i][1] && copyVectorDecimal[i][2] == decimal[i][2] && copyVectorDecimal[i][3] == decimal[i][3]) {
					mainEPI.push_back(binary[i]);
				}
			}
		}
		// 세로줄로 다시 지우기
		cout << "\n\n"; // 최소항 O로 변경
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
		int temp_count = 0; // temp_count 변수 선언
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
							cout << " " << setw(maxTermLength) << " ▲";
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
			cout << "값이 존재하지 않습니다.";
			return;
		}
		cout << "f(Σ) = ";
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
		cout << "장난치지 마라";
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
					cout << "\n\n스페이스바를 눌러주세요!!" << endl;
				}
				if (i == 1) {
					system("cls");
					copyVector();
					sortV3();
					printPage2();
					cout << "\n\n스페이스바를 눌러주세요!!" << endl;
				}
				if (i == 2) {
					system("cls");
					findPairs();
					cout << "\n\n스페이스바를 눌러주세요!!" << endl;
				}
				if (i == 3) {
					system("cls");
					backD();
					cout << "\n\n스페이스바를 눌러주세요!!" << endl;
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
v[i]는 v2[i][]의 10진수
v2[i][]는 v[i]의 2진수
v3는 0번째는 10진수가 있고 1번째는 2진수의 1의 갯수이다.
v4는 [0][1]까지 10진수, [2]일의 갯수, 나머지는 2진수
v5는 [0][1][2][3]까지 10진수, [4]는 일의 갯수, 나머지는 2진수
v6는 [0][1][2][3][4][5][6][7]까지 10진수, [8]는 일의 갯수, 나머지는 2진수
*/