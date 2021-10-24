#include<cstdio>

/* Vick Ye
 * 47m 51s
 * 10/10
 * still getting used to string stuff with c++ but logic was simple
 */


//essay[word]
char essay[100][15 + 1];
int N, K;

int charCount(char str[]) {
	int count = 0;
	while(str[count] != '\0') {
		count += 1;
	}
	return count;
}

void concatStr(char a[], char b[]) {
	int index = charCount(a);
	//add space if not empty
	if(index != 0) {
		a[index] = ' ';
		index += 1;
	}
	for(int i = 0; i < charCount(b); i++) {
		a[index] = b[i];
		index += 1;
	}
	a[index] = '\0';
}

int main() {
	//input
	FILE * in = fopen("word.in", "r");
	fscanf(in, "%d %d", &N, &K);
	for(int i = 0; i < N; i++) {
		fscanf(in, "%s", &essay[i]);
	}
	fclose(in);
	
	//algorithm
	//newEssay[line][words]
	char newEssay[N][2*K + 1];
	int lineNum = 0, lineLength = 0;
	for(int i = 0; i < N; i++) {
		newEssay[i][0] = '\0';
	}
	for(int i = 0; i < N; i++) {
		lineLength += charCount(essay[i]);
		if(lineLength > K) {
			lineNum += 1;
			lineLength = charCount(essay[i]);
		}
		concatStr(newEssay[lineNum], essay[i]);
	}

	//output
	FILE * out = fopen("word.out", "w");
	for(int i = 0; i <= lineNum; i++) {
		fprintf(out, "%s\n", newEssay[i]);
	}
	fclose(out);
	return 0;
}
