#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <clocale>
using namespace std;

void main() 
{
    setlocale(LC_ALL, "Ru");

    string text = "В недрах тундры выдры в гетрах тырят в вёдра ядра кедров\n"
        "Выдрав с выдры в тундре гетры, вытру выдрой ядра кедра,\n"
        "вытру гетрой выдре морду выдру в тундру, ядра в вёдра.";

    regex pattern("\\bвыд[^ ]*");
    smatch match;
    vector<string> matches;

    while (regex_search(text, match, pattern)) {
        matches.push_back(match.str(0));
        text = match.suffix().str();
    }

    cout << "Найденные слова:" << endl;
    for (const string& word : matches) {
        cout << word << endl;
    }
}