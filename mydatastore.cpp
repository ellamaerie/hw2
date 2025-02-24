#include "mydatastore.h"
#include "util.h"

#include <iostream>
#include <sstream>
#include <string>

MyDataStore::MyDataStore() {}

MyDataStore::~MyDataStore() {
    for (Product* x : products_) {
        delete x;
    }
    for (User* x : users_) {
        delete x;
    }
}

void MyDataStore::addProduct(Product* x) {
  products_.push_back(x);

  std::set <std::string> words;
  words = x->keywords();

  for (const std::string& w : words){
    keywordMap_[w].insert(x);
  }
}

void MyDataStore::addUser (User* x){
  users_.push_back(x);
}

std::vector<Product*> MyDataStore::search (std::vector<std::string>& term, int type){
  std::set<Product*> result;

  if(term.empty()){
    return {}; //empty vector
  }

  if(keywordMap_.find(term[0]) != keywordMap_.end()){
    result = keywordMap_[term[0]];
  }

  for (size_t i = 1; i <term.size() ; i++){
    if(keywordMap_.find(term[i]) != keywordMap_.end()){
      std::set<Product*> termProd;
      termProd = keywordMap_[term[i]];

      //and
      if(type == 0){
        result = setIntersection(result, termProd);
      }
      //or
      else {
        result = setUnion(result, termProd);
      }
    }
    //error
    else if (type == 0 && result.empty()) {
      return {};
      }
  }
  return std::vector<Product*>(result.begin(), result.end());
}

void MyDataStore::dump(std::ostream& ostr) {
    ostr << "<products>" << std::endl;
    for (Product* x : products_) {
        x->dump(ostr);
    }
    ostr << "</products>" << std::endl;

    ostr << "<users>" << std::endl;
    for (User* x : users_) {
        x->dump(ostr);
    }
    ostr << "</users>" << std::endl;
}

void MyDataStore::viewCart(const std::string& un) const {
  std::string lowUn;  
  lowUn = convToLower(un);

  if (userCart_.find(lowUn) == userCart_.end()) {
    std::cout << "Invalid username" << std::endl;
    return;
  }

  const std::vector<Product*>& shoppingCart = userCart_.at(lowUn);
  if (shoppingCart.empty()) {
    std::cout << "Cart is empty" << std::endl;
    return;
  }

  int i = 1;
  for (Product* x : shoppingCart) {
    std::cout << "Item " << i << std::endl;
    std::cout << x->displayString() << std::endl;
    std::cout << std::endl;
    i++;
  }
}

void MyDataStore::buyCart(const std::string& un) {
    std::string lowUn = convToLower(un);
    User* user = nullptr;
    for (User* u : users_) {
      if (convToLower(u->getName()) == lowUn) {
        user = u;
        break;
      }
    }
    if (!user) {
      std::cout << "Invalid username" << std::endl;
      return;
    }

    if (userCart_.find(lowUn) == userCart_.end() || userCart_[lowUn].empty()) {
      std::cout << "Cart is empty" << std::endl;
      return;
    }

    std::vector<Product*>& shoppingCart = userCart_[lowUn];
    std::vector<Product*> remains;
    for (Product* product : shoppingCart) {
      if (product->getQty() > 0 && user->getBalance() >= product->getPrice()) {  
      user->deductAmount(product->getPrice());
      product->subtractQty(1);
      } 
      else {
      remains.push_back(product);
    }
  }
  userCart_[lowUn] = remains;
}


void MyDataStore::addToCart(const std::string& un, Product* x) {
  std::string lowUn;
  lowUn = convToLower(un);

  if (userCart_.find(lowUn) == userCart_.end()) {
    bool uExists = false;
    for (User* u : users_) {
      if (convToLower(u->getName()) == lowUn) {
      uExists = true;
      break;
    }
  }
  if (!uExists) {
    std::cout << "Invalid username" << std::endl;
    return;
  }
 }
  userCart_[lowUn].push_back(x);
}