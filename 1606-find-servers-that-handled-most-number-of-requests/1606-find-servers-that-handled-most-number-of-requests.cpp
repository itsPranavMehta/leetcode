class Solution {
private:
    void checkFreeProcessors(int time, set<int>& availProcessors, set<pair<int,int>>& queProcessors){
        for(auto it=queProcessors.begin();it!=queProcessors.end() && it->first<=time;){
            availProcessors.insert(it->second);
            auto curr=it++;
            queProcessors.erase(curr);
        }
    }
    
    void assignProcessors(int id,int finishTime, set<int>& availProcessors, vector<int>& tasksHandled,set<pair<int,int>>& queProcessors){
        auto it=availProcessors.lower_bound(id);
        if(it==availProcessors.end())   it=availProcessors.begin();
        
        if(it==availProcessors.end())   return;
        tasksHandled[*it]++;
        queProcessors.insert({finishTime,*it});
        availProcessors.erase(it);
    }
    
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        //have a set which contains the list of all available servers, at time 0 all servers are available
        //have a variable counter which notices the current time and another set of type pair<int,int> where 1st int denotes the arrival time+load time and 2nd int denotes the processor id, whenever a task arrives we'd remove all the processor from this set which would've been done with the work now.
        set<int> availProcessors;
        set<pair<int,int>> queProcessors;  // this denotes the processors which are being used.
        vector<int> tasksHandled(k,0);
        
        for(int i=0;i<k;i++)    availProcessors.insert(i);
        
        for(int i=0;i<arrival.size();i++){
            int arvl=arrival[i],ld=load[i];
            int finishTime=arvl+ld;
            checkFreeProcessors(arvl,availProcessors,queProcessors);
            assignProcessors(i%k,finishTime,availProcessors,tasksHandled,queProcessors);
            
        }
        
        int mostTasksHandled=*max_element(tasksHandled.begin(),tasksHandled.end());
        vector<int> busiest;
        for(int i=0;i<k;i++){
            if(tasksHandled[i]==mostTasksHandled) busiest.push_back(i);
        }
        
        return busiest;;
    }
};