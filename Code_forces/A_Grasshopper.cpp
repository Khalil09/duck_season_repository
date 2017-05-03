#include <bits/stdc++.h>

using namespace std;

char s[103];

bool is_equal(char a){
	if(a == 'A' || a == 'E' ||
	   a == 'I' || a == 'O'	|| 
	   a == 'U' || a == 'Y'){
		return true;
	} else {

		return false;
	}
}

int main(){
	int count = 0, max = 0;
	cin >> s;

	int start = -1, end = 0;
	
	int i = 0;

	while(s[i] != '\0'){
		if(is_equal(s[i])){
			end = i;
			count = abs(end - start);
			if(count > max){
				max = count;
			}
			start = i;
		}
		i++;
	}
	count = i - start;

	if(count > max){
		max = count;
	}

	cout << max << endl;

	return 0;
}