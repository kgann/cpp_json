#include <string>
#include <map>
#include <vector>

class JSON {
  private:
    std::string json;
    std::map<std::string, std::string> json_map;
    std::string trim(std::string, char);
    void parse();
    void split(std::string, char, std::vector<std::string>&);

  public:
    JSON(std::string);
    ~JSON(){};
    std::string getJSON();
    std::string get(std::string key);
};
