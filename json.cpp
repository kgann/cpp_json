#include "./include/json.h"
#include <sstream>
#include <string>

#define COMMA ','
#define COLON ':'
#define DBL_QUOTE '"'
#define JSON_BEGIN '{'
#define JSON_END '}'

JSON::JSON(std::string json){
  this->json = json;
  parse();
}

void JSON::parse(){
  std::string token, key, value, json;
  size_t position;
  json = strip(strip(this->json, JSON_END), JSON_BEGIN);
  std::istringstream iss(json);
  while(getline(iss, token, COMMA)){
    position = token.find_first_of(COLON);
    key = strip(token.substr(0, position), DBL_QUOTE);
    value = strip(token.substr(position+1, token.size()), DBL_QUOTE);
    this->json_map[key] = value;
  }
}

std::string JSON::strip(std::string s, const char c){
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