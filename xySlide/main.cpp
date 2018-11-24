#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// x and y pointer to find the maximum window size where condition is true
// implementations comes out from a misunderstanding of problem strudel from training.olinfo.it

int findMaxSize(vector<int> d){
    int l=0, r=-1, maxSize = 0;

    while(r+1<d.size()){
        // extend the window as long as possible
        // while(notOutOfBound && condition is true){extend r}
        while(r+1 < d.size() && d[r+1]>0){
            r++;
        }
        maxSize = max(r-l+1, maxSize);
        // shrink the window to 0 and move on until a good slice is found
        // while(notOutOfBound && condition is false){extend r} then adjust l
        while(r+1 < d.size() && d[r+1] <= 0){
            r++;
        }
        l = r+1;
    }
    // reached the end
    return maxSize;
}

int main(){

    int n;
    cin >> n;

    vector<int> cann(n);
    vector<int> mand(n);
    vector<int> diff(n);
    for(int &x : mand){
        cin >> x;
    }
    for(int &x : cann){
        cin >> x;
    }
    for(int i=0; i<diff.size(); i++){
        diff[i] = cann[i] - mand[i];
    }
    cout << findMaxSize(diff);
}