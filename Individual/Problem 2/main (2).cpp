#include <bits/stdc++.h>

#include <utility>
using namespace std;

class LabelGenerator{
protected:
    string word;
    int cnt;
public:
    LabelGenerator(string prefix, int start);

    virtual string nextLabel();
};

LabelGenerator :: LabelGenerator(string prefix, int start){
    this->word = std::move(prefix);
    this->cnt = start;
}

string LabelGenerator :: nextLabel(){
    string temp  = this->word + " " + to_string(this->cnt++);
    return temp;
}


class  FileLabelGenerator : public LabelGenerator{
private :
    ifstream file;
public :
    FileLabelGenerator(string prefix, int start, const string& fileName);
    string nextLabel() override;

};

FileLabelGenerator :: FileLabelGenerator(string prefix, int start, const string& fileName)
                        : LabelGenerator(std::move(prefix), start){
    this->file.open(fileName, ios::in);
}

string FileLabelGenerator :: nextLabel(){
    string sentence;
    getline(this->file,sentence);
    string temp  = this->word + " " + to_string(this->cnt++) + " " + sentence;
    return temp;
}



int main() {

    FileLabelGenerator figureLabels("Figure", 1, "labels.txt");
    LabelGenerator pointLabels("Point", 4);
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;
    }
    for(int i = 0; i < 4; ++i){
        cout << pointLabels.nextLabel() << endl;
    }
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;
    }
    for(int i = 0; i < 4; ++i){
        cout << pointLabels.nextLabel() << endl;
    }


}
