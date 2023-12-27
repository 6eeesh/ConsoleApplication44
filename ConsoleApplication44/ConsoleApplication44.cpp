#include <iostream>
using namespace std;

/// <summary>
/// add the variables we will use
/// </summary>
class DateTime
{
private:
    int day;
    int month;
    int year;

public:

    /// <summary>
    /// a method to set day of birth
    /// </summary>
    /// <param name="day"></param>
    void SetDay(int day)
    {
        if (day > 0 && day <= 31) // TO DO: february 28-29, april june 30
        {
            this->day = day;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    /// <summary>
    /// a method to get day of birth
    /// </summary>
    /// <returns></returns>
    int GetDay() const
    {
        return day;
    }

    /// <summary>
    /// a method to set month of birth
    /// </summary>
    /// <param name="month"></param>
    void SetMonth(int month)
    {
        if (month >= 1 && month <= 12)
        {
            this->month = month;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    /// <summary>
    /// a method to get month of birth
    /// </summary>
    /// <returns></returns>
    int GetMonth() const
    {
        return month;
    }

    /// <summary>
    /// a method to set year of birth
    /// </summary>
    /// <param name="year"></param>
    void SetYear(int year)
    {
        this->year = year;
    }

    /// <summary>
    /// a method to get year of birth
    /// </summary>
    /// <returns></returns>
    int GetYear() const
    {
        return year;
    }

    DateTime() : DateTime(13, 4, 2004) {}

    DateTime(int day, int month) : DateTime(day, month, 2003) {}

    DateTime(int day, int month, int year)
    {
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    }

    void Print() const
    {
        cout << "Date: " << day << "." << month << "." << year << endl;
    }
};

//////////////////////////////////////////////////////

class Student
{
    string name;
    string surname;
    DateTime birthday;
    DateTime study_start; // 01.08.2022

    // TO DO:  

    int* hometask_rates = nullptr;
    int hometask_rates_count = 0;

    // TO DO: practice and exams

public:
    Student() :Student("John", "Doe", { 1, 1, 2000 }, { 1, 8, 2022 }) {}

    Student(string name, string surname) :Student("John", "Doe", { 1, 1, 2000 }, { 1, 8, 2022 }) {}

    Student(string name, string surname, DateTime birthday, DateTime study_start)
    {
        SetName(name);
        SetSurname(surname);
        SetBirthday(birthday);
        SetStudyStart(study_start);
    }

    ~Student()
    {
        if (hometask_rates != nullptr)
        {
            delete[] hometask_rates;
            hometask_rates = nullptr;
        }
    }

    void SetName(string name)
    {
        this->name = name;
    }

    string GetName() const
    {
        return name;
    }

private:
    void SetBirthday(const DateTime& birthday)
    {
        this->birthday = birthday;
    }

public:
    DateTime GetBirthday() const
    {
        return birthday;
    }

    void SetStudyStart(const DateTime& study_start)
    {
        this->study_start = study_start;
    }

    DateTime GetStudyStart() const
    {
        return study_start;
    }

    void PrintStudentInfo() const
    {
        cout << "Name: " << name << " " << surname << endl;
        cout << "Birthday: ";
        birthday.Print();
        cout << "Study Start: ";
        study_start.Print();
        cout << endl;
    }
};

int main()
{
    // Create a Student object and print its information
    Student student;
    student.PrintStudentInfo();

    // Create another Student object with custom information
    Student customStudent("Alice", "Wonderland", { 5, 5, 1999 }, { 1, 8, 2021 });
    customStudent.PrintStudentInfo();

    return 0;
}
