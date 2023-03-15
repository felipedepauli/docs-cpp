#include <iostream>
#include <map>

// Map works like a dictionary in Python.
// It is a container that stores elements in a mapped fashion.
// Each element has a key value and a mapped value.
// No two mapped values can have same key values.
// The key values are generally used to sort and uniquely identify the elements,
// while the mapped values store the content associated to this key.


// What we are going to look at:
// 1. How to create a map.
// 2. How to insert elements into a map.
// 3. How to access elements from a map.
// 4. How to iterate over a map.
// 5. How to remove elements from a map.

int main(int argc, char *argv[]) {

    // 1. How to create a map.
    // 1.1. Create an empty map.
    std::map<std::string, int> m1;

    // 1.2. Create a map with elements.
    std::map<std::string, int> m2 = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}};
    std::map<std::string, int> m3 = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}};
    std::map<std::string, int> m4 = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}};
    std::map<std::string, int> m5 = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}};

    // 2. How to insert elements into a map.
    // 2.1. Insert a single element.
    m1.insert(std::pair<std::string, int>("one", 1));
    m1.insert(std::pair<std::string, int>("two", 2));
    m1.insert(std::pair<std::string, int>("three", 3));

    // 2.2. Insert multiple elements.
    m1.insert({{"four", 4}, {"five", 5}, {"six", 6}});
    m1.insert({{"seven", 7}, {"eight", 8}, {"nine", 9}});
    m1.insert({{"ten", 10}, {"eleven", 11}, {"twelve", 12}});
    m1.insert({{"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15}});

    // 3. How to access elements from a map.
    // 3.1. Access a single element.
    std::cout << "m1[\"one\"]   = " << m1["one"] << std::endl;
    std::cout << "m1[\"two\"]   = " << m1["two"] << std::endl;
    std::cout << "m1[\"three\"] = " << m1["three"] << std::endl;
    std::cout << "m1[\"four\"]  = " << m1["four"] << std::endl;

    // 3.2. Access multiple elements.
    std::cout << "m2[\"one\"]   = " << m2["one"] << std::endl;
    std::cout << "m2[\"two\"]   = " << m2["two"] << std::endl;
    std::cout << "m2[\"three\"] = " << m2["three"] << std::endl;
    std::cout << "m2[\"four\"]  = " << m2["four"] << std::endl;

    // 4. How to iterate over a map.
    // 4.1. Iterate over all elements.
    std::cout << "Iterate over all elements:" << std::endl;
    for (auto it = m1.begin(); it != m1.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
    

    std::map<std::string, int> m;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;

    std::cout << "m[\"one\"]   = " << m["one"] << std::endl;
    std::cout << "m[\"two\"]   = " << m["two"] << std::endl;
    std::cout << "m[\"three\"] = " << m["three"] << std::endl;
    std::cout << "m[\"four\"]  = " << m["four"] << std::endl;

    return 0;
}