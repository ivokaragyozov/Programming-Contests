
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1.e+5 + 42;

int numCnt;
int nums[MAX_N];
bool checked[MAX_N];
int mainPair[2];
bool isPair;

int main() {
	scanf("%i", &numCnt);
	for(int i = 0;i < numCnt;i++) {
		scanf("%i", &nums[i]);
		nums[i]--;
	}

	for(int i = 0;i < numCnt;i++) {
		if(i == nums[nums[i]]) {
			mainPair[0] = i;
			mainPair[1] = nums[i];

			checked[i] = true;
			checked[nums[i]] = true;

			isPair = true;
			break;
		}
	}

	if(!isPair) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if(mainPair[0] != mainPair[1]) {
		printf("%i %i\n", mainPair[0] + 1, mainPair[1] + 1);
	}

	for(int i = 0;i < numCnt;i++) {
		if(checked[i]) {
			continue;
		}

		int cur = i;
		int j = 0;
		do {
			checked[cur] = true;
			printf("%i %i\n", mainPair[j] + 1, cur + 1);
			j = (j + 1) % 2;
			cur = nums[cur];
		} while(!checked[cur]);
	}
}

