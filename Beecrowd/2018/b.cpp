#include <iostream>
#include <queue>
using namespace std;
 
// Function to print the data of
// the priority queue ordered by first
void showpq(
    priority_queue<pair<int, pair<int,int>> > g)
{
    // Loop to print the elements
    // until the priority queue
    // is not empty
    while (!g.empty()) {
        cout << g.top().first
             << " " << g.top().second.first
             << " " << g.top().second.second
             << endl;
        g.pop();
    }
    cout << endl;
}
 
// Driver Code
int main()
{
    priority_queue<pair<int, pair<int,int>> > p1;
 
    // Insertion of elements
    p1.push({5, {5, 3}});
    p1.push({5, {5, 2}});
    p1.push({5, {6,0}});
    p1.push({7, {3,0}});
    p1.push({9, {4,0}});
    showpq(p1);
    return 0;
}
