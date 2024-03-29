#include "json.h"
#include <sstream>
#include <string>
#include <vector>

#define COMMA ','
#define COLON ':'
#define DBL_QUOTE '"'
#define JSON_BEGIN '{'
#define JSON_END '}'
#define ESCAPE '\\'
#define JSON_NULL "null"

JSON::JSON(std::string json){
  this->json = json;
  parse();
}

void JSON::parse(){
  std::string json, value, key;
  std::vector<std::string> properties, data;
  json = trim(trim(this->json, JSON_END), JSON_BEGIN);
  split(json, COMMA, properties);
  for(int i = 0; i < properties.size(); i++){
    split(properties[i], COLON, data);
    if(data.size() != 2)
      throw "Invalid JSON near " + properties[i];
    key = trim(data[0], DBL_QUOTE);
    value = trim(data[1], DBL_QUOTE);
    if(value == JSON_NULL)
      value.clear();
    this->json_map[key] = value;
    data.clear();
  }
}

void JSON::split(std::string s, const char delimeter, std::vector<std::string> &v){
  std::string current;
  bool inside_quote = false;
  for(int i = 0; i < s.length(); i++){
    if(s[i] != delimeter){
      if(s[i] == DBL_QUOTE && (i == 0 || (i > 0 && s[i-1] != ESCAPE)))
        inside_quote = !inside_quote;
      current += s[i];
    }else if(s[i] == delimeter && !inside_quote){
      v.push_back(current);
      current.clear();
    }else
      current += s[i];
  }
  v.push_back(current);
}

std::string JSON::trim(std::string s, const char c){
  if(s[0] == c)
    s = s.substr(1, s.size());
  if(s[s.size()-1] == c)
    s = s.substr(0, s.size()-1);
  return s;
}

std::string JSON::getJSON(){
  return this->json;
}

std::string JSON::get(std::string key){
  this->iterator = this->json_map.find(key);
  if(this->iterator == this->json_map.end())
    throw "'" + key + "'" + " is not a valid key!";
  return this->iterator->second;
}
