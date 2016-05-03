#include<stdio.h>
#include<string.h>

const int MAXN = 200010;
int nums[MAXN];
int sorted[MAXN];
long long int ans = 0;

void merge(int start, int end){
	if(start == end) return;
	int mid = (start+end)/2;
	merge(start, mid);
	merge(mid+1, end);

	int p1 = start, p2 = mid+1, p = start;

	while(p1 <= mid && p2 <= end) {
		if(nums[p1] <= nums[p2]) {
			sorted[p++] = nums[p1++];
		}	
		else {
			sorted[p++] = nums[p2++];
			ans += mid - p1+1;
		}
	}
	while(p1 <= mid) { 
		sorted[p++] = nums[p1++];
	}

	while(p2 <= end) {
		sorted[p++] = nums[p2++];
	}
	for(int i = start; i <= end; i++) {
		nums[i] = sorted[i];
	}
}


int main() {
	int T,N;
	scanf(" %d",&T);
	while(T--) {
		memset(nums,0,sizeof(nums));
		memset(sorted,0,sizeof(sorted));
		ans = 0;
		scanf(" %d",&N);
		for(int i = 0; i < N; i++){ 
			scanf(" %d",&nums[i]);	
		}
		merge(0, N-1);
		printf("%lld\n",ans);
	}
}	
