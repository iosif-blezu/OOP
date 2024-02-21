# OOP Course Projects and Tests: 

## Introduction

This project is part of the Object-Oriented Programming (OOP) course, designed to demonstrate the practical application of OOP principles and patterns in building a simple yet functional movie watchlist application.

## Theoretical Aspects

In the course, we cover fundamental OOP concepts such as:

- **Encapsulation**: Ensuring that a class's internal representation is hidden from the outside.
- **Inheritance**: Creating a new class that is based on an existing class.
- **Polymorphism**: Allowing methods to do different things based on the object it is acting upon.
- **Abstraction**: Reducing complexity by hiding unnecessary details in classes and interfaces.

These principles are implemented throughout the project to create a modular and scalable application.

## OOP Patterns Used

The project employs several OOP design patterns, including:

- **Singleton Pattern**: Ensured by the repository classes to have a single instance of the object throughout the application.
- **Factory Pattern**: Used in the creation of different types of watchlists (CSV and HTML).
- **Strategy Pattern**: Implemented for various sorting or filtering operations on the movie list.
- **Observer Pattern**: Used to update different types of watchlists when changes occur.

## Project Structure

- `*.cpp` & `*.h`: C++ source and header files containing the definitions and implementations of classes and methods.
- `Main.cpp`: The entry point of the application, tying together various components.
- `Movie.cpp` & `Movie.h`: Define the Movie class encapsulating movie details.
- `Validator.cpp` & `Validator.h`: Validate the data before processing.
- `Repository.cpp` & `Repository.h`: Abstract class for repository patterns and derived classes like `CSVWatchList.cpp` and `HTMLWatchList.cpp` for specific implementations.
- `Service.cpp` & `Service.h`: Contains business logic and ties the data layer with the UI.
- `UI.cpp` & `UI.h`: Handle the user interface and user input.
- `RepoExceptions.cpp` & `RepoExceptions.h`: Custom exception classes for repository operations.
- `WatchList.cpp` & `WatchList.h`: Handle the user's watchlist operations.
- `util.cpp` & `util.h`: Utility functions used across the application.
- `Test.cpp` & `Test.h`: Unit tests for validating the functionality of classes and methods.
- `diagram.png`: UML diagram of the project structure.
- `example.csv`, `movie.csv`, `watchlist.csv`: Sample data files.
- `example.html`, `watchlist.html`: Sample output files.


## Other:

This was one of the more complex assignments. The other project in this repo is a test of 1 hour, implemented with a visual interface made in QT, in which I managed to get a 10.

