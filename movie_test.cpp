#include "book.h"
#include "movie.h"
#include <iostream>
#include <set>

void printKeywords(const std::set<std::string>& keywords) {
    std::cout << "Keywords: ";
    for (const auto& x : keywords) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    Book myBook("book", "title", 1, 4, "123456789", "author");
    Movie myMovie("movie", "title", 1, 9, "genre", 9);

    std::cout << "display string" << std::endl;
    std::cout << myBook.displayString() << std::endl;

    printKeywords(myBook.keywords());

    std::cout << "\nMovie Details:" << std::endl;
    std::cout << myMovie.displayString() << std::endl;

    printKeywords(myMovie.keywords());

    std::cout << "book dump" << std::endl;
    myBook.dump(std::cout);

    std::cout << "movie dump" << std::endl;
    myMovie.dump(std::cout);

    return 0;
}