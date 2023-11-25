
#pragma once
#include "Service.h"

class UI
{
private:
    Service service;
    WatchList* watchList;

public:

    UI();
    UI(Service serv, WatchList* wl);
    ~UI();

    void runApp();

private:

    void runAdmin();
    void runUser();

    void printMenuApp();
    void printMenuAdmin();
    void printMenuUser();
    void printWatchMenu(Movie& m);

    void consoleADD();
    void consoleDELETE();
    void consoleUPDATE();
    void consoleSHOW();


    void userWATCH();
    void userShow();
    void userDELETE();
    void userSave();
    void userOpen();


};


