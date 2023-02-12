class Solution {
public:
    vector<int>* n;
    queue<pair<int, int>>* qp;
    queue<pair<int, int>> q;
    queue<pair<int, int>> p;
    int kk;
    pair<int, int> getMax(int start) {
        pair<int, int> maxV = pair((*n)[start], start);
        for (int i = 1; i < kk; i++ ) {
            if ((*n)[start + i] >= maxV.first) {
                maxV.first = (*n)[start + i];
                maxV.second = start + i;
            }
            
        }
        return maxV;
    }

    void cleanQueue(){
        pair<int, int> back = qp->back();
        queue<pair<int, int>>* other;
        if (qp == &p) { 
            other = &q;
        } else {
            other = &p;
        }
        pair<int, int> top;
        while (!qp->empty()) {
            top = qp->front();
            if (top.first >= back.first) { 
                other->push(top);
            }
            qp->pop();
        }
        qp = other;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        n = &nums;
        kk = k;
        vector<int>sol;
        
        qp = &q;

        pair<int, int> p = getMax(0);
        qp->push(p);
        sol.push_back(p.first);
        for (int i = k; i < nums.size(); i++) {
            // cout << q.back().first << ", " << q.back().second<< "\n";
            // cout << nums[i]<< ", "  << i << "\n";
            while (!qp->empty() && qp->front().second + k - 1 < i) {
                qp->pop();
            }
            qp->push(pair(nums[i], i));
            cleanQueue();
            sol.push_back(qp->front().first);
        }
        return sol;
    }
};
