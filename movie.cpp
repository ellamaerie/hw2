#include "movie.h"
#include "util.h"
#include <sstream>
#include <iomanip>

Movie::Movie(const std::string& category, const std::string& name, double price, int quantity, const std::string& genre, const std::string& rating)
: Product(category, name, price, quantity), genre_(genre), rating_(rating) {}

Movie::~Movie () {}

std::set<std::string> Movie::keywords() const{
  std::set<std::string> totalKeywords;
  
  //parse name
  std::set<std::string> nameKeyword;
  nameKeyword = parseStringToWords(getName());
  totalKeywords.insert(nameKeyword.begin(), nameKeyword.end());

  //parse genre?
  std::set<std::string> genreKeyword;
  genreKeyword = parseStringToWords(genre_);
  totalKeywords.insert(genreKeyword.begin(), genreKeyword.end());

  return totalKeywords;
}

std::string Movie::displayString() const{
  /*
  <name>
  Genre: <genre> Rating: <rating>
  <price> <quantity> left.
  */

  std::stringstream ss;

  ss << getName() << std::endl;
  ss << "Genre: " << genre_ << " Rating: " << rating_ << std::endl;
  ss << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left." << std::endl;

  return ss.str();
}

void Movie::dump(std::ostream& ostr) const {
  ostr << category_ << std::endl;
  ostr << name_ << std::endl;
  ostr << std::fixed << std::setprecision(2) << price_ << std::endl;
  ostr << getQty() << std::endl;

  //movie unique properties:
  ostr << genre_ << std::endl;
  ostr << rating_ << std::endl;
}