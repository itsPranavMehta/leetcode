class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        multiset<int,greater<int>> unusedStations;
        int numFuelStations=0;
        for(auto& station:stations){
            int fuel=station[1];
            int pos=station[0];
            while(startFuel<pos && startFuel<target && unusedStations.size()){
                startFuel+=*unusedStations.begin();
                unusedStations.erase(unusedStations.begin());
                numFuelStations++;
            }
            unusedStations.insert(fuel);
            if(startFuel<pos && startFuel<target)   return -1;
            
        }
        while(unusedStations.size() && startFuel<target){
                startFuel+=*unusedStations.begin();
                unusedStations.erase(unusedStations.begin());
                numFuelStations++;
        }
        return startFuel>=target?numFuelStations:-1;
    }
};