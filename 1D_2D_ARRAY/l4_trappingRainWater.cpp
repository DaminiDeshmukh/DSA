class Solution {
    public:
        vector <int> getLeftMax(vector <int>& height,int& n)
        {
            vector <int> LeftMax(n);
            LeftMax[0]=height[0];
            for(int i=1;i<n;i++)
            {
                LeftMax[i]=max(LeftMax[i-1],height[i]);
            }
            return LeftMax;
    
        }
        vector <int> getRightMax(vector <int>& height,int& n)
        {
            vector <int> RightMax(n);
            RightMax[n-1]=height[n-1];
            for(int i=n-2;i>=0;i--)
            {
                RightMax[i]=max(RightMax[i+1],height[i]);
            }
            return RightMax;
            
        }
        int trap(vector<int>& height) {
            int n=height.size();
            vector <int> LeftMax= getLeftMax(height,n);
            vector <int> RightMax=getRightMax(height,n);
            int sum=0;
            for(int i=0;i<n;i++)
            {
                int h=min(LeftMax[i],RightMax[i])-height[i];
                sum+=h;
            }
            return sum;
        }
    };