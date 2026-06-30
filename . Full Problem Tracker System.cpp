#include <bits/stdc++.h>
using namespace std;

struct Problem {
    string name;
    string topic;
    int difficulty; // 1-easy, 2-medium, 3-hard
    string date;
};

class LeetMentor {
private:
    vector<Problem> problems;
    map<string, int> topicCount;

public:

    void addProblem(string name, string topic, int difficulty, string date) {
        Problem p = {name, topic, difficulty, date};
        problems.push_back(p);
        topicCount[topic]++;
    }

    void showAllProblems() {
        cout << "\nSolved Problems:\n";
        for (auto &p : problems) {
            cout << p.name << " | " << p.topic 
                 << " | Difficulty: " << p.difficulty 
                 << " | Date: " << p.date << endl;
        }
    }

    void showTopicAnalysis() {
        cout << "\nTopic Analysis:\n";
        for (auto &t : topicCount) {
            cout << t.first << " -> " << t.second << " problems\n";
        }
    }

    string getWeakTopic() {
        string weakTopic = "";
        int minCount = INT_MAX;

        for (auto &t : topicCount) {
            if (t.second < minCount) {
                minCount = t.second;
                weakTopic = t.first;
            }
        }

        return weakTopic;
    }

    double getProgressScore() {
        if (problems.empty()) return 0;

        int score = 0;
        for (auto &p : problems) {
            score += p.difficulty;
        }

        return (double)score / problems.size();
    }

    void showDashboard() {
        cout << "\n===== LEETMENTOR DASHBOARD =====\n";
        cout << "Total Problems Solved: " << problems.size() << endl;
        cout << "Average Difficulty Score: " << getProgressScore() << endl;
        cout << "Weak Topic: " << getWeakTopic() << endl;
    }
};

int main() {
    LeetMentor lm;

    lm.addProblem("Two Sum", "Arrays", 1, "01-07-2026");
    lm.addProblem("Binary Tree Traversal", "Trees", 2, "02-07-2026");
    lm.addProblem("DP Knapsack", "DP", 3, "03-07-2026");
    lm.addProblem("Stack Valid Parentheses", "Stack", 2, "04-07-2026");

    lm.showAllProblems();
    lm.showTopicAnalysis();
    lm.showDashboard();

    return 0;
}
