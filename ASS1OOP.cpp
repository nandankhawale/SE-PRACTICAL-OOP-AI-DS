#include <iostream>
using namespace std;
class Complex
{
private:
    int real, imag;

public:
    Complex()
    {
        this->real = 0;
        this->imag = 0;
    }
    Complex(int r, int i)
    {
        this->real = r;
        this->imag = i;
    }

    friend istream &operator>>(istream &in, Complex &x);
    friend ostream &operator<<(ostream &out, Complex &x);

    Complex operator+(Complex &c)
    {
        Complex temp;
        temp.real = this->real + c.real;
        temp.imag = this->imag + c.imag;
        return temp;
    }

    Complex operator-(Complex &c)
    {
        Complex temp;
        temp.real = this->real - c.real;
        temp.imag = this->imag - c.imag;
        return temp;
    }

    Complex operator*(Complex c)
    {
        Complex temp;
        temp.real = (this->real * c.real) - (this->imag * c.imag);
        temp.imag = (this->imag * c.real) + (this->real * c.imag);
        return temp;
    }
};

istream &operator>>(istream &in, Complex &x)
{
    cout << "Enter the Real part: ";
    in >> x.real;
    cout << "Enter the Imaginary part: ";
    in >> x.imag;
    return in;
}

ostream &operator<<(ostream &out, Complex &x)
{
    out << x.real << " + " << x.imag << "i" << endl;
    return out;
}
int main() {

    int choice;
    Complex c1, c2, c3;

    do {
        cout << "********** Menu **********" << endl;
        cout << "1. Enter 1st Complex number" << endl;
        cout << "2. Enter 2nd Complex number" << endl;
        cout << "3. Print 1st Complex number" << endl;
        cout << "4. Print 2nd Complex number" << endl;
        cout << "5. Addition" << endl;
        cout << "6. Subtraction" << endl;
        cout << "7. Multiplication" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cin >> c1;
                break;
            case 2:
                cin >> c2;
                break;
            case 3:
                cout << c1;
                break;
            case 4:
                cout << c2;
                break;
            case 5:
                c3 = c1 + c2;
                cout << "Addition: " << c3;
                break;
            case 6:
                c3 = c1 - c2;
                cout << "Subtraction: " << c3;
                break;
            case 7:
                c3 = c1 * c2;
                cout << "Multiplication: " << c3;
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid Choice" << endl;
        }
        cout << "\n\n";
    }
    while (choice != 8);
    return 0;
}
