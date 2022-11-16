#include <bits/stdc++.h>

using namespace std;

class StringSet {
private:
    set<string> strings;
public:
    StringSet();

    StringSet(const string &s);

    StringSet(ifstream stream);

    StringSet(const set<string> &strings);

    void addString(const string &s);

    void removeString(const string &s);

    void clear();

    void print();

    double computeSimilatiry(const StringSet &other);

    StringSet friend operator+(const StringSet &a, const StringSet &b);

    StringSet friend operator*(const StringSet &a, const StringSet &b);
};

int main() {
    StringSet a("World Hello"), b("Hello Salah World");
    cout << "Similarity between a and b = " << a.computeSimilatiry(b) << endl;
    return 0;
}

StringSet::StringSet() : strings(set<string>()) {}

StringSet::StringSet(const string &s) : strings(set<string>()) {
    stringstream ss;
    ss << s;
    string cur;
    while (ss >> cur) {
        string filtered;
        for (char c: cur) {
            if (isalpha(c)) {
                filtered += (char) tolower(c);
            }
        }
        strings.insert(filtered);
    }
}

StringSet::StringSet(ifstream stream) : strings(set<string>()) {
    string cur;
    while (stream >> cur) {
        string filtered;
        for (char c: cur) {
            if (isalpha(c)) {
                filtered += (char) tolower(c);
            }
        }
        strings.insert(filtered);
    }
}

StringSet::StringSet(const set<string> &strings) : strings(strings) {
}

StringSet operator+(const StringSet &a, const StringSet &b) {
    set<string> un = b.strings;
    for (const auto &word: a.strings)
        un.insert(word);
    StringSet res(un);
    return res;
}

StringSet operator*(const StringSet &a, const StringSet &b) {
    set<string> inter;
    for (const auto &word: a.strings) {
        if (b.strings.count(word)) {
            inter.insert(word);
        }
    }
    StringSet res(inter);
    return res;
}

void StringSet::addString(const string &s) {
    StringSet::strings.insert(s);
}

void StringSet::removeString(const string &s) {
    StringSet::strings.erase(s);
}

void StringSet::clear() {
    StringSet::strings.clear();
}

void StringSet::print() {
    for (const auto &word: StringSet::strings) {
        cout << word << " \n"[word == *StringSet::strings.rbegin()];
    }
}

double StringSet::computeSimilatiry(const StringSet &other) {
    StringSet inter = *this * other;
    double res = inter.strings.size() / sqrt(this->strings.size()) / sqrt(other.strings.size());
    return res;
}