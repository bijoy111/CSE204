class Heap
{
    int* heap;
    int maxsize;
    int currsize;
public:
    void build_heap(int s)
    {
        int j=s;
        while(j>1)
        {
            int p=j/2;
            if(heap[p]<heap[j])
            {
                int tmp=heap[p];
                heap[p]=heap[j];
                heap[j]=tmp;
                j=p;
            }
            else
            {
                break;
            }
        }
    }
    Heap(int size)
    {
        maxsize=size;
        heap=new int[maxsize+1];
        currsize=1;
    }
    Heap(std::vector<int>numbers)
    {
        maxsize=numbers.size();
        heap=new int[maxsize+1];
        currsize=1;
        for(int i=0; i<numbers.size(); i++)
        {
            heap[currsize]=numbers[i];
            currsize++;
            build_heap(currsize-1);
        }
    }
    void max_heapify(int i)
    {
        int l=2*i;
        int r=(2*i)+1;
        int largest=i;
        if(l<currsize&&heap[l]>heap[largest])
        {
            largest=l;
        }
        if(r<currsize&&heap[r]>heap[largest])
        {
            largest=r;
        }
        if(largest!=i)
        {
            int tmp=heap[largest];
            heap[largest]=heap[i];
            heap[i]=tmp;
            max_heapify(largest);
        }
    }
    void insert(int number)
    {
        heap[currsize]=number;
        currsize++;
        build_heap(currsize-1);
    }
    int size()
    {
        return currsize-1;
    }
    int getMax()
    {
        return heap[1];
    }
    void deleteKey()
    {
        heap[1]=heap[currsize-1];
        currsize--;
        max_heapify(1);
    }
    int* get_heap()
    {
        return heap;
    }
};
void heapsort(std::vector<int>&v)
{
    Heap h(v);
    int cnt=v.size();
    for(int i=0;i<cnt;i++)
    {
        v[i]=h.getMax();
        h.deleteKey();
    }
}
