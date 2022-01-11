// Finds most frequent element iff it occurs more than n/2 times
// Moore's Voting Algorithm
// https://www.geeksforgeeks.org/frequent-element-array/
// similar question "Final450/Searching and Sorting/8.cpp" https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

#include <iostream>
using namespace std;

int maxFreq(int *arr, int n) {
	//using moore's voting algorithm
	int res = 0;
	int count = 1;
	for(int i = 1; i < n; i++) {
		if(arr[i] == arr[res]) {
			count++;
		} else {
			count--;
		}
		
		if(count == 0) {
			res = i;
			count = 1;
		}
		
	}
	
	return arr[res];
}

int main()
{
	int arr[] = {40,50,30,40,50,30,30};
	int n = sizeof(arr) / sizeof(arr[0]);
	int freq = maxFreq(arr , n);
	int count = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] == freq) {
			count++;
		}
	}
	cout <<"Element " << maxFreq(arr , n) << " occurs " << count << " times" << endl;;
	return 0;
	//This code is contributed by Ashish Kumar Shakya
}
