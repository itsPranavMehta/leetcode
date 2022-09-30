class Solution {
public:
    // comments below are pretty awesome!
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // use walls to record buildings; left wall is an insertion event, and right wall is a deletion event
        vector<pair<int, int>> walls;
        vector<vector<int>>ans;                  // first: x, second: height
        for (auto b : buildings) {
            // push in left / right walls
            // let left wall has negative height to ensure left wall goes to multiset first if with same 'x' as right wall
            walls.push_back(make_pair(b[0], -b[2]));        //have taken it negative so it appears before if some other wall has ending at this very location! with same height!
            walls.push_back(make_pair(b[1], b[2]));
        }
        
        sort(walls.begin(), walls.end());                   // sort walls
        
        multiset<int> leftWallHeights = {0};                // keep left wall heights sorted; dummy '0' for convenience
        int top = 0;                                        // current max height among leftWallHeights
        for (auto w : walls) 
        {
            // it's a left wall, insert the height
            if (w.second < 0)   leftWallHeights.insert(-w.second);                                                    // it's a right wall, delete the height from the multiset -> leftWallHeights;
            else    leftWallHeights.erase(leftWallHeights.find(w.second));
            
            // mark a skyline point if top changes
            if (*leftWallHeights.rbegin() != top) ans.push_back({w.first, top= *leftWallHeights.rbegin()});
        }
        
        return ans;
}
};