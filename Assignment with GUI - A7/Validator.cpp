
#include "Validator.h"

Validator::Validator()
{

}

Validator::~Validator()
{

}

void Validator::validate_movie(const Movie &movie)
{
    std::vector<std::string> errors;

    if(movie.getTitle().size()<1)
        errors.push_back("Invalid title!\n");

    if(movie.getYear()<1889)
        errors.push_back("Invalid year!\n");

    if(movie.getYear() > 2050)
        errors.push_back("Invalid year!\n");

    int isWWW = movie.getTrailer().find("www");
    int isHTTP = movie.getTrailer().find("http");

    if(isWWW == 0 && isHTTP == 0)
        errors.push_back("Invalid link!\n");

    if (errors.size() > 0)
        throw MovieException(errors);
}

MovieException::MovieException(std::vector<std::string> _errors)
{
    this->errors = _errors;
}

std::vector<std::string> MovieException::getErrors() const
{
    return this->errors;
}