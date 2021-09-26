/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> courses(numCourses);
        vector<int> degree(numCourses, 0);
        for (auto& prerequisty : prerequisites) {
            courses[prerequisty[1]].push_front(prerequisty[0]);
            degree[prerequisty[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if(degree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            numCourses--;
            for(auto i : courses[cur])
                if(--degree[i] == 0)
                    q.push(i);
        }
        return numCourses == 0;
    }
};
// @lc code=end

