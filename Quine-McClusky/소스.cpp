#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class Qm {
public:
	int inputArr[16] = { 0, };  // 초기 input값 입력 배열
	vector<int> v;
	vector<vector <int>> v2;
	vector<vector <int>> v3;   // 10진수와 1의 갯수를 포함한 벡터
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
				// 두 개 이상의 위치가 다르면 병합할 수 없습니다.
				return {};
			}
		}
	}

	if (diffIndex == -1) {
		// 두 2진수가 완전히 같으면 병합할 수 없습니다.
		return {};
	}
	else {
		// 한 위치만 다르다면 그 위치를 -1로 하여 병합합니다.
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
				// 두 개 이상의 위치가 다르면 병합할 수 없습니다.
				return {};
			}
		}
	}

	if (diffIndex == -1) {
		// 두 2진수가 완전히 같으면 병합할 수 없습니다.
		return {};
	}
	else {
		// 한 위치만 다르다면 그 위치를 -1로 하여 병합합니다.
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
				// 두 개 이상의 위치가 다르면 병합할 수 없습니다.
				return {};
			}
		}
	}

	if (diffIndex == -1) {
		// 두 2진수가 완전히 같으면 병합할 수 없습니다.
		return {};
	}
	else {
		// 한 위치만 다르다면 그 위치를 -1로 하여 병합합니다.
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

	// 여기까지 1merge 종료  --> v4 완성
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

	//////////////////////////////////////////////////////////////
	// v6를 만드는 과정
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

// 지우기 작업.
// 작업을 하기 앞서 해당 코드는 v6, v5, v4의 존재를 바탕으로 제작되었기 때문에 지우기 작업을 할 경우에도 해당 경우를 나눠서 작업을 해야 한다.

void Qm::init() {
	inputSettingArr();
	if (v.empty()) {
		cout << "장난치지 마라";
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
v[i]는 v2[i][]의 10진수
v2[i][]는 v[i]의 2진수
v3는 0번째는 10진수가 있고 1번째는 2진수의 1의 갯수이다.
*/