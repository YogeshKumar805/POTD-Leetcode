using PT = std::pair<int, int>;
using UP = PT;

class TaskManager {
public:
    std::unordered_map<int, UP> t_up;
    std::set<PT> pt;
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& utp: tasks) {
            add(utp[0], utp[1], utp[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        t_up.emplace(taskId, UP{userId, priority});
        pt.emplace(priority, taskId);
    }
    
    void edit(int taskId, int newPriority) {
        auto&[user, priority] = t_up[taskId];
        auto h = pt.extract({priority, taskId});
        priority = h.value().first = newPriority;
        pt.insert(std::move(h));
    }
    
    void rmv(int taskId) {
        auto it = t_up.find(taskId);
        pt.erase(PT{it->second.second, taskId});
        t_up.erase(it);
    }
    
    int execTop() {
        if (pt.empty()) return -1;
        auto pt_it = std::prev(pt.end());
        auto t_up_it = t_up.find(pt_it->second);
        int user = t_up_it->second.first;
        t_up.erase(t_up_it);
        pt.erase(pt_it);
        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
