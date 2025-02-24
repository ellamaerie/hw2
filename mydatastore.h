#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "product.h"
#include "user.h"
#include <map>
#include <vector>
#include <string>
#include <set>

class MyDataStore : public DataStore {
  private:
  std::vector<Product*> products_;
  std::vector<User*> users_;
  std::map<std::string, std::set <Product*> > keywordMap_;
  std::map<std::string, std:: vector<Product*> > userCart_;

  public:
  MyDataStore();
  virtual ~MyDataStore();

  void addProduct(Product* x) override;
  void addUser(User* u ) override;
  std::vector<Product*> search (std::vector <std::string> & term, int type) override;
  void dump(std::ostream& ostr) override;

  void addToCart(const std::string& un, Product* x);
  void viewCart(const std::string& un) const;
  void buyCart(const std::string& un);
};

#endif