# Login and Registration System

**Designed by:** Stephen Edem Adzoyi

A beginner-friendly, Object-Oriented C++ application that allows users to register an account and log in securely. The system uses basic file I/O to store user credentials locally and demonstrates fundamental security practices by scrambling (hashing) passwords before saving them.

## Features

- **User Registration:** Create a new account with a unique username and password.
- **User Login:** Authenticate existing users by comparing hashed credentials.
- **Input Validation:** \* Usernames must be at least 3 characters long and contain no spaces.
  - Passwords must be at least 6 characters long.
- **Duplicate Checking:** Prevents users from registering with an already existing username.
- **Secure Storage Simulation:** Uses the built-in `std::hash` to scramble passwords so plain-text passwords are never saved to the disk.
- **Persistent Storage:** Saves user data to a local text file (`users.txt`), meaning accounts remain accessible even after restarting the program.

## Concepts Demonstrated

This project is a great learning resource for beginners moving from procedural programming to Object-Oriented Programming (OOP) in C++. It highlights:

- **Classes and Objects:** Encapsulating logic and data within a `UserAccountManager` class.
- **Access Modifiers:** Keeping sensitive helper functions `private` while exposing `public` methods for the main menu.
- **File Handling:** Using `<fstream>` (`ifstream`, `ofstream`) to read from and append to text files.
- **Basic Hashing:** Using `<functional>` to generate hash values for basic data protection.

## Prerequisites

To run this program, you will need a C++ compiler installed on your system that supports at least C++11. Common options include:

- **GCC (MinGW)** for Windows
- **Clang** for macOS
- **GCC** for Linux

## How to Compile and Run

1. **Download the code:** Save the provided C++ code into a file named `main.cpp` (or `LoginSystem.cpp`).
2. **Open your terminal or command prompt.**
3. **Navigate to the folder** where you saved the file.
4. **Compile the code** using your C++ compiler. For example, using g++:
   ```bash
   g++ main.cpp -o LoginSystem
   ```
5. **Run the executable** 
    * On Windows:
      ```bash
        LoginSystem.exe
      ```
    * On macOS/Linux
    ```bash
      ./LoginSystem
    ```
  
##
**Developed By:** Stephen Edem Adzoyi \
***June, 2026***

#

