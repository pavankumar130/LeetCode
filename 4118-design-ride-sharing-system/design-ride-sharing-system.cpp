class RideSharingSystem {
    set<int>st;
    queue<int>rider;
    queue<int>driver;
public:
    RideSharingSystem() {

    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        st.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.size() != 0 && driver.size() != 0){
            vector<int> res = {driver.front(), rider.front()};
            driver.pop();
            rider.pop();
            return res;
        }

        return {-1, -1};
    }
    
    void cancelRider(int riderId) {
        if(st.find(riderId) != st.end()){
            queue<int>q;

            while(rider.size()){
                if(rider.front() == riderId){
                    rider.pop();
                    continue;
                }
                q.push(rider.front());
                rider.pop();
            }
            rider = q;
            st.erase(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */