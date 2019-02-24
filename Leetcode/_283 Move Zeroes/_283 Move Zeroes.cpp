void moveZeroes(int* nums, int numsSize)
{
	int i;
	int temp;
	int nonZeroCount = 0;
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] != 0)
		{
			nums[nonZeroCount] = nums[i];
			//nums[i]=0;
			nonZeroCount++;
		}
		if (nums[i] == 0)
			continue;
	}
	for (i = nonZeroCount; i<numsSize; i++)
	{
		nums[i] = 0;
	}
}