struct Node {
    Node* link[2];
    Node() {
        link[0] = nullptr;
        link[1] = nullptr;
    }
    Node* get(int i) {
        return link[i];
    }
    void put(Node* node, int i) {
        link[i] = node;
    }
    bool containsKey(int bit) {
        return link[bit] != nullptr;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(int n) {
        Node* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(new Node(), bit);
            }
            node = node->get(bit);
        }
    }
    int getMax(int x) {
        Node* node = root;
        int maxi = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if(node->containsKey(1 - bit)) {
                maxi |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int> ans(queries.size());
        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int,int>>> q;  

        for(int i = 0; i < queries.size(); i++){
            q.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(q.begin(), q.end());  

        Trie* trie = new Trie();
        int i = 0;  

        for(auto &it : q) {
            int m = it.first;
            int x = it.second.first;
            int index = it.second.second;

            while(i < nums.size() && nums[i] <= m) {
                trie->insert(nums[i]);
                i++;
            }

            if(i == 0) { 
                ans[index] = -1;
            }
            else {
                ans[index] = trie->getMax(x);
            }
        }
        
        return ans;
    }
};
