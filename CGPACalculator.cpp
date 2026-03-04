#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string R   = "\033[0m";
string B   = "\033[1m";
string DM  = "\033[2m";
string RED = "\033[91m";
string GRN = "\033[92m";
string YLW = "\033[93m";
string BLU = "\033[94m";
string CYN = "\033[96m";
string WHT = "\033[97m";

double gradeToPoints(string grade)
{
    if (grade == "A+" || grade == "a+") 
    { 
        return 4.0; 
    }
    if (grade == "A"  || grade == "a") 
    { 
        return 4.0; 
    }
    if (grade == "A-" || grade == "a-") 
    { 
        return 3.7; 
    }
    if (grade == "B+" || grade == "b+") 
    { 
        return 3.3; 
    }
    if (grade == "B"  || grade == "b") 
    { 
        return 3.0; 
    }
    if (grade == "B-" || grade == "b-") 
    { 
        return 2.7; 
    }
    if (grade == "C+" || grade == "c+") 
    { 
        return 2.3; 
    }
    if (grade == "C"  || grade == "c") 
    { 
        return 2.0; 
    }
    if (grade == "C-" || grade == "c-") 
    { 
        return 1.7; 
    }
    if (grade == "D+" || grade == "d+") 
    { 
        return 1.3; 
    }
    if (grade == "D"  || grade == "d")  { return 1.0; }
    if (grade == "F"  || grade == "f")  { return 0.0; }
    return -1.0;
}

string gpaColor(double gpa)
{
    if (gpa >= 3.5) { return GRN; }
    if (gpa >= 2.5) { return YLW; }
    return RED;
}

void printLine(int n = 50)
{
    cout << "  " << DM << CYN;
    for (int i = 0; i < n; i++)
    {
        cout << "-";
    }
    cout << R << endl;
}

void printDoubleLine(int n = 50)
{
    cout << "  " << DM << CYN;
    for (int i = 0; i < n; i++)
    {
        cout << "=";
    }
    cout << R << endl;
}

int main()
{
    system("cls");
    cout << endl;
    printDoubleLine();
    cout << "         " << CYN << B << "CGPA CALCULATOR" << R << endl;
    cout << "      " << DM << "Track Your Academic Progress" << R << endl;
    printDoubleLine();
    cout << endl;

    int numSemesters;
    cout << "  " << CYN << ">> " << R << "Enter number of semesters: ";
    cin >> numSemesters;

    while (numSemesters < 1 || numSemesters > 12)
    {
        cout << "  " << RED << "[!] Please enter between 1 and 12: " << R;
        cin >> numSemesters;
    }

    double semGPA[12];
    int semCredits[12];
    double semQP[12];
    int grandTotalCredits = 0;
    double grandTotalQP = 0.0;
    int grandTotalCourses = 0;

    string courseNames[15], courseGrades[15];
    int courseCr[15];
    double coursePts[15], courseQP[15];

    for (int s = 0; s < numSemesters; s++)
    {
        cout << endl;
        printDoubleLine();
        cout << "          " << YLW << B << "SEMESTER " << (s + 1) << R << endl;
        printDoubleLine();
        cout << endl;

        int numCourses;
        cout << "  " << CYN << ">> " << R << "Number of courses (1-15): ";
        cin >> numCourses;

        while (numCourses < 1 || numCourses > 15)
        {
            cout << "  " << RED << "[!] Enter between 1 and 15: " << R;
            cin >> numCourses;
        }
        cin.ignore();

        int totalCr = 0;
        double totalQP = 0.0;

        for (int i = 0; i < numCourses; i++)
        {
            cout << endl;
            printLine(40);
            cout << "  " << WHT << B << "Course " << (i + 1) << " of " << numCourses << R << endl;
            printLine(40);

            cout << "  " << CYN << ">> " << R << "Course Name  : ";
            getline(cin, courseNames[i]);

            bool valid = false;
            while (!valid)
            {
                cout << "  " << CYN << ">> " << R << "Grade (A-F)  : ";
                getline(cin, courseGrades[i]);

                if (!courseGrades[i].empty())
                {
                    courseGrades[i][0] = toupper(courseGrades[i][0]);
                }

                coursePts[i] = gradeToPoints(courseGrades[i]);

                if (coursePts[i] >= 0)
                {
                    valid = true;
                }
                else
                {
                    cout << "  " << RED << "[!] Invalid! Use: A+, A, A-, B+, B, B-, C+, C, C-, D+, D, F" << R << endl;
                }
            }

            cout << "  " << CYN << ">> " << R << "Credit Hours : ";
            cin >> courseCr[i];

            while (courseCr[i] < 1 || courseCr[i] > 6)
            {
                cout << "  " << RED << "[!] Enter between 1 and 6: " << R;
                cin >> courseCr[i];
            }
            cin.ignore();

            courseQP[i] = (coursePts[i] * courseCr[i]);
            totalCr = (totalCr + courseCr[i]);
            totalQP = (totalQP + courseQP[i]);

            cout << "  " << GRN << "[+] " << R << DM << courseNames[i] << " added!" << R << endl;
        }

        cout << endl << endl;
        printDoubleLine();
        cout << "      " << CYN << B << "SEMESTER " << (s + 1) << " - REPORT CARD" << R << endl;
        printDoubleLine();
        cout << endl;

        cout << "  " << B << WHT
             << left << setw(4) << "#"
             << setw(20) << "Course"
             << setw(8) << "Grade"
             << setw(8) << "Cr.Hr"
             << setw(8) << "Pts"
             << setw(10) << "Quality" << R << endl;
        printLine();

        for (int i = 0; i < numCourses; i++)
        {
            string name = courseNames[i];
            if ((int)name.length() > 18)
            {
                name = name.substr(0, 15) + "...";
            }

            string gc = gpaColor(coursePts[i]);
            cout << "  " << DM << left << setw(4) << (i + 1) << R
                 << WHT << setw(20) << name << R
                 << gc << B << setw(8) << courseGrades[i] << R
                 << WHT << setw(8) << courseCr[i] << R
                 << gc << setw(8) << fixed << setprecision(1) << coursePts[i] << R
                 << WHT << setw(10) << fixed << setprecision(1) << courseQP[i] << R << endl;
        }

        printLine();
        cout << "  " << B << left << setw(24) << "  TOTAL" << R
             << WHT << setw(8) << "" << B << setw(8) << totalCr << R
             << WHT << setw(8) << "" << B << setw(10) << fixed << setprecision(1) << totalQP << R << endl;

        double gpa;
        if (totalCr > 0)
        {
            gpa = (totalQP / totalCr);
        }
        else
        {
            gpa = 0.0;
        }

        semGPA[s] = gpa;
        semCredits[s] = totalCr;
        semQP[s] = totalQP;
        grandTotalCredits = (grandTotalCredits + totalCr);
        grandTotalQP = (grandTotalQP + totalQP);
        grandTotalCourses = (grandTotalCourses + numCourses);

        cout << endl;
        printLine();
        cout << "  Semester GPA : " << gpaColor(gpa) << B << fixed << setprecision(2) << gpa << " / 4.00" << R << endl;

        int filled = (int)((gpa / 4.0) * 30);
        cout << "  Progress     : " << gpaColor(gpa) << "[";
        for (int i = 0; i < 30; i++)
        {
            if (i < filled)
            {
                cout << "#";
            }
            else
            {
                cout << DM << "-" << R << gpaColor(gpa);
            }
        }
        cout << "] " << fixed << setprecision(2) << gpa << R << endl;
        printLine();
    }

    double cgpa;
    if (grandTotalCredits > 0)
    {
        cgpa = (grandTotalQP / grandTotalCredits);
    }
    else
    {
        cgpa = 0.0;
    }

    cout << endl << endl;
    printDoubleLine();
    cout << "  " << DM << CYN << "*  *  *  *  *  *  *  *  *  *  *  *  *" << R << endl;
    cout << endl;
    cout << "          " << CYN << B << "FINAL CGPA RESULT" << R << endl;
    cout << endl;
    cout << "  " << DM << CYN << "*  *  *  *  *  *  *  *  *  *  *  *  *" << R << endl;
    printDoubleLine();
    cout << endl;

    cout << "          CGPA : " << gpaColor(cgpa) << B << fixed << setprecision(2) << cgpa << " / 4.00" << R << endl;
    cout << endl;

    int bar = (int)((cgpa / 4.0) * 40);
    cout << "  " << gpaColor(cgpa) << "[";
    for (int i = 0; i < 40; i++)
    {
        if (i < bar)
        {
            cout << "#";
        }
        else
        {
            cout << DM << "-" << R << gpaColor(cgpa);
        }
    }
    cout << "] " << B << fixed << setprecision(2) << cgpa << R << endl;
    cout << endl;

    printLine();
    cout << "  " << DM << CYN << "Semesters Completed : " << R << WHT << numSemesters << R << endl;
    cout << "  " << DM << CYN << "Total Courses       : " << R << WHT << grandTotalCourses << R << endl;
    cout << "  " << DM << CYN << "Total Credit Hours  : " << R << WHT << grandTotalCredits << R << endl;
    cout << "  " << DM << CYN << "Total Quality Pts   : " << R << WHT << fixed << setprecision(1) << grandTotalQP << R << endl;
    printLine();
    cout << endl;

    cout << "  Academic Standing : ";
    if (cgpa >= 3.7)
    {
        cout << GRN << B << "Dean's List (Outstanding!)" << R;
    }
    else if (cgpa >= 3.5)
    {
        cout << GRN << "Honor Roll (Excellent!)" << R;
    }
    else if (cgpa >= 3.0)
    {
        cout << GRN << "Good Standing" << R;
    }
    else if (cgpa >= 2.0)
    {
        cout << YLW << "Satisfactory" << R;
    }
    else
    {
        cout << RED << B << "Academic Probation" << R;
    }
    cout << endl << endl;

    if (numSemesters > 1)
    {
        printLine();
        cout << "  " << WHT << B << "Semester GPA Trend:" << R << endl;
        cout << endl;

        for (int i = 0; i < numSemesters; i++)
        {
            int b = (int)((semGPA[i] / 4.0) * 25);
            cout << "  Sem " << (i + 1) << ": " << gpaColor(semGPA[i]) << "[";

            for (int j = 0; j < 25; j++)
            {
                if (j < b)
                {
                    cout << "#";
                }
                else
                {
                    cout << DM << "-" << R << gpaColor(semGPA[i]);
                }
            }
            cout << "] " << B << fixed << setprecision(2) << semGPA[i] << R << endl;
        }
        cout << endl;
    }

    printDoubleLine();
    cout << "  " << DM << "Developed by Rehan Ilyas" << R << endl;
    cout << "  " << DM << "CodeAlpha Internship | March 2026" << R << endl;
    printDoubleLine();
    cout << endl;

    return 0;
}
