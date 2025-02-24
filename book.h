#ifndef BOOK_H
#define BOOK_H

#include "product.h"
#include <iostream>
#include <string>
#include <set>

class Book : public Product {
private:
  std::string isbn_;
  std::string author_;

public:
  Book(
    const std::string& category,
    const std::string& name,
    const double price,
    const int qty,
    
    const std::string& ISBN,
    const std::string& author
  );

  virtual ~Book();

  std::set<std::string> keywords() const override;
  std::string displayString() const override;
  void dump(std::ostream& ostr) const override;
};

#endif