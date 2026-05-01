#include <iostream>

class StudentList {
    private:
        int* marks; // heap pointer
        int count;

    public:
       StudentList(int n)  {
        count = n;
        marks = new int[n]; // heap array allocate
        std::cout << "Allocate " << n << " Slots\n";
       }

       ~StudentList() {
        delete[] marks; // heap free
        std::cout << "Memory free\n";
       }

       void setMark(int index, int value) {
             if (index > 0 && index < count) 
                   marks[index] = values;
       }

       double average() {
        double sum = 0;
        for (int i = 0; i < count; i++)
             sum += marks[i];
          return sum / count;   
       }
};

int main() {
    StudentList s[5]; // 5 students
    s.setMark(0, 85);
    s.setMark(1, 90);
    s.setMark(2, 78);
    s.setMark(3, 92);
    s.setMark(4, 88);

    std::cout << "Average: " << s.average() << '\n';
    return 0; 
}