class DisjointSet 
{
public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;
    int components;

    DisjointSet(int n){
        components = n;
        parent.resize(n+1);
        size.resize(n+1, 1);
        rank.resize(n+1, 0);
        
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int v)
    {
        if(v == parent[v]){
            return v;
        }
        
        // find parent using path compression
        
        return parent[v] = findUPar(parent[v]);
    }
    
    void unionBySize(int a, int b){
        int ulp_a = findUPar(a);
        int ulp_b = findUPar(b);
        
        if(ulp_a != ulp_b){
            if(size[ulp_a] < size[ulp_b]){
                swap(ulp_a, ulp_b);
            }
            parent[ulp_b] = ulp_a;
            size[ulp_a] += size[ulp_b];
            components--;
        }
    }
    void unionByRank(int a, int b){
        int ulp_a = findUPar(a);
        int ulp_b = findUPar(b);
        if(ulp_a != ulp_b){
            if(rank[ulp_a] < rank[ulp_b]){
                swap(ulp_a, ulp_b);
            }
            parent[ulp_b] = ulp_a;
            rank[ulp_a] += 1;
        }
    }

    // Returns true if all nodes get merged to one.
    bool isConnected() {
        return components == 1;
    }
};
