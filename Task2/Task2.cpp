#include <iostream>
#include <iomanip>
#include <list>
#include <string>
#include <cmath>

using std::string;
using std::rand;
using std::cout;
using std::setw;

// Male names
string firstNamesMale[] = { "Aleksey", "Andrey", "Artur", "Valentin", "Vladimir" };
string lastNamesMale[] = { "Babushkin", "Georgiyev", "Vasilyev", "Kovalsky", "Tatishchev" };

// Female names
string firstNamesFemale[] = { "Yelena", "Irina", "Olga", "Anastasia", "Yulia" };
string lastNamesFemale[] = { "Yeremeyeva", "Frolova", "Smelyanskaya", "Tyurina", "Anichkina" };

struct User {
    size_t id;
    string firstName;
    string lastName;
    size_t age;
    string sex;
    string birthday;
    User(size_t id, string firstName, string lastName, string sex, size_t age, string birthday)
    {
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->sex = sex;
        this->birthday = birthday;
    }
};

void addUser(std::list<User> *users, User user);
void printAllUsers(std::list<User> users);
void deleteUsers(std::list<User> *users);
User generateRandomUser();
bool ageLessThenEighteen(const User user);

int main()
{
    std::srand(std::time(nullptr));

    size_t amountOfUsers = 10;

    // Create database of users
    std::list<User> users;

    // Filling the database with random users
    for (size_t i = 0; i < amountOfUsers; i++) {
        User user = generateRandomUser();
        user.id = i;
        addUser(&users, user);
    }

    // Print all users
    printAllUsers(users);

    // Remove all users with age less then eighteen
    std::cout << "\nAFTER DELETENIG USERS WITH AGE LESS THEN EIGHTEEN:" << std::endl;
    deleteUsers(&users);

    // Print all users
    printAllUsers(users);
}

void addUser(std::list<User> *users, User user)
{
    users->push_back(user);
}

void deleteUsers(std::list<User> *users)
{
    users->remove_if(ageLessThenEighteen);
}

void printAllUsers(std::list<User> users)
{

    std::cout.setf(std::ios_base::left);

    std::cout <<
              setw(16) << "Id" <<
              setw(16) << "First Name" <<
              setw(16) << "Last Name" <<
              setw(16) << "Age" <<
              setw(16) << "Sex" <<
              setw(16) << "Birthday" <<
              std::endl;

    for (User u : users) {
        std::cout <<
                  setw(16) << u.id <<
                  setw(16) << u.firstName <<
                  setw(16) << u.lastName <<
                  setw(16) << u.age <<
                  setw(16) << u.sex <<
                  setw(16) << u.birthday <<
                  std::endl;
    }
}

User generateRandomUser()
{

    size_t fistNameId = (size_t)round(4 * ((double)rand() / RAND_MAX));
    size_t lastNameId = (size_t)round(4 * ((double)rand() / RAND_MAX));
    size_t age = 10 + (size_t)round(25 * (double)rand() / RAND_MAX);

    size_t day = 1 + (int)round(25 * ((double)rand() / RAND_MAX));
    size_t mounth = 1 + (int)round(4 * ((double)rand() / RAND_MAX));
    size_t year = 2022 - age;

    string birthday = std::to_string(day) + "." + std::to_string(mounth) + "." + std::to_string(year);

    if (((double)rand() / RAND_MAX) < 0.5) {
        return User(-1, firstNamesMale[fistNameId], lastNamesMale[lastNameId], "Male", age, birthday);
    }
    else {
        return User(-1, firstNamesFemale[fistNameId], lastNamesFemale[lastNameId], "Female", age, birthday);
    }
}

bool ageLessThenEighteen(const User user)
{
    return (user.age < 18);
}