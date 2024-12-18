#include <iostream>
#include <sstream>
using namespace std;
int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;
    cout << "this is a pointer to that number (&number)" << endl;
    std::ostringstream oss;
    oss << &a;
    cout << &a << endl;
    cout << "the memory representation would be something like \n"
            "|"+ oss.str() +"| <------------- |a|" << endl;
    cout << "try adding something!";
    int b;

    cin >> b;
    cout << &a + b<< endl;

    cout << "Here, we get a pointer to a and move it forward by \n" + std::to_string(sizeof(int));
    cout << "bytes" << endl;
    cout << "This is unsafe as it moves the pointer beyond our programs memory" << endl;
    cout << "|Program Memory                      | Here be dragons!\n"
            "|Pointer to a (&a)| <------------- |a|\n"
            "|"+ oss.str() + "+" + std::to_string((b*sizeof(int))) +  "| <--------------------- " << endl;
    cout << "What if we want to access the original value?" << endl;
    cout << "We do this by dereferencing the pointer or going back to it's value "<< endl;
    cout << "the memory representation would be something like \n"
            "|"+ oss.str() +"| -------------> |a|" << endl;
    cout << "any changes made by dereferencing a pointer (*) will be reflected in the original variable" << endl;
    cout << *&a << endl;
    cout << "we can now add to it and see it reflect in the original value!"     << endl;
    cout << *&a + b << endl;
    cout << "hmm, what if we want to prevent out-of-bounds access?" << endl;
    cout << "we can achieve this through constant pointers" << endl;
    cout << "a constant pointer is immutable (cannot be changed)" << endl;
    cout << "the syntax is int *const name = value\n";
    cin >> b;
    int *const p = &b;
    cout << "Lets try adding now!";

        cout << "This failed, forcing me to handle it explicitly" << endl;

    cout << "however, we can modify the value it points to" << endl;
    *p = *p + 10;
    cout << *p << endl;
    return 0;
}