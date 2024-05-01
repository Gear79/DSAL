#include <iostream>
#include <queue>
#include <string>


struct Patient {
    std::string name;
    int priority; 

   
    bool operator<(const Patient& other) const {
        return priority < other.priority;
    }
};


class PatientComparator {
public:
    bool operator()(const Patient& p1, const Patient& p2) {
        return p1.priority < p2.priority;
    }
};

int main() {
    std::priority_queue<Patient, std::vector<Patient>, PatientComparator> hospitalQueue;

    
    hospitalQueue.push({"Rahul Gandhi", 2}); // Serious patient
    hospitalQueue.push({"Ambani", 1}); // Non-serious patient
    hospitalQueue.push({"Alexa", 0}); // General checkup patient
    hospitalQueue.push({"tailor swift", 2}); // Another serious patient
    hospitalQueue.push({"Emma watson", 1}); // Another non-serious patient

   
    std::cout << "Patients being served:\n";
    while (!hospitalQueue.empty()) {
        Patient currentPatient = hospitalQueue.top();
        hospitalQueue.pop();

 
        std::string priorityLabel;
        if (currentPatient.priority == 0)
            priorityLabel = "General Checkup";
        else if (currentPatient.priority == 1)
            priorityLabel = "Non-serious";
        else
            priorityLabel = "Serious";

        std::cout << "Patient: " << currentPatient.name << " (Priority: " << priorityLabel << ")\n";
    }

    return 0;
}
