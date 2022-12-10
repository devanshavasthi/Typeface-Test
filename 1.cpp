#include<bits/stdc++.h>

using namespace std;

int top = INT_MAX, bottom = 0, l = INT_MAX, r = 0;

void dfs(int m, int n, vector<vector<int> >& matrix, int idx1, int idx2){

	if(idx1 < 0 || idx1 >= m || idx2 < 0 || idx2 >= n || matrix[idx1][idx2] == 0)
		return;

	if(idx1 < top)
		top = idx1;
	if(idx1 > bottom)
		bottom = idx1;
	if(idx2 < l)
		l = idx2;
	if(idx2 > r)
		r = idx2;

	matrix[idx1][idx2] = 0;

	dfs(m, n, matrix, idx1-1, idx2);
	dfs(m, n, matrix, idx1+1, idx2);
	dfs(m, n, matrix, idx1, idx2-1);
	dfs(m, n, matrix, idx1, idx2+1);

}

vector<vector<double> > getBound(int m, int n, vector<vector<int> >& matrix){

	vector<vector<double> > ans;

	for(int idx1=0; idx1<m; idx1++){
		for(int idx2=0; idx2<n; idx2++){
			if(matrix[idx1][idx2] == 1){
				dfs(m, n, matrix, idx1, idx2);
				double centreX = l + ((double)r - l)/2.0;
				double centrey = top + ((double)bottom - top)/2.0;
				double width = r - l + 1;
				double height = bottom - top + 1;
				ans.push_back({centreX, centrey, width, height});
				top = INT_MAX, bottom = 0, l = INT_MAX, r = 0;
			}
		}
	}

	return ans;

}

int main(){

	int m, n;
	// get input
	cin >> m >> n;

	vector<vector<int> > matrix(m, vector<int> (n));
	for(int idx1=0; idx1<m; idx1++){
		for(int idx2=0; idx2<n; idx2++){
			cin >> matrix[idx1][idx2];
		}
	}

	vector<vector<double> > ans = getBound(m, n, matrix);

	for(int idx1=0; idx1<ans.size(); idx1++){
		for(int idx2=0; idx2<4; idx2++){
			cout << ans[idx1][idx2] << " ";
		}
		cout << endl;
	}

	return 0;

}