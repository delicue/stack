// stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Stack.h"

void process_input(const std::string& input, Stack<std::string>& stack)
{
    if (input == "push") {
        std::cout << "What is the name of the item you would like to add to the stack? ";
        std::string item;
        std::getline(std::cin, item);

        stack.push(item);
        std::cout << item << " pushed onto the stack.\n";
    }
    else if (input == "pop") {
        stack.pop();
        std::cout << "Removed the top item from the stack.\n";
    }
    else if (input == "peek") {
        if (stack.size() > 0)
            std::cout << "Took a peek and it looks like `" << stack.peek() << "` is at the top of the stack.\n";
        else
            std::cerr << "Stack is empty!\n";
    }
    else if (input == "size") {
        std::cout << "Stack has " << stack.size() << " items.\n";
    }
    else if (input == "clear") {
        stack.clear();
        std::cout << "Removed all items from the stack. Stack is now empty.\n";
    }
    else if(input != "exit")
        std::cout << "INVALID INPUT\n";
}
void display_menu(Stack<std::string>&& stack)
{
    std::cout << "There are " << stack.size() << " items, currently.\n";

    std::string command;

    do {
        command = "";
        std::cout << "Menu:\n"
            << "\tpush\t(stacks an item on top)\n"
            << "\tpeek\t(looks at the top of the stack and displays the name of it)\n"
            << "\tpop\t(removes the item from the top of the stack)\n"
            << "\tsize\t(displays the size of the stack)\n"
            << "\tclear\t(clears the whole stack)\n"
            << "\texit\n"
            << "What would you like to do? ";
        std::getline(std::cin, command);
        process_input(command, stack);
        std::cout << command + "\n\n";
    } while (command != "exit");
}

int main()
{
    std::cout << "This is a Stacking program. You get to stack an item.\n";
    display_menu(Stack<std::string>());
    std::cout << std::endl;
}