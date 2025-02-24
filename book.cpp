#include "book.h"
#include "util.h"
#include <sstream>
#include <iomanip>

Book::Book(const std::string& category, const std::string& name, double price, int quantity, const std::string& ISBN, const std::string& author)
: Product(category, name, price, quantity), isbn_(ISBN), author_(author) {}

Book::~Book(){}

std::set<std::string> Book::keywords() const{

  std::set<std::string> totalKeywords;

  //parsing book name keyword into totalKeywords
  std::set<std::string> nameKeyword;
  nameKeyword = parseStringToWords(getName());
  totalKeywords.insert(nameKeyword.begin(), nameKeyword.end());

  //parsing author keyword into total
  std::set<std::string> authorKeyword;
  authorKeyword = parseStringToWords(author_);
  totalKeywords.insert(authorKeyword.begin(), authorKeyword.end());

  //parsing book ISBN keyword into total
  //can't split ISBN, append directly into set
  totalKeywords.insert(isbn_);

  //returns appropriate keywords to index the product
  return totalKeywords;
}

std::string Book::displayString () const{
  //creates a string that contains the product info
  std::stringstream ss;

  /*
  <name>
  Author: <author> ISBN: <isbn>
  <price> <quantity> left.
  */

  ss << getName() << std::endl;
  ss << "Author: " << author_ << " ISBN: " << isbn_ << std::endl;
  ss << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left." << std::endl;

  return ss.str();
}

void Book::dump(std::ostream& ostr) const{ // output stream
  // outputs the database format of the product info

  // product properties:
  ostr << category_ << std::endl;
  ostr << name_ << std::endl;
  ostr << std::fixed << std::setprecision(2) << price_ << std::endl;
  ostr << getQty() << std::endl;

  // book unique properties:
  ostr << isbn_ << std::endl;
  ostr << author_ << std::endl;
}