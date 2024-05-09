#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> symptomChecker = {
    {"headache", "Possible causes: stress, dehydration, migraine."},
    {"fever", "Possible causes: infection, flu, cold."},
    {"cough", "Possible causes: respiratory infection, allergies, asthma."},
    {"fatigue", "Possible causes: lack of sleep, anemia, thyroid problems."},
    {"nausea", "Possible causes: food poisoning, stomach flu, migraine."},
    {"back_pain", "Possible causes: muscle strain, poor posture, herniated disc."},
    {"sore_throat", "Possible causes: viral infection, bacterial infection, allergies."},
    {"shortness_of_breath", "Possible causes: asthma, pneumonia, heart disease."},
    {"joint_pain", "Possible causes: arthritis, injury, lupus."},
    {"abdominal_pain", "Possible causes: indigestion, gastritis, appendicitis."}
};

int main() {
    string symptom;

    while (true) {
        cout << "Enter your symptom (or type 'exit' to quit): ";
        cin >> symptom;

        if (symptom == "exit") {
            cout << "Exiting program..." << endl;
            break;
        }

        if (symptomChecker.find(symptom) != symptomChecker.end()) {
            cout << "Possible causes: " << symptomChecker[symptom] << endl;
        } else {
            cout << "No information available for \"" << symptom << "\"" << endl;
        }
    }

    return 0;
}
