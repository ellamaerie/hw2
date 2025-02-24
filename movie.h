#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"
#include <iostream>
#include <set>
#include <string>

class Movie : public Product{
private:
  std::string genre_;
  std::string rating_;

public:
  Movie(
    const std::string& category,
    const std::string& name,
    const double price,
    const int qty,

    const std::string& genre,
    const std::string& rating
  );

  virtual ~Movie();

  std::set<std::string> keywords() const override;
  std::string displayString() const override;
  void dump(std::ostream& ostr) const override;
};

#endif