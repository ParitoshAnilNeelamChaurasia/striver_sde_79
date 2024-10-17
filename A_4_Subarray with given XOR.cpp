

// BRUTE FORCE

int Solution::solve(vector<int> &A, int B) {
    int n = A.size() ;
    
    int count = 0 ;
   
    
    for(int i = 0 ; i < n ; ++i)
    {
        int num = 0 ;
        for(int j = i ; j < n ; ++j)
        {
            num = num ^ A[j] ;
            if(num == B)
            count++;
        }
    }
    return count ;
}


// OPTIMAL
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> freq; // To store frequency of prefixXOR values
    int xor_sum = 0;  // To store XOR of the current prefix
    int count = 0;    // To count the number of subarrays

    for (int i = 0; i < n; ++i) {
        xor_sum ^= A[i];  // XOR up to the current element
        
        // If XOR from the start matches B, count it
        if (xor_sum == B) {
            count++;
        }
        
        // If there exists a prefix such that prefixXOR ^ B == xor_sum, it means
        // the subarray from that prefix to the current index has XOR equal to B
        if (freq.find(xor_sum ^ B) != freq.end()) {
            count += freq[xor_sum ^ B];
        }

        // Increment the frequency of the current prefix XOR
        freq[xor_sum]++;
    }

    return count;
}
