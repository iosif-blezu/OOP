
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include "Movie.h"
#include "Test.h"
#include "UI.h"
#include "CSVWatchlist.h"
#include "HTMLWatchList.h"
#include <string>
int main()
{

    std::string type = "";
    while(1)
    {
        std::cout << "For exit type: exit\n";
        std::cout << "Choose file type (csv or html): ";
        std::getline(std::cin,type);
        std::cout<<"\n";
        if (type == "exit")
        {
            std::cout << "\nExiting\n";
            break;
        }
        if(type == "csv" || type == "html")
        {
            MmeoryRepository* admin_repo = new FileRepository("movie.csv");
            WatchList* user_repo;
            if(type == "csv")
                user_repo = new CSVWatchList();
            else
                user_repo = new HTMLWatchList();

            Service* admin_serv = new Service{admin_repo};
            UI* ui = new UI(*admin_serv,user_repo);

            ui->runApp();

        }

    }



    return 0;
}
