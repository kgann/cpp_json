#include "./include/json.h"
#include <sstream>
#include <string>

JSON::JSON(std::string json){
  this->json = json;
  parse();
}

JSON::~JSON(){}

void JSON::parse(){
  std::string token, key, value;
  size_t position;
  std::string json(strip(strip(this->json, '}'), '{'));
  std::istringstream iss(json);
  while(getline(iss, token, ',')){
    position = token.find_first_of(':');
    key = strip(token.substr(0, position), '"');
    value = strip(token.substr(position+1, token.size()), '"');
    this->json_map[key] = value;
  }
}

std::string JSON::strip(std::string s, char c){
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
  if (this->json_map.find(key) == this->json_map.end()) {
    throw "'" + key + "'" + " is not a valid key!";
  } else {
    return this->json_map[key];
  }
}