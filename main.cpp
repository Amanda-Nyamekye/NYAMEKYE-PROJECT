#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Define the Patient class
class Patient {
public:
    Patient(const std::string& name, int age, const std::string& gender)
        : name(name), age(age), gender(gender) {}

    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getGender() const { return gender; }

private:
    std::string name;
    int age;
    std::string gender;
};

// Define the MedicalRecord class
class MedicalRecord {
public:
    MedicalRecord(const std::string& diagnosis, const std::string& medication)
        : diagnosis(diagnosis), medication(medication) {}

    std::string getDiagnosis() const { return diagnosis; }
    std::string getMedication() const { return medication; }

private:
    std::string diagnosis;
    std::string medication;
};

// Define the MedicalInformationSystem class
class MedicalInformationSystem {
public:
    void addPatient(const Patient& patient) {
        patients.push_back(patient);
    }

    void addMedicalRecord(const Patient& patient, const MedicalRecord& record) {
        medicalRecords[patient.getName()].push_back(record);
    }

    void displayPatientInfo() {
        for (const auto& patient : patients) {
            std::cout << "Name: " << patient.getName() << "\n";
            std::cout << "Age: " << patient.getAge() << "\n";
            std::cout << "Gender: " << patient.getGender() << "\n\n";
        }
    }

    void displayMedicalRecords(const Patient& patient) {
        const auto& records = medicalRecords[patient.getName()];
        std::cout << "Medical Records for " << patient.getName() << ":\n";
        for (const auto& record : records) {
            std::cout << "Diagnosis: " << record.getDiagnosis() << "\n";
            std::cout << "Medication: " << record.getMedication() << "\n\n";
        }
    }

private:
    std::vector<Patient> patients;
    std::unordered_map<std::string, std::vector<MedicalRecord>> medicalRecords;
};

int main() {
    MedicalInformationSystem medSystem;

    Patient patient1("Asante Boah Rainhard", 30, "Male");
    Patient patient2("Amanda Nyamekye", 19, "Female");

    MedicalRecord record1("Common Cold", "Antibiotics");
    MedicalRecord record2("Fractured Arm", "Cast and Painkillers");

    medSystem.addPatient(patient1);
    medSystem.addPatient(patient2);

    medSystem.addMedicalRecord(patient1, record1);
    medSystem.addMedicalRecord(patient2, record2);

    medSystem.displayPatientInfo();
    medSystem.displayMedicalRecords(patient1);
    medSystem.displayMedicalRecords(patient2);

    return 0;
}
