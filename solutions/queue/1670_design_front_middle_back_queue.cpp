class FrontMiddleBackQueue {
private:
    deque<int> q;

public:
    FrontMiddleBackQueue() {
    }

    void pushFront(int val) {
        q.push_front(val);
    }

    void pushMiddle(int val) {
        int mid = q.size() / 2;
        q.insert(q.begin() + mid, val);
    }

    void pushBack(int val) {
        q.push_back(val);
    }

    int popFront() {
        if (q.empty())
            return -1;

        int value = q.front();
        q.pop_front();

        return value;
    }

    int popMiddle() {
        if (q.empty())
            return -1;

        int mid = (q.size() - 1) / 2;
        int value = q[mid];

        q.erase(q.begin() + mid);

        return value;
    }

    int popBack() {
        if (q.empty())
            return -1;

        int value = q.back();
        q.pop_back();

        return value;
    }
};