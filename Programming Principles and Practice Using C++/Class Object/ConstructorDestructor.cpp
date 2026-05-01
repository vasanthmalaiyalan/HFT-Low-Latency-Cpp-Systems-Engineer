#include <iostream>

class Engine {
    private:
       int horsepower;
       std::string model;

   public:
        // Constructor - object create auto call
        Engine(int hp, std::string m) {
            horsepower = hp;
            model = m;
            std::cout << "Engine created: " << model << '\n';
        }
        
        // Destructor - object destory auto call
        ~Engine() {
            std::cout << "Engine destory: " << model << '\n';
        }

        void show() {
            std::cout << model << " -> " << horsepower << "hp\n";
        }
};

int main() {
    // Stack Allocation - Scope auto destiry
    Engine e1(100, "V4");
    e1.show();

    {
        Engine e2(200, "v6"); // inner scope
        e2.show();
    } // e2 destory

    std::cout << "Still in main\n";

    // Heap allocation - manually delete
    Engine* e3 = new Engine(400, "v8");
    e3->show();
    delete e3; // e3 destroy

    return 0;
}