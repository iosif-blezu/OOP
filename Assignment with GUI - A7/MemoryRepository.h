
#include <vector>
#pragma once
#include "Validator.h"
#include "Repository.h"

class MmeoryRepository:
    public Repository
{
protected:
    std::vector<Movie> items;
    Validator validator_movies;
public:

    MmeoryRepository();
    ~MmeoryRepository();

    MmeoryRepository(const MmeoryRepository& otherRepo) {this->items = otherRepo.items;}

    std::vector<Movie> get_All_Movies_Repo() {return this->items;}

    int add_Movie_repo(Movie movie);
    int delete_Movie_repo(const Movie movie);
    int update_Movie_repo(const Movie movie);
    int does_the_movie_exist(Movie movie);
    void incLikes(const Movie movie) {this->items[does_the_movie_exist(movie)].incLikes();}

    void saveToFile();


};