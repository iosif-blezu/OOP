
#include "HTMLWatchList.h"
#include <windows.h>
#include <shellapi.h>
#include <fstream>

HTMLWatchList::HTMLWatchList()
{

}

HTMLWatchList::~HTMLWatchList()
{

}

void HTMLWatchList::saveToFile()
{
    std::ofstream f("watchlist.html");

    f << "<!DOCTYPE html>" << "\n";
    f << "<html>" << "\n";

    f << "<head>" << "\n";
    f << "<title>Movie Playlist</title>" << "\n";
    f << "</head>" << "\n";

    f << "<body>" << "\n";

    f << "<table border=\"1\">" << "\n";

    f << "<tr>" << "\n";
    f << "<td>Title</td>" << "\n";
    f << "<td>Genre</td>" << "\n";
    f << "<td>Year</td>" << "\n";
    f << "<td>Likes</td>" << "\n";
    f << "<td>Trailer</td>" << "\n";
    f << "</tr>" << "\n";

    for(auto &i: this->movies)
    {
        f << "<tr>" << "\n";

        f << "<td>" << i.getTitle() << "</td>" << "\n";
        f << "<td>" << i.getGenre() << "</td>" << "\n";
        f << "<td>" << i.getYear() << "</td>" << "\n";
        f << "<td>" << i.getLikes() << "</td>" << "\n";
        f << "<td><a href =" << i.getTrailer() << ">Link</a></td>";

        f << "</tr>" << "\n";
    }
    f << "</table>" << "\n";
    f << "</body>" << "\n";
    f << "</html>" << "\n";

    f.close();
}

void HTMLWatchList::openInFile()
{
    ShellExecuteA(NULL, NULL, "chrome.exe", "C:/Users/iosif/source/repos/A7/A7/watchlist.html", NULL, SW_SHOWMAXIMIZED);
    system("PAUSE");
}