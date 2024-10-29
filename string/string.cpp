#include <iostream>
#include <cstring>

class String {
private:
    char* data;                 
    size_t length;              
    static int objectCount;      

public:
    String() : String(80) {}  

    explicit String(size_t len) : length(len) {
        data = new char[length + 1];
        data[0] = '\0'; 
        ++objectCount;
    }

    String(const char* str) : length(strlen(str)) {
        data = new char[length + 1];
        strcpy_s(data, length + 1, str);
        ++objectCount;
    }

    ~String() {
        delete[] data;
        --objectCount;
    }

    void input() {
        std::cout << "Введите строку: ";
        std::cin.getline(data, length + 1);
    }

    void display() const {
        std::cout << "Строка: " << data << std::endl;
    }

    static int getObjectCount() {
        return objectCount;
    }
};

int String::objectCount = 0;

int main() {
    String str1;                     
    String str2(50);                 
    String str3("Пример строки");     

    std::cout << "Создано объектов: " << String::getObjectCount() << std::endl;

    str1.input();
    str1.display();
    str3.display();

    std::cout << "Создано объектов: " << String::getObjectCount() << std::endl;

    return 0;
}