#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

bool isValidEventCode(const string &code) {
    if (code.size() != 3) 
        return false ;
    if (code[0] < 'A' || code[0] > 'G') 
        return false ;
    if (code[1] < '0' || code[1] > '9') 
        return false ; 
    if (code[2] < '0' || code[2] > '9') 
        return false ; 
    return true;
}

void processTestCase(const string &events) {
    int n = events.size();
    vector<string> validEvents;
    for ( int i = 0; i < n; i += 3 ) {
        if ( !isValidEventCode( events.substr(i, 3) ) ) {
            cout << "-1 " << events.substr(i, 3) << '\n' ;
            return ;
        }
        validEvents.push_back(events.substr(i, 3));
    }

    // Sliding window to find the longest unique subsequence
    unordered_set<string> currentSet;
    unordered_map<string, int> categoryCount;
    int maxLength = 0, bestStart = 0;
    int start = 0;
    
    for (int end = 0; end < validEvents.size(); ++end) {
        string event = validEvents[end];
        
        // If we find a repeated event, slide the window from the start
        while (currentSet.find(event) != currentSet.end()) {
            currentSet.erase(validEvents[start]);
            categoryCount[validEvents[start]]--;
            start++;
        }
        
        currentSet.insert(event);
        categoryCount[event]++;
        if (end - start + 1 > maxLength) {
            maxLength = end - start + 1;
            bestStart = start;
        }
    }

    // Get the longest unique sequence
    vector<string> longestSeq(validEvents.begin() + bestStart, validEvents.begin() + bestStart + maxLength);
    
    // Count the number of instances.
    unordered_map<char, int> categoryCountFinal;
    for (const string &event : longestSeq) {
        categoryCountFinal[event[0]]++ ;
    }
    
    cout << maxLength << " ";
    for (const string &event : longestSeq) {
        cout << event << " ";
    }
    
    // Output the count of each category
    string categories[] = {"Competitions", "Entertainment", "Social Gatherings", "Dinners", "Processions", "Training Workshops", "Exams"};
    for (char c = 'A'; c <= 'G'; c++) {
        if (categoryCountFinal.find(c) != categoryCountFinal.end()) {
            cout << categoryCountFinal[c] << " " << categories[c - 'A'] << " ";
        }
    }
    cout << '\n' ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string events;
        cin >> events;
        processTestCase(events);
    }
    return 0;
}
