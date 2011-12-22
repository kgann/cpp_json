#include <string>
#include <map>
#include <vector>

class JSON {
  private:
    std::string json;
    std::map<std::string, std::string> json_map;
    std::map<std::string, std::string>::iterator iterator;
    std::string trim(std::string, const char);
    void parse();
    void split(std::string, const char, std::vector<std::string>&);

  public:
    JSON(std::string);
    ~JSON(){};
    std::string getJSON();
    std::string get(std::string key);
};
