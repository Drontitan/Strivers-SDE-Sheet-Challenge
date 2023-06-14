

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int findXOR = 0;
	
	// calculating the XOR of all the numbers from 1 to n
	for(int i  = 1; i <= n; i += 1)
	{
		findXOR ^= i;
	}
	
	// calculating the XOR of all the elements of the array
	for(int i  = 0; i < n; i += 1)
	{
		findXOR ^= arr[i];
	}
	
	// last set bit of findXOR
	int bitIndex = findXOR & ~(findXOR - 1); 
	
	int bitSet = 0, bitNotSet = 0;
	
	// dividing the elements of the array in two sets, bitSet and bitNotSet
	for (int i = 0; i < n; i++) 
	{ 
        if (arr[i] & bitIndex) 
        {
            bitSet = bitSet ^ arr[i];
		}
  
        else
        {
            bitNotSet = bitNotSet ^ arr[i]; 
        }
    } 
    
    // dividing the elements from 1 to n in two sets
    for (int i = 1; i <= n; i++) 
	{ 
        if (i & bitIndex) 
        {
            bitSet = bitSet ^ i; 
  		}
  		
        else
		{
            bitNotSet = bitNotSet ^ i; 
        }
    } 
    
	int m, r;
	
	
	for(int i = 0; i < n; i += 1)
	{
		// if bitSet is present in the array, it is the repeating number and bitNotSet is the missing number
		if(bitSet == arr[i])
		{
			r = bitSet ; 
			m = bitNotSet;
			break;
		}
		
		// if bitNotSet is present in the array, it is the repeating number and bitSet is the missing number
		if(bitNotSet == arr[i])
		{
			r = bitNotSet;
			m = bitSet;
			break;
		}
	}
	
	pair<int, int>ans;
	
	ans.first = m;
	ans.second = r;
	
	return ans;
	 
}
