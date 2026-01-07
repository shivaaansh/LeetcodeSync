class RandomizedCollection {
public:
    vector<pair<int,int>> nums; // val, position in map
    unordered_map<int, vector<int>> mp; // val, vector of idxs of val in nums
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        auto res = mp.find(val) == mp.end();
        mp[val].push_back(nums.size());
        nums.push_back({val, mp[val].size()-1});
        return res;
    }
    
    bool remove(int val) {
        auto res = mp.find(val) != mp.end();
        if(res) {
            auto last = nums.back();
            mp[last.first][last.second] = mp[val].back();
            nums[mp[val].back()] = last;
            mp[val].pop_back();
            nums.pop_back();
            if(mp[val].empty()) mp.erase(val);
        }
        return res;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */