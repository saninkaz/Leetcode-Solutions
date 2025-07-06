class DisjointSet{
    public:
    vector<int> size,parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }

    void UnionBySize(int u,int v){
        int up_u = findUPar(u);
        int up_v = findUPar(v);

        if(up_u == up_v) return;
        if(size[up_u]<size[up_v]){
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else if(size[up_u]>=size[up_v]){
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
        
    }
};



class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        
        

        int low = 0, high =1e9;
        int ans =-1;

        while(low<=high){
            int count =0;
            int mid = (low+high)/2;
            DisjointSet ds(n+1);
            for(int i=0;i<edges.size();i++){
                int u = edges[i][0];
                int v = edges[i][1];
                if(edges[i][2] > mid){
                ds.UnionBySize(u,v);
                }
            }

            for(int i=0;i<n;i++){
                if(ds.parent[i]==i) count++;
            }
                if(count >=k){
                    ans=mid;
                    high = mid -1;
                }
                else{
                    low = mid +1;
                }
        }

        return ans;
    }
};