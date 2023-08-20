#include <iostream>
using namespace std;

float power(float d, int e)
{
    float temp = 1;
    for (int i = 0; i < e; i++)
    {
        temp = temp * d;
    }
    return temp;
}

int main()
{
    int code, a, b;
    long double ans, n1, n2, sin, cos;
    cout << "calculator__" << endl;
    cout << "enter code \n addition-1 \n subraction-2 \n multiplication-3 \n division-4 \n exponentiation-5 \n sine-6 \n cosine-7 \n tan-8 \n cot-9 " << endl;
    cin >> code;

    if (code == 1)
    {
        cout << "a+b" << endl;
        cout << "enter a ";
        cin >> n1;
        cout << "\nenter b ";
        cin >> n2;
        ans = n1 + n2;
        cout << "sum= " << ans << endl;
    }
    else if (code == 2)
    {
        cout << "a-b" << endl;
        cout << "enter a ";
        cin >> n1;
        cout << "\nenter b ";
        cin >> n2;
        ans = n1 - n2;
        cout << "difference= " << ans << endl;
    }
    else if (code == 3)
    {
        cout << "a*b" << endl;
        cout << "enter a ";
        cin >> n1;
        cout << "\nenter b ";
        cin >> n2;
        ans = n1 * n2;
        cout << "product= " << ans << endl;
    }
    else if (code == 4)
    {
        cout << "a/b" << endl;
        cout << "enter a ";
        cin >> n1;
        cout << "\nenter b ";
        cin >> n2;
        ans = n1 / n2;
        cout << "quotient= " << ans << endl;
    }
    else if (code == 5)
    {
        cout << "a^b" << endl;
        cout << "enter a ";
        cin >> n1;
        cout << "\nenter b ";
        cin >> b;
        ans = power(n1, b);
        cout << "answer= " << ans << endl;
    }
    else if (code == 6)
    {
        cout << "sin(x)" << endl;
        cout << "enter x ";
        cin >> n1;
        ans = n1 - (power(n1, 3)) / 6 + (power(n1, 5)) / 120 - (power(n1, 7) / 5040) + (power(n1, 9) / 362880);
        cout << "answer= " << ans << endl;
    }
    else if (code == 7)
    {
        cout << "cos(x)" << endl;
        cout << "enter x ";
        cin >> n1;
        ans = 1 - (power(n1, 2)) / 2 + (power(n1, 4)) / 24 - (power(n1, 6) / 720) + (power(n1, 8) / 40320);
        cout << "answer= " << ans << endl;
    }
    else if (code == 8)
    {
        cout << "tan(x)" << endl;
        cout << "enter x ";
        cin >> n1;
        sin = n1 - (power(n1, 3)) / 6 + (power(n1, 5)) / 120 - (power(n1, 7) / 5040) + (power(n1, 9) / 362880);
        cos = 1 - (power(n1, 2)) / 2 + (power(n1, 4)) / 24 - (power(n1, 6) / 720) + (power(n1, 8) / 40320);
        ans = sin / cos;
        cout << "answer= " << ans << endl;
    }
    else if (code == 9)
    {
        cout << "cot(x)" << endl;
        cout << "enter x ";
        cin >> n1;
        sin = n1 - (power(n1, 3)) / 6 + (power(n1, 5)) / 120 - (power(n1, 7) / 5040) + (power(n1, 9) / 362880);
        cos = 1 - (power(n1, 2)) / 2 + (power(n1, 4)) / 24 - (power(n1, 6) / 720) + (power(n1, 8) / 40320);
        ans = cos / sin;
        cout << "answer= " << ans << endl;
    }
    else
    {
        cout << "invalid code";
    }
    return 0;
}