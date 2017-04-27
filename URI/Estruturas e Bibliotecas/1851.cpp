#include <bits/stdc++.h>

#define si pair<long double, unsigned long long int>
#define pi pair<si,unsigned long long int>
#define ppi pair<pi, unsigned long long int>

using namespace std;

int main() {
    unsigned long long int t, f, timeCount = 0, sum = 0, day = 0;
    double aux;

    priority_queue<ppi> v;
    ppi train;


    while((cin >> t >> f)||(!v.empty())){
        if((t!=0) && (f!=0)){
            aux=t/f;
            // aux = f;
            v.push(ppi(pi(si(aux, t), f), day));
            if(timeCount == 0){
                train = v.top();
                v.pop();
                timeCount = train.first.first.second;
                sum += (day - train.second) * train.first.second;
            }

            timeCount--;
            day++;


        } else{
            timeCount = 0;
            train = v.top();
            v.pop();
            sum += (day - train.second) * train.first.second;
            day += (train.first.second-1);
        }


        t = 0;
        f = 0;

    }

    cout << sum << endl;

    return 0;
}
