#include <iostream>

class Stack1
{
    int limit;
    int noCap;

public:
    char* x;

    Stack1()
    {
        limit = -1; noCap = 100; x = new char[noCap];
    }
    bool push1(char h);
    char plop();
    char check();
    bool checkEmpty();
};

bool Stack1::push1(char h)
{
    if (limit >= (noCap - 1))
    {
        noCap += 100;
        x = (char*)realloc(x, noCap);
    }
    x[++limit] = h;
    return true;
}

char Stack1::plop()
{
    if (limit < 0)
    {
        return 0;
    }
    else
    {
        return x[limit--];
    }
}

char Stack1::check()
{
    if (limit < 0)
    {
        return 0;
    }
    else
    {
        return x[limit];
    }
}

bool Stack1::checkEmpty()
{
    if (limit == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void seperator()
{
    std::cout << "\n------------------------------------- Stack using Arrays -------------------------------------" << std::endl;
}

int main()
{
    char looper = 'n';
    std::string str = "{[()]}";
    std::string expression;
    seperator();
    do {
        Stack1 temp;
        std::cout << " \n Please Input an Expression: ";
        std::cin >> expression;
        for (int i = 0; i < expression.length(); i++)
        {
            if (str.find(expression[i]) != std::string::npos)
            {
                if (temp.checkEmpty())
                {
                    temp.push1(expression[i]);
                }
                else if ((temp.check() == '(' && expression[i] == ')') || (temp.check() == '[' && expression[i] == ']') || (temp.check() == '{' && expression[i] == '}'))
                {
                    temp.plop();
                }
                else
                {
                    temp.push1(expression[i]);
                }
            }
        }
        if (temp.checkEmpty())
        {
            std::cout << "\n The expression \"" << expression << "\" is a balanced expression.\n";
            std::cout << "Retry (Press y or Y to retry)?: ";
            std::cin >> looper;
        }
        else
        {
            std::cout << "\n Error: The expression\"" << expression << "\" is an unbalanced expression\n";
            std::cout << "Retry (Press y or Y to retry)?: ";
            std::cin >> looper;
        }
        
    } while (looper == 'y' || looper == 'Y');
    return 0;
    
}