class ds
{
    int *rank, *parent, n;
    int numOfSets;
    int *childCount;
    int maxChild;

public:
    ds(int n)
    {
        rank = new int[n];
        parent = new int[n];
        childCount = new int[n];
        this->n = n;
        this->numOfSets = n;
        this->maxChild = 0;
        makeSet();
    }

    void makeSet()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            childCount[i] = 0;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void Union(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);

        if (xset == yset)
            return;

        if (rank[xset] < rank[yset])
        {
            parent[xset] = yset;
            childCount[yset] += 1 + childCount[xset];
            maxChild = max(maxChild, childCount[yset]);
        }
        else if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
            childCount[xset] += 1 + childCount[yset];
            maxChild = max(maxChild, childCount[xset]);
        }
        else
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
            childCount[xset] += 1 + childCount[yset];
            maxChild = max(maxChild, childCount[xset]);
        }
        numOfSets--;
    }

    void temp()
    {
        for (int i = 1; i < n; i++)
        {
            cout << childCount[i] << " ";
        }
        cout << endl;
    }

    int numSets()
    {
        return numOfSets;
    }

    int maxSet()
    {
        return (1 + maxChild);
    }
};
