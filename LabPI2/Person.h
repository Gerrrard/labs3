#pragma once
#include <ctime>
#include <string>
#include <fstream>

using namespace std;
typedef struct PersonID {
    int series = 0;
    int number = 0;

    bool operator==(const PersonID& id) const {
        return series == id.series && number == id.number;
    }
    bool operator!=(const PersonID& id) const {
        return series != id.series || number != id.number;
    }
} PersonID;

class Person {
private:
    PersonID id{};
    string firstName;
    string middleName;
    string lastName;
    int birthDate;
public:
    Person() {};
    Person(const PersonID& id, string firstName, string middleName, string lastName, int birthDate) {
        this->id = id;
        this->firstName = firstName;
        this->middleName = middleName;
        this->lastName = lastName;
        this->birthDate = birthDate;
    };
    Person(int a) {
        this->id.number = a;
        this->id.series = a;
        this->birthDate = a;
        this->middleName = "";
        this->lastName = "";
    }

    Person(const Person& person) :
        Person(person.id, person.firstName,
            person.middleName, person.lastName, person.birthDate) {};

    PersonID GetID() const {
        return id;
    }
    string GetFirstName() {
        return firstName;
    }
    string GetMiddleName() {
        return middleName;
    }
    string GetLastName() {
        return lastName;
    }
    string GetFullName() const {
        return firstName + " " + middleName + " " + lastName;
    }
    int GetBirthDate() const {
        return birthDate;
    }

    friend ostream& operator<<(ostream& out, const Person& person) {
        out << "id: ";
        out << person.id.series;
        out << " ";
        out << person.id.number;
        out << ", full name: ";
        out << person.GetFullName();
        out << ", birth date: ";
        out << person.GetBirthDate();
        return out;
    }

    friend istream& operator>>(istream& in, Person& person) {
        in >> person.id.number;
        in >> person.id.series;
        in >> person.firstName;
        in >> person.middleName;
        in >> person.lastName;
        in >> person.birthDate;
        return in;
    }

    bool operator<(const Person& person) const {
        return GetFullName() < person.GetFullName();
    }
    bool operator<=(const Person& person) const {
        return GetFullName() <= person.GetFullName();
    }
    bool operator>(const Person& person) const {
        return GetFullName() > person.GetFullName();
    }
    bool operator>=(const Person& person) const {
        return GetFullName() >= person.GetFullName();
    }
    bool operator==(const Person& person) const {
        return GetFullName() == person.GetFullName() && GetID() == person.GetID();
    }
    bool operator!=(const Person& person) const {
        return GetFullName() != person.GetFullName() || GetID() != person.GetID();
    }
};