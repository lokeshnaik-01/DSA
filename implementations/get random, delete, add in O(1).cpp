class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end()) {
            return false;
        }
        v.push_back(val);
        m[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end()) {
            return false;
        }
        int currIndex = m[val];
        int currValue = val;

        int lastIndex = v.size()-1;
        int lastValue = v[lastIndex];

        v[currIndex] = lastValue;

        m[lastValue] = currIndex;
        v.pop_back();
        m.erase(currValue);
        return true;
    }
    
    int getRandom() {
        int n = v.size();
        int index = rand()%(n);
        return v[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */