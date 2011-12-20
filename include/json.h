#include <string>
#include <map>

class JSON {
  private:
    std::string json;
    std::map<std::string, std::string> json_map;
    std::string strip(std::string, char);
    void parse();

  public:
    JSON(std::string);
    ~JSON(){};
    std::string getJSON();
    std::string get(std::string key);
};