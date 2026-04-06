#include <memory_resource>
pmr::unsynchronized_pool_resource pool;
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const unsigned lb=30000;
        pmr::unordered_set<unsigned> obSet(&pool);
        obSet.reserve(obstacles.size());
        for(auto& ob: obstacles){
            const unsigned x=ob[0]+lb, y=ob[1]+lb;
            obSet.insert((x<<16)+y);
        }

        const int dir[4][2]={{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int x=0, y=0, dx=0, dy=1, face=0, maxD2=0;
        for(int c: commands){
            switch(c){
                case -2: face=(face+1)&3; dx=dir[face][0]; dy=dir[face][1]; break;
                case -1: face=(face+3)&3; dx=dir[face][0]; dy=dir[face][1]; break;
                default:
                //    cout<<"\nc="<<c<<" face="<<face<<":";
                    for(int i=0; i<c; i++){
                        x+=dx, y+=dy;
                        if (obSet.count(((x+lb)<<16)+y+lb)) {
                            x-=dx;  // previous move
                            y-=dy;
                            break;
                        }
                    //    cout<<"("<<x<<","<<y<<"),";
                        maxD2=max(maxD2, x*x+y*y);
                    }
            }
        }
        return maxD2;
    }
};
