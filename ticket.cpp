#include <iostream>
#include <queue>
#include <string>
#include <iomanip>

class Person {
public:
    std::string name;
    int ticket_number;

    Person(std::string name, int ticket_number) 
        : name(name), ticket_number(ticket_number) {}
};

class Queue {
private:
    std::queue<Person> queue;
    int next_ticket_number = 1;

public:
    void Enqueue(const std::string& name) {
        Person new_person(name, next_ticket_number++);
        queue.push(new_person);
        std::cout << name << " added to the queue with Ticket #" 
                  << std::setw(3) << std::setfill('0') << new_person.ticket_number << "\n";
    }

    void AutoDequeue() {
        if (queue.empty()) {
            std::cout << "No one is in the queue to dequeue.\n";
        } else {
            Person next_person = queue.front();
            queue.pop();
            std::cout << next_person.name << " received a ticket (Ticket #" 
                      << std::setw(3) << std::setfill('0') << next_person.ticket_number << ")\n";
        }
    }

    bool IsEmpty() const {
        return queue.empty();
    }

    int Size() const {
        return queue.size();
    }

    void Peek() const {
        if (queue.empty()) {
            std::cout << "The queue is empty.\n";
        } else {
            Person next_person = queue.front();
            std::cout << "Next in line: " << next_person.name 
                      << " with Ticket #" << std::setw(3) << std::setfill('0') << next_person.ticket_number << "\n";
        }
    }

    void Position(const std::string& name) const {
        int position = 1;
        bool found = false;
        std::queue<Person> temp_queue = queue;

        while (!temp_queue.empty()) {
            Person current_person = temp_queue.front();
            temp_queue.pop();
            if (current_person.name == name) {
                std::cout << name << " is currently at position " << position << " in the queue.\n";
                found = true;
                break;
            }
            position++;
        }

        if (!found) {
            std::cout << name << " is not in the queue.\n";
        }
    }
};

int main() {
    Queue concertQueue;
    int choice;

    std::cout << "Welcome to Olivia Rodrigo's Concert Ticketing System!\n";
    while (true) {
        std::cout << "\n1. Enqueue a person\n"
                  << "2. Check your position in the queue\n"
                  << "3. Auto Dequeue (1 minute passed)\n"
                  << "4. Peek at the next person in line\n"
                  << "5. Exit\n"
                  << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            std::cout << "Enter the name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            concertQueue.Enqueue(name);
            std::cout << "Queue size: " << concertQueue.Size() << "\n";
        } else if (choice == 2) {
            std::string name;
            std::cout << "Enter your name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            concertQueue.Position(name);
        } else if (choice == 3) {
            concertQueue.AutoDequeue();
            std::cout << "Queue size: " << concertQueue.Size() << "\n";
        } else if (choice == 4) {
            concertQueue.Peek();
        } else if (choice == 5) {
            std::cout << "Exiting the ticketing system. Have a great day!\n";
            break;
        } else {
            std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}