void sortColors(vector<int> &a)
{
    int n = a.size(), low = 0, mid=0, high = n - 1;
    

    while (mid <=high)
    {
        if (a[mid] == 0)
        {
            swap(a[low++], a[mid++]);
            
        }
        else if (a[mid] == 1)
        mid++;
        else if (a[mid] == 2)
        {
            swap(a[high--], a[mid]);
            
        }
    }
}