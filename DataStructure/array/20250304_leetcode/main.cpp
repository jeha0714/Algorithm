class Solution {
	public:
		vector<int> pivotArray(vector<int>& nums, int pivot) {
			vector<int> result, tmp;
			int numPivot;
	
			result.reserve(nums.size());
			tmp.reserve(nums.size());
			numPivot = 0;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] < pivot)
					result.push_back(nums[i]);
				else if (nums[i] == pivot)
					numPivot++;
				else
					tmp.push_back(nums[i]);
			}
	
			for (int i = 0; i < numPivot; i++)
				result.push_back(pivot);
	
			for (int i = 0; i < tmp.size(); i++)
				result.push_back(tmp[i]);
	
			return (result);
		}
	};
	
	