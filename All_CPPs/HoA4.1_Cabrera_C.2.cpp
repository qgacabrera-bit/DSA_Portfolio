#include <iostream>
struct Nod
{
    char expression;
    Nod* next;
    Nod(char h)
    {
        expression = h;
        next = nullptr;
    }
};
Nod* limit;

void push2(char exp)
{
    Nod* temp = new Nod(exp);
    temp->next = limit;
    limit = temp;
}

bool checkEmpty()
{
    return limit == NULL;
}

char check2()
{
    if (!checkEmpty())
        return limit->expression;
    else
        exit(1);
}

void plop()
{
    Nod* temp;
    if (limit == NULL)
    {
        std::cout << " Stack Underflow " << std::endl;
        exit(1);
    }
    else
    {
        temp = limit;
        limit = limit->next;
        free(temp);

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
    int h;
    seperator();
    do {
        limit = nullptr;
        std::cout << " \n Please Input an Expression: ";
        std::cin >> expression;
        for (int i = 0; i < expression.length(); i++)
        {
            if (str.find(expression[i]) != std::string::npos)
            {
                if (checkEmpty())
                {
                    push2(expression[i]);
                }
                else if ((check2() == '(' && expression[i] == ')') || (check2() == '{' && expression[i] == '}') || (check2() == '[' && expression[i] == ']'))
                {
                    plop();
                }
                else
                {
                    push2(expression[i]);
                }
            }
        }
        if (checkEmpty())
        {
            std::cout << "\n The expression \"" << expression << "\" is a balanced expression.\n";
            std::cout << "Repeat (Press y or Y to repeat)? ";
            std::cin >> looper;
        }
        else
        {
            std::cout << "\n Error: The expression \"" << expression << "\" is an unbalanced expression\n";
            std::cout << "Repeat (Press y or Y to repeat)? ";
            std::cin >> looper;

        }
    } while (looper == 'y' || looper == 'Y');
    return 0;
}
