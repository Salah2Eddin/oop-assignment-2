#include <bits/stdc++.h>

using namespace std;

class Process {
protected:
    string processName;
    int processID;
    string memory;
public:
    const string &getProcessName() const;

    void setProcessName(const string &processName);

    int getProcessId() const;

    void setProcessId(int processId);

    const string &getMemory() const;

    void setMemory(const string &memory);

public :
    Process(string name, int id, string memory);

};

Process::Process(string name, int id, string memory) {
    this->processName = name;
    this->processID = id;
    this->memory = memory;
}

const string &Process::getProcessName() const {
    return processName;
}

void Process::setProcessName(const string &processName) {
    Process::processName = processName;
}

int Process::getProcessId() const {
    return processID;
}

void Process::setProcessId(int processId) {
    processID = processId;
}

const string &Process::getMemory() const {
    return memory;
}

void Process::setMemory(const string &memory) {
    Process::memory = memory;
}


class TaskManager {
protected:
    vector<Process> numProcess[2];
public :
    void loadProcess();

    void print(int sortedBy);

    void sortMemory();

    void sortName();
};

void TaskManager::loadProcess() {
    system("tasklist > process.txt");
    ifstream file("process.txt");
    string temp;
    for (int i = 0; i < 3; ++i) {
        getline(file,temp);
    }
    while (!file.eof()) {
        getline(file,temp);
        if(temp.empty())break;
        stringstream s;
        s << temp;
        string name,id,memory;
        s >> name;
        s >> id;
        while(!isdigit(id[0])){
            name += " " + id;
            s >> id;
        }
        s >> temp;
        s >> temp;
        s >> memory;
        numProcess[0].emplace_back(name, stoi(id),memory);
        numProcess[1].emplace_back(name, stoi(id),memory);
    }
    auto sortByName = [&](Process &p1, Process &p2) { return p1.getProcessName() < p2.getProcessName();};
    auto sortById = [&](Process &p1, Process &p2) { return p1.getProcessId() < p2.getProcessId();};
    sort(numProcess[0].begin(), numProcess[0].end(),sortByName);
    sort(numProcess[1].begin(), numProcess[1].end(),sortById);
}

void TaskManager::print(int sortedBy) {
    cout << setw(30) << left << "Image Name" << setw(10) << right << "PID" << setw(15) << right << "Mem Usage" << endl;
    cout << setw(30) << left << "===========" << setw(10) << right << "=====" << setw(15) << right << "========="
         << endl;

    for (auto &val: numProcess[sortedBy]) {
        cout << setw(30) << left << val.getProcessName();
        cout << setw(10) << right << val.getProcessId();
        cout << setw(13) << right << val.getMemory() << "K" << endl;
    }
}



int main() {
    TaskManager taskManager;
    taskManager.loadProcess();

    // Display sorted by name
    taskManager.print(0);

    // Display sorted by Id
    taskManager.print(1);
}
