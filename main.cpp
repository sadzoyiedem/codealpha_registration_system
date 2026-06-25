/*
 * TASK 2: Login and Registration System
 * Designed by: Stephen Edem Adzoyi
 */

#include <iostream>
#include <fstream>
#include <string>
#include <functional>

using namespace std;

class UserAccountManager
{
private:
  string dataFile;

  // Scramble passweord text
  string hashPassword(string password)
  {
    hash<string> hasher;
    size_t hashValue = hasher(password);
    return to_string(hashValue);
  }

  // Basic validation: username must be at least 3 characters and have no spaces.
  bool isValidUsername(string username)
  {
    if (username.length() < 3)
    {
      cout << "Username must be at least 3 characters long.\n";
      return false;
    }
    for (char c : username)
    {
      if (c == ' ')
      {
        cout << "Username cannot contain spaces.\n";
        return false;
      }
    }
    return true;
  }

  // Basic validation: password must be at least 6 characters.
  bool isValidPassword(string password)
  {
    if (password.length() < 6)
    {
      cout << "Password must be at least 6 characters long.\n";
      return false;
    }
    return true;
  }

  // Reads through the data file to see if a username already exists.
  bool usernameExists(string username)
  {
    ifstream file(dataFile);
    string fileUsername, fileHash;

    while (file >> fileUsername >> fileHash)
    {
      if (fileUsername == username)
      {
        return true;
      }
    }
    return false;
  }

public:
  UserAccountManager(string fileName) : dataFile(fileName) {}

  void registerUser(string username, string password)
  {
    if (!isValidUsername(username))
      return;
    if (!isValidPassword(password))
      return;

    if (usernameExists(username))
    {
      cout << "Registration failed: username '" << username << "' is already taken.\n";
      return;
    }

    string hashedPassword = hashPassword(password);

    ofstream file(dataFile, ios::app);
    if (!file)
    {
      cout << "Registration failed: could not open the data file.\n";
      return;
    }

    file << username << " " << hashedPassword << endl;
    cout << "Registration successful! You can now log in as '" << username << "'.\n";
  }

  void loginUser(string username, string password)
  {
    ifstream file(dataFile);
    if (!file)
    {
      cout << "Login failed: no users have registered yet.\n";
      return;
    }

    string fileUsername, fileHash;
    string enteredHash = hashPassword(password);

    while (file >> fileUsername >> fileHash)
    {
      if (fileUsername == username)
      {
        if (fileHash == enteredHash)
        {
          cout << "Login successful! Welcome back, " << username << ".\n";
        }
        else
        {
          cout << "Login failed: incorrect password.\n";
        }
        return;
      }
    }

    cout << "Login failed: username '" << username << "' not found.\n";
  }
};

int main()
{
  UserAccountManager accountManager("users.txt");
  int choice = 0;

  while (choice != 3)
  {
    cout << "\nLogin & Registration System\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
      string username, password;
      cout << "Enter a username: ";
      cin >> username;
      cout << "Enter a password: ";
      cin >> password;

      accountManager.registerUser(username, password);
    }
    else if (choice == 2)
    {
      string username, password;
      cout << "Enter your username: ";
      cin >> username;
      cout << "Enter your password: ";
      cin >> password;

      accountManager.loginUser(username, password);
    }
    else if (choice == 3)
    {
      cout << "Goodbye!\n";
    }
    else
    {
      cout << "Invalid choice. Please enter 1, 2, or 3.\n";
    }
  }

  return 0;
}