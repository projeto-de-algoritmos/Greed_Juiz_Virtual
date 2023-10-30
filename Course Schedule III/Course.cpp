#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int currentTime = 0;
        int numCourses = 0;
        priority_queue<int> maxHeap;

        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Ordenar por deadline
        });

        for (const vector<int>& course : courses) {
            if (currentTime + course[0] <= course[1]) { // Se não ultrapassar o tempo, coloca na lista de cursos
                currentTime += course[0];
                maxHeap.push(course[0]);
                numCourses++;
            } else { //se ultrapassar, pega o de maior duração e troca pelo atual
                if (!maxHeap.empty()) {
                    int maxDuration = maxHeap.top();
                    if (course[0] < maxDuration) {
                        currentTime += course[0] - maxDuration;
                        maxHeap.pop();
                        maxHeap.push(course[0]);
                    }
                }
            }
        }

        return numCourses;
    }
};
