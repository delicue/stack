// stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Stack.h"

std::string& prompt(const std::string& msg)
{
    std::string cmd;
    std::cout << msg << " ";
    std::cin >> cmd;
    return cmd;
}
void display_menu(const std::string &stack_item, const Stack<std::string>& stack)
{
    std::cout << "There are " << stack.size() << " of the item " << stack_item << " currently.\n";
    std::cout << "Menu:\n"
        << "push (stacks a " << stack_item << " on top)"
        << "peek (looks at the top of the stack, returning
    auto command = prompt("What would you like to do ?");
}

int main()
{
    Stack<int> stack;

    std::cout << "This is a Stacking program. You get to stack an item.\n";
    prompt("What would you like to stack?");

    std::cout << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
