#include <set>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;
int main(int argc, char *argv[])
{
    vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    ifstream in(argv[1]);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	        tokens.push_back(nopunct);
		    unique.insert(nopunct);
		    // cout << token<<endl;
	    }
    }

    // map<string, vector<string>> wordmap;
    // string state = "";
    // for(vector<string>::iterator it=tokens.begin(); it !=tokens.end(); it++) {
    //     wordmap[state].push_back(*it);
    //     state = *it;
    // }
    // state = "";
    // srand(time(0));
    // for (int i = 0; i < 100; i++) {
    //     int ind = rand() % wordmap[state].size();
    //     cout << wordmap[state][ind] << " ";
    //     state = wordmap[state][ind];
    // }
    // cout << endl;

    map<list<string>, vector<string>> wordmap;
    list<string> state;
    for (int i = 0; i < 4; ++i) {
        state.push_back("");
    }
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); ++it) {
        wordmap[state].push_back(*it);
        state.push_back(*it);
        state.pop_front();
    }
    state.clear();
    for(int i = 0; i < 4; ++i) {
        state.push_back("");
    }
    srand(time(0));
    for (int i = 0; i < 100; ++i) {
        int ind= rand() % wordmap[state].size();
        cout << wordmap[state][ind] << " ";
        state.push_back(wordmap[state][ind]);
        state.pop_front();
    }
    cout << endl;




    // cout << "Number of words "<<tokens.size()<<endl;
    // cout << "Number of unique words "<<unique.size()<<endl;
    // map<list<string>, vector<string>> wordmap;
    // list<string> state;
    // for (int i = 0; i < 100; ++i) {
    //     state.push_back("");
    // }
    // for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    // {
    //     state.push_back(*it);
    // }
    // srand(time(0));
    // for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
    //     wordmap[state].push_back(*it);
    //     state.push_back(*it);
    //     state.pop_front();
    // }
    // cout << " here" << " ";
    // cout << wordmap[state].size();
    // state.clear();
    // for (int i = 0; i < 100; ++i) {
    //     state.push_back(" ");
    // }
    // for (int i = 0; i < 100; ++i) {
    //     int ind = rand() % wordmap[state].size();
    //     cout << wordmap[state][ind] << " ";
    //     state.push_back(wordmap[state][ind]);
    //     state.pop_front();
    // }
    // for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it)
    //     cout << ' ' << *it;
    // cout << endl;
    
    // string last="";
    // for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
    //     wordmap[last]=*it;
    //     last = *it;
    // }
    // for (int i = 0; i < 100; i++) {
    //     cout << wordmap[state] << " ";
    //     state = wordmap[state];
    // }
    // cout << endl;
    // map<list<string>, vector<string>> wordmap;
    // list<string> state;
    // for (int i = 0; i < 100; i++) {
    //     state.push_back("");
    // }
                        
    // for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
    //     wordmap[state].push_back(*it);
    //     state.push_back(*it);
    //     state.pop_front();
    // }
    // state.clear();
    // for (int i = 0; i < 100; i++) {
    //     state.push_back("");
    // }
    // srand(time(0));
    // for (int i = 0; i < 100; i++) {
    //     int ind = rand() % wordmap[state].size();
    //     cout << ind << wordmap[state].size();
    //     cout << wordmap[state][ind] << " ";
    //     state.push_back(wordmap[state][ind]);
    //     state.pop_front();
    // }
    // cout << endl;
}