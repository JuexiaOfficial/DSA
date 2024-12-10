#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &nums, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && nums[left] > nums[largest])
    {
        largest = left;
    }
    if (right < n && nums[right] > nums[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}
void heapSort(vector<int> &nums)
{
    // 堆的叶子节点天然满足堆的性质，因为它们没有子节点，因此不需要调整
    // 构建最大堆，从最后一个非叶子节点开始调整
    for (int i = nums.size() / 2 - 1; i >= 0; i--)
    {
        heapify(nums, nums.size(), i);
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        swap(nums[0], nums[i]);
        // 0 的位置被交换过，因此需要重新调整
        heapify(nums, i, 0);
    }
}

int main()
{
    vector<int> nums{2, 5, 1, 8, 3, 7, 6, 4};
    heapSort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}