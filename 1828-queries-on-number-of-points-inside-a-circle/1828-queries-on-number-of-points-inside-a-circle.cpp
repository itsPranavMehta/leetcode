class Solution {
private:
    int squaredDistance(int x1,int y1,int x2,int y2){     //return
        return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    }
public:
    // can reduce "average complexity" by sorting points on the basis of either x or y coords (say x). and then for any query just searching for points which lie within [x1-r,x1+r]
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto& q:queries){
            int x1=q[0],y1=q[1],r=q[2],pointsInside=0;
            for(auto& p:points){
                int x2=p[0],y2=p[1];
                if(squaredDistance(x1,y1,x2,y2)<=r*r)   pointsInside++;
            }
            res.push_back(pointsInside);
        }   
        return res;
    }
};