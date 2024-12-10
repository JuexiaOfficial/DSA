#include <vector>
#include <iostream>
class heap
{
private:
    std::vector<int> data; // 堆数组
public:
    heap() = delete;         // 禁止默认构造函数
    heap(int n) : data(n) {} // 构造函数，传入堆的大小
    // 构造函数，传入数组
    heap(std::vector<int> &arr) : data(arr)
    {
        build_max_heap();
    }

    // 获取左子节点索引
    int left(int i)
    {
        return 2 * i + 1;
    }
    // 获取右子节点索引
    int right(int i)
    {
        return 2 * i + 2;
    }
    // 获取父节点索引
    int parent(int i)
    {
        return (i - 1) / 2; // 向下取整
    }

    // 建堆
    void build_max_heap()
    {
        for (int i = parent(data.size() - 1); i >= 0; i--)
        {
            max_heapify(i);
        }
    }
    // 调整堆
    void max_heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < data.size() && data[l] > data[largest])
        {
            largest = l;
        }
        if (r < data.size() && data[r] > data[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            std::swap(data[i], data[largest]);
            max_heapify(largest);
        }
    }
    // 插入元素
    void insert(int x)
    {
        data.push_back(x);
        int i = data.size() - 1;
        while (i > 0 && data[parent(i)] < data[i])
        {
            std::swap(data[i], data[parent(i)]);
            i = parent(i);
        }
    }
    // 取出最大元素
    int extract_max()
    {
        if (data.empty())
        {
            return -1;
        }
        int max = data[0];
        data[0] = data.back();
        data.pop_back();
        max_heapify(0);
        return max;
    }
    void print()
    {
        for (int i = 0; i < data.size(); i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    std::vector<int> arr = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};        // 构造数组
    heap h(arr);                                                     // 构造堆
    h.insert(5);                                                     // 插入元素
    std::cout << "Max element is: " << h.extract_max() << std::endl; // 取出最大元素
    h.print();                                                       // 打印堆
    return 0;
}