
#include <fstream>
#include <windows.h>
#include "CSVWatchlist.h"

CSVWatchList::CSVWatchList()
{

}

CSVWatchList::~CSVWatchList()
{

}

void CSVWatchList::saveToFile()
{
    std::ofstream f("watchlist.csv");
    for(auto &i : this->movies)
        f << i << "\n";
    f.close();
}

void CSVWatchList::openInFile()
{
    ShellExecuteA(NULL, NULL , "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE", "watchlist.csv", NULL, SW_SHOWMAXIMIZED);
    system("PAUSE");
}