#include "./include/json.h"
#include <sstream>
#include <string>
#include <vector>

#define COMMA ','
#define COLON ':'
#define DBL_QUOTE '"'
#define JSON_BEGIN '{'
#define JSON_END '}'
#define ESCAPE '\\'

JSON::JSON(std::string json){
  this->json = json;
  parse();
}

void JSON::parse(){
  std::string json;
  std::vector<std::string> properties, data;
  json = trim(trim(this->json, JSON_END), JSON_BEGIN);
  split(json, COMMA, properties);
  for(int i = 0; i < properties.size(); i++){
    split(properties[i], COLON, data);
    this->json_map[trim(data[0], DBL_QUOTE)] = trim(data[1], DBL_QUOTE);
    data.clear();
  }
}

void JSON::split(std::string s, const char delimeter, std::vector<std::string> &v){
  std::string current;
  bool inside_quote = false;
  for(int i = 0; i < s.length(); i++){
    if(s[i] == DBL_QUOTE){
      if(i == 0 || (i > 0 && s[i-1] != ESCAPE)){
        inside_quote = !inside_quote;
      }
      current += s[i];
    }else if(s[i] == delimeter && !inside_quote){
      v.push_back(current);
      current.clear();
    }else{
      current += s[i];
    }
  }
  v.push_back(current);
}

std::string JSON::trim(std::string s, const char c){
  size_t first, last;
  first = s.find_first_of(c);
  last = s.find_last_of(c);
  if(first == s.length() - 1) first = -1;
  return s.substr(first+1, last-1);
}

std::string JSON::getJSON(){
  return this->json;
}

std::string JSON::get(std::string key) {
  if(this->json_map.find(key) == this->json_map.end())
    throw "'" + key + "'" + " is not a valid key!";
  else
    return this->json_map[key];
}
