class Solution {
    // so am able to think of 2 ways to solve this question
    // 1 is the basic brute force-> for the square [x-r,x+r]*[y-r,y+r] check for all points which are inside the square.
    // the other way is using bianry search to lacate that in a certain axis (say x=c), what's the first and last y which lies inside the circle..
    // the complexity of first approach would be n*r*r,where n is the number of circles
    // the complexity for the other solution would be n*r*logr...
    // BUT IN THE SECOND METHOD, THE INTERSECTION OF CIRCLES WOULD CAUSE SOME PROBLEMS
    bool insideCircle(int x,int y,int x1,int y1,int r){
        return (x1-x)*(x1-x)+(y1-y)*(y1-y)<=r*r;
    }
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        unordered_map<int,set<int>> visited; // for all x coords which y has been visited;
        int points=0;
        for(auto& circle:circles){
            int x=circle[0],y=circle[1],r=circle[2];
            int x_start=x-r,x_end=x+r;
            int y_start=y-r,y_end=y+r;
            for(int x1=x_start;x1<=x_end;x1++){
                for(int y1=y_start;y1<=y_end;y1++){
                    if(insideCircle(x,y,x1,y1,r) && !visited[x1].count(y1)){
                        visited[x1].insert(y1);
                        points++;
                    }
                }
            }
        }
        return points;
        
    }
};