class RLEIterator {
public:
    vector<int> a;
    RLEIterator(vector<int>& encoding) {
         a = encoding;   
    }
    
    int next(int n) {
        int val = -1;
        for(int i = 0; i < a.size(); i+=2) {
            if(a[i] > 0) {
                if(a[i] >= n) {
                    a[i] -= n;
                    n = 0;
                    val = a[i+1];
                    break;
                }else if(a[i] < n && a[i] != 0) {
                    n -= a[i];
                    a[i] = 0;
                }
            }
        }
        return val;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */