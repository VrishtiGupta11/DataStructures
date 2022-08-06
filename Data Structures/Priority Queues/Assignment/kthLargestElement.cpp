#include <iostream>
#include <queue>
using namespace std;

int kthLargestELement(int* arr, int N, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<k; i++)
        pq.push(arr[i]);
    for(int i=k; i<N; i++) {
        if(arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main() {
    int N, k;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cin >> k;
    cout << kthLargestELement(arr, N, k);
}