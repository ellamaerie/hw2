#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"
#include <iostream> 
#include <set>
#include <string>

class Clothing : public Product {
private:
  std::string size_;
  std::string brand_;

public:
  Clothing (
    const std::string& category,
    const std::string& name,
    const double price,
    const int qty,

    const std::string& size,
    const std::string& brand
  );

  virtual ~Clothing();

  std::set<std::string> keywords() const override;
  std::string displayString() const override;
  void dump(std::ostream& ostr) const override;
};

#endif