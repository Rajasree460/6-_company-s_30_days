class Solution {
public:
		static bool comp(const pair<string,int> a, const pair<string,int> b){ // Comparator function to check and compare the 
		//values in pair of vectors as we can't directly compare the values in map.
        if (a.second != b.second) return (a.second < b.second); // checking according to frequency
        return (a.first > b.first); // checking lexographical order
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        vector<pair<string,int>> v;
        for (int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        vector<string> res;
        for (auto val: mp){
            v.push_back({val.first,val.second});
        }
        sort(v.begin(),v.end(),comp);
        reverse(v.begin(),v.end());
        for (int i=0; i<k; i++){ // print k string with highest frequency in lexographical order when same
            res.push_back(v[i].first);
        }
        return res;
    }
};
