#include <iostream>
#include <string>


int menu() {
    std::cout << "\n\n===== GRADE MANAGEMENT SYSTEM =====\n" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. View All Students" << std::endl;
    std::cout << "3. Search Student" << std::endl;
    std::cout << "4. Calculate Class Average" << std::endl;
    std::cout << "5. Show Highest Score" << std::endl;
    std::cout << "6. Show Lowest Score" << std::endl;
    std::cout << "7. Delete Student" << std::endl;
    std::cout << "8. Exit" << std::endl << std::endl;

    std::cout << "Enter Choice : ";

    int choice {};
    std::cin >> choice;

    return choice;
}


char calculateGrade(float marks) {
    if (marks >= 90) {return 'A';}
    else if (marks >= 80) {return 'B';}
    else if (marks >= 70) {return 'C';}
    else if (marks >= 60) {return 'D';}
    else {return 'F';}
}


void display(int studentCount, const std::string names[], const float marks[]) {
    std::cout << "  Name          Marks" << std::endl;
    std::cout << "  -------------------" << std::endl;
    for (int i = 0; i < studentCount; i++) {
        std::cout << "  " << names[i] << "           " << marks[i] << "\n";
    }
    std::cout << std::endl;
}


int main() {
    std::string names[100];
    float marks[100];
    char grades[100];
    int studentCount = 0;
    int menu_choice = 0;

    while (menu_choice != 8) {
        menu_choice = menu();

        if (menu_choice == 1)
        {
            if (studentCount >= 100) {
                std::cout << "\nMaximum student limit reached. Cannot add more students." << std::endl;
                continue;
            }
            std::string name;
            float marksInput {-1.0};

            std::cout << "\nADD STUDENTS" << std::endl;
            std::cout << "  Name : ";
            std::cin >> name;
            while (marksInput < 0 || marksInput > 100) {
                std::cout << "  Marks out of 100 : ";
                std::cin >> marksInput;
            }
            marks[studentCount] = marksInput;
            names[studentCount] = name;
            grades[studentCount] = calculateGrade(marks[studentCount]);
            studentCount++;

            std::cout << "  Student added successfully." <<std::endl;
            continue;
        }

        else if (studentCount == 0) {
            std::cout << "\nNo students added yet." << std::endl;
            continue;
        }

        else if (menu_choice == 2)
        {
            std::cout << "\nVIEW ALL STUDENTS" << std::endl;
            display(studentCount, names, marks);
        }


        else if (menu_choice == 3)
        {
            std::cout << "\nSEARCH STUDENTS" << std::endl;
            std::cout << "  Enter name : ";
            std::string search_name;
            std::cin >> search_name;

            bool found = false;

            for (int i = 0; i <studentCount; i++)
            {
                if (names[i] == search_name) {
                    found = true;
                    std::cout << "  Name  : " << names[i] << std::endl;
                    std::cout << "  Marks : " << marks[i] << std::endl;
                    std::cout << "  Grade : " << grades[i] << std::endl;
                    break;
                }
            }
            if (!found) {
                std::cout << "  Student not found." << std::endl;
            }
        }


        else if (menu_choice == 4)
        {
            std::cout << "\nCLASS AVERAGE" << std::endl;
            float marksTotal {};

            for (int i = 0; i < studentCount; i++) 
            {
                marksTotal += marks[i];
            }
            std::cout << "  Class Average = " << marksTotal/studentCount << std::endl;
        }


        else if (menu_choice == 5)
        {
            std::cout << "\nHIGHEST SCORE" << std::endl;
            
            float highestMarks = marks[0];
            int   highestIndex = 0;
            for (int i = 0; i < studentCount; i++) 
            {
                if (marks[i] > highestMarks) {
                    highestMarks = marks[i];
                    highestIndex = i;
                }
            }
            std::cout << "  Top Student : " << names[highestIndex] << std::endl;
            std::cout << "  Marks : " << marks[highestIndex] << std::endl;
        }


        else if (menu_choice == 6)
        {
            std::cout << "\nLOWEST SCORE" << std::endl;
            
            float lowestMarks = marks[0];
            int   lowestIndex = 0;
            for (int i = 0; i < studentCount; i++) 
            {
                if (marks[i] < lowestMarks) {
                    lowestMarks = marks[i];
                    lowestIndex = i;
                }
            }
            std::cout << "  Lowest Student : " << names[lowestIndex] << std::endl;
            std::cout << "  Marks : " << marks[lowestIndex] << std::endl;
        }

        
        else if (menu_choice == 7) 
        {
            std::cout << "\nDELETE STUDENT" << std::endl;
            std::string search_name;

            std::cout << "  Enter name : ";
            std::cin >> search_name;

            bool found = false;

            for (int i = 0; i < studentCount; i++)
            {
                if (names[i] == search_name) {
                    found = true;
                    for (int j = i; j < studentCount - 1; j++) {
                        names[j] = names[j + 1];
                        marks[j] = marks[j + 1];
                        grades[j] = grades[j + 1];
                    }
                    break;
                }
            }
            if (!found) {
                std::cout << "  Student not found." << std::endl;
            }
            else {
                studentCount--;
                std::cout << "  Student deleted successfully." << std::endl;
                std::cout << "\nUPDATED STUDENT LIST" << std::endl;
                display(studentCount, names, marks);
            }
        }

        
        else if (menu_choice == 8)
        {
            std::cout << "\nExiting the program. Goodbye!" << std::endl;
        }


        else
        {
            std::cout << "\nInvalid choice. Please try again." << std::endl;
        }

    }
}
