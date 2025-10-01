#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

string toLowerStr(const string& s) {
    string r = s;
    transform(r.begin(), r.end(), r.begin(), [](unsigned char c){ return tolower(c); });
    return r;
}

pair<bool,string> checkGuess(const string& ideal, const string& guess) {
    string lowIdeal = toLowerStr(ideal);
    string lowGuess = toLowerStr(guess);
    int n = (int)lowIdeal.size();

    vector<bool> exact(n, false);
    unordered_map<char,int> remaining;

    for (int i = 0; i < n; ++i) {
        if (lowGuess[i] == lowIdeal[i]) exact[i] = true;
        else remaining[lowIdeal[i]]++;
    }

    string feedback;
    bool allExact = true;
    for (int i = 0; i < n; ++i) {
        char orig = guess[i];
        if (exact[i]) {
            feedback += '['; feedback += orig; feedback += ']';
        } else if (remaining[lowGuess[i]] > 0) {
            feedback += '('; feedback += orig; feedback += ')';
            remaining[lowGuess[i]]--;
            allExact = false;
        } else {
            feedback += orig;
            allExact = false;
        }
        if (i < n - 1) feedback += ' ';
    }

    return { allExact, feedback };
}

int main() {
    vector<string> words = {
        "a","to","sun","pear","apple",
        "orange","tomatos","bluebird","pineapple","strawberry"
    };

    int lengthChoice;
    cout << "Choose the length of the word (1-10): " << flush;
    if (!(cin >> lengthChoice)) return 0;

    if (lengthChoice < 1 || lengthChoice > 10) {
        cout << "Invalid choice. Exiting." << endl;
        return 0;
    }

    string ideal = words[lengthChoice - 1];
    cout << "The word has " << ideal.size() << " letters. Try to guess it!" << endl;

    string guess;
    bool won = false;
    int maxAttempts = 6;

    for (int attempt = 1; attempt <= maxAttempts; attempt++) {
        cout << "Attempt " << attempt << "/" << maxAttempts << " - Enter your guess: " << flush;
        if (!(cin >> guess)) break;

        if ((int)guess.size() != (int)ideal.size()) {
            cout << "Your guess must have exactly " << ideal.size() << " letters." << endl;
            attempt--; 
            continue;
        }

        auto [isMatch, feedback] = checkGuess(ideal, guess);
        if (isMatch) {
            cout << "Congratulations, The word was: " << ideal << endl;
            won = true;
            break;
        } else {
            cout << feedback << endl;
        }
    }

    if (!won) {
        cout << "Game Over. The word was: " << ideal << endl;
    }

    return 0;
}
