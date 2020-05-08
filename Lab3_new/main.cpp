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
    // Sets
    set <string> strset;
    strset.insert("bug");
    strset.insert("horse");
    strset.insert("horse");
    set<string>::iterator findit;
    findit = strset.find("horse");
    cout << "Found horse "<< *findit<<endl;
    for (set<string>::iterator it=strset.begin(); it!=strset.end(); ++it)
        cout << ' ' << *it;
    cout << endl;
    
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
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;
    for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it)
        cout << ' ' << *it;
    cout << endl;
    
    string state = "";
    map<string, string> wordmap;
    string last="";
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap[last]=*it;
        last = *it;
    }
    for (int i = 0; i < 100; i++) {
        cout << wordmap[state] << " ";
        state = wordmap[state];
    }
    map<list<string>, vector<string>> wordmap1;
    list<string> stateList;
    for (int i = 0; i < 100; i++) {
        stateList.push_back("");
    }
                        
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap1[stateList].push_back(*it);
        stateList.push_back(*it);
        stateList.pop_front();
    }
    state.clear();
    for (int i = 0; i < 100; i++) {
        stateList.push_back("");
    }
    for (int i = 0; i < 100; i++) {
        int ind = rand() % wordmap[state].size();
        cout << wordmap1[stateList][ind] << " ";
        stateList.push_back(wordmap1[stateList][ind]);
        stateList.pop_front();
    }
}