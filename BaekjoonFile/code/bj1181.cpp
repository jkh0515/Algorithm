//단어 정렬

#include <iostream>
#include <algorithm>
using namespace std;

int cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}

string word[20000];

int main() {
	int N;
    scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}
	sort(word, word + N, cmp);
	for (int i = 0; i < N; i++) {
		if (word[i] == word[i - 1]) {
			continue;
		}
		cout << word[i] << "\n";
	}
	return 0;
}
