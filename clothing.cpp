#include "clothing.h"
#include "util.h"
#include <sstream>
#include <iomanip>

Clothing::Clothing(const std::string& category, const std::string& name, double price, int quantity, const std::string& size, const std::string& brand)
: Product(category, name, price, quantity), size_(size), brand_(brand) {}

Clothing::~Clothing () {}

std::set<std::string> Clothing::keywords() const{
  std::set<std::string> totalKeywords;

  // parse name
  std::set<std::string> nameKeyword;
  nameKeyword = parseStringToWords(getName());
  totalKeywords.insert(nameKeyword.begin(), nameKeyword.end());

  // parse brand
  std::set<std::string> brandKeyword;
  brandKeyword = parseStringToWords(brand_);
  totalKeywords.insert(brandKeyword.begin(), brandKeyword.end());

  return totalKeywords;
}

std::string Clothing::displayString() const{
  /* 
  <name>
  Size: <size> Brand: <brand>
  <price> <quantity> left.
  */
  std::stringstream ss;

  ss << getName() << std::endl;
  ss << "Size: " << size_ << " Brand: " << brand_ << std::endl;
  ss << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left." << std::endl;

  return ss.str();
}

void Clothing::dump (std::ostream& ostr) const{
  ostr << category_ << std::endl;
  ostr << name_ << std::endl;
  ostr << std::fixed << std::setprecision(2) << price_ << std::endl;
  ostr << getQty() << std::endl;

  //clothing unique properties:
  ostr << size_ << std::endl;
  ostr << brand_ << std::endl;
}