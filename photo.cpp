#include<cstdio>

/* Vick Ye
 * 55m 10s
 * 2/10
 * I dont really understand what lexicographical means
 */


int main() {
	int N, bessieLen;
	//input
	FILE * in = fopen("photo.in", "r");
	fscanf(in, "%d", &N);

	//line contains N-1 ints
	bessieLen = N - 1;

	int bessieSeq[bessieLen];
	for(int i = 0; i < bessieLen; i++) {
		fscanf(in, "%d", &bessieSeq[i]);
	}
	fclose(in);

	//preprocess
	//convert to base 0(which is -2 because the nums are sums of two nums >= 1)
	for(int i = 0; i < bessieLen; i++) {
		bessieSeq[i] -= 2;
	}
	
	//algorithm
	int testNum = 0;
	int sequence[N];
	//test sequences from 0 up where the first num + int = bessieSeq[0] so 0 <= num <= bessieSeq
	for(int i = 0; i <= bessieSeq[0]; i++) {
		//build sequence based on first which is testNum
		sequence[0] = testNum;
		for(int j = 1; j < N; j++) {
			//seq[i] + seq[i + 1] = bessieSeq[i] flipped -> seq[i - 1] + seq[i] = bessieSeq[i - 1]
			sequence[j] = bessieSeq[j - 1] - sequence[j - 1];
		}
		
		//test if lexicographical(foreach i:seq, seq[i] != i)
		//position and value are shifted left, comparison shouldn't differ from original
		bool lexicographical = true;
		for(int j = 0; j < N; j++) {
			if(sequence[j] == j) {
				lexicographical = false;
				break;
			}
		}
		if(lexicographical) {
			break;
		} else {
			//test next num if seq doesn't work
			testNum += 1;
		}
	}

	//output
	//shift back to base 1
	for(int i = 0; i < N; i++) {
		sequence[i] += 1;
	}
	
	FILE * out = fopen("photo.out", "w");
	//add spaces only between
	fprintf(out, "%d", sequence[0]);
	for(int i = 1; i < N; i++) {
		fprintf(out, " %d", sequence[i]);
	}
	fclose(out);
	return 0;
}
