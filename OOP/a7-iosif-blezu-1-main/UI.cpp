

#include "RepoExceptions.h"
#include "UI.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <cstring>

UI::UI() {

}

UI::~UI()
{

}

UI::UI(Service serv, WatchList *wl)
{
    this->service = serv;
    this->watchList = wl;
}


void UI::printMenuApp()
{
    std::cout<<"\n Options: \n";
    std::cout<<"admin -> administrator mode.\n";
    std::cout<<"user -> user mode.\n";
    std::cout<<"exit -> exit the application.\n";
}

void UI::runApp() {

    this->service.save_to_file();
    this->watchList->saveToFile();

    while (true)
    {
        printMenuApp();
        std::string command;
        std::cout << "Your choice: ";
        std::getline(std::cin, command);

        if(command == "exit")
            break;
        if(command == "admin")
        {
            std::cout<<"\nNow you are in Admin mode.\n";
            runAdmin();
            std::cout << "You are no longer in administrator mode. \n";
            continue;
        }

        if( command == "user")
        {
            std::cout << "\nNow you are in User mode\n";
            runUser();
            std::cout << "\nYou are no more in User mode! ^_^\n";
            continue;
        }

        std::cout << "Invalid mode!\n";
    }

    this->service.save_to_file();
    this->watchList->saveToFile();

}


void UI::printMenuAdmin()
{
    std::cout<<"\nAdministrator \n";
    std::cout<<"<add> add a movie.\n";
    std::cout<<"<delete> delete a movie. \n";
    std::cout<<"<update> update a movie. \n";
    std::cout<<"<show> show all the movies. \n";
    std::cout<<"<exit> exit administrator mode. \n";
}

void UI::runAdmin()
{

    while(true)
    {
        printMenuAdmin();
        std::string command;
        std::cout<<"Your choice: ";
        std::getline(std::cin,command);

        if(command == "exit")
            break;
        if(command == "add")
        {
            consoleADD();
            continue;
        }
        if(command == "delete")
        {
            consoleDELETE();
            continue;
        }
        if(command == "update")
        {
            consoleUPDATE();
            continue;
        }
        if(command == "show")
        {
            consoleSHOW();
            std::cout<<"\n\n";
            continue;
        }

        std::cout << "Invalid command!\n\n";
    }
    }


void UI::printMenuUser()
{
    std::cout<<"\nUser \n";
    std::cout<<"<watch> see movies by genre. \n";
    std::cout<<"<show> show the watchlist. \n";
    std::cout<<"<delete> delete a watched movie. \n";
    std::cout<<"<open> display the watchlist. \n";
    std::cout<<"<exit> exit user mode. \n";
}

void UI::runUser()
{
    while (true)
    {
        printMenuUser();
        std::string command;
        std::getline(std::cin, command);
        if (command == "exit")
            break;
        if (command == "watch")
        {
            userWATCH();
            continue;
        }
        if (command == "show")
        {
            userShow();
            continue;
        }
        if (command == "delete")
        {
            userDELETE();
            continue;
        }

        if (command == "save")
        {
            userSave();
            continue;
        }
        if (command == "open")
        {
            userOpen();
            continue;
        }
        std::cout << "Invalid command!\n\n";
    }
}


void UI::printWatchMenu(Movie& m)
{
    std::cout<<"\nWatchlist\n";
    std::cout<<"Title: "<< m.getTitle()<<"\n";
    std::cout<<"<next> go to the next movie.\n";
    std::cout<<"<add> add the movie into the WatchList. \n";
    std::cout<<"<exit> exit watch mode. \n";
}

void UI::consoleADD()
{
    std::string title, genre, year, nbLikes, trailer;
    std::cout << "Insert title: ";
    std::getline(std::cin, title);
    std::cout << "Insert genre: ";
    std::getline(std::cin, genre);
    std::cout << "Insert year: ";
    std::getline(std::cin, year);
    std::cout << "Insert number of likes: ";
    std::getline(std::cin, nbLikes);
    std::cout << "Insert trailer link: ";
    std::getline(std::cin, trailer);

    try {
        this->service.add_Movie_service(title,genre,std::stoi(year), std::stoi(nbLikes) ,trailer);
    }
    catch (MovieException& e)
    {
        for(auto &s : e.getErrors())
            std::cout << s;
    }
    catch (RepositoryExceptions& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (FileException& e)
    {
        std::cout<< e.what() << '\n';
    }
    catch (std::invalid_argument e)
    {
        std::cout << "Insert numbers! \n";
    }
}

void UI::consoleDELETE()
{
    std::string title, genre;

    std::cout<<"Insert the title: ";
    std::getline(std::cin,title);
    std::cout<<"Insert the genre: ";
    std::getline(std::cin,genre);

    try
    {
        this->service.delete_Movie_service(title,genre,2312,2000,"http");
    }
    catch (MovieException& e)
    {
        for (auto &s : e.getErrors())
            std::cout << s;
    }
    catch (RepositoryExceptions& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (FileException& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (std::invalid_argument e)
    {
        std::cout << "Insert numbers! \n";
    }
}

void UI::consoleUPDATE()
{
    std::string title, genre, year, nbLikes, trailer;
    std::cout << "Insert title: ";
    std::getline(std::cin, title);
    std::cout << "Insert genre: ";
    std::getline(std::cin, genre);
    std::cout << "Insert year: ";
    std::getline(std::cin, year);
    std::cout << "Insert number of likes: ";
    std::getline(std::cin, nbLikes);
    std::cout << "Insert trailer link: ";
    std::getline(std::cin, trailer);

    try {
        this->service.update_Movie_service(title,genre, std::stoi(nbLikes), std::stoi(year),trailer);
    }
    catch (MovieException& e)
    {
        for (auto s : e.getErrors())
            std::cout << s;
    }
    catch (RepositoryExceptions& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (FileException& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (std::invalid_argument e)
    {
        std::cout << "Insert numbers\n";
    }
}

void UI::consoleSHOW()
{
    for(auto &i : this->service.get_All_Movies_Service())
        std::cout<<i.getTitle()<<" | " << i.getGenre()
        << " | "<< i.getLikes() << " | "
        << i.getYear() << " | " <<i.getTrailer()<<"\n";

}

void UI::userWATCH()
{
    std::cout<<"Please enter the genre: ";
    std::string genre;
    std::getline(std::cin,genre);

    std::vector<Movie> s;
    std::vector<Movie> movies = this->service.get_All_Movies_Service();
    s = this->watchList->getSuggestions(movies,genre);

    this->watchList->suggestions = s;

    if(this->watchList->suggestions.size() == 0)
        std::cout<<"There are 0 movies of this genre.\n";
    else
    {
        while(1)
        {
            if(this->watchList->suggestions.size() == 0)
                break;
            Movie m = this->watchList->getCurrentMovie();
            m.PlayTrailer();
            printWatchMenu(m);

            std::string command;
            std::cout<<"\nYour choice: \n";
            std::getline(std::cin,command);

            if(command == "exit")
                break;
            if(command == "add")
            {
                this->watchList->add(m);
                continue;
            }
            if(command == "next")
            {
                this->watchList->next();
                continue;
            }

            std::cout<<"Invalid command! Try again.\n\n";

        }
    }

    if(s.size() == 0)
    {
        std::cout << "That's all for now!\n";
    }
}

void UI::userShow()
{
    if(this->watchList->getList().size() ==0)
        std::cout << "\nNo movie in your WatchList!\n";
    else
        for(auto &m: this->watchList->getList())
            std::cout  << m.getTitle() << " | " << m.getGenre() << " | " << m.getYear() << " | " << m.getLikes() << " | " << m.getTrailer() << "\n";
}

void UI::userDELETE()
{
    std::cout << "Input title: ";
    std::string title;
    std::getline(std::cin, title);

    std::cout << "Input genre: ";
    std::string genre;
    std::getline(std::cin, genre);

    Movie m{title,genre,9,2000,"http://sfds"};

    if(this->watchList->deleteMovie(m) == 0)
    {
        std::cout << "Inexistent movie!\n";
    }
    else
    {
        std::cout << "Like the movie? (yes / no): ";
        std::string liked;

        do
        {
            std::getline(std::cin, liked);
            if (liked != "yes" && liked != "no")
                std::cout << "Invalid option\n";
        } while (liked != "yes" && liked != "no");

        if (liked == "yes")
            this->service.LikeVideo(m);
    }
}

void UI::userSave()
{
    this->watchList->saveToFile();
}

void UI::userOpen()
{
    this->watchList->openInFile();
}
