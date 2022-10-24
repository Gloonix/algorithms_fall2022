#include <iostream>

template <typename T, typename Comparator = std::less<T>>
int partition(T *arr, int l, int r, Comparator cmp)
{
    T pivot = arr[l];
    int i = l + 1;
    int j = r;
    
    while (true)
    {
        while (i <= r && cmp(arr[i], pivot))
        {
            i++;
        }
        while (cmp(pivot, arr[j]))
        {
            j--;
        }
        if (i >= j)
        {
            std::swap(arr[l], arr[j]);
            return j;
        }
        
        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

template <typename T, typename Comparator = std::less<T>>
T kth_stat(T *arr, int k, int l, int r, Comparator cmp = Comparator())
{
    int pivot_pos = partition(arr, l, r, cmp);
    if (pivot_pos == k)
    {
        return arr[pivot_pos];
    }
    if (pivot_pos > k)
    {
        return kth_stat(arr, k, l, pivot_pos - 1, cmp);
    }
    return kth_stat(arr, k, pivot_pos + 1, r, cmp);
}

int main(int argc, const char * argv[]) {
    {
        int arr[] = {5, 2, 8, 1, 9, 22};
        for (int i = 0; i < 5; i++)
            std::cout << kth_stat<int>(arr, i, 0, 5) << " ";
        std::cout << std::endl;
    }
    {
        std::string arr[] = {"5", "2", "8", "1", "9", "22"};
        for (int i = 0; i < 5; i++)
            std::cout << kth_stat(arr, i, 0, 5, std::greater<std::string>())  << " ";
        std::cout << std::endl;
    }
    return 0;
}
