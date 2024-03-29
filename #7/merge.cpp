
#define MAX 20

int a[MAX];

void merge(int low, int mid, int high)
{
    int* left = new int[mid - low + 1];
    int* right = new int[high - mid];


    int n1 = mid - low + 1;
    int n2 = high - mid;
    int i;
    int j;

    // left
    for (i = 0; i < n1; i++)
        left[i] = a[i + low];

    // right
    for (i = 0; i < n2; i++)
        right[i] = a[i + mid + 1];

    int k = low;
    i = j = 0;


    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }


    while (i < n1) {
        a[k++] = left[i++];
    }


    while (j < n2) {
        a[k++] = right[j++];
    }
}


void merge_sort(int low, int high)
{

    int mid = low + (high - low) / 2;
    if (low < high) {


        merge_sort(low, mid);


        merge_sort(mid + 1, high);


        merge(low, mid, high);
    }
}


