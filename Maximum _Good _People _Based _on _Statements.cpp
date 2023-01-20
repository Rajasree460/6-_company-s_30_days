class Solution {
public:
    vector<vector<int>> stm;
    int n;
	int rf(vector<int> v, int i){
			if(i>=n){
				//check valid
				int cnt = 0;
				for(int i=0; i<n; i++){
					if(v[i] == 1){
						cnt++;
						for(int j=0; j<n; j++){
							// if not valid, return -1
							if(stm[i][j] == 1 && v[j] == 0) return -1;
							if(stm[i][j] == 0 && v[j] == 1) return -1;
						}
					}
				}
				// if valid, return good people count
				return cnt;
			}
			// let person i be good
			v[i] = 1;
			int x = rf(v,i+1);
			
			// let person i be bad
			v[i] = 0;
			int y = rf(v, i+1);
			
			return max({0,x,y});
	}
	int maximumGood(vector<vector<int>>& statements) {
        n = statements.size();
        stm = statements;
        vector<int> v(n);
        return rf(v,0);
    }
};
